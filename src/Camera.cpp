//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * Реализация класса Camera
 * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
 * @version 0.1
 * @date 11.09.2006
 */
#include "glamour/Camera.h"
using namespace Glamour;
//==========================================================
//Конструктор по умолчанию
Camera::Camera():
    p(0.0,0.0,0.0),
    v(0.0,1.0,0.0),
    n(0.0,0.0,1.0),
    rot(),
    projection(),
    modelview()
{
}
/*//==========================================================
//Конструктор копирования
Camera::Camera(const Camera& from)
{
}
//==========================================================
//Оператор присваивания
Camera& Camera::operator=(const Camera& from)
{
    return *this;
}*/
//==========================================================
//Деструктор
Camera::~Camera()
{
}
//==========================================================
Camera::Camera(const vec3& _pos,const vec3& _dir,const vec3& _up):
    p(_pos),
    v(_up),
    n(_dir),
    projection(),
    modelview()
{
}

void Camera::buildView()
{
    n.normalize();
    u=(v*n)/v.norm();
    v=n*u;
    modelview=mat4(
        u.x,v.x,n.x,0.0,
        u.y,v.y,n.y,0.0,
        u.z,v.z,n.z,0.0,
        0.0,0.0,0.0,1.0
    );
    modelview*=(-rot).toMatrix();
    modelview*=Matrix4x4::createTranslate(-p);
};

void Camera::apply()
{
    projection.setAsGlProjection();
    modelview.setAsGlModelview();
}

void Camera::resetView()
{
    modelview.setAsGlModelview();
}
