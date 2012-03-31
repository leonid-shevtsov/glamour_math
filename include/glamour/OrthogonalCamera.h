//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * Определение класса OrthogonalCamera
 * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
 * @version 0.1
 * @date 11.09.2006
 */
#ifndef GLA_OrthogonalCamera_h
#define GLA_OrthogonalCamera_h

#include "Camera.h"
namespace Glamour
{
    /// Ортогональная камера
    /**
     * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
     * @version 0.1
     * @date 11.09.2006
     */
    class OrthogonalCamera: public Camera
    {
    public:
//==========================================================
///@name Необходимые операции
///@{
        ///Конструктор по умолчанию
        OrthogonalCamera();
        ///Конструктор копирования
        /**
         * @param from Исходный объект
         */
        OrthogonalCamera(const OrthogonalCamera& from);
        ///Оператор присваивания
        /**
         * @param from Исходный объект
         * @return Данный объект
         */
        OrthogonalCamera& operator=(const OrthogonalCamera& from);
        ///Деструктор
        ~OrthogonalCamera();
///@}
//==========================================================
///@name Конструкторы
///@{
    OrthogonalCamera(
        const vec3& pos,
        const vec3& dir,
        const vec3& up,
        const vec3& _min,
        vec3& _max);
    OrthogonalCamera(
        float left,
        float top,
        float right,
        float bottom);
///@}
//==========================================================
///@name Методы
///@{
    virtual void build();
///@}
//==========================================================
///@name Члены
///@{
        vec3 wMin;
        vec3 wMax;
///@}
//==========================================================
    };
}
#endif
