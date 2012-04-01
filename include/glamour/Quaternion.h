#ifndef GLA_Quaternion_h
#define GLA_Quaternion_h

#include "Vector3d.h"
#include "Matrix4x4.h"
namespace Glamour
{
    /** Quaternion
     */
    class Quaternion
    {
    public:
        /** Scalar component
         */
        float w;

        /** Vector component
         */
        Vector3d v;

        /** Default constructor
         *  Creates an empty quaternion (0, 0, 0, 1)
         */
        Quaternion();

        /** Vector constructor
         *  Creates (v.x, v.y, v.z, 0) 
         */
        Quaternion(const Vector3d& v);

        /** Complete constructor
         *  Creates (v.x, v.y, v.z, w)
         */
        Quaternion(const Vector3d& v,float w);

        /** Per-element constructor
         *  Creates (x, ,y, z, w)
         */
        Quaternion(float x,float y,float z,float w);

        /** Quaternion norm
         */
        float norm() const;

        /** Quaternion magnitude
         */
        float magnitude() const;

        /** Negative quaternion
         *  The vector component is negated
         */
        friend Quaternion operator-(const Quaternion& q);

        /** Inverse quaternion
         *  Negative quaternion divided by its norm
         */
        friend Quaternion operator!(const Quaternion& q);
        friend Quaternion operator+(const Quaternion& q1,const Quaternion& q2);
        friend Quaternion operator*(const Quaternion& q,float f);
        friend Quaternion operator/(const Quaternion& q,float f);

        friend Quaternion operator*(float f,const Quaternion& q);
        friend Quaternion operator*(const Quaternion& q1,const Quaternion& q2);
        Quaternion& operator*=(const Quaternion& q1);

        /** Cast to Vector3d
         *  Returns the vector component
         */
        operator Vector3d();

        /** Create rotation quaternion
         *  The quaternion will represent a rotation around an arbitrary axis
         *  @param angle rotation angle in radians
         *  @param axis rotation axis
         */
        void makeRotate(float angle,const Vector3d& axis);

        /** Create rotation quaterion, axis = Ox
         */
        void makeRotateX(float angle);

        /** Create rotation quaterion, axis = Oy
         */
        void makeRotateY(float angle);

        /** Create rotation quaterion, axis = Oz
         */
        void makeRotateZ(float angle);

        /** Convert rotation to equivalent matrix
         */
        Matrix4x4 toMatrix();

        /** Apply rotation to vector
         */
        Vector3d applyToVector(const Vector3d& v);

        /** Create rotation quaternion
         *  The quaternion will represent a rotation around an arbitrary axis
         *  @param angle rotation angle in radians
         *  @param axis rotation axis
         */
        static Quaternion createRotate(float angle,const Vector3d& axis);

        /** Create rotation quaterion, axis = Ox
         */        
        static Quaternion createRotateX(float angle);

        /** Create rotation quaterion, axis = Oy
         */        
        static Quaternion createRotateY(float angle);

        /** Create rotation quaterion, axis = Oz
         */        
        static Quaternion createRotateZ(float angle);

        Quaternion(const Quaternion& from);
        Quaternion& operator=(const Quaternion& from);
        ~Quaternion();
    };

    /** Shorthand type name for Quaternion
     */
    typedef Quaternion quat;
}
#endif
