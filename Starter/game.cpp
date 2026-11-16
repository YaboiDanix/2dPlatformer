//
// Created by danix on 10/22/2026.
//
#include "print"
#include "src/game.h"
#include "src/Joueur.h"
void Game::Initialize() {

    window.create(sf::VideoMode({1620, 1000}), "The Game");
    window.setFramerateLimit(60);
    //sf::RectangleShape sol({100.f, 100.f});
    //sol.setFillColor(sf::Color(255, 0, 0));
    //sol.setPosition({window.getSize().x / 2.f, window.getSize().y /2.f});
    //sol.setOrigin({sol.getSize().x / 2.f, sol.getSize().y / 2.f});sf::Texture texture("../../Starter/Ressources/Cuphead_Run_03.png");
    joueur.create();

}
void Game::Loop() {
    sf::Clock horloge;
    while (window.isOpen()) {
    const float dt = horloge.restart().asSeconds();


        joueur.move();
        while (const std::optional event = window.pollEvent())
        {

            if (const auto* key = event->getIf<sf::Event::KeyPressed>())
                if (key->scancode == sf::Keyboard::Scancode::Space)
                    joueur.jump();

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }


        window.clear();
        joueur.draw(window);

        window.display();

    }
}