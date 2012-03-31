//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * Определение класса Vector2d
 * @author <a href="LeonidShevtsov@gmail.com">Леонид Шевцов</a>
 * @version 0.1
 * @date 16.11.2006
 */
#ifndef GLA_Vector2d_h
#define GLA_Vector2d_h
namespace Glamour
{
    /// Двумерный вектор
    /**
     * !!! Важно - код перенесен из Vector2d. Могут быть нестыковки!
     * @todo Операции над векторами
     * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
     * @version 0.1
     * @date 16.11.2006
     */
    class Vector2d
    {
    public:
//==========================================================
///@name Необходимые операции
///@{
        ///Конструктор по умолчанию
        /**
         * Создает нулевой вектор
         */
        Vector2d();
        ///Конструктор копирования
        /**
         * @param from Исходный объект
         */
        Vector2d(const Vector2d& from);
        ///Оператор присваивания
        /**
         * @param from Исходный объект
         * @return Данный объект
         */
        Vector2d& operator=(const Vector2d& from);
        ///Деструктор
        ~Vector2d();
///@}
//==========================================================
///@name Конструкторы
///@{
    ///Поэлементный конструктор
    Vector2d(const float f);
    Vector2d(const float X,const float Y);
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
    friend Vector2d operator+(const Vector2d& u,const Vector2d& v);
    ///Вычитание
    friend Vector2d operator-(const Vector2d& u,const Vector2d& v);
    ///Умножение на скаляр
    friend Vector2d operator*(const Vector2d& v,const float f);
    ///Умножение на скаляр
    friend Vector2d operator*(const float f,const Vector2d& v);
    ///Векторное умножение
    friend float operator*(const Vector2d& u,const Vector2d& v);
    ///Деление на скаляр
    friend Vector2d operator/(const Vector2d& v,const float f);
    ///Обратный вектор
    friend Vector2d operator-(const Vector2d& v);
    ///Скалярное произведение
    friend float operator&(const Vector2d& u,const Vector2d& v);

    ///Умножение на скаляр
    friend Vector2d& operator*=(Vector2d& v,const float f);
    friend Vector2d& operator+=(Vector2d& u,const Vector2d& v);
///@}
//==========================================================
///@name Методы
///@{
    Vector2d& normalize();
    Vector2d getNormalize() const;
///@}
//==========================================================
///@name Фабрики
///@{
    static Vector2d randomCircleDelta(float radius);
    static Vector2d randomSquareDelta(float side);
///@}
//==========================================================
///@name Члены
///@{
    public:
    ///координата
    float x;
    ///координата
    float y;
///@}
//==========================================================
    };
    ///Короткое название для класса Vector2d
    typedef Vector2d vec2;
}
#endif
