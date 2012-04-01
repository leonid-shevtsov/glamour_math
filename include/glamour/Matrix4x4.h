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
//==========================================================
///@name Необходимые операции
///@{
        ///Конструктор по умолчанию
        /**
         * Создает единичную матрицу
         */
        Matrix4x4();
        ///Конструктор копирования
        /**
         * @param from Исходный объект
         */
        Matrix4x4(const Matrix4x4& from);
        ///Оператор присваивания
        /**
         * @param from Исходный объект
         * @return Данный объект
         */
        Matrix4x4& operator=(const Matrix4x4& from);
        ///Деструктор
        ~Matrix4x4();
///@}
//==========================================================
///@name Конструкторы
///@{
        /// Конструктор диагональной матрицы
        /**
         * @param a Значение элементов диагонали
         */
        Matrix4x4(const float a);
        /// Поэлементный конструктор
        /**
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
///@}
//==========================================================
///@name Свойства
///@{
    ///Выборка элемента по двум индексам
    /**
     * @param i Ряд
     * @param j Колонка
     * @return A[i,j]
     * @note Индексы должны принадлежать отрезку [0..3]
     * @warning Оператор не производит проверку на корректность индексов!
     */
    float& element(const int i,const int j);
///@}
//==========================================================
///@name Операторы
///@{
    ///Выборка элемента по индексу
    /**
     * @param i Индекс элемента
     * @return Ссылка на элемент
     * @note Индекс должен принадлежать отрезку [0..15]
     * @warning Оператор не производит проверку на корректность индекса!
     */
    float& operator[](const int i);
    ///Преобразование в массив элементов
    /**
     * Полученный таким образом массив содержит 16 элементов и может быть
     * использован как для записи, так и для чтения.
     * @return Указатель на матрицу как на массив чисел
     */
    operator float*();
    ///Умножение на число
    /**
     * @param k Коэффициент
     * @return Результат операции
     */
    Matrix4x4& operator*=(const float k);
    ///Матричное умножение
    /**
     * @param matrix Матрица-множитель
     * @return Результат операции
     */
    Matrix4x4& operator*=(const Matrix4x4& matrix);
    ///Умножение на число
    /**
     * Важно! Оптимизация подразумевает, что четвертые столбцы
     * матриц пустые (т.е. w=const).
     * Для полных расчетов используй mulMatrix
     * @param matrix Матрица-множитель
     * @param k Коэффициент
     * @return Результат операции
     */
    friend Matrix4x4 operator*(const Matrix4x4& matrix,const float k);
    ///Умножение на число
    /**
     * @param matrix Матрица-множитель
     * @param k Коэффициент
     * @return Результат операции
     */
    friend Matrix4x4 operator*(const float k,const Matrix4x4& matrix);
    ///Матричное умножение
    /**
     * @param a Матрица-множитель
     * @param b Матрица-множитель
     * @return Результат операции
     */
    friend Matrix4x4 operator*(const Matrix4x4& a,const Matrix4x4& b);
///@}
//==========================================================
///@name Операции
///@{
    ///Транспонирование непосредственно данной матрицы
    void transpose();
    ///Возвращает транспонированную матрицу
    /**
     * @return Транспонированная матрица
     */
    Matrix4x4 getTranspose();
    ///Применение к вектору
    /**
     * @param v Вектор
     * @return Преобразованный вектор
     * @note Операция неприменима, если матрица
     * изменяет однородную координату вектора @i w,
     * например, если это матрица проекции.
     */
    Vector3d applyToVector(const Vector3d& v);
    ///Применение к точке
    /**
     * @param p Вектор координат точки
     * @return Преобразованная точка
     * @note Операция неприменима, если матрица
     * изменяет однородную координату вектора @i w,
     * например, если это матрица проекции.
     */
    Vector3d applyToPoint(const Vector3d& p);
    ///Применение к вектору с учетом W
    /**
     * @param v Вектор
     * @return Преобразованный вектор
     */
    Vector3d applyToVectorW(const Vector3d& v);
    ///Применение к точке с учетом W
    /**
     * @param p Вектор координат точки
     * @return Преобразованная точка
     */
    Vector3d applyToPointW(const Vector3d& p);
    ///Установка в GL_PROJECTION
    void setAsGlProjection();
    ///Установка в GL_MODELVIEW
    void setAsGlModelview();
    ///Сохранение GL_PROJECTION
    void getGlProjection();
    ///Сохранение GL_MODELVIEW
    void getGlModelview();

    Matrix4x4 mulMatrix(const Matrix4x4& m2);
///@}
//==========================================================
///@name Фабрики
///@{
    ///Создает матрицу перемещения
    /**
     * @param t Вектор перемещения
     * @return Матрица перемещения
     */
    static Matrix4x4 createTranslate(const Vector3d& t);
    ///Создает матрицу масштабирования
    /**
     * @param s Вектор масштабирования
     * @return Матрица масштабирования
     */
    static Matrix4x4 createScale(const Vector3d& s);
    ///Создает матрицу вращения вокруг произвольной оси
    /**
     * @param a Угол
     * @param r Вектор оси
     * @return Матрица вращения
     */
    //static Matrix4x4 createRotate(const float a,const Vector3d& r);
    ///Создает матрицу вращения вокруг оси X
    /**
     * @param a Угол
     * @return Матрица вращения
     */
    static Matrix4x4 createRotateX(const float a);
    ///Создает матрицу вращения вокруг оси Y
    /**
     * @param a Угол
     * @return Матрица вращения
     */
    static Matrix4x4 createRotateY(const float a);
    ///Создает матрицу вращения вокруг оси Z
    /**
     * @param a Угол
     * @return Матрица вращения
     */
    static Matrix4x4 createRotateZ(const float a);
///@}
//==========================================================
///@name Члены
///@{
    protected:
    private:
        float data[16];
///@}
//==========================================================
    };
    ///Короткое название типа Matrix4x4
    typedef Matrix4x4 mat4;
}
#endif
