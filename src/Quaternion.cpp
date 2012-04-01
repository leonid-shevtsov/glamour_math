#include <cmath>
#include "glamour/Quaternion.h"
namespace Glamour {

Quaternion::Quaternion():
    w(1),
    v(0,0,0)
{
}
Quaternion::Quaternion(const Quaternion& from):
    w(from.w),
    v(from.v)
{
}

Quaternion& Quaternion::operator=(const Quaternion& from)
{
    w=from.w;
    v=from.v;
    return *this;
}

Quaternion::~Quaternion()
{
}

Quaternion::Quaternion(const Vector3d& _v):
    w(0.0),
    v(_v)
{
}

Quaternion::Quaternion(const Vector3d& _v,float _w):
    w(_w),
    v(_v)
{
}

Quaternion::Quaternion(float x,float y,float z,float _w):
    w(_w),
    v(x,y,z)
{
}

Quaternion operator-(const Quaternion& q)
{
    return Quaternion(-q.v,q.w);
}

Quaternion operator!(const Quaternion& q)
{
    return (-q)/q.norm();
}


Quaternion operator+(const Quaternion& q1,const Quaternion& q2)
{
    return Quaternion(q1.v+q2.v,q1.w+q2.w);
}

Quaternion operator*(const Quaternion& q,float f)
{
    return Quaternion(q.v*f,q.w*f);
}

Quaternion operator/(const Quaternion& q,float f)
{
    f=1.0/f;
    return Quaternion(q.v*f,q.w*f);
}

Quaternion operator*(float f,const Quaternion& q)
{
    return q*f;
}

Quaternion operator*(const Quaternion& q1,const Quaternion& q2)
{
    return Quaternion(q1.w*q2.v+q2.w*q1.v+q1.v*q2.v,
                      q1.w*q2.w-(q1.v&q2.v));
}

Quaternion& Quaternion::operator*=(const Quaternion& q)
{
    *this=(*this)*q;
    return *this;
}

Quaternion::operator Vector3d()
{
    return v;
}

void Quaternion::makeRotate(float angle,const Vector3d& axis)
{
    angle/=2;
    w=cos(angle);
    v=axis.getNormalize()*sin(angle);
}

void Quaternion::makeRotateX(float angle)
{
    angle/=2;
    w=cos(angle);
    v=Vector3d(sin(angle),0.0,0.0);
}

void Quaternion::makeRotateY(float angle)
{
    angle/=2;
    w=cos(angle);
    v=Vector3d(0.0,sin(angle),0.0);
}

void Quaternion::makeRotateZ(float angle)
{
    angle/=2;
    w=cos(angle);
    v=Vector3d(0.0,0.0,sin(angle));
}

Quaternion Quaternion::createRotate(float angle,const Vector3d& axis)
{
    angle/=2;
    return Quaternion(axis.getNormalize()*sin(angle),cos(angle));
}

Quaternion Quaternion::createRotateX(float angle)
{
    angle/=2;
    return Quaternion(sin(angle),0.0,0.0,cos(angle));
}

Quaternion Quaternion::createRotateY(float angle)
{
    angle/=2;
    return Quaternion(0.0,sin(angle),0.0,cos(angle));
}

Quaternion Quaternion::createRotateZ(float angle)
{
    angle/=2.0;
    return Quaternion(0.0,0.0,sin(angle),cos(angle));
}

Matrix4x4 Quaternion::toMatrix()
{
    return Matrix4x4(
        1.0-2.0*(v.y*v.y+v.z*v.z),2.0*(v.x*v.y-w*v.z)    ,2.0*(v.x*v.z+w*v.y)    ,0.0,
        2.0*(v.x*v.y+w*v.z)    ,1.0-2.0*(v.x*v.x+v.z*v.z),2.0*(v.y*v.z-w*v.x)    ,0.0,
        2.0*(v.x*v.z-w*v.y)    ,2.0*(v.y*v.z+w*v.x)    ,1.0-2.0*(v.x*v.x+v.y*v.y),0.0,
        0.0                    ,0.0                    ,0.0                    ,1.0
    );
}

float Quaternion::magnitude() const
{
    return sqrt(norm());
}

float Quaternion::norm() const
{
    return w*w+(v&v);
}
/*
Quaternion Quaternion::createRotateZW(float angle)
{
    return createRotate(
        angle,
        Vector3d(-2*(v.x*v.z+w*v.y),
        -2*(v.y*v.z-w*v.x),
        -1+2*(v.x*v.x+v.y*v.y)
        ));
}
*/
Vector3d Quaternion::applyToVector(const Vector3d& v)
{
    return (Vector3d)((*this)*quat(v)*(-(*this)));
}

} //namespace Glamour

