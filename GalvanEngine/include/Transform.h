#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

/**
 * @brief Clase que gestiona la transformaci�n de un objeto, incluyendo posici�n, rotaci�n y escala.
 */
class
Transform : public Component {
public:
    /**
     * @brief Constructor de la clase Transform.
     * Inicializa la posici�n en (0, 0), la rotaci�n en (0, 0) y la escala en (1, 1).
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
     * @brief M�todo de actualizaci�n. (Vac�o en este caso)
     * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
     */
    void
	update(float deltaTime) override { }

    /**
     * @brief M�todo de renderizado. (Vac�o en este caso)
     * @param window Ventana donde se renderizar�.
     */
    void
	render(Window window) override { }

    /**
     * @brief M�todo para destruir el objeto Transform. (Vac�o en este caso)
     */
    void
	destroy() { }

    /**
     * @brief Mueve el objeto hacia una posici�n objetivo a una velocidad espec�fica.
     * @param targetPosition Posici�n objetivo.
     * @param speed Velocidad de movimiento.
     * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
     * @param range Distancia m�nima para moverse hacia el objetivo.
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
     * @brief Establece la posici�n del objeto.
     * @param _position Nueva posici�n.
     */
    void
	setPosition(const sf::Vector2f& _position) {
        position = _position;
    }

    /**
     * @brief Establece la rotaci�n del objeto.
     * @param _rotation Nueva rotaci�n.
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
     * @brief Obtiene la posici�n del objeto.
     * @return Referencia a la posici�n.
     */
    sf::Vector2f& 
    getPosition() {
        return position;
    }

    /**
     * @brief Obtiene la rotaci�n del objeto.
     * @return Referencia a la rotaci�n.
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