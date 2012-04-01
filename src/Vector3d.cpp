#include <cmath>
#include <cstdlib>
#include "glamour/Vector3d.h"
namespace Glamour{

Vector3d::Vector3d():
    x(0.0),y(0.0),z(0.0)
{
}

Vector3d::Vector3d(const Vector3d& from):
    x(from.x),
    y(from.y),
    z(from.z)
{
}

Vector3d& Vector3d::operator=(const Vector3d& from)
{
    x=from.x;
    y=from.y;
    z=from.z;
    return *this;
}

Vector3d::~Vector3d()
{
}

Vector3d::Vector3d(const float X,const float Y,const float Z):
    x(X),y(Y),z(Z)
{
}

Vector3d::Vector3d(const float f):
    x(f),y(f),z(f)
{
}

Vector3d::Vector3d(const Vector2d& v):
    x(v.x),y(v.y),z(0.0f)
{
}

float Vector3d::norm() const
{
    return sqrt(x*x+y*y+z*z);
}

float Vector3d::normSq() const
{
    return x*x+y*y+z*z;
}

Vector3d& Vector3d::normalize()
{
    return (*this)*=1.0f/norm();
}

Vector3d Vector3d::getNormalize() const
{
    return (*this)*(1.0f/norm());
}

Vector3d operator+(const Vector3d& v1,const Vector3d& v2)
{
    return Vector3d(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
}

Vector3d operator-(const Vector3d& v1,const Vector3d& v2)
{
    return Vector3d(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
}

Vector3d operator*(const Vector3d& u,const Vector3d& v)
{
    return Vector3d(u.y*v.z-u.z*v.y,u.z*v.x-u.x*v.z,u.x*v.y-u.y*v.x);
}

Vector3d operator/(const Vector3d& v,const float f)
{
    return v*(1.0f/f);
}

Vector3d operator-(const Vector3d& v)
{
    return Vector3d(-v.x,-v.y,-v.z);
}

float operator&(const Vector3d& u,const Vector3d& v)
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}

Vector3d operator*(const Vector3d& v,const float f)
{
    return Vector3d(v.x*f,v.y*f,v.z*f);
}

Vector3d operator*(const float f,const Vector3d& v)
{
    return v*f;
}

Vector3d& operator*=(Vector3d& v,const float f)
{
    v.x*=f;
    v.y*=f;
    v.z*=f;
    return v;
}

Vector3d& operator+=(Vector3d& u,const Vector3d& v)
{
    u.x+=v.x;
    u.y+=v.y;
    u.z+=v.z;
    return u;
}


Vector3d::operator float*()
{
    return &x;
}

Vector3d Vector3d::randomColor()
{
    return Vector3d(rand()/float(RAND_MAX),rand()/float(RAND_MAX),rand()/float(RAND_MAX));
}

/*
Vector3d Vector3d::randomSphereDelta(float radius)
{
    return 0.0;
}

Vector3d Vector3d::randomCubeDelta(float side)
{
    return Vector3d(
        (rand()/float(RAND_MAX)-0.5)*side,
        (rand()/float(RAND_MAX)-0.5)*side,
        (rand()/float(RAND_MAX)-0.5)*side);
}
*/

} //namespace Glamour
