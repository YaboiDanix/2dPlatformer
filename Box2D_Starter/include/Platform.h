//
// Created by danix on 11/19/2026.
//

#ifndef SFML_STARTER_PLATFORM_H
#define SFML_STARTER_PLATFORM_H
#include "Entity.h"


class Platform : public Entity{
    sf::Texture Rtexture;
    sf::Texture Ctexture;
    std::optional<sf::Sprite> rsprite_;
    std::optional<sf::Sprite> csprite_;
public:
    bool createC(b2Vec2 position);

    bool createR(b2Vec2 position);

    void displayR(sf::RenderWindow &window);

    void displayC(sf::RenderWindow &window);

    void UpdateR();
};


#endif //SFML_STARTER_PLATFORM_H
