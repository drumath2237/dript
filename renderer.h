#ifndef H_RENDERER
#define H_RENDERER

#include <vector>
#include <iostream>
#include <fstream>
#include <optional>

#include "dript.h"

struct Renderer {
  PPM ppm;
  Scene scene;

  Renderer(PPM p, Scene s):ppm(p), scene(s){}

  bool render()
  {
    if(ppm.size() <= 0) return false;

    vector<Vec> ppm_color(ppm.size());
    for(int i=0; i<ppm.size(); i++){
      int w = ppm.width;
      int h = ppm.height;
      
      int x = i%w;
      int y = i/w;

      Ray ray;
      ray.o = Vec(2. * double(x) / w - 1., 2. * double(y) / h - 1., 5.);
      ray.d = Vec(0, 0, -1);

      if (auto h = scene.intersect(ray, 0, 1e+10))
      {
        ppm_color[i] = Vec(
          tonemap(h->n.x),
          tonemap(h->n.y),
          tonemap(h->n.z)
        );
      }else{
        ppm_color[i] = Vec();
      }
    }

    ppm_out(ppm, ppm_color);
    
    return true;
  }

  
};

#endif // !H_RENDERER