//
// Created by danix on 11/14/2026.
//

#include "../include/Obstacle.h"
#include "../include/constants.h"
#include <SFML/Graphics/RenderTarget.hpp>

#include "../include/Entity.h"

void Obstacle::Setup(sf::Color, sf::Vector2f size) {
    shape.setSize(size);
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineThickness(1.0f);
    shape.setOutlineColor(sf::Color::White);
    shape.setOrigin({size.x / 2, size.y / 2});
}

void Obstacle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Obstacle::Update(Entity& entity) {
    //physics.Update();
    sf::Vector2f newPosition;
    newPosition.x = Convertions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Convertions::PhysicsToScreen(physics.GetPosition().y);


    shape.setPosition(newPosition);
    if (danger_.HasHit) {
        entity.Respawn();
        danger_.HasHit = false;
    } else{
        shape.setFillColor(sf::Color::Red);
    }
}

void Obstacle::SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position) {
    b2Vec2 halfSize = {
        Convertions::ScreenToPhysics(shape.getSize().x / 2), Convertions::ScreenToPhysics(shape.getSize().y / 2)
    };

    physics.Setup(
        world,
        type,
        position,
        halfSize);

    danger_.Setup(
        physics.GetBodyId(),
        halfSize);
}