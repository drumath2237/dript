#ifndef H_VEC
#define H_VEC

struct Vec {
  double x;
  double y;
  double z;

  Vec(): x(0),y(0),z(0){}
  Vec(double d):x(d),y(d),z(d){}
  Vec(double x, double y, double z):x(x),y(y),z(z){}
};

Vec operator-(const Vec v){
  return Vec(-v.x, -v.y, -v.z);
}
Vec operator+(const Vec a, const Vec b)
{
  return Vec(a.x + b.x, a.y + b.y, a.z + b.z);
}
Vec operator-(const Vec a, const Vec b)
{
  return Vec(a.x - b.x, a.y - b.y, a.z - b.z);
}
Vec operator*(const double d, const Vec b)
{
  return Vec(d * b.x, d * b.y, d * b.z);
}
Vec operator*(const Vec b, const double d)
{
  return Vec(d * b.x, d * b.y, d * b.z);
}

#endif // !H_VEC