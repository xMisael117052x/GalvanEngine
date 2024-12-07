#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que representa una ventana para renderizado utilizando SFML.
 */
class Window
{
public:
    /**
     * @brief Constructor por defecto.
     */
    Window() = default;

    /**
     * @brief Constructor que inicializa la ventana con las dimensiones y título especificados.
     * @param width Ancho de la ventana.
     * @param height Alto de la ventana.
     * @param title Título de la ventana.
     */
    Window(int width, int height, const std::string& title);

    /**
     * @brief Destructor que limpia los recursos de la ventana.
     */
    ~Window();

    /**
     * @brief Maneja los eventos de la ventana.
     */
    void handleEvents();

    /**
     * @brief Limpia el contenido de la ventana con el color predeterminado.
     */
    void clear();

    /**
     * @brief Muestra el contenido de la ventana en la pantalla.
     */
    void display();

    /**
     * @brief Verifica si la ventana sigue abierta.
     * @return true si la ventana está abierta, false en caso contrario.
     */
    bool isOpen() const;

    /**
     * @brief Dibuja un objeto que puede ser dibujado en la ventana.
     * @param drawable Referencia a un objeto SFML que puede ser dibujado.
     */
    void draw(const sf::Drawable& drawable);

    /**
     * @brief Obtiene el objeto interno SFML RenderWindow.
     * @return Un puntero al objeto interno SFML RenderWindow.
     */
    sf::RenderWindow* getWindow();

    /**
     * @brief Renderiza el contenido a una textura en lugar de la ventana principal.
     */
    void renderToTexture();

    /**
     * @brief Presenta el contenido en la interfaz gráfica de imgui.
     */
    void showInImGui();

    /**
     * @brief Inicializa la ventana y sus recursos.
     */
    void init();

    /**
     * @brief Actualiza la ventana por cada frame.
     */
    void update();

    /**
     * @brief Renderiza el contenido de la ventana.
     */
    void render();

    /**
     * @brief Destruye la ventana y libera los recursos.
     */
    void destroy();

    sf::Clock clock; ///< Reloj para calcular deltaTime.
    sf::Time deltaTime; ///< Almacena el tiempo transcurrido entre frames.
    sf::RenderTexture m_renderTexture; ///< Textura donde se puede renderizar contenido antes de mostrarlo.

private:
    sf::RenderWindow* m_window; ///< Puntero a la ventana de renderizado de SFML.
    sf::View m_view; ///< Vista usada para el renderizado.
};
