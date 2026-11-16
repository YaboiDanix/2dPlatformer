//
// Created by danix on 11/4/2026.
//

#ifndef SFML_STARTER_CONSTANTS_H
#define SFML_STARTER_CONSTANTS_H
static class Convertions {
    static constexpr float pixelToMeters = 0.05f;
public:
    static float PhysicsToScreen(float meters) {
        return meters / pixelToMeters;
    }
    static float ScreenToPhysics(float pixels) {
        return pixelToMeters * pixels;
    }
};
#endif //SFML_STARTER_CONSTANTS_H
