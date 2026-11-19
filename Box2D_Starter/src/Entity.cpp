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
void Entity::Update() {
    //physics.Update();
    if (!sprite_) {

        return;
    }
    sf::Vector2f newPosition;
    newPosition.x = Convertions::PhysicsToScreen(physics.GetPosition().x);
    newPosition.y = Convertions::PhysicsToScreen(physics.GetPosition().y);


    shape.setPosition(newPosition);
    sprite_->setPosition(newPosition);

        if (grounded.HasTouched) {
            shape.setFillColor(sf::Color::Green);
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
            shape.setFillColor(sf::Color::Yellow);
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
        physics.SetVelocity({xVelocity, -16});
        coyote_ = 0.f;

    }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)||sf::Joystick::isButtonPressed(0, 1)) {

            if (grounded.HasTouched) {
                physics.SetVelocity({xVelocity, -16});
                coyote_ = 0.f;

            }

        }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)||sf::Joystick::isButtonPressed(0, 1)) && coyote_ > 0.f) {
        physics.SetVelocity({xVelocity, -16});
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
