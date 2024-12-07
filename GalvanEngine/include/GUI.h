#pragma once
#include "Prerequisites.h"

class Actor;
class Window;

class GUI
{
public:
    /**
     * @brief Constructor por defecto del sistema de interfaz gráfica de usuario.
     */
    GUI() = default;

    /**
     * @brief Destructor por defecto del sistema de interfaz gráfica de usuario.
     */
    ~GUI() = default;

    /**
     * @brief Inicializa los elementos y recursos necesarios para la interfaz.
     */
    void init();

    /**
     * @brief Actualiza el estado y comportamiento de la interfaz.
     */
    void update();

    /**
     * @brief Renderiza todos los elementos visuales de la interfaz.
     */
    void render();

    /**
     * @brief Libera los recursos y destruye los elementos de la interfaz.
     */
    void destroy();

    /**
     * @brief Configura los estilos visuales de la interfaz gráfica.
     */
    void setupGUIStyle();

    /**
     * @brief Despliega una jerarquía con la lista de actores presentes.
     * @param actors Vector que contiene los actores a incluir en la lista.
     */
    void jerarquia(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

    /**
     * @brief Muestra una consola con mensajes agrupados por tipo de error.
     * @param programMessages Mapa que contiene los mensajes de error categorizados.
     */
    void console(const std::map<ConsoleErrorType, std::vector<std::string>>& programMessages);

    /**
     * @brief Posiciona actores dentro de la escena interactiva.
     * @param actors Vector de actores actualmente presentes en la escena.
     */
    void placeActors(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

    /**
     * @brief Muestra detalles del actor seleccionado y sus componentes en el inspector.
     * @param actors Vector que contiene los actores a ser inspeccionados.
     */
    void inspector(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

private:
    EngineUtilities::TSharedPointer<Actor> m_actors; ///< Puntero al actor o conjunto de actores manejados.
    int selectedActorIndex = -1;
};
