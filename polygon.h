#ifndef H_POLYGON
#define H_POLYGON

#include <vector>
#include <optional>

#include "vec.h"
#include "ray.h"
#include "hit.h"

using namespace std;

struct Polygon3 {
  vector<Vec> vertexes = {
    {}, {}, {}
  };

  Polygon3(vector<Vec> vs)
  {
    if(vs.size() == 3){
      for(int i=0; i<3; i++){
        vertexes[i] = vs[i];
      }
    }
  }

  Polygon3(Vec a, Vec b, Vec c)
  {
    vertexes[0] = a;
    vertexes[1] = b;
    vertexes[2] = c;
  }

  Vec normal_vec()
  {
    // TODO: 法線を返す関数の実装
  }

  optional<Hit> intersect(Ray ray, double tmin, double tmax)
  {
    // TODO: 交差判定をする関数の実装
  }
};

#endif // !H_POLYGON