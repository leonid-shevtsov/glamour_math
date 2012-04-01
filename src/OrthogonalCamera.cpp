#include "glamour/OrthogonalCamera.h"
namespace Glamour {

OrthogonalCamera::OrthogonalCamera():
    Camera(),
    wMin(-1.0,-1.0,-1.0),
    wMax(1.0,1.0,1.0)
{
}

OrthogonalCamera::OrthogonalCamera(const OrthogonalCamera& from)
{
}

OrthogonalCamera& OrthogonalCamera::operator=(const OrthogonalCamera& from)
{
    return *this;
}

OrthogonalCamera::~OrthogonalCamera()
{
}

OrthogonalCamera::OrthogonalCamera(
    const vec3& pos,
    const vec3& dir,
    const vec3& up,
    const vec3& _min,
    vec3& _max):
    Camera(pos,dir,up),
    wMin(_min),
    wMax(_max)
{
}

OrthogonalCamera::OrthogonalCamera(float left,float top,float right,float bottom):
    Camera(),
    wMin(left,bottom,-1),
    wMax(right,top,1)
{
}


void OrthogonalCamera::build()
{
    projection=mat4(
        2/(wMax.x-wMin.x),0.0,0.0,-(wMax.x+wMin.x)/(wMax.x-wMin.x),
        0.0,2/(wMax.y-wMin.y),0.0,-(wMax.y+wMin.y)/(wMax.y-wMin.y),
        0.0,0.0,-2/(wMax.z-wMin.z),-(wMax.z+wMin.z)/(wMax.z-wMin.z),
        0.0,0.0,0.0,1.0
    );
    buildView();
}

} // namespace Glamour
