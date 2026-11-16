//
// Created by danix on 10/29/2026.
//
#include "game.h"
#include <SFML/Graphics.hpp>
#ifndef SFML_STARTER_MOVEMENT_H
#define SFML_STARTER_MOVEMENT_H
class Joueur
{
    public:

    bool create();
    void move();
    void jump();
void draw(sf::RenderWindow& window);

protected:
    float gravity = 24.f;
    float acceleration = 10.f;
    std::optional<sf::Sprite> cuphead;
    sf::Texture texture;
};
#endif //SFML_STARTER_MOVEMENT_H
