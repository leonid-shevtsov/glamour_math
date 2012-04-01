#ifndef GLA_Vector3d_h
#define GLA_Vector3d_h

#include "Vector2d.h"

namespace Glamour
{
    /** Three-dimensional vector type
     *  Note: vector multiplication is *. Scalar multiplication is &.
     *  This is to preserve correct operator priority.
     */
    class Vector3d
    {
    public:
        float x;
        float y;
        float z;
        
        /** Creates a zero vector
         */
        Vector3d();

        /** Initialize all components with the same value
         *  Creates (f, f, f) 
         */
        Vector3d(const float f);

        /** Per-component constructor
         *  Creates (X, Y, Z)
         */
        Vector3d(const float X,const float Y,const float Z);

        /** Typecast from 2D vector
         *  Creates (v.x, v.y, 0)
         */
        Vector3d(const Vector2d& v);

        /** Norm (length)
         */
        float norm() const;

        /** Norm squared
         *  Faster than norm(), could be useful for sorting vectors by length
         */
        float normSq() const;

        /** Typecast into float array
         */
        operator float*();

        friend Vector3d operator+(const Vector3d& u,const Vector3d& v);
        friend Vector3d operator-(const Vector3d& u,const Vector3d& v);

        friend Vector3d operator*(const Vector3d& v,const float f);
        friend Vector3d operator*(const float f,const Vector3d& v);
        friend Vector3d operator/(const Vector3d& v,const float f);

        /** Vector multiplication
         */
        friend Vector3d operator*(const Vector3d& u,const Vector3d& v);

        /** Per-component negation
         */
        friend Vector3d operator-(const Vector3d& v);

        /** Scalar multiplication
         *  @warn can cause operator precendence errors. You'll notice them
         *  because scalar multiplication returns a number, not a vector.
         */
        friend float operator&(const Vector3d& u,const Vector3d& v);

        friend Vector3d& operator*=(Vector3d& v,const float f);
        friend Vector3d& operator+=(Vector3d& u,const Vector3d& v);

        /** In-place normalization
         *  Makes a vector of the same orientation with a norm of 1. 
         */
        Vector3d& normalize();

        /** Normalization
         *  Returns a vector of the same orientation with a norm of 1.
         */
        Vector3d getNormalize() const;

        /** Random color
         *  Returns a vector of three random values in the [0, 1) range
         */
        static Vector3d randomColor();

        // TODO figure out these methods
        //static Vector3d randomSphereDelta(float radius);
        //static Vector3d randomCubeDelta(float side);

        Vector3d(const Vector3d& from);
        Vector3d& operator=(const Vector3d& from);
        ~Vector3d();
    };

    /** Shorthand type name for Vector3d
     */
    typedef Vector3d vec3;
}
#endif
