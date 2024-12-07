#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que representa un componente de transformación aplicado a objetos en un espacio 2D.
 *        Hereda de la clase base 'Component'.
 */
class Transform : public Component
{
public:
    /**
     * @brief Constructor por defecto.
     */
    Transform() : position(0.0f, 0.0f),
                  rotation(0.0f, 0.0f),
                  scale(1.0f, 1.0f),
                  Component(ComponentType::TRANSFORM)
    {
    }

    /**
     * @brief Destructor virtual.
     */
    virtual ~Transform() = default;

    /**
     * @brief Actualiza el componente.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void update(float deltaTime) override
    {
        // Lógica de actualización
    }

    /**
     * @brief Renderiza el componente.
     * @param window Contexto de la ventana para operaciones gráficas.
     */
    void render(Window window) override
    {
        // Lógica de renderizado
    }

    /**
     * @brief Destruye el componente.
     */
    void destroy()
    {
        // Lógica de destrucción
    }

    /**
     * @brief Actualiza la posición del objeto buscando un objetivo.
     * @param targetPosition Posición objetivo.
     * @param speed Velocidad de movimiento.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     * @param range Rango dentro del cual buscar el objetivo.
     */
    void Seek(const Vector2& targetPosition, float speed, float deltaTime, float range)
    {
        Vector2 direction = targetPosition - position;
        float length = direction.magnitude();

        if (length > range)
        {
            direction.normalize(); // Normaliza el vector
            position += direction * speed * deltaTime;
        }
    }

    /**
     * @brief Establece las transformaciones del objeto.
     * @param _position Nueva posición.
     * @param _rotation Nueva rotación.
     * @param _scale Nueva escala.
     */
    void setTransform(const Vector2& _position, const Vector2& _rotation, const Vector2& _scale)
    {
        position = _position;
        rotation = _rotation;
        scale = _scale;
    }

    /**
     * @brief Establece la posición del objeto.
     * @param _position Nueva posición.
     */
    void setPosition(const Vector2& _position)
    {
        position = _position;
    }

    /**
     * @brief Establece la rotación del objeto.
     * @param _rotation Nueva rotación.
     */
    void setRotation(const Vector2& _rotation)
    {
        rotation = _rotation;
    }

    /**
     * @brief Establece la escala del objeto.
     * @param _scale Nueva escala.
     */
    void setScale(const Vector2& _scale)
    {
        scale = _scale;
    }

    /**
     * @brief Obtiene la posición del objeto.
     * @return Referencia a la posición del objeto.
     */
    Vector2& getPosition()
    {
        return position;
    }

    /**
     * @brief Obtiene la rotación del objeto.
     * @return Referencia a la rotación del objeto.
     */
    Vector2& getRotation()
    {
        return rotation;
    }

    /**
     * @brief Obtiene la escala del objeto.
     * @return Referencia a la escala del objeto.
     */
    Vector2& getScale()
    {
        return scale;
    }

    /**
     * @brief Obtiene un puntero a los datos de posición en memoria.
     * @return Puntero a la posición en la memoria.
     */
    float* getPosData()
    {
        return &position.x;
    }

    /**
     * @brief Obtiene un puntero a los datos de rotación en memoria.
     * @return Puntero a la rotación en la memoria.
     */
    float* getRotData()
    {
        return &rotation.x;
    }

    /**
     * @brief Obtiene un puntero a los datos de escala en memoria.
     * @return Puntero a la escala en la memoria.
     */
    float* getScaData()
    {
        return &scale.x;
    }

private:
    Vector2 position; ///< Posición del objeto.
    Vector2 rotation; ///< Rotación del objeto.
    Vector2 scale; ///< Escala del objeto.
};
