#ifndef H_SCENE
#define H_SCENE

#include <vector>
#include <optional>

#include "sphere.h"
#include "hit.h"

#include <iostream>
#include <cstdio>

struct Scene {
  std::vector<Sphere> spheres;

  optional<Hit> intersect(const Ray ray, double tmin, double tmax) const
  {
    optional<Hit> minh;
    for(auto sphere : spheres){
      const auto h = sphere.intersect(ray, tmin, tmax);
      if(!h){continue;}
      // std::cout << h->sphere->p.x << std::endl;
      minh = h;
      tmax = minh->t;
    }

    if(minh)
    {
      const auto *s = minh->sphere;

      printf("(%lf, %lf)\n", s->p.x, s->p.y);
      
      minh->p = ray.o + ray.d * minh->t;
      minh->n = (minh->p - s->p)/s->r;
    }
    
    return minh;
  }
};

#endif // !H_SCENE