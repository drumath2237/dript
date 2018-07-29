#ifndef H_SCENE
#define H_SCENE

#include <vector>
#include <optional>

#include "sphere.h"
#include "hit.h"

struct Scene {
  std::vector<Sphere> spheres;

  optional<Hit> intersect(const Ray ray, double tmin, double tmax) const
  {
    optional<Hit> minh;
    for(auto sphere : spheres){
      const auto h = sphere.intersect(ray, tmin, tmax);
      if(!h){continue;}
      minh = h;
      tmax = minh->t;
    }

    if(minh)
    {
      auto *s = minh->sphere;
      minh->p = ray.o + ray.d * minh->t;
      minh->n = (minh->p - s->p)/s->r;
    }
    
    return minh;
  }
};

#endif // !H_SCENE