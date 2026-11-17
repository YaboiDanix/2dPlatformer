//
// Created by danix on 11/16/2026.
//
#include <box2d/box2d.h>
#include <box2d/types.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#ifndef SFML_STARTER_GAME_H

#define SFML_STARTER_GAME_H
class game {
    public:
    void initialize();
    void loop();
    b2Vec2 startPosition;
    sf::Clock time;
    float coyote_ = 0;
    double dt;
    double accumulateur_ = 0.0f;
private:

    b2WorldDef def;
    sf::RenderWindow window;
    b2WorldId monde;
    sf::Clock dtclock;
sf::Font font;


};
#endif //SFML_STARTER_GAME_H
