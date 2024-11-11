#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

/**
 * @brief Clase que gestiona la transformación de un objeto, incluyendo posición, rotación y escala.
 */
class
Transform : public Component {
public:
    /**
     * @brief Constructor de la clase Transform.
     * Inicializa la posición en (0, 0), la rotación en (0, 0) y la escala en (1, 1).
     */
    Transform() : position(0.0f, 0.0f),
        rotation(0.0f, 0.0f),
        scale(1.0f, 1.0f),
        Component(ComponentType::TRANSFORM) { }

    /**
     * @brief Destructor de la clase Transform.
     * El destructor por defecto es suficiente.
     */
    virtual
	~Transform() = default;

    /**
     * @brief Método de actualización. (Vacío en este caso)
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void
	update(float deltaTime) override { }

    /**
     * @brief Método de renderizado. (Vacío en este caso)
     * @param window Ventana donde se renderizará.
     */
    void
	render(Window window) override { }

    /**
     * @brief Método para destruir el objeto Transform. (Vacío en este caso)
     */
    void
	destroy() { }

    /**
     * @brief Mueve el objeto hacia una posición objetivo a una velocidad específica.
     * @param targetPosition Posición objetivo.
     * @param speed Velocidad de movimiento.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     * @param range Distancia mínima para moverse hacia el objetivo.
     */
    void
	Seek(const sf::Vector2f& targetPosition,
        float speed,
        float deltaTime,
        float range) {
        sf::Vector2f direction = targetPosition - position;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (length > range) {
            direction /= length;
            position += direction * speed * deltaTime;
        }
    }

    /**
     * @brief Establece la posición del objeto.
     * @param _position Nueva posición.
     */
    void
	setPosition(const sf::Vector2f& _position) {
        position = _position;
    }

    /**
     * @brief Establece la rotación del objeto.
     * @param _rotation Nueva rotación.
     */
    void
	setRotation(const sf::Vector2f& _rotation) {
        rotation = _rotation;
    }

    /**
     * @brief Establece la escala del objeto.
     * @param _scale Nueva escala.
     */
    void
	setScale(const sf::Vector2f& _scale) {
        scale = _scale;
    }

    /**
     * @brief Obtiene la posición del objeto.
     * @return Referencia a la posición.
     */
    sf::Vector2f& 
    getPosition() {
        return position;
    }

    /**
     * @brief Obtiene la rotación del objeto.
     * @return Referencia a la rotación.
     */
    sf::Vector2f& 
    getRotation() {
        return rotation;
    }

    /**
     * @brief Obtiene la escala del objeto.
     * @return Referencia a la escala.
     */
    sf::Vector2f& 
    getScale() {
        return scale;
    }

    virtual std::string getTypeName() const override {
        return "Transform";
    }

private:
    sf::Vector2f position;
    sf::Vector2f rotation;
    sf::Vector2f scale;
};