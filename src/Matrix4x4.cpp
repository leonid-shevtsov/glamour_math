#include <cstring>
#include <cmath>
#include "glamour/Matrix4x4.h"

namespace Glamour {

Matrix4x4::Matrix4x4()
{
    data[ 0]=1.0; data[ 1]=0.0; data[ 2]=0.0; data[ 3]=0.0;
    data[ 4]=0.0; data[ 5]=1.0; data[ 6]=0.0; data[ 7]=0.0;
    data[ 8]=0.0; data[ 9]=0.0; data[10]=1.0; data[11]=0.0;
    data[12]=0.0; data[13]=0.0; data[14]=0.0; data[15]=1.0;
}

Matrix4x4::Matrix4x4(const Matrix4x4& from)
{
    memcpy(data,from.data,16*sizeof(float));
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& from)
{
    memcpy(data,from.data,16*sizeof(float));
    return *this;
}

Matrix4x4::~Matrix4x4()
{
}

Matrix4x4::Matrix4x4(const float a)
{
    data[ 0]=  a; data[ 1]=0.0; data[ 2]=0.0; data[ 3]=0.0;
    data[ 4]=0.0; data[ 5]=  a; data[ 6]=0.0; data[ 7]=0.0;
    data[ 8]=0.0; data[ 9]=0.0; data[10]=  a; data[11]=0.0;
    data[12]=0.0; data[13]=0.0; data[14]=0.0; data[15]=  a;
}

Matrix4x4::Matrix4x4(
    const float a00,const float a10,
    const float a20,const float a30,
    const float a01,const float a11,
    const float a21,const float a31,
    const float a02,const float a12,
    const float a22,const float a32,
    const float a03,const float a13,
    const float a23,const float a33)
{
    data[ 0]=a00; data[ 4]=a10; data[ 8]=a20; data[12]=a30;
    data[ 1]=a01; data[ 5]=a11; data[ 9]=a21; data[13]=a31;
    data[ 2]=a02; data[ 6]=a12; data[10]=a22; data[14]=a32;
    data[ 3]=a03; data[ 7]=a13; data[11]=a23; data[15]=a33;
}

float& Matrix4x4::operator[](const int i)
{
    return data[i];
}

Matrix4x4::operator float*()
{
    return data;
}

Matrix4x4& Matrix4x4::operator*=(const float k)
{
    data[ 0]*=k;data[ 1]*=k;data[ 2]*=k;data[ 3]*=k;
    data[ 4]*=k;data[ 5]*=k;data[ 6]*=k;data[ 7]*=k;
    data[ 8]*=k;data[ 9]*=k;data[10]*=k;data[11]*=k;
    data[12]*=k;data[13]*=k;data[14]*=k;data[15]*=k;
    return *this;
}

Matrix4x4 operator*(const Matrix4x4& matrix,const float k)
{
    Matrix4x4 m=matrix;
    m*=k;
    return m;
}

Matrix4x4 operator*(const float k,const Matrix4x4& matrix)
{
    Matrix4x4 m=matrix;
    m*=k;
    return m;
}

Matrix4x4 Matrix4x4::mulMatrix(const Matrix4x4& b)
{
    Matrix4x4 c;
    c.data[ 0]=
         b.data[ 0]*data[ 0]+b.data[ 1]*data[ 4]
        +b.data[ 2]*data[ 8]+b.data[ 3]*data[12];
    c.data[ 1]=
         b.data[ 0]*data[ 1]+b.data[ 1]*data[ 5]
        +b.data[ 2]*data[ 9]+b.data[ 3]*data[13];
    c.data[ 2]=
         b.data[ 0]*data[ 2]+b.data[ 1]*data[ 6]
        +b.data[ 2]*data[10]+b.data[ 3]*data[14];
    c.data[ 3]=
         b.data[ 0]*data[ 3]+b.data[ 1]*data[ 7]
        +b.data[ 2]*data[11]+b.data[ 3]*data[15];

    c.data[ 4]=
         b.data[ 4]*data[ 0]+b.data[ 5]*data[ 4]
        +b.data[ 6]*data[ 8]+b.data[ 7]*data[12];
    c.data[ 5]=
         b.data[ 4]*data[ 1]+b.data[ 5]*data[ 5]
        +b.data[ 6]*data[ 9]+b.data[ 7]*data[13];
    c.data[ 6]=
         b.data[ 4]*data[ 2]+b.data[ 5]*data[ 6]
        +b.data[ 6]*data[10]+b.data[ 7]*data[14];
    c.data[ 7]=
         b.data[ 4]*data[ 3]+b.data[ 5]*data[ 7]
        +b.data[ 6]*data[11]+b.data[ 7]*data[15];

    c.data[ 8]=
         b.data[ 8]*data[ 0]+b.data[ 9]*data[ 4]
        +b.data[10]*data[ 8]+b.data[11]*data[12];
    c.data[ 9]=
         b.data[ 8]*data[ 1]+b.data[ 9]*data[ 5]
        +b.data[10]*data[ 9]+b.data[11]*data[13];
    c.data[10]=
         b.data[ 8]*data[ 2]+b.data[ 9]*data[ 6]
        +b.data[10]*data[10]+b.data[11]*data[14];
    c.data[11]=
         b.data[ 8]*data[ 3]+b.data[ 9]*data[ 7]
        +b.data[10]*data[11]+b.data[11]*data[15];

    c.data[12]=
         b.data[12]*data[ 0]+b.data[13]*data[ 4]
        +b.data[14]*data[ 8]+b.data[15]*data[12];
    c.data[13]=
         b.data[12]*data[ 1]+b.data[13]*data[ 5]
        +b.data[14]*data[ 9]+b.data[15]*data[13];
    c.data[14]=
         b.data[12]*data[ 2]+b.data[13]*data[ 6]
        +b.data[14]*data[10]+b.data[15]*data[14];
    c.data[15]=
         b.data[12]*data[ 3]+b.data[13]*data[ 7]
        +b.data[14]*data[11]+b.data[15]*data[15];
    return c;
}

Matrix4x4 operator*(const Matrix4x4& a,const Matrix4x4& b)
{
    Matrix4x4 c;
    c.data[ 0]=
         b.data[ 0]*a.data[ 0]+b.data[ 1]*a.data[ 4]
        +b.data[ 2]*a.data[ 8];
    c.data[ 1]=
         b.data[ 0]*a.data[ 1]+b.data[ 1]*a.data[ 5]
        +b.data[ 2]*a.data[ 9];
    c.data[ 2]=
         b.data[ 0]*a.data[ 2]+b.data[ 1]*a.data[ 6]
        +b.data[ 2]*a.data[10];
    //c.data[ 3]=0.0;

    c.data[ 4]=
         b.data[ 4]*a.data[ 0]+b.data[ 5]*a.data[ 4]
        +b.data[ 6]*a.data[ 8];
    c.data[ 5]=
         b.data[ 4]*a.data[ 1]+b.data[ 5]*a.data[ 5]
        +b.data[ 6]*a.data[ 9];
    c.data[ 6]=
         b.data[ 4]*a.data[ 2]+b.data[ 5]*a.data[ 6]
        +b.data[ 6]*a.data[10];
    //c.data[ 7]=0.0;

    c.data[ 8]=
         b.data[ 8]*a.data[ 0]+b.data[ 9]*a.data[ 4]
        +b.data[10]*a.data[ 8];
    c.data[ 9]=
         b.data[ 8]*a.data[ 1]+b.data[ 9]*a.data[ 5]
        +b.data[10]*a.data[ 9];
    c.data[10]=
         b.data[ 8]*a.data[ 2]+b.data[ 9]*a.data[ 6]
        +b.data[10]*a.data[10];
    //c.data[11]=0.0;

    c.data[12]=
         b.data[12]*a.data[ 0]+b.data[13]*a.data[ 4]
        +b.data[14]*a.data[ 8]+a.data[12];
    c.data[13]=
         b.data[12]*a.data[ 1]+b.data[13]*a.data[ 5]
        +b.data[14]*a.data[ 9]+a.data[13];
    c.data[14]=
         b.data[12]*a.data[ 2]+b.data[13]*a.data[ 6]
        +b.data[14]*a.data[10]+a.data[14];
    //c.data[15]=1.0;
    return c;
}


Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& m)
{
    *this=(*this)*m;
    return *this;
}

void Matrix4x4::transpose()
{
    float t;
    t=data[ 1];data[ 1]=data[ 4];data[ 4]=t;
    t=data[ 2];data[ 2]=data[ 8];data[ 8]=t;
    t=data[ 3];data[ 3]=data[12];data[12]=t;
    t=data[ 6];data[ 6]=data[ 9];data[ 9]=t;
    t=data[ 7];data[ 7]=data[13];data[13]=t;
    t=data[11];data[11]=data[14];data[14]=t;
}

Matrix4x4 Matrix4x4::getTranspose()
{
    Matrix4x4 m(*this);
    m.transpose();
    return m;
}

Vector3d Matrix4x4::applyToVector(const Vector3d& v)
{
    return Vector3d(
        data[0]*v.x+data[4]*v.y+data[8]*v.z,
        data[1]*v.x+data[5]*v.y+data[9]*v.z,
        data[2]*v.x+data[6]*v.y+data[10]*v.z
    );
}

Vector3d Matrix4x4::applyToPoint(const Vector3d& p)
{
    return Vector3d(
        data[0]*p.x+data[4]*p.y+data[8]*p.z+data[12],
        data[1]*p.x+data[5]*p.y+data[9]*p.z+data[13],
        data[2]*p.x+data[6]*p.y+data[10]*p.z+data[14]
    );
}
//==========================================================
//Применение к вектору с учетом W
Vector3d Matrix4x4::applyToVectorW(const Vector3d& v)
{
    float w_1=1.0/(data[3]*v.x+data[7]*v.y+data[11]*v.z);
    return Vector3d(
        (data[0]*v.x+data[4]*v.y+data[8]*v.z)*w_1,
        (data[1]*v.x+data[5]*v.y+data[9]*v.z)*w_1,
        (data[2]*v.x+data[6]*v.y+data[10]*v.z)*w_1
    );
}

Vector3d Matrix4x4::applyToPointW(const Vector3d& p)
{
    float w_1=1.0/(data[3]*p.x+data[7]*p.y+data[11]*p.z+data[15]);
    return Vector3d(
        (data[0]*p.x+data[4]*p.y+data[8]*p.z+data[12])*w_1,
        (data[1]*p.x+data[5]*p.y+data[9]*p.z+data[13])*w_1,
        (data[2]*p.x+data[6]*p.y+data[10]*p.z+data[14])*w_1
    );
}

float& Matrix4x4::element(const int i,const int j)
{
    return data[i*4+j];
}

Matrix4x4 Matrix4x4::createTranslate(const Vector3d& t)
{
    return Matrix4x4
    (
        1.0,0.0,0.0,t.x,
        0.0,1.0,0.0,t.y,
        0.0,0.0,1.0,t.z,
        0.0,0.0,0.0,1.0
    );
}

Matrix4x4 Matrix4x4::createScale(const Vector3d& s)
{
    return Matrix4x4
    (
        s.x,0.0,0.0,0.0,
        0.0,s.y,0.0,0.0,
        0.0,0.0,s.z,0.0,
        0.0,0.0,0.0,1.0
    );
}

Matrix4x4 Matrix4x4::createRotateX(const float a)
{
    float c=cos(a);
    float s=sin(a);
    return Matrix4x4
    (
        1.0,0.0,0.0,0.0,
        0.0,  c, -s,0.0,
        0.0,  s,  c,0.0,
        0.0,0.0,0.0,1.0
    );
}

Matrix4x4 Matrix4x4::createRotateY(const float a)
{
    float c=cos(a);
    float s=sin(a);
    return Matrix4x4
    (
          c,0.0,  s,0.0,
        0.0,1.0,0.0,0.0,
         -s,0.0,  c,0.0,
        0.0,0.0,0.0,1.0
    );
}

Matrix4x4 Matrix4x4::createRotateZ(const float a)
{
    float c=cos(a);
    float s=sin(a);
    return Matrix4x4
    (
          c, -s,0.0,0.0,
          s,  c,0.0,0.0,
        0.0,0.0,1.0,0.0,
        0.0,0.0,0.0,1.0
    );
}

} // namespace Glamour
