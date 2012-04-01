#include <cmath>
#include "glamour/PerspectiveCamera.h"
namespace Glamour {

PerspectiveCamera::PerspectiveCamera():
    Camera(),
    theta(60),
    aspect(4.0/3.0),
    zNear(1.0),
    zFar(10000.0)
{
}

PerspectiveCamera::PerspectiveCamera(const PerspectiveCamera& from)
{
}

PerspectiveCamera& PerspectiveCamera::operator=(const PerspectiveCamera& from)
{
    return *this;
}

PerspectiveCamera::~PerspectiveCamera()
{
}

PerspectiveCamera::PerspectiveCamera(
    const vec3& pos,
    const vec3& dir,
    const vec3& up,
    float _theta,
    float _aspect,
    float _zNear,
    float _zFar):
    Camera(pos,dir,up),
    theta(_theta),
    aspect(_aspect),
    zNear(_zNear),
    zFar(_zFar)
{
}

void PerspectiveCamera::build()
{
    float ct=1.0f/tan(theta*3.14159265/(180.0*2.0));
    float zd=1.0f/(zNear-zFar);
    projection=mat4(
        ct/aspect,0.0,0.0,0.0,
        0.0,ct,0.0,0.0,
        0.0,0.0,(zNear+zFar)*zd,(2*zNear*zFar)*zd,
        0.0,0.0,-1.0,0.0
    );
    buildView();
}

} // namespace Glamour
