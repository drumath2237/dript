#ifndef H_SPHERE
#define H_SPHERE

#include <optional>

#include "vec.h"
#include "ray.h"
#include "hit.h"

struct Sphere {
  Vec p;
  double r;

  bool isIntersect(const Ray ray, double tmin, double tmax) const
  {
    Vec op = p - ray.o;
    double b = dot(ray.d, op);
    double det = b * b - dot(op, op) + r * r; // check this

    if (det < 0)
    {
      return false;
    }else{
      return true;
    }
  }

  optional<Hit> intersect(const Ray ray, double tmin, double tmax)
  {
    if(!isIntersect(ray, tmin, tmax)){ return {}; }

    Vec op = p - ray.o;
    double b = dot(ray.d, op);
    double det = b * b - dot(op, op) + r * r; // check this

    double t1 = b-sqrt(det);
    if(tmin<t1 && t1<tmax){
      Hit hit;
      hit.t = t1;
      hit.sphere = this;
    }

    double t2 = b+sqrt(det);
    if(tmin<t1 && t1<tmax){ return Hit{t1, this}; }

    return {};
  }
};

#endif