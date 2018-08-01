#ifndef H_POLYGON
#define H_POLYGON

#include <vector>
#include <optional>

#include "vec.h"
#include "ray.h"
#include "hit.h"

using namespace std;

struct Polygon3 {
  Vec a, b, c;
  
  Polygon3(vector<Vec> vs):a(vs[0]),b(vs[1]),c(vs[2]){}

  Polygon3(Vec a, Vec b, Vec c):a(a),b(b),c(c){}

  Vec normal_vec()
  {
    Vec AB = b - a;
    Vec BC = c - b;

    return normalize(cross(AB, BC));
  }

  optional<Hit> intersect(Ray ray, double tmin, double tmax)
  {
    // TODO: 交差判定をする関数の実装
  }
};

#endif // !H_POLYGON