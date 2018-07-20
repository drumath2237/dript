#ifndef H_SCENE
#define H_SCENE

#include <vector>
#include <optional>
#include <iostream>

#include "sphere.h"
#include "hit.h"

using namespace std;

struct Scene {
  std::vector<Sphere> spheres;

  double intersect(const Ray ray, double tmin, double tmax) const
  {
    double h;
    for (auto sphere : spheres)
    {
      h = sphere.intersect_test(ray, tmin, tmax);
      // if(!h){continue;}
      // else {return true;}
      cout << h << endl;
    }
    return h;
  }
};

#endif // !H_SCENE