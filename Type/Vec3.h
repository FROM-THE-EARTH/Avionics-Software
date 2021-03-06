#ifndef INCLUDE_VEC3_H
#define INCLUDE_VEC3_H

#include "../Utils/Utils.h"
#include "../Type/XString.h"

struct Vec3
{
  float x, y, z;

  constexpr Vec3()
      : x(0.0f), y(0.0f), z(0.0f)
  {
  }

  constexpr Vec3(float _x, float _y, float _z)
      : x(_x), y(_y), z(_z)
  {
  }

  /*========================method=============================*/

  xString toString() const
  {
    return xString("(" + to_XString(x) + "," + to_XString(y) + "," + to_XString(z) + ")");
  }

  float length() const
  {
    return Utils::Math::sqrt(x * x + y * y + z * z);
  }

  Vec3 normalized() const
  {
    return *this / length();
  }

  /*============================operator=========================*/

  constexpr bool operator==(const Vec3 &v) const
  {
    return (x == v.x) && (y == v.y) && (z == v.z);
  }

  constexpr Vec3 operator+() const
  {
    return *this;
  }

  constexpr Vec3 operator-() const
  {
    return {-x, -y, -z};
  }

  constexpr Vec3 operator+(const Vec3 &v) const
  {
    return {x + v.x, y + v.y, z + v.z};
  }

  constexpr Vec3 operator-(const Vec3 &v) const
  {
    return {x - v.x, y - v.y, z - v.z};
  }

  constexpr Vec3 operator*(float value) const
  {
    return {x * value, y * value, z * value};
  }

  constexpr Vec3 operator*(const Vec3 &v) const
  {
    return {x * v.x, y * v.y, z * v.z};
  }

  constexpr Vec3 operator/(float value) const
  {
    return {x / value, y / value, z / value};
  }

  Vec3 &operator+=(const Vec3 &v)
  {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  Vec3 &operator-=(const Vec3 &v)
  {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  Vec3 &operator*=(const Vec3 &v)
  {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  Vec3 &operator/=(const Vec3 &v)
  {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
  }

  //inner product
  constexpr float operator^(const Vec3 &v) const
  {
    return x * v.x + y * v.y + z * v.z;
  }

  //outer product
  constexpr Vec3 operator|(const Vec3 &v) const
  {
    return {
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x};
  }
};

inline constexpr Vec3 operator*(float value, const Vec3 &v)
{
  return {value * v.x, value * v.y, value * v.z};
}


#endif