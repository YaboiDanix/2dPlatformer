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
