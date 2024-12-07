#include "ShapeFactory.h"

/**
 * @brief Crea una forma basada en el tipo especificado.
 * @param shapeType Tipo de forma a crear.
 * @return Un puntero a la forma SFML creada o nullptr si no se puede crear.
 */
sf::Shape* ShapeFactory::createShape(ShapeType shapeType)
{
    m_shapeType = shapeType;
    switch (shapeType)
    {
    case NONE:
        {
            return nullptr;
        }
    case CIRCLE:
        {
            sf::CircleShape* circle = new sf::CircleShape(10.0f);
            circle->setFillColor(sf::Color::White);
            m_shape = circle;
            return circle;
        }
    case RECTANGLE:
        {
            sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f));
            rectangle->setFillColor(sf::Color::White);
            m_shape = rectangle;
            return rectangle;
        }
    case TRIANGLE:
        {
            sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3);
            triangle->setFillColor(sf::Color::White);
            m_shape = triangle;
            return triangle;
        }
    default:
        return nullptr;
    }
}

/**
 * @brief Establece la posición de la forma.
 * @param x Coordenada X.
 * @param y Coordenada Y.
 */
void ShapeFactory::setPosition(float x, float y)
{
    if (m_shape)
    {
        m_shape->setPosition(sf::Vector2f(x, y));
    }
}

/**
 * @brief Establece la posición de la forma usando un Vector2.
 * @param position Posición vectorial 2D.
 */
void ShapeFactory::setPosition(const Vector2& position)
{
    if (m_shape)
    {
        m_shape->setPosition(sf::Vector2f(position.x, position.y));
    }
}

/**
 * @brief Establece el color de relleno de la forma.
 * @param color Color de relleno.
 */
void ShapeFactory::setFillColor(const sf::Color& color)
{
    if (m_shape)
    {
        m_shape->setFillColor(color);
    }
}

/**
 * @brief Establece la rotación de la forma.
 * @param angle Ángulo de rotación en grados.
 */
void ShapeFactory::setRotation(float angle)
{
    if (m_shape)
    {
        m_shape->setRotation(angle);
    }
}

/**
 * @brief Escala la forma utilizando un Vector2.
 * @param scale Factor de escala.
 */
void ShapeFactory::setScale(const Vector2& scale)
{
    if (m_shape)
    {
        m_shape->setScale(sf::Vector2f(scale.x, scale.y));
    }
}
