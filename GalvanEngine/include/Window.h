#pragma once
#include "Prerequisites.h"

class
Window {
public:
    Window() = default;
    Window(int width, int height, const std::string& title);
    ~Window();

    void
    handleEvents();

    /**
     * @brief Limpia el contenido de la ventana con el color predeterminado.
     */
    void
    clear();

    /**
     * @brief Muestra el contenido de la ventana en la pantalla.
     */
    void
    display();

    /**
     * @brief Verifica si la ventana sigue abierta.
     *
     * @return true si la ventana est? abierta, false en caso contrario.
     */
    bool
    isOpen() const;

    /**
     * @brief Dibuja un objeto que puede ser dibujado en la ventana.
     *
     * @param drawable Referencia a un objeto SFML que puede ser dibujado.
     */
    void
    draw(const sf::Drawable& drawable);

    /**
     * @brief Obtiene el objeto interno SFML RenderWindow.
     *
     * @return Un puntero al objeto interno SFML RenderWindow.
     */
    sf::RenderWindow*
     getWindow();

    /**
     * @brief Renderiza el contenido actual a una textura.
     *
     * Este método captura la escena o contenido actual y lo renderiza en una textura en lugar de en la ventana principal.
     * Puede ser útil para efectos de post-procesado o para renderizar elementos en una interfaz gráfica.
     */
    void
	renderToTexture();

    /**
     * @brief Muestra contenido en la interfaz de usuario de ImGui.
     *
     * Este método permite integrar y mostrar contenido generado por ImGui dentro de la ventana,
     * facilitando la creación de interfaces gráficas interactivas y personalizadas.
     */
    void
	showInImGui();

    // Funcion de inicializacion
    void
    init();

    // Funcion que se actualiza por frame
    void
    update();

    // Funcion de renderizado
    void
    render();

    void
    destroy();

    sf::Clock clock;
    sf::Time deltaTime;
    sf::RenderTexture m_renderTexture;
private:
    sf::RenderWindow* m_window;
    sf::View m_view;
};