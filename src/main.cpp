
//#include "threepp/extras/imgui/ImguiContext.hpp"
#include "threepp/threepp.hpp"

#include <iostream>

using namespace threepp;

int main() {

    Canvas canvas("Particle Simulator", {{"aa", 4}});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::black);

    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;
    camera->aspect = canvas.size().aspect();
    camera->updateProjectionMatrix();

    OrbitControls controls{*camera, canvas};

    auto scene = Scene::create();

    TextRenderer textRenderer;
    auto& textHandle0 = textRenderer.createHandle("Frame 0");
    auto& textHandle1 = textRenderer.createHandle("Particles: 0");
    textHandle0.verticalAlignment = threepp::TextHandle::VerticalAlignment::TOP;
    textHandle1.verticalAlignment = threepp::TextHandle::VerticalAlignment::TOP;
    textHandle0.setPosition(0, 5);
    textHandle1.setPosition(0, 25);
    textHandle0.scale = 1.5;
    textHandle1.scale = 1.5;

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        textHandle0.setPosition(0, 5);
        textHandle1.setPosition(0, 25);
    });

    float radius = 1.0;
    int segments = 64;

    auto geometry = CircleGeometry::create(radius, segments);
    auto material = MeshBasicMaterial::create();
    material->color.copy(Color::aliceblue);
    auto mesh = Mesh::create(geometry, material);
    scene->add(mesh);

    Clock clock;
    int frameCount = 0;

    canvas.animate([&] {
        auto dt = clock.getDelta();

        renderer.render(*scene, *camera);
        renderer.resetState();// needed when using TextRenderer
        textRenderer.render();

        frameCount++;
        textHandle0.setText("Frame " + std::to_string(frameCount));
        textHandle1.setText("Particles: 0");

        //mesh->position += 0.1 * dt;
    });
}
