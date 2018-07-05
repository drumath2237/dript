#ifndef H_SCENE
#define H_SCENE

#include <vector>
#include <optional>

#include "sphere.h"
#include "hit.h"

struct Scene {
  std::vector<Sphere> spheres;

  std::optional<Hit> intersect(Ray& ray, double tmin, double tmax)
  {
    
  }
};

#endif // !H_SCENE