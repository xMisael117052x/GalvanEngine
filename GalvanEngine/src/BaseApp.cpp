﻿#include "BaseApp.h"

#include "ShapeFactory.h"
#include "Transform.h"

int
BaseApp::run() {
    if (!initialize()) {
        ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
    }

    while (m_window->isOpen()) {
        m_window->handleEvents();
        //deltaTime = clock.restart();
        update();
        render();
    }

    cleanup();
    return 0;
}

bool
BaseApp::initialize() {
    m_window = new Window(800, 600, "Galvan Engine");
    if (!m_window) {
        ERROR("BaseApp", "initialize", "Error on window creation, var is null");
        return false;
    }

    Track = EngineUtilities::MakeShared<Actor>("Track");
    if (!Track.isNull()) {
        Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

        Track->getComponent<Transform>()->setPosition(sf::Vector2f(0.0f, 0.0f));
        Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Track->getComponent<Transform>()->setScale(sf::Vector2f(11.0f, 12.0f));

        // Insertar textura
        if (!texture.loadFromFile("circuit.png")) {
            return false;
        }

        Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
    }

    Circle = EngineUtilities::MakeShared<Actor>("Circle");
    if (!Circle.isNull()) {
        Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);

        Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
        Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
    }

    // Actor de Triángulo
    Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
    if (!Triangle.isNull()) {
        Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
        Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
        Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Triangle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
    }

    return true;
}

void
BaseApp::update() {
    m_window->update();

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
    sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (!Track.isNull()) {
        Track->update(m_window->deltaTime.asSeconds());
    }

    if (!Triangle.isNull()) {
        Triangle->update(m_window->deltaTime.asSeconds());
    }

    if (!Circle.isNull()) {
        Circle->update(m_window->deltaTime.asSeconds());
        updateMovement(m_window->deltaTime.asSeconds(), Circle);
    }
}

void
BaseApp::render() {
    m_window->clear();
    if (!Track.isNull()) {
        Track->render(*m_window);
    }

    if (!Circle.isNull()) {
        Circle->render(*m_window);
    }

    if (!Triangle.isNull()) {
        Triangle->render(*m_window);
    }
    ImGui::Begin("Hello, world!");
    ImGui::Text("This is a simple example.");
    //ImGui::Image(texture);
    ImGui::End();
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