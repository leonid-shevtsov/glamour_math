//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * Определение класса Quaternion
 * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
 * @version 0.1
 * @date 27.09.2006
 */
#ifndef GLA_Quaternion_h
#define GLA_Quaternion_h

#include "Vector3d.h"
#include "Matrix4x4.h"
namespace Glamour
{
    /// Кватернион
    /**
     * Кватернионы используются для описания поворотов
     * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
     * @version 0.1
     * @date 27.09.2006
     */
    class Quaternion
    {
    public:
//==========================================================
///@name Необходимые операции
///@{
        ///Конструктор по умолчанию
        Quaternion();
        ///Конструктор копирования
        /**
         * @param from Исходный объект
         */
        Quaternion(const Quaternion& from);
        ///Оператор присваивания
        /**
         * @param from Исходный объект
         * @return Данный объект
         */
        Quaternion& operator=(const Quaternion& from);
        ///Деструктор
        ~Quaternion();
///@}
//==========================================================
///@name Конструкторы
///@{
    Quaternion(const Vector3d& v);
    Quaternion(const Vector3d& v,float w);
    Quaternion(float x,float y,float z,float w);
///@}
//==========================================================
///@name Свойства
///@{
    float norm() const;
    float magnitude() const;
///@}
//==========================================================
///@name Операторы
///@{
    friend Quaternion operator-(const Quaternion& q);
    friend Quaternion operator!(const Quaternion& q);
    friend Quaternion operator+(const Quaternion& q1,const Quaternion& q2);
    friend Quaternion operator*(const Quaternion& q,float f);
    friend Quaternion operator/(const Quaternion& q,float f);
    friend Quaternion operator*(float f,const Quaternion& q);
    friend Quaternion operator*(const Quaternion& q1,const Quaternion& q2);

    Quaternion& operator*=(const Quaternion& q1);
    operator Vector3d();
///@}
//==========================================================
///@name Методы
///@{
    ///Произвести поворот относительно заданной оси
    /**
     * @param angle Угол поворота.
     * @param axis Ось поворота.
     */
    void makeRotate(float angle,const Vector3d& axis);
    ///Произвести поворот относительно оси X
    /**
     * @param angle Угол поворота (рад).
     */
    void makeRotateX(float angle);
    ///Произвести поворот относительно оси Y
    /**
     * @param angle Угол поворота (рад).
     */
    void makeRotateY(float angle);
    ///Произвести поворот относительно оси Z
    /**
     * @param angle Угол поворота (рад).
     */
    void makeRotateZ(float angle);
    ///Создает матрицу для поворота
    /**
     * @return Эквивалентная матрица
     */
    Matrix4x4 toMatrix();
    ///Применяет заданный поворот к вектору
    Vector3d applyToVector(const Vector3d& v);
///@}
//==========================================================
///@name Фабрики
///@{
    static Quaternion createRotate(float angle,const Vector3d& axis);
    static Quaternion createRotateX(float angle);
    static Quaternion createRotateY(float angle);
    static Quaternion createRotateZ(float angle);
///@}
//==========================================================
///@name Члены
///@{
public:
    ///Скалярная часть
    float w;
    ///Векторная часть
    Vector3d v;
    protected:
    private:
///@}
//==========================================================
    };
    ///Короткое имя типа для кватерниона
    typedef Quaternion quat;
}
#endif
