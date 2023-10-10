
//#include "threepp/extras/imgui/ImguiContext.hpp"
#include <threepp/threepp.hpp>
#include <iostream>

#include "ThreeppHandler.hpp"

using namespace threepp;

int main() {

    ThreeppHandler handler{"Particle Simulator"};

    int ix = handler.addText("Frame: 0", 0, 0, 1.5);
    handler.setCanvasAnimate();

    /*float radius = 1.0;
    int segments = 64;

    auto geometry = CircleGeometry::create(radius, segments);
    auto material = MeshBasicMaterial::create();
    material->color.copy(Color::aliceblue);
    auto mesh = Mesh::create(geometry, material);
    scene->add(mesh);


    canvas.animate([&] {
        auto dt = clock.getDelta();

        renderer.render(*scene, *camera);
        renderer.resetState();// needed when using TextRenderer
        textRenderer.render();

        frameCount++;
        textHandle0.setText("Frame " + std::to_string(frameCount));
        textHandle1.setText("Particles: 0");

        //mesh->position += 0.1 * dt;
    });*/
}
