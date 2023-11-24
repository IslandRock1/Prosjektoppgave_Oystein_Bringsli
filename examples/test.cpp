//
// Created by Øystein Bringsli on 3/11/2023.
//

#include "GravityObject.hpp"
#include "ParticleHandler.hpp"
#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 500, 3);
    particleHandler.setGravityType(GravityType::BetweenObjects);
    particleHandler.setGravityStrength(500);
    particleHandler.setTimeBetweenParticles(3);
    particleHandler.setMinSpeed(0.1);
    particleHandler.setFriction(0.99);
    particleHandler.setSubSteps(8);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.toggleRandomColor(true);

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}