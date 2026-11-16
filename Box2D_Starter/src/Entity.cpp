//
// Created by danix on 11/4/2026.
//

#include "../include/Entity.h"

#include <print>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../include/constants.h"


void Entity::Setup(sf::Color, sf::Vector2f size) {
    shape.setSize(size);
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineThickness(1.0f);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOrigin({size.x / 2, size.y / 2});
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Entity::Update() {
    //physics.Update();
    sf::Vector2f newPosition;
    newPosition.x = Convertions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Convertions::PhysicsToScreen(physics.GetPosition().y);


    shape.setPosition(newPosition);
    if (grounded.HasTouched) {
        shape.setFillColor(sf::Color::Green);
    } else{
        shape.setFillColor(sf::Color::Yellow);
    }
}

void Entity::SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position) {
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


//void Entity::MoveLeft() {
  //  std::println("Move Left");
    //float yVelocity = physics.GetVelocity().y;
    //
//}

//void Entity::MoveRight() {

  //  std::println("Move Right");
    //
//}
void Entity::Move() {
    float yVelocity = physics.GetVelocity().y;
    float x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)||x <-10.f) {
        physics.SetVelocity({-X_VELOCITY, yVelocity});
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)|| x > 10.f) {
        physics.SetVelocity({X_VELOCITY, yVelocity});
    }
    else{
        physics.SetVelocity({0, yVelocity});
    }
}


void Entity::Jump() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)||sf::Joystick::isButtonPressed(0, 1)) {
        if (grounded.HasTouched) {
            float xVelocity = physics.GetVelocity().x;
            physics.SetVelocity({xVelocity, -16});
        }
    }
}

void Entity::CancelMovement() {
    float yVelocity = physics.GetVelocity().y;
    physics.SetVelocity({0, yVelocity});
}
void Entity::Respawn() {
    b2Body_SetTransform(physics.body_, spawnPoint, b2Rot_identity);
    b2Body_SetLinearVelocity(physics.body_, b2Vec2_zero);
}