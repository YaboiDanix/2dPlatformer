//
// Created by danix on 11/19/2026.
//

#ifndef SFML_STARTER_PLATFORM_H
#define SFML_STARTER_PLATFORM_H
#include "Entity.h"


class Platform {
    sf::Texture Rtexture;
    sf::Texture Ctexture;
    std::optional<sf::Sprite> rsprite_;
    std::optional<sf::Sprite> csprite_;
    sf::RectangleShape shape;
    Physical_Object physics;
    sensor grounded;
public:
    bool createC(b2Vec2 position);

    bool createR(b2Vec2 position);

    void displayR(sf::RenderWindow &window);

    void displayC(sf::RenderWindow &window);

    void UpdateR();

    void UpdateC();

    void setupBorder(b2WorldId &world, b2BodyType type, b2Vec2 position);

    void Setup(sf::Color color, sf::Vector2f size);

    void SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //SFML_STARTER_PLATFORM_H
