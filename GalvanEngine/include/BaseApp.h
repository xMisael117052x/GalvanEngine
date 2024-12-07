#pragma once
#include "Prerequisites.h"

class BaseApp
{
public:
    BaseApp() = default; ///< Constructor por defecto.
    ~BaseApp(); ///< Destructor por defecto.

    /**
     * @brief Ejecuta la aplicación desde el punto de entrada principal (main).
     * @return Código de estado tras la ejecución.
     */
    int run();

    /**
     * @brief Inicializa los recursos y componentes de la aplicación.
     * @return true si la inicialización es exitosa, false en caso contrario.
     */
    bool initialize();

    /**
     * @brief Actualiza la lógica de la aplicación por cada frame.
     */
    void update();

    /**
     * @brief Maneja el renderizado de todos los elementos en pantalla.
     */
    void render();

    /**
     * @brief Libera los recursos utilizados por la aplicación.
     */
    void cleanup();

    /**
     * @brief Actualiza el movimiento del actor representado como círculo.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     * @param circle Puntero compartido al actor de tipo círculo.
     */
    void updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
    Window* m_window; ///< Puntero a la ventana principal de la aplicación.
    EngineUtilities::TSharedPointer<Actor> Triangle; ///< Puntero compartido al Actor de forma triangular.
    EngineUtilities::TSharedPointer<Actor> Circle; ///< Puntero compartido al Actor de forma circular.
    EngineUtilities::TSharedPointer<Actor> Track; ///< Puntero compartido al Actor que actúa como pista de recorrido.

    std::vector<EngineUtilities::TSharedPointer<Actor>> m_actors; ///< Lista de actores en la aplicación.
    EngineUtilities::TSharedPointer<Actor> m_selectedActor; ///< Actor actualmente seleccionado en la interfaz.

    int currentWaypoint = 0; ///< Índice actual en la lista de waypoints.

    std::vector<Vector2> waypoints = {
        {720.0f, 350.0f},
        {720.0f, 260.0f},
        {125.0f, 50.0f},
        {70.0f, 120.0f},
        {70.0f, 450.0f},
        {400.0f, 350.0f},
        {550.0f, 500.0f},
        {650.0f, 550.0f},
        {720.0f, 450.0f}
    }; ///< Lista de waypoints para el movimiento del actor.

    sf::Texture texture; ///< Textura utilizada para el fondo visual.
    sf::Texture characterTexture; ///< Textura para el modelo del personaje principal.

    GUI m_GUI; ///< Sistema de interfaz gráfica de usuario.
};
