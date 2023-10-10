//
// Created by Øystein Bringsli on 10/5/2023.
//

#include <threepp/threepp.hpp>
#include <string>

#include "../include/ThreeppHandler.hpp"
#include <string>

using namespace threepp;

ThreeppHandler::ThreeppHandler(const std::string& title)
    :_canvas(title, {{"aa", 4}}),
      _renderer(_canvas.size()),
      _camera(PerspectiveCamera::create()),
      _scene(Scene::create())

{
    _renderer.setClearColor(Color::black);

    _camera->position.z = 5;
    _camera->aspect = _canvas.size().aspect();
    _camera->updateProjectionMatrix();

    OrbitControls controls{*_camera, _canvas};

    _canvas.onWindowResize([&](WindowSize size) {
        _camera->aspect = size.aspect();
        _camera->updateProjectionMatrix();
        _renderer.setSize(size);
    });
}

int ThreeppHandler::addText(const std::string& label, int x, int y, float scale) {
    auto& textHandle = _textRenderer.createHandle(label);
    textHandle.setPosition(x, 7);
    textHandle.scale = scale;

    _textHandles.push_back(&textHandle);
    return _textHandles.size() - 1;
}
