#include <iostream>
#include <fstream>
#include <vector>

#include "dript.h"
#include "renderer.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int w = 800;
  int h = 800;

  PPM ppm = PPM(w, h);
  vector<Vec> v(ppm.size());

  Sphere sphere;
  sphere.p = Vec();
  sphere.r = 1.;
  
  Scene scene;
  scene.spheres.push_back(sphere);

  Renderer renderer(ppm, scene);
  renderer.render();  
  
  return 0;
}
