#ifndef GLA_PerspectiveCamera_h
#define GLA_PerspectiveCamera_h

#include "Camera.h"
namespace Glamour
{
    /** Perspective camera
     *  A perspective camera does a perspective transform when doing the projection to
     *  view space: objects that are further away look smaller.
     */
    class PerspectiveCamera: public Camera
    {
    public:
        /** Basic constructor
         *  In addition to pos, dir and up (see Camera::Camera()), this constructor
         *  takes more params to set up the perspective projection.
         *
         *  @param pos the camera position
         *  @param dir camera direction
         *  @param up the "up" vector (should be perpendicular to dir)
         *  @param _theta field-of-value angle
         *  @param _aspect screen aspect ratio
         *  @param _zNear Z value of the near clipping plane
         *  @param _zFar  Z value of the far clipping planeo
         */
        PerspectiveCamera(
            const vec3& pos,
            const vec3& dir,
            const vec3& up,
            float _theta,
            float _aspect,
            float _zNear,
            float _zFar);

        virtual void build();

        float theta;
        float aspect;
        float zNear;
        float zFar;

        PerspectiveCamera();
        PerspectiveCamera(const PerspectiveCamera& from);
        PerspectiveCamera& operator=(const PerspectiveCamera& from);
        ~PerspectiveCamera();
    };
}
#endif
