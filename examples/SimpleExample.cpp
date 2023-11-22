//
// Created by Øystein Bringsli on 2/11/2023.
//

#include "GravityObject.hpp"
#include "ParticleHandler.hpp"
#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 5, 10);
    particleHandler.setGravityType(GravityType::NoGravity);
    particleHandler.setMinSpeed(0.1);
    particleHandler.setFriction(0.99);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.setRandomColor(true);

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}