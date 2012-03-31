//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * Определение класса PerspectiveCamera
 * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
 * @version 0.1
 * @date 11.09.2006
 */
#ifndef GLA_PerspectiveCamera_h
#define GLA_PerspectiveCamera_h

#include "Camera.h"
namespace Glamour
{
    /// Перспективная камера
    /**
     * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
     * @version 0.1
     * @date 11.09.2006
     */
    class PerspectiveCamera: public Camera
    {
    public:
//==========================================================
///@name Необходимые операции
///@{
        ///Конструктор по умолчанию
        PerspectiveCamera();
        ///Конструктор копирования
        /**
         * @param from Исходный объект
         */
        PerspectiveCamera(const PerspectiveCamera& from);
        ///Оператор присваивания
        /**
         * @param from Исходный объект
         * @return Данный объект
         */
        PerspectiveCamera& operator=(const PerspectiveCamera& from);
        ///Деструктор
        ~PerspectiveCamera();
///@}
//==========================================================
///@name Конструкторы
///@{
    PerspectiveCamera(
        const vec3& pos,
        const vec3& dir,
        const vec3& up,
        float _theta,
        float _aspect,
        float _zNear,
        float _zFar);
///@}
//==========================================================
///@name Методы
///@{
    virtual void build();
///@}
//==========================================================
///@name Члены
///@{
        float theta;
        float aspect;
        float zNear;
        float zFar;
    protected:
    private:
///@}
//==========================================================
    };
}
#endif
