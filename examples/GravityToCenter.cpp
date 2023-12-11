
#include "GravityObject.hpp"
#include "ParticleHandler.hpp"
#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 50, 3);
    particleHandler.setGravityType(GravityType::Center);
    particleHandler.setGravityStrength(10000.0);
    particleHandler.setMinSpeed(0.02);
    particleHandler.setSubSteps(64);
    particleHandler.setFriction(0.99);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.setColor(1, 0, 1);

    handler.frameText = true;
    handler.particleText = true;
    handler.dtText = true;
    handler.maxParticleText = true;

    MyKeyListener myKeyListener(particleHandler);
    handler.addKeyListener(myKeyListener);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}