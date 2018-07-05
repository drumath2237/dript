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
  }
};

#endif // !H_SCENE