//
// Created by danix on 11/5/2026.
//

#ifndef SFML_STARTER_SENSOR_H
#define SFML_STARTER_SENSOR_H
#include <box2d/id.h>
#include <box2d/math_types.h>
#include <box2d/types.h>


class sensor {
public:
    void Setup(b2BodyId body_id, b2Vec2 halfSize);
    bool HasTouched = false;
};


#endif //SFML_STARTER_SENSOR_H
