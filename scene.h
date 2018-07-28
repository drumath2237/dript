#ifndef H_SCENE
#define H_SCENE

#include <vector>

#include "sphere.h"
#include "hit.h"

struct Scene {
  std::vector<Sphere> spheres;

  bool intersect(const Ray ray, double tmin, double tmax) const
  {
    for(auto sphere : spheres){
      const auto h = sphere.intersect_test(ray, tmin, tmax);
      if(!h){continue;}
      else {return true;}
    }
    return false;
  }
};

#endif // !H_SCENE