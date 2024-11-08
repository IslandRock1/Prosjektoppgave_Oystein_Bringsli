
#include "GravityObject.hpp"
#include "MyKeyListener.hpp"
#include "ParticleHandler.hpp"
#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 100, 5);
    particleHandler.setGravityType(GravityType::BetweenObjects);
    particleHandler.setMinSpeed(0.5);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.toggleRandomColor(true);

    MyKeyListener myKeyListener(particleHandler);
    handler.addKeyListener(myKeyListener);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}