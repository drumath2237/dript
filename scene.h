#ifndef H_SCENE
#define H_SCENE

#include <vector>
#include <optional>

#include "sphere.h"
#include "hit.h"

struct Scene {
  std::vector<Sphere> spheres;

  /*std::optional<Hit>*/bool intersect(const Ray& ray, double tmin, double tmax) const
  {
    // std::optional<Hit> minh;
    bool minh;
    for(auto& sphere : spheres){
      const auto h = sphere.intersect_test(ray, tmin, tmax);
      if(!h){continue;}
      else {return true;}
      // minh = h;
      // tmax = minh->t;
    }
    return false;
  }
};

#endif // !H_SCENE