#include <cmath>
#include <cstdlib>
#include "glamour/Vector2d.h"

namespace Glamour {

Vector2d::Vector2d():
    x(0.0),y(0.0)
{
}

Vector2d::Vector2d(const Vector2d& from):
    x(from.x),
    y(from.y)
{
}

Vector2d& Vector2d::operator=(const Vector2d& from)
{
    x=from.x;
    y=from.y;
    return *this;
}

Vector2d::~Vector2d()
{
}

Vector2d::Vector2d(const float X,const float Y):
    x(X),y(Y)
{
}

Vector2d::Vector2d(const float f):
    x(f),y(f)
{
}

float Vector2d::norm() const
{
    return sqrt(x*x+y*y);
}

float Vector2d::normSq() const
{
    return x*x+y*y;
}

Vector2d& Vector2d::normalize()
{
    return (*this)*=1.0f/norm();
}

Vector2d Vector2d::getNormalize() const
{
    return (*this)*(1.0f/norm());
}

Vector2d operator+(const Vector2d& v1,const Vector2d& v2)
{
    return Vector2d(v1.x+v2.x,v1.y+v2.y);
}

Vector2d operator-(const Vector2d& v1,const Vector2d& v2)
{
    return Vector2d(v1.x-v2.x,v1.y-v2.y);
}

float operator*(const Vector2d& u,const Vector2d& v)
{
    return u.x*v.y-u.y*v.x;
}

Vector2d operator/(const Vector2d& v,const float f)
{
    return v*(1.0f/f);
}

Vector2d operator-(const Vector2d& v)
{
    return Vector2d(-v.x,-v.y);
}

float operator&(const Vector2d& u,const Vector2d& v)
{
    return u.x*v.x+u.y*v.y;
}

Vector2d operator*(const Vector2d& v,const float f)
{
    return Vector2d(v.x*f,v.y*f);
}

Vector2d operator*(const float f,const Vector2d& v)
{
    return v*f;
}

Vector2d& operator*=(Vector2d& v,const float f)
{
    v.x*=f;
    v.y*=f;
    return v;
}

Vector2d& operator+=(Vector2d& u,const Vector2d& v)
{
    u.x+=v.x;
    u.y+=v.y;
    return u;
}


Vector2d::operator float*()
{
    return &x;
}

/*
Vector2d Vector2d::randomCircleDelta(float radius)
{
    return 0.0;
}

Vector2d Vector2d::randomSquareDelta(float side)
{
    return Vector2d(
        (rand()/float(RAND_MAX)-0.5)*side,
        (rand()/float(RAND_MAX)-0.5)*side);
}
*/

} //namespace Glamour
