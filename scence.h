#ifndef H_SCENE
#define H_SCENE

#include <vector>
#include <optional>

#include "sphere.h"

struct Scene {
  std::vector<Sphere> spheres;
};

#endif // !H_SCENE