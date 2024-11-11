#pragma once
#include <map>

#include "Prerequisites.h"

class
    Actor;

class
    Window;

class
    GUI {
public:
    /**
     * @brief Constructor por defecto.
     */
    GUI() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~GUI() = default;

    /**
     * @brief Inicializa la ventana.
     */
    void
        init();

    /**
     * @brief Actualiza la ventana.
     */
    void
        update();

    /**
     * @brief Renderiza el contenido.
     */
    void
        render();

    /**
    * @brief Destruye la ventana.
    */
    void
        destroy();

    /**
    * @brief Declara los estilos de la ventana.
    */
    void
        setupGUIStyle();

    /**
     * @brief Muestra el outliner con la lista de actores.
     * @param actors Vector de actores a listar.
     */
    void
        jerarquia(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

    /**
    * @brief Muestra una consola con mensajes del programa.
    * @param programMessages Mapa de mensajes del programa categorizados por tipo de error.
    */
    void
        console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages);

    /**
     * @brief Permite colocar actores en la escena.
     * @param actors Vector de actores en la escena.
     */
    void
        placeActors(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

    /**
    * @brief Muestra el inspector del actor seleccionado con sus componentes.
    * @param actors Vector de actores a inspeccionar.
    */
    void
        inspector(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

private:
    EngineUtilities::TSharedPointer<Actor> m_actors;
};