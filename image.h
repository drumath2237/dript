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
  PPM(string f):file_name(f){}
  PPM(int w, int h, string f):width(w),height(h),file_name(f){}

  int size(){return width*height;}
};

/**
 * ppm_out() output .ppm file by scan data from PPM Object.
*/
void ppm_out(PPM ppm)
{
  if(ppm.C.size() != ppm.width*ppm.height) return; // if vector size doesn't match ppm image size, return.

  ofstream ofs(ppm.file_name);
  ofs << "P3\n" << ppm.width << " " << ppm.height << "\n" << ppm.max_color << endl;

  for(auto v : ppm.C){
    ofs << v.x << " "
        << v.y << " "
        << v.z << endl;
  }
}

#endif