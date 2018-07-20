#include <iostream>
#include <cstdio>
#include <vector>

#include "dript.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Scene scene;
  Sphere s = Sphere(Vec(), 100);
  PPM ppm;
  // color vector
  vector<Vec> I(400*640);

  for(int i=0; i<400*640; i++){
    int x = i % 640;
    int y = i / 640;
    Ray ray;
    ray.o = Vec(x,y,0);
    ray.d = Vec(0,0,1);

    auto res = scene.intersect(ray, 1e-10, 1e+10);
    I[i] = res ? Vec(255, 255, 255) : Vec(0,0,0);

    // cout << i << ":" << res << endl;
  }
  for(auto i : I){
    ppm.C.push_back(i);
  }
  // for(int i=0; i<640*400; i++){
  //   cout << i << ":" << ppm.C[i].x << endl;
  // }
  ppm_out(&ppm);

  return 0;
}
