#ifndef H_HIT
#define H_HIT

#include "sphere.h"
#include "ray.h"

struct Hit
{
  Ray* ray;
  double d;
  Sphere* sphere;
};

#endif // !H_HIT