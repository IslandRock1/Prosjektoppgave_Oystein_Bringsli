
#include <threepp/threepp.hpp>
#include <iostream>

#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

using namespace threepp;

int main() {

    ThreeppHandler handler{"Particle Simulator"};

    int ix = handler.addText("Frame 0", 0, 0, 1.5);
    int ix2 = handler.addText("Particles: 0", 0, 20, 1.5);

    int ix4 = handler.addSphere(1.0);
    int ix5 = handler.addSphere(1.0);
    handler.setCanvasAnimate(ix4, ix5);
}
