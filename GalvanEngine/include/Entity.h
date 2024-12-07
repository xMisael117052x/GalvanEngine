#pragma once
#include "Prerequisites.h"
#include "Component.h"

class Window;

class Entity
{
public:
    /**
     * @brief Destructor virtual necesario para la correcta eliminación de recursos en la herencia.
     */
    virtual ~Entity() = default;

    /**
     * @brief Método virtual puro para actualizar la lógica de la entidad.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief Método virtual puro para manejar el renderizado de la entidad.
     * @param window Contexto gráfico utilizado para el renderizado.
     */
    virtual void render(Window& window) = 0;

    /**
     * @brief Agrega un componente a la entidad.
     * @tparam T Tipo del componente, debe derivarse de Component.
     * @param component Puntero compartido al componente que se va a agregar.
     */
    template <typename T>
    void addComponent(EngineUtilities::TSharedPointer<T> component)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
        components.push_back(component.template dynamic_pointer_cast<Component>());
    }

    /**
     * @brief Obtiene un componente específico de la entidad.
     * @tparam T Tipo del componente que se va a buscar.
     * @return Puntero compartido al componente encontrado, o nullptr si no existe.
     */
    template <typename T>
    EngineUtilities::TSharedPointer<T> getComponent()
    {
        for (auto& component : components)
        {
            EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
            if (specificComponent)
            {
                return specificComponent;
            }
        }
        return EngineUtilities::TSharedPointer<T>();
    }

protected:
    bool isActive; ///< Estado de actividad de la entidad.
    int id; ///< Identificador único asociado a la entidad.

    std::vector<EngineUtilities::TSharedPointer<Component>> components;
    ///< Colección de componentes que pertenecen a la entidad.
};
