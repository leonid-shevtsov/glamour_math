//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * Определение класса Vector3d
 * @author <a href="LeonidShevtsov@gmail.com">Леонид Шевцов</a>
 * @version 0.1
 * @date 23.08.2006
 */
#ifndef GLA_Vector3d_h
#define GLA_Vector3d_h

#include "Vector2d.h"

namespace Glamour
{
    /// Трехмерный вектор
    /**
     * @todo Операции над векторами
     * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
     * @version 0.3
     * Набор операторов расширен.
     * @date 27.09.2006
     * !!! Важно !!!
     * Поскольку операции & и ^ имеют меньший приоритет, чем
     * + и -, то операция ^ (векторное умножение) изменена на
     * *. Операция & (скалярное умножение) не так опасна, так как
     * выражение
     * @code
     * float f,a;
     * Vector3d v1,v2;
     * f=a+v1&v2; // f = (a+v1)&v2;
     * @endcode
     * требует сложения числа и вектора, что невозможно, а выражение
     * @code
     * Vector3d u,q,v1,v2;
     * q=u+v1^v2; // q = (u+v1)^v2;
     * @endcode
     * вполне корректно и не вызовет ошибку.
     *
     * Ввиду этого операции над векторами выполняются так:
     * @code
     * x=u+v1*v2; // векторное умножение
     * x=a+(v1&v2); //скалярное умножение
     * @endcode
     * @version 0.2
     * Набор операций расширен: norm,normSq,normalise
     * @date 11.09.2006
     * @version 0.1
     * @date 23.08.2006
     */
    class Vector3d
    {
    public:
//==========================================================
///@name Необходимые операции
///@{
        ///Конструктор по умолчанию
        /**
         * Создает нулевой вектор
         */
        Vector3d();
        ///Конструктор копирования
        /**
         * @param from Исходный объект
         */
        Vector3d(const Vector3d& from);
        ///Оператор присваивания
        /**
         * @param from Исходный объект
         * @return Данный объект
         */
        Vector3d& operator=(const Vector3d& from);
        ///Деструктор
        ~Vector3d();
///@}
//==========================================================
///@name Конструкторы
///@{
    ///Поэлементный конструктор
    Vector3d(const float f);
    Vector3d(const float X,const float Y,const float Z);
    Vector3d(const Vector2d& v);
///@}
//==========================================================
///@name Свойства
///@{
    ///Длина (норма)
    float norm() const;
    ///Длина в квадрате
    float normSq() const;
///@}
//==========================================================
///@name Операторы
///@{
    operator float*();
    ///Сложение
    friend Vector3d operator+(const Vector3d& u,const Vector3d& v);
    ///Вычитание
    friend Vector3d operator-(const Vector3d& u,const Vector3d& v);
    ///Умножение на скаляр
    friend Vector3d operator*(const Vector3d& v,const float f);
    ///Умножение на скаляр
    friend Vector3d operator*(const float f,const Vector3d& v);
    ///Векторное умножение
    friend Vector3d operator*(const Vector3d& u,const Vector3d& v);
    ///Деление на скаляр
    friend Vector3d operator/(const Vector3d& v,const float f);
    ///Обратный вектор
    friend Vector3d operator-(const Vector3d& v);
    ///Скалярное произведение
    friend float operator&(const Vector3d& u,const Vector3d& v);

    ///Умножение на скаляр
    friend Vector3d& operator*=(Vector3d& v,const float f);
    friend Vector3d& operator+=(Vector3d& u,const Vector3d& v);
///@}
//==========================================================
///@name Методы
///@{
    Vector3d& normalize();
    Vector3d getNormalize() const;
///@}
//==========================================================
///@name Фабрики
///@{
    static Vector3d randomColor();
    static Vector3d randomSphereDelta(float radius);
    static Vector3d randomCubeDelta(float side);
///@}
//==========================================================
///@name Члены
///@{
    public:
    ///координата
    float x;
    ///координата
    float y;
    ///координата
    float z;
    protected:
    private:
///@}
//==========================================================
    };
    ///Короткое название для класса Vector3d
    typedef Vector3d vec3;
}
#endif
