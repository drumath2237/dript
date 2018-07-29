#ifndef H_HIT
#define H_HIT

#include <iostream>
#include <vector>
#include <algorithm>

#include "ray.h"

class Sphere; // 循環参照を避けるためにinclude分を使わずクラスのプロトタイプを使用

struct Hit
{
  double t;
  Vec p;
  Vec n;
  Sphere *sphere; // すべては循環参照のせい
};

int tonemap(double v)
{
  return std::min(std::max(int(std::pow(v, 1/2.2)*255), 0), 255);
}

#endif // !H_HIT