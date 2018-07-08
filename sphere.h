#ifndef H_SPHERE
#define H_SPHERE

// #include <optional>

#include "vec.h"
// #include "hit.h"
#include "ray.h"

struct Sphere {
  Vec p;
  double r;

  // std::optional<Hit> intersect(const Ray& ray, double tmin, double tmax) const 
  // {
  //   Vec op = p - ray->o;
  //   double b = dot(ray->d, op);
  //   double det = b*b -4*(dot(op, op) - r*r);  // check this 

  //   if(det < 0){return {}}

  // }
  Sphere():p(Vec()),r(1.0){}
  Sphere(Vec v, double r):p(v),r(r){}
  
  bool intersect_test(const Ray *ray, double tmin, double tmax) const
  {
    Vec op = p - ray->o;
    double b = dot(ray->d, op);
    double det = b * b - 4 * (dot(op, op) - r * r); // check this

    if (det < 0)
    {
      return false;
    }else{
      return true;
    }

    return false;
  }
};

#endif