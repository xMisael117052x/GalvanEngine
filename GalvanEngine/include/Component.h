#pragma once
class Window;

/**
 * @enum ComponentType
 * @brief Clasificación de los tipos de componentes disponibles en el juego.
 */
enum ComponentType
{
    NONE = 0, ///< Sin tipo definido.
    TRANSFORM = 1, ///< Componente de transformación.
    SPRITE = 2, ///< Componente de sprite.
    RENDERER = 3, ///< Componente de renderizado.
    PHYSICS = 4, ///< Componente de física.
    AUDIOSOURCE = 5, ///< Componente de audio.
    SHAPE = 6, ///< Componente de forma.
    TEXTURE = 7 ///< Componente de textura.
};

class Component
{
public:
    /**
     * @brief Constructor por defecto de Component.
     */
    Component() = default;

    /**
     * @brief Constructor que inicializa un componente con un tipo específico.
     * @param type Tipo del componente a inicializar.
     */
    Component(const ComponentType type) : m_type(type)
    {
    }

    /**
     * @brief Destructor virtual, necesario para permitir la eliminación limpia de herencias.
     */
    virtual ~Component() = default;

    /**
     * @brief Método virtual puro que actualiza el estado del componente.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief Método virtual puro que maneja el renderizado del componente.
     * @param window Objeto Window que representa el contexto gráfico.
     */
    virtual void render(Window window) = 0;

    /**
     * @brief Devuelve el tipo del componente.
     * @return Tipo de componente almacenado.
     */
    ComponentType getType() const { return m_type; }

protected:
    ComponentType m_type; ///< Tipo de Componente actual.
};
