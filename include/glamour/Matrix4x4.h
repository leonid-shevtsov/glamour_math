#ifndef GLA_Matrix4x4_h
#define GLA_Matrix4x4_h

#include "Vector3d.h"
namespace Glamour
{
    /** A 4 by 4 matrix 
     *  Such matrices are used to describe three-dimensional transformations.
     *
     *  This class is designed to be OpenGL-compatible, so it uses OpenGL indexing
     *  conventions: column-first, row-second.
     *
     *  The * (multiplication) operator is expecting affine matrices. If the matrix
     *  transforms the fourth coordinate, or if you are not sure if it does, use
     *  the mulMatrix method instead
     *
     *  Use Quaternion objects to create rotation matrices.
     */
    class Matrix4x4
    {
    public:
        /** Diagonal matrix constructor
         *  @param a value of diagonal elements
         */
        Matrix4x4(const float a);
        /** Per-element constructor
         */
        Matrix4x4(
            const float a00,const float a10,
            const float a20,const float a30,
            const float a01,const float a11,
            const float a21,const float a31,
            const float a02,const float a12,
            const float a22,const float a32,
            const float a03,const float a13,
            const float a23,const float a33);

        /** Element selector
        *  Take care! There is no range checking.
        *  TODO range checking in debug mode
        *
        *  @param i Row (0..3)
        *  @param j Column (0..3)
        *  @return reference to A[i,j]
        */
        float& element(const int i,const int j);

        /** Element selector (single-index)
         *  Take care! There is no range checking.
         *  TODO range checking in debug mode
         *  TODO more docs here
         *
         *  @param i Element index
         *  @return reference to A[i] 
         */
        float& operator[](const int i);

        /** Cast to a floating-point array
         *  Returns a pointer to a 16-element array of matrix values.
         *  The array is writable (modifications will affect the matrix). 
         */
        operator float*();

        /** Multiplication by a number
        */
        Matrix4x4& operator*=(const float k);

        /** Multiplication by a matrix
        */
        Matrix4x4& operator*=(const Matrix4x4& matrix);

        friend Matrix4x4 operator*(const Matrix4x4& matrix,const float k);
        friend Matrix4x4 operator*(const float k,const Matrix4x4& matrix);
        friend Matrix4x4 operator*(const Matrix4x4& a,const Matrix4x4& b);

        /** In-place transposition
         */
        void transpose();

        /** Transposition into a new matrix
         */
        Matrix4x4 getTranspose();

        /** Application to a vector (representing orientation)
         *  If the matrix changes the W (fourth) coordinate of the vector,
         *  i.e. it's a projection matrix, this method will produce wrong
         *  results
         */
        Vector3d applyToVector(const Vector3d& v);

        /** Application to a point (a vector representing position)
         *  If the matrix changes the W (fourth) coordinate of the vector,
         *  i.e. it's a projection matrix, this method will produce wrong
         *  results
         */
        Vector3d applyToPoint(const Vector3d& p);

        /** Application to a vector with computing W
         *  Same as applyToVector, but with the fourth coordinate
         */
        Vector3d applyToVectorW(const Vector3d& v);

        /** Application to a point with computing W
         *  Same as applyToPoint, but with the fourth coordinate
         */
        Vector3d applyToPointW(const Vector3d& p);

        /** Matrix multiplication
         *  Straightforward mathematical matrix multiplication.
         */
        Matrix4x4 mulMatrix(const Matrix4x4& m2);

        /** Translation matrix factory
         */
        static Matrix4x4 createTranslate(const Vector3d& t);

        /** Scale matrix factory
         */
        static Matrix4x4 createScale(const Vector3d& s);

        //static Matrix4x4 createRotate(const float a,const Vector3d& r);
        
        /** Rotation around X axis matrix factory
         */
        static Matrix4x4 createRotateX(const float a);

        /** Rotation around Y axis matrix factory
         */
        static Matrix4x4 createRotateY(const float a);

        /** Rotation around Z axis matrix factory
         */
        static Matrix4x4 createRotateZ(const float a);

    private:
        float data[16];

    public:
        Matrix4x4();
        Matrix4x4(const Matrix4x4& from);
        Matrix4x4& operator=(const Matrix4x4& from);
        ~Matrix4x4();
    };

    /** Shorthand name of the Matrix4x4 class
     */
    typedef Matrix4x4 mat4;
}
#endif
