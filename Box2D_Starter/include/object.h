//
// Created by danix on 11/4/2026.
//

#ifndef SFML_STARTER_OBJECT_H
#define SFML_STARTER_OBJECT_H
#include <box2d/types.h>
#include <SFML/Graphics/Drawable.hpp>


class Physical_Object {
   b2BodyDef def_;
    b2ShapeDef shape_def_;
    public:
    b2BodyId body_;
    void Setup(b2WorldId &world,b2BodyType type, b2Vec2 position,b2Vec2 halfSize);
    void Update();
    b2Vec2 GetPosition();
    void SetVelocity(b2Vec2 vel);
    b2Vec2 GetVelocity();
    b2BodyId GetBodyId();
};


#endif //SFML_STARTER_OBJECT_H
