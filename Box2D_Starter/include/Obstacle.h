//
// Created by danix on 11/14/2026.
//

#ifndef SFML_STARTER_OBSTACLE_H
#define SFML_STARTER_OBSTACLE_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "danger.h"
#include "Entity.h"
#include "object.h"


class Obstacle : public sf::Drawable, public game{
    sf::RectangleShape shape;
    sf::Texture textureS;
    sf::Texture textureE;
    Physical_Object physics;
    Danger danger_;
    std::optional<sf::Sprite> spriteS;
    std::optional<sf::Sprite> spriteE;


public:
    void Setup(sf::Color color, sf::Vector2f size);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void Update(Entity& entity);

    void SetupPhysics(b2WorldId &world, b2BodyType type, b2Vec2 position);

    bool CreateS();
    bool CreateE();

    void DisplayS(sf::RenderWindow &window);
    void DisplayE(sf::RenderWindow &window);
};



#endif //SFML_STARTER_OBSTACLE_H
