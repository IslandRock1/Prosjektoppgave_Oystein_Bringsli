
#include <threepp/threepp.hpp>
#include <iostream>

#include "ThreeppHandler.hpp"
#include "Vec3.hpp"

using namespace threepp;

int main() {

    Vec3 pos_own(5, 7, 8);
    Vec3 prev_pos_own(9, 2, 1);
    Vec3 g_own(0, 0, 0);

    Vector3 pos(5, 7, 8);
    Vector3 prev_pos(9, 2, 1);
    Vector3 g(0, 0, 0);
    double dt = 0.1;

    Vec3 vec = pos_own + g_own;
    vec += prev_pos_own;
    Vec3 new_vec = vec + 5;
    /*pos_own = g_own + 2;
    pos_own *= 2;
    pos_own = g_own * 2;
    pos_own = pos_own * 2 - prev_pos_own + g_own * dt * dt;*/

    pos = pos * 2 - prev_pos + g * dt * dt;


    ThreeppHandler handler{"Particle Simulator"};

    int ix = handler.addText("Frame 0", 0, 0, 1.5);
    int ix2 = handler.addText("Particles: 0", 0, 20, 1.5);

    int ix4 = handler.addSphere(1.0);
    int ix5 = handler.addSphere(1.0);
    handler.setCanvasAnimate(ix4, ix5);
}
