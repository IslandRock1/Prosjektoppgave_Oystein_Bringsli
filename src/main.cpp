
#include "ThreeppHandler.hpp"
#include "ParticleHandler.hpp"
#include "Vec3.hpp"

using namespace threepp;

int main() {

    ThreeppHandler handler{"Particle Simulator"};

    Vec3 boundingBoxSize = {100, 100, 100};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 2, 5);

    handler.addText("Frame 0", 0, 0, 1.5);
    handler.addText("Particles: 0", 0, 20, 1.5);

    int maxFrames = 10000;
    for (int i = 0; i < maxFrames; i++)
    {
        handler.CanvasAnimateOnce(particleHandler.getParticles(), particleHandler.getRadius());
        particleHandler.step(0.01);
    }
}
