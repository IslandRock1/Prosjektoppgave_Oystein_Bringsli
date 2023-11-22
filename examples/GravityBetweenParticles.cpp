//
// Created by Øystein Bringsli on 1/11/2023.
//

#include "GravityObject.hpp"
#include "MyKeyListener.hpp"
#include "ParticleHandler.hpp"
#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 100, 5);
    particleHandler.setGravityType(GravityType::BetweenObjects);
    particleHandler.setMinSpeed(0.1);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.setRandomColor(true);

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    MyKeyListener myKeyListener(particleHandler);
    handler.addKeyListener(myKeyListener);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}