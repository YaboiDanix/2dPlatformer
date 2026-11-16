//
// Created by danix on 10/29/2026.
//
#include <SFML/Graphics.hpp>
#include "print"
#include "joueur.h"
void Joueur::move() {
    if (sf::Joystick::isConnected(0)) {
        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
        if (std::abs(x) > 20.f) {
            cuphead->move({ x ,0.f});
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {

        cuphead->move({-10.f,0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {

        cuphead->move({10.f,0.f});
    }

}
void Joueur::jump() {
std::println("Jump");
}

bool Joueur::create() {
    texture.loadFromFile("../../Starter/Ressources/Cuphead_Run_03.png");

    cuphead = sf::Sprite(texture);
    if (cuphead) {
        cuphead->setTexture(texture);
    std::println("cuphead created");
        //sol.move({1,1});
        cuphead->setPosition({100.f,100.f});;
    } return true;
    std::println("cuphead not created");
    return false;
}
void Joueur::draw(sf::RenderWindow& window) {
    if (cuphead) {
        window.draw(*cuphead);
    }
}

