//
// Created by danix on 11/4/2026.
//

#include "../include/Entity.h"

#include <print>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../include/constants.h"


void Entity::Setup(sf::Color color, sf::Vector2f size) {
    shape.setSize(size);
    shape.setFillColor(color);
    shape.setOutlineThickness(1.0f);
    shape.setOutlineColor(color);
    shape.setOrigin({size.x / 2, size.y / 2});
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape, states);
}
bool Entity::create() {
    if (!texture.loadFromFile(
            "C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/Assets/Transparent/Tilemap/tilemap.png", false,
            sf::IntRect({0, 55}, {8, 8}))) {
        std::println("Echec du chargement de la texture");
        return false;
            }

    sprite_.emplace(texture);
    sprite_->setScale({5.f, 5.f});
    sprite_->setOrigin({4.f,4.f});
    sprite_->setPosition({10.f, 10.f});
    std::println("sprite_ created");
    return true;
}
bool Entity::createEnd() {
    if (!texture.loadFromFile(
            "C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/Assets/Transparent/Tilemap/tilemap_packed.png", false,
            sf::IntRect({104, 48}, {16, 16}))) {
        std::println("Echec du chargement de la texture");
        return false;
            }

    Endsprite_.emplace(texture);
    Endsprite_->setScale({5.f, 5.f});
    Endsprite_->setOrigin({8.f,8.f});
    Endsprite_->setPosition({10.f, 10.f});
    std::println("sprite_ created");
    return true;
}
void Entity::Update() {
    //physics.Update();

    sf::Vector2f newPosition;
    newPosition.x = Convertions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Convertions::PhysicsToScreen(physics.GetPosition().y);
    shape.setPosition(newPosition);

    if (!sprite_) {

        return;
    }

    sprite_->setPosition(newPosition);

        if (grounded.HasTouched) {
            //shape.setFillColor(sf::Color::Green);
            texture.loadFromFile(
     "C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/Assets/Transparent/Tilemap/tilemap.png", false,
     sf::IntRect({9, 55}, {8, 8}));
            sprite_->setTexture(texture);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)|| x > 10.f) {

                sprite_->setScale({5.f, 5.f});

            }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)||x <-10.f){

                sprite_->setScale({-5.f, 5.f});

            }
        } else {
            //shape.setFillColor(sf::Color::Yellow);
            texture.loadFromFile(
                    "C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/Assets/Transparent/Tilemap/tilemap.png", false,
                    sf::IntRect({18, 54}, {8, 8}));
            sprite_->setTexture(texture);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)|| x > 10.f) {

                sprite_->setScale({5.f, 5.f});

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)||x <-10.f){

                sprite_->setScale({-5.f, 5.f});

            }
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



void Entity::Move(double dt) {
    float yVelocity = physics.GetVelocity().y;

    constexpr float kPeriod = 1.f/ 12.f;
    time += dt;

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


void Entity::Jump(double dt) {
    float xVelocity = physics.GetVelocity().x;
    float kCoyote = 80.f;
    float kTampon = 100.f;
    if (grounded.HasTouched) {
        coyote_ = kCoyote;
    }
    else {
        coyote_ -= dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)||sf::Joystick::isButtonPressed(0, 1)) {
        tampon_ = kTampon;
    }
    else{
        tampon_ -= dt;
    }
    if (grounded.HasTouched && tampon_ > 0.f) {
        physics.SetVelocity({xVelocity, -Y_VELOCITY});
        coyote_ = 0.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)||sf::Joystick::isButtonPressed(0, 1)) {

        if (grounded.HasTouched) {
            physics.SetVelocity({xVelocity, -Y_VELOCITY});
            coyote_ = 0.f;

        }
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)||sf::Joystick::isButtonPressed(0, 1)) && coyote_ > 0.f) {
        physics.SetVelocity({xVelocity, -Y_VELOCITY});
        coyote_ = 0.f;

    }
}

void Entity::CancelMovement() {
    float yVelocity = physics.GetVelocity().y;
    physics.SetVelocity({0, yVelocity});
}
void Entity::Respawn() {
    b2Body_SetTransform(physics.body_, spawnPoint, b2Rot_identity);
    b2Body_SetLinearVelocity(physics.body_, b2Vec2_zero);
    coyote_ = 0.f;
    tampon_ = 0.f;
}



void Entity::display(sf::RenderWindow &window) {
    if (sprite_) {
        window.draw(*sprite_);
    }
}
void Entity::Enddisplay(sf::RenderWindow &window) {
    sf::Vector2f newPosition;
    newPosition.x = Convertions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Convertions::PhysicsToScreen(physics.GetPosition().y);
    shape.setPosition(newPosition);
    Endsprite_->setPosition(newPosition);
    if (Endsprite_) {
        window.draw(*Endsprite_);
    }
}

bool Entity::End() {

    if (grounded.HasTouched) {
        return true;
    }

        return false;

}

