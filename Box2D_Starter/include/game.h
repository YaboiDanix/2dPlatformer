//
// Created by danix on 11/16/2026.
//
#include <box2d/box2d.h>
#include <box2d/types.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Entity.h"


#ifndef SFML_STARTER_GAME_H

#define SFML_STARTER_GAME_H
class game {
    public:
    void initialize();
    void loop();

    b2Vec2 startPosition;
    double dt;
    double accumulateur_ = 0.0f;


protected:
    b2WorldId monde;
    sf::RenderWindow window;
    sf::Music music;
   sf::Font font;
    std::optional<sf::Text> timertext;
private:

    b2WorldDef def;
    sf::Clock dtclock;
    sf::Clock timer;

};
#endif //SFML_STARTER_GAME_H
