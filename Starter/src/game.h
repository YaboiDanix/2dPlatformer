//
// Created by danix on 10/22/2026.
//

#ifndef SFML_STARTER_GAME_H
#define SFML_STARTER_GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Joueur.h"


class Game {

    sf::RenderWindow window;
Joueur joueur;

public :

    void Initialize();
    void Loop();




};
#endif //SFML_STARTER_GAME_H
