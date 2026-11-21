//
// Created by danix on 11/20/2026.
//

#include "../include/levels.h"
#include "../include/Obstacle.h"
#include "../include/Platform.h"

void levels::addText(const std::string& str, sf::Vector2f pos) {
    sf::Text t(font);
    t.setString(str);
    t.setFillColor(sf::Color::White);
    t.setPosition(pos);
    texts.push_back(std::move(t));
}
void levels::load() {
//tutorial 1


    end.Setup(sf::Color::Red, {40, 40});
    end.SetupPhysics(monde, b2_staticBody, {60, 30});
    end.createEnd();

    mario.Setup(sf::Color::Transparent, {40, 40});
    mario.SetupPhysics(monde, b2_dynamicBody, startPosition);
    mario.SetSpawnPoint(startPosition);
    mario.create();

    Deathbox.Setup(sf::Color::Transparent, {10000, 1});
    Deathbox.SetupPhysics(monde, b2_staticBody, {0, 50});
    leftwall.Setup(sf::Color::Black,{40,2000});
    leftwall.setupBorder(monde,b2_staticBody,{-1,45});


    rightwall.Setup(sf::Color::Black,{40,2000});
    rightwall.setupBorder(monde,b2_staticBody,{80,45});

    ceiling.Setup(sf::Color::Black,{2000,40});
    ceiling.setupBorder(monde,b2_staticBody,{45,0});

    platform.Setup(sf::Color::Transparent, {1000.f, 450.f});
    platform.SetupPhysics(monde, b2_staticBody, {40, 45});
    platform.createR({0.0});

}

bool levels::tutorial(double dt) {
    mario.Move(dt);
    mario.Jump(dt);

        mario.Update();
        Deathbox.Update(mario);
        platform.UpdateR();

        mario.display(window);
        window.draw(Deathbox);
        Deathbox.DisplayS(window);
        platform.displayR(window);
        window.draw(end);
        end.Enddisplay(window);

    if (end.End()== true) {
        return true;
    }
    }

