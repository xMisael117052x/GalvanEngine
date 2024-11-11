#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class
ShapeFactory : public Component {
public:
    /**
     * @brief Constructor por defecto.
     */
    ShapeFactory() : m_shape(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) { }

    /**
     * @brief Destructor virtual por defecto.
     */
    virtual
        ~ShapeFactory() = default;

    /**
     * @brief Constructor que inicializa el ShapeFactory con un tipo de forma específica.
     * @param shapeType Tipo de la forma a crear.
     */
    ShapeFactory(ShapeType shapeType) :
        m_shape(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) { }

    /**
     * @brief Crea una forma del tipo especificado.
     * @param shapeType Tipo de la forma a crear.
     * @return Puntero a la forma creada.
     */
    sf::Shape* createShape(ShapeType shapeType);

    /**
     * @brief Actualiza el estado del componente. (Actualización vacía en este caso)
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void 
    update(float deltaTime) override { }

    /**
     * @brief Renderiza la forma en la ventana especificada. (Renderizado vacío en este caso)
     * @param window Ventana donde se renderizará la forma.
     */
    void
    render(Window window) override { }

    /**
     * @brief Establece la posición de la forma.
     * @param x Coordenada en el eje X.
     * @param y Coordenada en el eje Y.
     */
    void setPosition(float x, float y);

    /**
     * @brief Establece la posición de la forma.
     * @param position Vector con la posición (X, Y).
     */
    void setPosition(const sf::Vector2f& position);

    /**
     * @brief Establece el color de relleno de la forma.
     * @param color Color de relleno.
     */
    void setFillColor(const sf::Color& color);

    /**
     * @brief Establece la rotación de la forma.
     * @param angle Ángulo de rotación en grados.
     */
    void setRotation(float angle);

    /**
     * @brief Establece la escala de la forma.
     * @param scl Vector con la escala (X, Y).
     */
    void setScale(const sf::Vector2f& scl);

    /**
     * @brief Mueve la forma entre un conjunto de puntos a una velocidad específica.
     * @param points Puntos entre los que se moverá la forma.
     * @param targetIndex Índice del punto objetivo.
     * @param speed Velocidad de movimiento.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void MoveTriangle(const std::vector<sf::Vector2f>& points, int& targetIndex, float speed, float deltaTime);

    /**
     * @brief Obtiene la forma actual.
     * @return Puntero a la forma actual.
     */
    sf::Shape* getShape() {
        return m_shape;
    }

    virtual std::string getTypeName() const override {
        return "Transform";
    }
private:
    sf::Shape* m_shape; ///< Puntero a la forma creada.
    ShapeType m_shapeType; ///< Tipo de la forma actual.
};