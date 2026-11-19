//
// Created by danix on 11/4/2026.
//

#ifndef SFML_STARTER_ENTITY_H
#define SFML_STARTER_ENTITY_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "danger.h"
#include "game.h"
#include "object.h"
#include "sensor.h"


class Entity : public sf::Drawable, public game {
    static constexpr float X_VELOCITY = 16.f;

    sf::Texture texture;
    std::optional<sf::Sprite> sprite_;
    float time = 0.f;
    Danger danger_;
    float tampon_ = 60.f;
    b2Vec2 spawnPoint;   // en unités Box2D (mètres)
    float x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);

public:
    Physical_Object physics;

    sf::RectangleShape shape;

    sensor grounded;

    void SetSpawnPoint(b2Vec2 spawn) { spawnPoint = spawn; }

    void Respawn();

    void Setup(sf::Color color, sf::Vector2f size);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void Update();

    void SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position);

    void Move(double dt);

    void CancelMovement();

    void Jump(double dt);

    bool create();

    void display(sf::RenderWindow &window);

};


#endif //SFML_STARTER_ENTITY_H
