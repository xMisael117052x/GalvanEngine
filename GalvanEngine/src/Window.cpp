#include "Window.h"

Window::Window(int width, int height, const std::string& title) {
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

    if (!m_window) {
        ERROR("Window", "Window", "CHECK CONSTRUCTOR");
    }
    else {
        MESSAGE("Window", "Window", "OK");
    }

    ImGui::SFML::Init(*m_window);
}

Window::~Window() {
    ImGui::SFML::Shutdown();
    delete m_window;
}

void
Window::handleEvents() {
    sf::Event event;
    while (m_window->pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);

        switch (event.type) {
        case sf::Event::Closed:
            m_window->close();
            break;
        case sf::Event::Resized:
            // Manejar el evento de redimensionar
            // Obtener el nuevo tamaño de la ventana
            unsigned int newWidth = event.size.width;
            unsigned int newHeight = event.size.height;

            // Opcional: Redefinir el tamaño de la vista para ajustarse al nuevo tamaño de la ventana
            sf::View view = m_window->getView();
            view.setSize(static_cast<float>(newWidth), static_cast<float>(newHeight));
            m_window->setView(view);
            break;
        }
    }
}

void
Window::clear() {
    if (m_window != nullptr) {
        m_window->clear();
    }
    else {
        ERROR("Window", "clear", "CHECK FOR WINDOW POINTER DATA");
    }
}

void
Window::display() {
    if (m_window != nullptr) {
        m_window->display();
    }
    else {
        ERROR("Window", "display", "CHECK FOR WINDOW POINTER DATA");
    }
}

bool
Window::isOpen() const {
    if (m_window != nullptr) {
        return m_window->isOpen();
    }
    else {
        ERROR("Window", "isOpen", "CHECK FOR WINDOW POINTER DATA");
        return false;
    }
}

void
Window::draw(const sf::Drawable& drawable) {
    if (m_window != nullptr) {
        m_window->draw(drawable);
    }
    else {
        ERROR("Window", "draw", "CHECK FOR WINDOW POINTER DATA");
    }
}

sf::RenderWindow*
Window::getWindow() {
    if (m_window != nullptr) {
        return m_window;
    }
    else {
        ERROR("Window", "getWindow", "CHECK FOR WINDOW POINTER DATA");
        return nullptr;
    }
}

void
Window::update() {
    // Almacena el deltaTime una sola vez
    deltaTime = clock.restart();
    // Usa ese deltaTime para actualizar ImGui
    ImGui::SFML::Update(*m_window, deltaTime);
}

void
Window::render() {
    ImGui::SFML::Render(*m_window);
}

void
Window::destroy() {
    SAFE_PTR_RELEASE(m_window);
}
