#include <iostream>
#include <fstream>
#include <vector>
// #include <optional>

#include "dript.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int w = 300;
  int h = 300;
  PPM* ppm = new PPM(w, h);
  Scene scene;
  vector<Vec> I(w*h);
  long int i;

  for(i=0;i<w*h;i++){
    const int x = i%x;
    const int y = h-i/w;

    Ray* ray;
    ray->o = Vec(x,y,0);
    ray->d = Vec(0,0,-1);

    I[i] = scene.intersect(ray, 1e-4, 1e+10) ? Vec(255,255,255):Vec(0,0,0);
    // cout << scene.intersect(ray, 1e-4, 1e+10) << endl;
  }

  ppm->C = I;
  ppm_out(ppm);

  return 0;
}
