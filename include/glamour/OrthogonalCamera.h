#ifndef GLA_OrthogonalCamera_h
#define GLA_OrthogonalCamera_h

#include "Camera.h"
namespace Glamour
{
    /** Orthogonal camera
     *  An orthogonal camera projects items preserving their original size.
     *
     *  It is useful for user interfaces.
     */
    class OrthogonalCamera: public Camera
    {
        /** Basic constructor
         *  @param pos the camera position
         *  @param dir camera direction
         *  @param up the "up" vector (should be perpendicular to dir)
         *  @param _min TODO ? 
         *  @param _max TODO ?
         */
        OrthogonalCamera(
            const vec3& pos,
            const vec3& dir,
            const vec3& up,
            const vec3& _min,
            vec3& _max);

        /** 2D-based constructor
         *  This constructor is useful to create a camera for a screen region
         *
         *  @param left left side of the viewable region
         *  @param top top side of the viewable region
         *  @param right right side of the viewable region
         *  @param bottom bottom side of the viewable regiono
         */
        OrthogonalCamera(
            float left,
            float top,
            float right,
            float bottom);

        virtual void build();

        vec3 wMin;
        vec3 wMax;

        OrthogonalCamera();
        OrthogonalCamera(const OrthogonalCamera& from);
        OrthogonalCamera& operator=(const OrthogonalCamera& from);
        ~OrthogonalCamera();
    };
}
#endif
