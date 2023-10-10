
//#include "threepp/extras/imgui/ImguiContext.hpp"
#include "threepp/threepp.hpp"

#include <iostream>

using namespace threepp;

int main() {

    Canvas canvas("Particle Simulator", {{"aa", 4}});

    std::cout << canvas.size().aspect() << std::endl;
    //canvas.setSize(WindowSize::)

    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::black);

    //auto camera = PerspectiveCamera::create();
    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;
    camera->aspect = canvas.size().aspect();
    camera->updateProjectionMatrix();

    OrbitControls controls{*camera, canvas};

    auto scene = Scene::create();

    renderer.enableTextRendering();
    int textYOffset = 5;
    auto& textHandle0 = renderer.textHandle("Frame 0");
    auto& textHandle1 = renderer.textHandle("Particles: 0");
    textHandle0.setPosition(2, textYOffset + 3);
    textHandle1.setPosition(2, 2 * textYOffset + 10);
    textHandle0.scale = 1;
    textHandle1.scale = 1;

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        textHandle0.setPosition(0, textYOffset + 3);
        textHandle1.setPosition(0, 2 * textYOffset + 10);
    });

    float radius = 1.0;
    int segments = 64;

    auto geometry = CircleGeometry::create(radius, segments);
    auto material = MeshBasicMaterial::create();
    material->color.copy(Color::aliceblue);
    auto mesh = Mesh::create(geometry, material);
    scene->add(mesh);

    Clock clock;
    int name = 0;

    canvas.animate([&] {
        auto dt = clock.getDelta();

        renderer.render(*scene, *camera);

        name++;
        textHandle0.setText("Frame " + std::to_string(name));
        textHandle1.setText("Particles: 0");

        //mesh->position += 0.1 * dt;
    });
}
