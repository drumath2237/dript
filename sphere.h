#ifndef H_SPHERE
#define H_SPHERE

#include <optional>

#include "vec.h"
#include "hit.h"
#include "ray.h"

struct Sphere {
  Vec p;
  double r;

  std::optional<Hit> intersect(const Ray& ray, double tmin, double tmax) const 
  {
    
  }
};

#endif