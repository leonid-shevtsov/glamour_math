#ifndef GLA_Camera_h
#define GLA_Camera_h

#include "Vector3d.h"
#include "Matrix4x4.h"
#include "Quaternion.h"

namespace Glamour
{
    /** Camera base class
    *  This is the base class representing a camera. It handles generating the view matrix, and the
    *  projection matrix must be implemented in a descendant class. (see PerspectiveCamera)
    *  @todo fix the quaternion issues - dont need rot OR uvn anymore
    */
    class Camera
    {
    public:

        /** Vector-based constructor
        *  This constructor takes three vectors to describe the camera:
        * @param _pos is the camera position
        * @param _dir is the direction it's facing
        * @param _up is the "up" direction, which should be perpendicular to _dir
        */
        Camera(const vec3& _pos,const vec3& _dir,const vec3& _up);
        
        virtual void build()=0;
        virtual void buildView();
        void apply();
        void resetView();

        vec3 p;
        vec3 u;
        vec3 v;
        vec3 n;
        quat rot;
        mat4 projection;
        mat4 modelview;


        /// Default constructor
        Camera();
        /// Copy costructor
        Camera(const Camera& from);
        /// Assignment operator
        Camera& operator=(const Camera& from);
        /// Destructor
        virtual ~Camera();
  };
}
#endif
