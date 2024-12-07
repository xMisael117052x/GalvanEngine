#pragma once
#include "Prerequisites.h"

class ShapeFactory : public Component
{
public:
    /**
     * @brief Constructor por defecto de la fábrica de formas.
     */
    ShapeFactory() = default;

    /**
     * @brief Destructor virtual para la correcta eliminación de recursos.
     */
    virtual ~ShapeFactory() = default;

    /**
     * @brief Constructor que inicializa el tipo de forma a crear.
     * @param shapeType Tipo de la forma a crear.
     */
    ShapeFactory(ShapeType shapeType) :
        m_shape(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE)
    {
    }

    /**
     * @brief Crea una forma del tipo especificado.
     * @param shapeType Tipo de la forma a crear.
     * @return Puntero a la forma creada.
     */
    sf::Shape* createShape(ShapeType shapeType);

    /**
     * @brief Actualiza el estado del componente de malla.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void update(float deltaTime) override
    {
    }

    /**
     * @brief Renderiza el componente de malla en la ventana proporcionada.
     * @param window Contexto de la ventana para operaciones gráficas.
     */
    void render(Window window) override
    {
    }

    /**
     * @brief Establece la posición de la forma usando coordenadas individuales.
     * @param x Coordenada X.
     * @param y Coordenada Y.
     */
    void setPosition(float x, float y);

    /**
     * @brief Establece la posición de la forma usando un vector personalizado.
     * @param position Vector2 que contiene la nueva posición.
     */
    void setPosition(const Vector2& position);

    /**
     * @brief Asigna un color de relleno a la forma.
     * @param color Color de relleno.
     */
    void setFillColor(const sf::Color& color);

    /**
     * @brief Establece la rotación de la forma.
     * @param angle Ángulo de rotación en grados.
     */
    void setRotation(float angle);

    /**
     * @brief Define la escala de la forma usando un vector personalizado.
     * @param scl Vector2 que representa la nueva escala.
     */
    void setScale(const Vector2& scl);

    /**
     * @brief Mueve el triángulo a través de una serie de puntos especificados.
     * @param points Vector de posiciones objetivo.
     * @param targetIndex Índice del punto objetivo actual.
     * @param speed Velocidad del movimiento.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void MoveTriangle(const std::vector<Vector2>& points, int& targetIndex, float speed, float deltaTime);

    /**
     * @brief Obtiene la forma actual.
     * @return Puntero a la forma actualmente gestionada.
     */
    sf::Shape* getShape()
    {
        return m_shape;
    }

private:
    sf::Shape* m_shape; ///< Puntero a la forma gestionada.
    ShapeType m_shapeType; ///< Tipo de la forma gestionada.
};
