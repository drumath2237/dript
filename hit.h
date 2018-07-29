#ifndef H_HIT
#define H_HIT

#include "ray.h"

class Sphere; // 循環参照を避けるためにinclude分を使わずクラスのプロトタイプを使用

struct Hit
{
  double t;
  Sphere *sphere; // すべては循環参照のせい
};

#endif // !H_HIT