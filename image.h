#ifndef H_IMAGE
#define H_IMAGE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "vec.h"

using namespace std;

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
};

void ppm_out(PPM* ppm)
{
  ofstream ofs(ppm->file_name);
  ofs << "P3\n" << ppm->width << " " << ppm->height << "\n" << ppm->max_color << endl;

  for(int i=0; i<ppm->width*ppm->height; i++){
    ofs << ppm->C[i].x << " "
        << ppm->C[i].y << " "
        << ppm->C[i].z;
  }
}

#endif