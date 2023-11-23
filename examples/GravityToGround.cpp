//
// Created by Øystein Bringsli on 1/11/2023.
//

#include "GravityObject.hpp"
#include "ParticleHandler.hpp"
#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 1000, 2);
    particleHandler.setGravityType(GravityType::Ground);
    particleHandler.setTimeBetweenParticles(20);
    particleHandler.setMinSpeed(0.1);
    particleHandler.setFriction(0.999);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.setColor(1, 1, 1);

    handler.particleText = true;
    handler.fpsText = true;

    MyKeyListener myKeyListener(particleHandler);
    handler.addKeyListener(myKeyListener);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}