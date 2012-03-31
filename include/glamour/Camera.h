//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * Определение класса Camera
 * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
 * @version 0.1
 * @date 11.09.2006
 */
#ifndef GLA_Camera_h
#define GLA_Camera_h

#include "Vector3d.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
namespace Glamour
{
    /// Камера
    /**
     * Базовый класс "Камера". Выполняет операции, связанные с ориентацией камеры. Операции проецирования
	 * должны быть реализованы в наследниках (см. PerspectiveCamera).
     * @author <a href="mailto:LeonidShevtsov@gmail.com">Леонид Шевцов</a>
     * @todo fix the quaternion issues - dont need rot OR uvn anymore
     * @version 0.1
     * @date 11.09.2006
     */
    class Camera
    {
    public:
//==========================================================
///@name Необходимые операции
///@{
        ///Конструктор по умолчанию
        Camera();
        ///Конструктор копирования
        /**
         * @param from Исходный объект
         */
        Camera(const Camera& from);
        ///Оператор присваивания
        /**
         * @param from Исходный объект
         * @return Данный объект
         */
        Camera& operator=(const Camera& from);
        ///Деструктор
        virtual ~Camera();
///@}
//==========================================================
///@name Конструкторы
///@{
	///Cоздает камеру с заданными параметрами
	/**
	 * @
	 */
    Camera(const vec3& _pos,const vec3& _dir,const vec3& _up);
///@}
//==========================================================
///@name Свойства
///@{
///@}
//==========================================================
///@name Методы
///@{
    virtual void build()=0;
    virtual void buildView();
    void apply();
    void resetView();
///@}
//==========================================================
///@name Фабрики
///@{
///@}
//==========================================================
///@name Члены
///@{
    protected:
    public:
        vec3 p;
        vec3 u;//up (y)
        vec3 v;//right (x)
        vec3 n;//forward (z)
        quat rot;
        mat4 projection;
        mat4 modelview;
///@}
//==========================================================
    };
}
#endif
