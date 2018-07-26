#include <iostream>
#include <fstream>
#include <vector>

#include "dript.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int w = 1200;
  int h = 800;

  PPM ppm = PPM(w, h);
  vector<Vec> v(ppm.size());
  for(int i=0; i<ppm.size(); i++)
    v[i] = Vec(255, 0 ,255);
  for(int i=0; i<ppm.size(); i++)
    ppm.C.push_back(v[i]);
  ppm_out(ppm);
  return 0;
}
