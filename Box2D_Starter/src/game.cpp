//
// Created by danix on 11/16/2026.
//
#include <box2d/box2d.h>
#include <box2d/types.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../include/game.h"
#include "../include/Entity.h"
#include "../include/contacts.h"
#include "../include/constants.h"
#include <print>

#include "../include/levels.h"

void game::initialize() {
    window.create(sf::VideoMode({1600, 900}), "The physics");
    window.setFramerateLimit(60);
    def = b2DefaultWorldDef();
    def.gravity = {0.f, 20};
    monde = b2CreateWorld(&def);

}

void game::loop() {

    constexpr double kPas = 1000.f / 60.f;
    constexpr int kSousPas = 4;

    startPosition = {Convertions::ScreenToPhysics(400), Convertions::ScreenToPhysics(400)};
    if (!font.openFromFile("C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/Assets/determination.ttf")) {
        std::println("police non chargee");
    }
    timertext.emplace(font);
    timertext->setFillColor(sf::Color::White);
    timertext->setPosition({10, 10});
    //if (!music.openFromFile("C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/cysmix-fates-0ne96c.ogg")) {
    //    std::println("music non chargé");
    //}else {
     //   music.play();
    //}
    levels level(monde,window,startPosition,font);
    level.load();

timer.start();





    while (window.isOpen()) {
        dt = dtclock.restart().asMilliseconds();
        accumulateur_ += dt;
        while (accumulateur_ >= kPas) {
            b2World_Step(monde, kPas / 1000.0f, kSousPas);
            accumulateur_ -= kPas;
        }
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            }







        SensorsContact(monde);
        DangerContact(monde);



        window.clear(sf::Color::Black);


        level.tutorial(dt);



    window.draw(*timertext);
        window.display();

     }

}
