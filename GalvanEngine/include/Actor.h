#pragma once
#include "Entity.h"
#include "Prerequisites.h"

class
Actor : Entity {
public:
    /*
     * @brief Constructor por defecto.
     */
    Actor() = default;

    Actor(std::string actorName);

    /*
     * @brief Destructor por defecto.
     */
    virtual
    ~Actor() = default;

    /*
     * @brief Actualiza el actor.
     * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
     */
    void
    update(float deltaTime) override;

    /*
     * @brief Renderiza el actor.
     * @param window Contexto del dispositivo para operaciones gr�ficas.
     */
    void
    render(Window& window) override;

    /*
     * @brief Destruye el actor y libera los recursos asociados.
     */
    void
    destroy();

    /**
	* @brief Obtiene el nombre del actor.
	* @return Nombre del actor.
	*/
    std::string getName() const
    {
        return n_name;
    }

    /**
     * @brief Establece el nombre del actor.
     * @param name El nuevo nombre del actor.
     */
    void
        setName(const std::string& name)
    {
        n_name = name;
    }

    /**
	* @brief Obtiene una lista de componentes del actor.
	* @return Lista de componentes.
	*/
    const std::vector<EngineUtilities::TSharedPointer<Component>>&
        getComponents() const
    {
        return components;
    }


    /*
     * @brief Obtiene un componente especifico del actor.
     * @tparam T Tipo del componente que se va a obtener.
     * @return Puntero compartido al componente, o nullptr si no se encuentra.
     */
    template <typename T>
    EngineUtilities::TSharedPointer<T>
        getComponent();

private:
    std::string n_name = "Actor"; ///< Nombre del actor.
};

/*
 * El prop�sito de esta funci�n es buscar y devolver un componente especifico de un actor,
 * utilizando el tipo de componente especificado como argumento de la plantilla.
 * Si el componente no se encuentre, la funci�n devuelve nullptr.
 */
template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
    for (auto& component : components) {
        EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
        if (specificComponent) {
            return specificComponent;
        }
    }
    // Devuelve un TSharedPointer vac�o si no se encuentra el componente
    return EngineUtilities::TSharedPointer<T>();
}