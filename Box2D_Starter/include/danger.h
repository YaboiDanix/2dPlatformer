//
// Created by danix on 11/11/2026.
//

#ifndef SFML_STARTER_DANGER_H
#define SFML_STARTER_DANGER_H
#include <box2d/id.h>
#include <box2d/math_types.h>



class Danger {
    public:
    void Setup(b2BodyId bodyId, b2Vec2 halfSize);
    bool HasHit = false;
};

#endif //SFML_STARTER_DANGER_H
