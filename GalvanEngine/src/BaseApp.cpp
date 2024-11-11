#include "BaseApp.h"

#include "NotificationService.h"
#include "ShapeFactory.h"
#include "Transform.h"


BaseApp::~BaseApp()
{
    NotificationService& notifier = NotificationService::getInstance();
    notifier.saveMessagesToFile("LogData.txt");
}

int
BaseApp::run() {
    NotificationService& notifier = NotificationService::getInstance();

    if (!initialize()) {
        notifier.addMessage(ConsolErrorType::ERROR, "Initializes result on a false statemente, check method validations");
        notifier.saveMessagesToFile("LogData.txt");
        ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
    }
    else {
        notifier.addMessage(ConsolErrorType::INFO, "All programs were initialized correctly");
    }

    m_GUI.init();

    while (m_window->isOpen()) {
        m_window->handleEvents();
        update();
        render();
    }

    cleanup();
    return 0;
}

bool
BaseApp::initialize() {
    NotificationService& notifier = NotificationService::getInstance();
    m_window = new Window(1920, 1080, "Galvan Engine");
    if (!m_window) {
        ERROR("BaseApp", "initialize", "Error on window creation, var is null");
        return false;
    }

    // Actor de Circuito
    Track = EngineUtilities::MakeShared<Actor>("Track");
    if (!Track.isNull()) {
        Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

        // Establecer posición, rotación y escala desde Transform
        Track->getComponent<Transform>()->setPosition(sf::Vector2f(0.0f, 0.0f));
        Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Track->getComponent<Transform>()->setScale(sf::Vector2f(11.0f, 12.0f));

        // Insertar textura
        if (!texture.loadFromFile("circuit.png")) {
            std::cout << "Error de carga de textura" << std::endl;
            return -1; // Manejar error de carga
        }

        Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
    }
    m_actors.push_back(Track);

    // Actor de Círculo
    Circle = EngineUtilities::MakeShared<Actor>("Circle");
    if (!Circle.isNull()) {
        Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
        //Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

        // Establecer posición, rotación y escala desde Transform
        Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
        Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));

        // Insertar textura
        if (!characterTexture.loadFromFile("Characters/tile005.png")) {
            std::cout << "Error de carga de textura" << std::endl;
            return -1; // Manejar error de carga
        }

        Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&characterTexture);
    }
    m_actors.push_back(Circle);


    // Actor de Triángulo
    Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
    if (!Triangle.isNull()) {
        Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
        Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
        Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Triangle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
    }
    m_actors.push_back(Triangle);


    return true;
}

void
BaseApp::update() {
    m_window->update();

    // Posición del ratón
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
    sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    // Actualizar los actores
    for (auto& actor : m_actors) {
        if (!actor.isNull()) {
            actor->update(m_window->deltaTime.asSeconds());
            if (actor->getName() == "Circle") {
                updateMovement(m_window->deltaTime.asSeconds(), actor);
            }
        }
    }
}

void
BaseApp::render() {
    NotificationService& notifier = NotificationService::getInstance();
    m_window->clear();

    // Update the actors
    for (auto& actor : m_actors) {
        if (!actor.isNull()) {
            actor->render(*m_window);
        }
    }

    // Mostrar el render en ImGui
    m_window->renderToTexture();
    m_window->showInImGui();
    m_GUI.console(notifier.getNotifications());
    m_GUI.jerarquia(m_actors);
    m_GUI.placeActors(m_actors);
    m_GUI.inspector(m_actors);
    m_window->render();
    m_window->display();
}

void
BaseApp::cleanup() {
    m_window->destroy();
    delete m_window;
}

void
BaseApp::updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
    // Verificar si el Circle es nulo
    if (!circle || circle.isNull()) {
        return;
    }

    // Obtener el componente Transform
    auto transform = circle->getComponent<Transform>();
    if (transform.isNull()) {
        return;
    }

    // Posición actual del destino (punto de recorrido)
    sf::Vector2f targetPos = waypoints[currentWaypoint];

    // Llamar al Seek del Transform
    transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

    // Obtener la posición actual del actor desde Transform
    sf::Vector2f currentPos = transform->getPosition();

    // Comprobar si el actor ha alcanzado el destino (o está cerca)
    float distanceToTarget = std::sqrt(
        std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

    if (distanceToTarget < 10.0f) {
        // Umbral para considerar que ha llegado
        currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a través de los puntos
    }
}