//
// Created by danix on 11/14/2026.
//
#include "../include/danger.h"
#include "../include/Entity.h"
#include "../include/object.h"
#include <box2d/box2d.h>
#include <box2d/types.h>

void Danger::Setup(b2BodyId body_id, b2Vec2 halfSize) {


    const b2Polygon pieds =
        b2MakeOffsetBox(halfSize.x, halfSize.y, {0, 0}, b2Rot_identity);

    b2ShapeDef def = b2DefaultShapeDef();
    def.isSensor = true;              // il détecte, il n'arrête rien
    def.enableSensorEvents = true;    // sans ça : aucun événement
    def.userData = this;

    b2CreatePolygonShape(body_id, &def, &pieds);

}



