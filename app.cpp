#include <iostream>
#include <fstream>
#include <vector>

#include "dript.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int w = 800;
  int h = 800;

  PPM ppm = PPM(w, h);
  vector<Vec> v(ppm.size());

  Scene scene;
  Sphere sphere;
  sphere.p = Vec();
  sphere.r = 1.;
  scene.spheres.push_back(sphere);

  for(int i=0; i<ppm.size(); i++){
    int x = i%w;
    int y = i/w;

    Ray ray;
    ray.o = Vec(2. * double(x) / w - 1., 2. * double(y) / h - 1., 5.);
    ray.d = Vec(0, 0, -1);

    if(auto h = scene.intersect(ray, 0, 1e+10)){
      v[i] = Vec(
        tonemap(h->n.x),
        tonemap(h->n.y),
        tonemap(h->n.z)        
      );
    }else{
      v[i] = Vec();
    }
  }

  ppm_out(ppm, v);
  
  return 0;
}
