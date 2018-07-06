#ifndef H_SCENE
#define H_SCENE

#include <vector>
#include <optional>

#include "sphere.h"
#include "hit.h"

struct Scene {
  std::vector<Sphere> spheres;

  std::optional<Hit> intersect(const Ray& ray, double tmin, double tmax) const
  {
    std::optional<Hit> minh;
    for(auto& sphere : spheres){
      const auto h = sphere.intersect(ray, tmin, tmax);
      if(!h){continue;}
      minh = h;
      tmax = minh->t;
    }
  }
};

#endif // !H_SCENE