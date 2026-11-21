//
// Created by danix on 11/19/2026.
//
#include <print>
#include "../include/Platform.h"
#include "../include/constants.h"

bool Platform::createR(b2Vec2 position) {
    if (!Rtexture.loadFromFile(
            "C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/Assets/Transparent/Tilemap/tilemap_packed.png", false,
            sf::IntRect({24, 24}, {24, 8}))) {
        std::println("Echec du chargement de la texture");
        return false;
            }

    rsprite_.emplace(Rtexture);
    rsprite_->setScale({shape.getSize().x/24, shape.getSize().y/8});
    rsprite_->setOrigin({12.f, 4.f});
    rsprite_->setPosition({position.x, position.y});
    std::println("sprite_ created");
    return true;
}

void Platform::displayR(sf::RenderWindow &window) {
    if (rsprite_) {
        window.draw(*rsprite_);
    }
}

void Platform::UpdateR() {
    if (!rsprite_) {

        return;
    }
    sf::Vector2f newPosition;
    newPosition.x = Convertions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Convertions::PhysicsToScreen(physics.GetPosition().y);


    shape.setPosition(newPosition);
    rsprite_->setPosition(newPosition);

    if (grounded.HasTouched) {
        shape.setFillColor(sf::Color::Green);
    }else {
        shape.setFillColor(sf::Color::Yellow);
    }
}

void Platform::setupBorder(b2WorldId &world, b2BodyType type, b2Vec2 position) {
    b2Vec2 halfSize = {
        Convertions::ScreenToPhysics(shape.getSize().x / 2), Convertions::ScreenToPhysics(shape.getSize().y / 2)
    };

    physics.Setup(
        world,
        type,
        position,
        halfSize);
}
void Platform::UpdateC() {
    if (!csprite_) {

        return;
    }
    sf::Vector2f newPosition;
    newPosition.x = Convertions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Convertions::PhysicsToScreen(physics.GetPosition().y);


    shape.setPosition(newPosition);
    csprite_->setPosition(newPosition);

    if (grounded.HasTouched) {
        shape.setFillColor(sf::Color::Green);
    }else {
        shape.setFillColor(sf::Color::Yellow);
    }
}
void Platform::displayC(sf::RenderWindow &window) {
    if (csprite_) {
        window.draw(*csprite_);
    }
}
bool Platform::createC(b2Vec2 position) {
    if (!Ctexture.loadFromFile(
            "C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/Assets/Transparent/Tilemap/tilemap_packed.png", false,
            sf::IntRect({24, 32}, {16, 16}))) {
        std::println("Echec du chargement de la texture");
        return false;
            }

    csprite_.emplace(Ctexture);
    csprite_->setScale({shape.getSize().x/16, shape.getSize().y/16});
    csprite_->setOrigin({8.f, 8.f});
    csprite_->setPosition({position.x, position.y});
    std::println("sprite_ created");
    return true;
}
void Platform::SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position) {
    b2Vec2 halfSize = {
        Convertions::ScreenToPhysics(shape.getSize().x / 2), Convertions::ScreenToPhysics(shape.getSize().y / 2)
    };

    physics.Setup(
        world,
        type,
        position,
        halfSize);

    grounded.Setup(
        physics.GetBodyId(),
        halfSize);
}
void Platform::Setup(sf::Color color, sf::Vector2f size) {
    shape.setSize(size);
    shape.setFillColor(color);
    shape.setOutlineThickness(1.0f);
    shape.setOutlineColor(color);
    shape.setOrigin({size.x / 2, size.y / 2});
}
void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape, states);
}