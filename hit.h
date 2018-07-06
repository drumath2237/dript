#ifndef H_HIT
#define H_HIT

#include "sphere.h"
#include "ray.h"

struct Hit
{
  Ray* ray;
  double t;
  Sphere* sphere;
};

#endif // !H_HIT