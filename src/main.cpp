
#include "ThreeppHandler.hpp"
#include "ParticleHandler.hpp"
#include "Vec3.hpp"

using namespace threepp;

int main() {

    ThreeppHandler handler{"Particle Simulator"};

    Vec3 boundingBoxSize = {2, 2, 2};
    ParticleHandler particleHandler = ParticleHandler(boundingBoxSize, 5, 10);

    particleHandler.makeParticle(Vec3(10, 10, 10));
    particleHandler.makeParticle(Vec3(-10, -10, -10));

    std::vector<int> indices;
    for (Particle &p : particleHandler.getParticles())
    {
        indices.push_back(handler.addSphere(p.pos, particleHandler.getRadius()));
    }

    int ix = handler.addText("Frame 0", 0, 0, 1.5);
    int ix2 = handler.addText("Particles: 2", 0, 20, 1.5);

    handler.setCanvasAnimate(indices);
}
