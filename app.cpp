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

  Scene scene;
  Sphere sphere;
  sphere.p = Vec(.5, 0, 0);
  sphere.r = .5;
  scene.spheres.push_back(sphere);

  sphere.p = Vec(-.5, 0, 0);
  scene.spheres.push_back(sphere);

  sphere.p = Vec(0, -.5, 0);
  scene.spheres.push_back(sphere);

  sphere.p = Vec(0, .5, 0);
  scene.spheres.push_back(sphere);

  // for(auto s : scene.spheres){
  //   cout << s.p.x << endl;
  // }

  Renderer renderer(ppm, scene);
  renderer.render();  
  
  return 0;
}
