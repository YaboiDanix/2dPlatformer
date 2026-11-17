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
    sf::RectangleShape shape;
    sf::Texture texture;
    Physical_Object physics;
    sensor grounded;
    Danger danger_;
    float tampon_ = 60.f;
    b2Vec2 spawnPoint = {0,0};   // en unités Box2D (mètres)

public:
    void SetSpawnPoint(b2Vec2 spawn) { spawnPoint = spawn; }

    void Respawn();

    void Setup(sf::Color color, sf::Vector2f size);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void Update();

    void SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position);

   // void MoveLeft();

    //void MoveRight();
void Move();
    void CancelMovement();

    void Jump(double dt);

};


#endif //SFML_STARTER_ENTITY_H
