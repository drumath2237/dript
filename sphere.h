#ifndef H_SPHERE
#define H_SPHERE

#include <optional>
#include <iostream>

#include "vec.h"
#include "ray.h"
#include "hit.h"

struct Sphere {
  Vec p;
  double r;

  optional<Hit> intersect(const Ray ray, double tmin, double tmax)
  {
    Vec op = p - ray.o;
    double b = dot(ray.d, op);
    double det = b * b - dot(op, op) + r * r; // check this

    if(det < 0) return std::nullopt;

    double t1 = b-sqrt(det);
    if(tmin<t1 && t1<tmax){
      Hit hit;
      hit.t = t1;
      hit.sphere = this;
      return hit;
    }

    double t2 = b+sqrt(det);
    if(tmin<t2 && t2<tmax){
      Hit hit;
      hit.t = t2;
      hit.sphere = this;
      return hit;
    }

    return std::nullopt;
  }
};

#endif