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
#include "../include/Obstacle.h"
#include "../include/contacts.h"
#include "../include/constants.h"
#include <print>

void game::initialize() {
    window.create(sf::VideoMode({1600, 1000}), "The physics");
    window.setFramerateLimit(120);
    def = b2DefaultWorldDef();
    def.gravity = {0.f, 9.81f};
    monde = b2CreateWorld(&def);
}

void game::loop() {
    constexpr double kPas = 1000.f / 60.f;
    constexpr int kSousPas = 4;
    double accumulateur_ = 0.0f;
    double dt;
    startPosition = {Convertions::ScreenToPhysics(400), Convertions::ScreenToPhysics(400)};
    font.openFromFile( "C:/Users/danix/projets_c++/SFML_Starter/Box2D_Starter/include/determination.ttf");




    Entity platform;
    platform.Setup(sf::Color::Red, {1000, 30});
    platform.SetupPhysics(monde, b2_staticBody, {10, 45});
    Entity mario;

    mario.Setup(sf::Color::Green, {40, 40});
    mario.SetupPhysics(monde, b2_dynamicBody, startPosition);
    mario.SetSpawnPoint(startPosition);
    Obstacle spike;
    spike.Setup(sf::Color::Red,{80,100});
    spike.SetupPhysics(monde, b2_staticBody, {30,35});
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            mario.Move();
            mario.Jump();
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            }

        dt = dtclock.restart().asMilliseconds();
        accumulateur_ += dt;
        //if () coyote_ = kCoyote;        // kCoyote ≈ 0,08 s
        //else         coyote_ -= dt;
        while (accumulateur_ >= kPas) {
            b2World_Step(monde, kPas / 1000.0f, kSousPas);
            accumulateur_ -= kPas;
        }



        mario.Update();

        SensorsContact(monde);
        DangerContact(monde);

        platform.Update();
        spike.Update(mario);
        time.start();
        float t = time.getElapsedTime().asSeconds();
        sf::String timer = std::format("{:.2f}",t);
        sf::Text text(font);
        text.setString(timer);
        text.setFillColor(sf::Color::White);
        text.setPosition({10,10});
        window.clear(sf::Color::Black);
        window.draw(mario);
        window.draw(platform);
        window.draw(spike);
        window.draw(text);
        window.display();

     }

}
