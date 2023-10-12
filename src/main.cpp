
//#include "threepp/extras/imgui/ImguiContext.hpp"
#include <threepp/threepp.hpp>
#include <iostream>

#include "ThreeppHandler.hpp"

using namespace threepp;

int main() {

    ThreeppHandler handler{"Particle Simulator"};

    int ix = handler.addText("Frame 0", 0, 0, 1.5);
    int ix2 = handler.addText("Particles: 0", 0, 20, 1.5);

    int ix3 = handler.addCircle(1.0);
    handler.setCanvasAnimate();
}
