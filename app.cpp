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
  vector<Vec> I(400*640);

  for(int i=0; i<400*640; i++){
    int x = i % 640;
    int y = i / 640;

    printf("(%d, %d)\n", x, y);
  }

  return 0;
}
