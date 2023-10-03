
#include "threepp/extras/imgui/ImguiContext.hpp"
#include "threepp/threepp.hpp"

#include <iostream>

using namespace threepp;

int main() {

    Canvas canvas("Particle Simulator", {{"aa", 4}});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::aliceblue);

    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;

    OrbitControls controls{*camera, canvas};

    auto scene = Scene::create();

    renderer.enableTextRendering();
    int textYOffset = 30;
    auto& textHandle = renderer.textHandle("Hello World");
    textHandle.setPosition(0, canvas.size().height - textYOffset);
    textHandle.scale = 2;

    std::array<float, 3> posBuf{};
    ImguiFunctionalContext ui(canvas.windowPtr(), [&] {
        ImGui::SetNextWindowPos({0, 0}, 0, {0, 0});
        ImGui::SetNextWindowSize({230, 0}, 0);
        ImGui::Begin("Demo");
        ImGui::SliderFloat3("position", posBuf.data(), -1.f, 1.f);
        controls.enabled = !ImGui::IsWindowHovered();
        ImGui::End();
    });

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        textHandle.setPosition(0, size.height - textYOffset);
    });

    Clock clock;
    float rotationSpeed = 1;
    int name = 1;

    canvas.animate([&] {
        auto dt = clock.getDelta();

        renderer.render(*scene, *camera);

        auto& textHandle = renderer.textHandle();
    });
}
