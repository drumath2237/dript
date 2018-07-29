#ifndef H_IMAGE
#define H_IMAGE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "vec.h"

using namespace std;

/**
 * PPM structure is about .ppm file.
 */
struct PPM
{
  int width=600;
  int height=400;
  int max_color=255;
  string file_name = "result.ppm";
  vector<Vec> C;

  PPM(){}
  PPM(int w, int h):width(w),height(h){}

  int size(){ return width*height; }
};


bool ppm_out(PPM ppm, vector<Vec> C)
{
  if(ppm.size() != C.size()) return false; // if vector size doesn't match ppm image size, return.

  ofstream ofs(ppm.file_name);
  ofs << "P3\n" << ppm.width << " " << ppm.height << "\n" << ppm.max_color << endl;

  for(auto v : C){
    ofs << v.x << " "
        << v.y << " "
        << v.z << endl;
  }
  return true;
}

#endif