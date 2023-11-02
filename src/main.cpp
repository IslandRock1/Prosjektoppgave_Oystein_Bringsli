
#include "ThreeppHandler.hpp"
#include "ParticleHandler.hpp"
#include "GravityControl.hpp"
#include "Vec3.hpp"

using namespace threepp;

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 100, 5);
    particleHandler.setGravityType(GravityType::BetweenObjects);
    particleHandler.setMinSpeed(0.1);

    ThreeppHandler handler{"Particle Simulator", particleHandler};
    handler.setRandomColor(false);
    handler.setColor(1, 1, 1);

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    handler.setWindowResizeListener();
    handler.CanvasAnimate();
}
