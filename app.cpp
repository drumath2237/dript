#include <iostream>
#include <cstdio>
#include <vector>

#include "dript.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Scene scene;
  Sphere s = Sphere(Vec(), 1);
  PPM ppm;
  // color vector
  vector<Vec> I(ppm.width*ppm.height);

  for(int i=0; i<ppm.width*ppm.height; i++){
    int x = i % ppm.width;
    int y = i / ppm.width;
    x/=ppm.width;
    y/=ppm.height;
    Ray ray;
    ray.o = Vec(x,y,-5);
    ray.d = Vec(0,0,1);

    auto res = scene.intersect(ray, 1e-10, 1e+10);
    // I[i] = res ? Vec(255, 255, 255) : Vec(0,0,0);
    cout << res << endl;

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
