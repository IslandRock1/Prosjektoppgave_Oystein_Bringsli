
#include "ThreeppHandler.hpp"
#include "ParticleHandler.hpp"
#include "Vec3.hpp"

using namespace threepp;

int main() {

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 100, 5);

    ThreeppHandler handler{"Particle Simulator", particleHandler};

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    handler.CanvasAnimate();
}
