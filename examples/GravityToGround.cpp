//
// Created by Øystein Bringsli on 1/11/2023.
//

#include "ThreeppHandler.hpp"
#include "ParticleHandler.hpp"
#include "GravityControl.hpp"
#include "Vec3.hpp"

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 1000, 2);
    particleHandler.setGravityType(GravityType::Ground);
    particleHandler.setTimeBetweenParticles(20);
    particleHandler.setMinSpeed(0.1);
    particleHandler.setFriction(0.9);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.setColor(1, 1, 1);

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    MyKeyListener myKeyListener(particleHandler);
    handler.addKeyListener(myKeyListener);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}