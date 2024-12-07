#pragma once
#include "Prerequisites.h"

class Actor : Entity
{
public:
    /**
     * @brief Constructor por defecto.
     */
    Actor() = default;

    /**
     * @brief Constructor que inicializa un actor con un nombre específico.
     * @param actorName Nombre del actor.
     */
    Actor(std::string actorName);

    /**
     * @brief Destructor virtual por defecto, utilizado para liberar recursos.
     */
    virtual ~Actor() = default;

    /**
     * @brief Actualiza el estado del actor.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void update(float deltaTime) override;

    /**
     * @brief Renderiza el actor en la ventana proporcionada.
     * @param window Ventana donde se realiza el renderizado.
     */
    void render(Window& window) override;

    /**
     * @brief Libera los recursos y destruye el actor.
     */
    void destroy();

    /**
     * @brief Obtiene el nombre asignado al actor.
     * @return Una cadena con el nombre del actor.
     */
    std::string getName() const
    {
        return m_name;
    }

    /**
     * @brief Define un nuevo nombre para el actor.
     * @param name El nombre que se asignará al actor.
     */
    void setName(const std::string& name)
    {
        m_name = name;
    }

    /**
     * @brief Proporciona una lista de componentes asociados al actor.
     * @return Vector con los componentes del actor.
     */
    const std::vector<EngineUtilities::TSharedPointer<Component>>& getComponents() const
    {
        return components;
    }

    /**
     * @brief Busca y devuelve un componente específico del actor.
     * @tparam T Tipo del componente a buscar.
     * @return Puntero compartido al componente buscado, o nullptr si no se encuentra.
     */
    template <typename T>
    EngineUtilities::TSharedPointer<T> getComponent();

private:
    std::string m_name = "Actor"; ///< Nombre del actor.

    std::vector<EngineUtilities::TSharedPointer<Component>> components; ///< Componentes del actor.
};

/*
 * @brief Función que busca y devuelve un componente específico del actor.
 * Utiliza el tipo especificado en el argumento de plantilla para encontrar el componente.
 * Devuelve nullptr si el componente no se encuentra.
 */
template <typename T>
inline EngineUtilities::TSharedPointer<T> Actor::getComponent()
{
    for (auto& component : components)
    {
        EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
        if (specificComponent)
        {
            return specificComponent;
        }
    }
    // Devuelve un TSharedPointer vacío si no se encuentra el componente
    return EngineUtilities::TSharedPointer<T>();
}
