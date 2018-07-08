#ifndef H_HIT
#define H_HIT

#include "sphere.h"
#include "ray.h"

struct Hit
{
  double t;
  Sphere* sphere;
};

#endif // !H_HIT