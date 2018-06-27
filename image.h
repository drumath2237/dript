#ifndef H_IMAGE
#define H_IMAGE

#include <iostream>
#include <string>

using namespace std;

struct PPM
{
  int width;
  int height;
  string file_name;
  int max_color;

  PPM():width(600),height(400),file_name("result.ppm"),max_color(255){}
};

#endif