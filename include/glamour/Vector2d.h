#ifndef GLA_Vector2d_h
#define GLA_Vector2d_h
namespace Glamour
{
    /** Two-dimensional vector
     */
    class Vector2d
    {
    public:
        float x;
        float y;

        /** Creates a zero vector
         */
        Vector2d();

        /** Creates (f, f)
         */
        Vector2d(const float f);

        /** Creates (X, Y)
         */
        Vector2d(const float X,const float Y);

        /** Norm (length)
         */
        float norm() const;

        /** Squared norm
         *  Significantly faster than norm
         */
        float normSq() const;

        /** Typecast to float[2]
         */
        operator float*();

        friend Vector2d operator+(const Vector2d& u,const Vector2d& v);
        friend Vector2d operator-(const Vector2d& u,const Vector2d& v);
        friend Vector2d operator*(const Vector2d& v,const float f);
        friend Vector2d operator*(const float f,const Vector2d& v);
        friend Vector2d operator/(const Vector2d& v,const float f);

        /** Vector multiplication
        */
        friend float operator*(const Vector2d& u,const Vector2d& v);
        
        /** Scalar multiplication
        */
        friend float operator&(const Vector2d& u,const Vector2d& v);

        /** Per-component negation
        */
        friend Vector2d operator-(const Vector2d& v);

        friend Vector2d& operator*=(Vector2d& v,const float f);
        friend Vector2d& operator+=(Vector2d& u,const Vector2d& v);

        /** In-place normalization
        */
        Vector2d& normalize();
        
        /** Normalization into a new vector
        */
        Vector2d getNormalize() const;

        // TODO figure these out
        //static Vector2d randomCircleDelta(float radius);
        //static Vector2d randomSquareDelta(float side);

        Vector2d(const Vector2d& from);
        Vector2d& operator=(const Vector2d& from);
        ~Vector2d();
    };
    
    /** Shorthand type name for Vector2d
     */
    typedef Vector2d vec2;
}
#endif
