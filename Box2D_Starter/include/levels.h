//
// Created by danix on 11/20/2026.
//

#ifndef SFML_STARTER_LEVELS_H
#define SFML_STARTER_LEVELS_H
#include "Entity.h"
#include "Obstacle.h"
#include "Platform.h"


    class levels {
    public:
        levels(b2WorldId& monde, sf::RenderWindow& window, b2Vec2 start,sf::Font font)
            : monde(monde), window(window), startPosition(start), font(font){}
        void load();
        bool tutorial(double dt);
        bool tutorial2(double dt);

    private:
        void addText(const std::string& str, sf::Vector2f pos);
        b2WorldId& monde;
        sf::RenderWindow& window;
        b2Vec2 startPosition;
        const sf::Font& font;
        std::vector<sf::Text> texts;

        Entity mario;
        Entity end;
        Platform leftwall;
        Platform rightwall;
        Platform ceiling;
        Obstacle Deathbox;
        Platform platform;
    };
#endif //SFML_STARTER_LEVELS_H
