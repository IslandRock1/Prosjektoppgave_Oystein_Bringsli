
#include "ThreeppHandler.hpp"
#include "ParticleHandler.hpp"
#include "Vec3.hpp"

using namespace threepp;

int main() {

    ThreeppHandler handler{"Particle Simulator"};

    Vec3 boundingBoxSize = {500, 500, 500};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 100, 5);

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    handler.CanvasAnimate(particleHandler);
}
