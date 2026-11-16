//
// Created by danix on 11/4/2026.
//

#include "../include/object.h"

#include <print>
#include <box2d/box2d.h>
#include <box2d/types.h>

void Physical_Object::Setup(b2WorldId &world, b2BodyType type, b2Vec2 position,b2Vec2 halfSize) {
    def_ = b2DefaultBodyDef();
    def_.type = type;
    def_.position = position;

    body_ = b2CreateBody(world, &def_);

    b2Polygon square = b2MakeBox(halfSize.x,halfSize.y);

    shape_def_ = b2DefaultShapeDef();
    shape_def_.density = 1.0f;
    shape_def_.material.friction = 0.0f;
    shape_def_.material.restitution = 0.0f;
    b2CreatePolygonShape(body_, &shape_def_, &square);
    shape_def_.enableContactEvents =false;
    shape_def_.isSensor= false;

    b2MassData myMass;
    myMass.mass = 5.0f;
    myMass.center = {0, 0};
    myMass.rotationalInertia = 0.0f;
    b2Body_SetMassData(body_, myMass);
}
void Physical_Object::Update() {
    std::println("object position {} : {}", b2Body_GetPosition(body_).x, b2Body_GetPosition(body_).y);
}
b2Vec2 Physical_Object::GetPosition() {
    return b2Body_GetPosition(body_);
}


void Physical_Object::SetVelocity(b2Vec2 vel) {
    b2Body_SetLinearVelocity(body_, vel);
}

b2Vec2 Physical_Object::GetVelocity() {
    return b2Body_GetLinearVelocity(body_);
}
b2BodyId Physical_Object::GetBodyId() {
    return body_;
}