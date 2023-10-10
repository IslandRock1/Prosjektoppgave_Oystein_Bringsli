//
// Created by oyste on 10/5/2023.
//

#include "../include/ThreeppHandler.hpp"
#include <threepp/threepp.hpp>
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