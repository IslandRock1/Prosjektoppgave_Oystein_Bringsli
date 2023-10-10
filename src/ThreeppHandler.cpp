//
// Created by Øystein Bringsli on 10/5/2023.
//

#include "../include/ThreeppHandler.hpp"
#include <threepp/threepp.hpp>
#include <string>

using namespace threepp;

ThreeppHandler::ThreeppHandler() {

    Canvas canvas("Particle Simulator", {{"aa", 4}});
    GLRenderer renderer(canvas.size());
    renderer.setClearColor(Color::black);

    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;
    camera->aspect = canvas.size().aspect();
    camera->updateProjectionMatrix();

    OrbitControls controls{*camera, canvas};
    auto scene = Scene::create();

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });
}

int ThreeppHandler::addText(const std::string& label, int x, int y, float scale) {
    auto& textHandle = _textRenderer.createHandle(label);
    textHandle.setPosition(x, 7);
    textHandle.scale = scale;

    _textHandles.push_back(&textHandle);
    return _textHandles.size() - 1;
}
