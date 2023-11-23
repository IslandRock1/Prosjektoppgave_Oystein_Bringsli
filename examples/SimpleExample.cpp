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

    handler.frameText = true;
    handler.particleText = true;
    handler.dtText = true;
    handler.maxParticleText = true;

    MyKeyListener myKeyListener(particleHandler);
    handler.addKeyListener(myKeyListener);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}