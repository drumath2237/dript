#include <iostream>
#include <fstream>

#include "dript.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int w = 1200;
  int h = 800;

  ofstream ofs("result.ppm");
  ofs << "P3\n" << w << " " << h << "\n255\n";
  for(int i=0; i<w*h; i++){
    ofs << "255 0 255" << endl;
  }
  return 0;
}
