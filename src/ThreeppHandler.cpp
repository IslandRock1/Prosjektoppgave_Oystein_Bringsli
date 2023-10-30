//
// Created by Øystein Bringsli on 10/5/2023.
//

#include <threepp/threepp.hpp>

#include "ThreeppHandler.hpp"
#include <string>
#include <iostream>

#include "Vec3.hpp"
#include "Particle.hpp"

using namespace threepp;

ThreeppHandler::ThreeppHandler(const std::string& title, ParticleHandler &particleHandler)
    :_canvas(title, {{"aa", 4}}),
      _renderer(_canvas.size()),
      _camera(PerspectiveCamera::create()),
      _scene(Scene::create()),
      _controls(*_camera, _canvas),
      _particleHandler(particleHandler)

{
    _renderer.setClearColor(Color::black);

    auto bound_size = std::max(_particleHandler.getBounding().x, _particleHandler.getBounding().y);
    _camera->position.z = bound_size * 3.0;
    _camera->aspect = _canvas.size().aspect();
    _camera->updateProjectionMatrix();

    _canvas.onWindowResize([&](WindowSize size) {
        _camera->aspect = size.aspect();
        _camera->updateProjectionMatrix();
        _renderer.setSize(size);
    });

    _drawBorder();
}

void ThreeppHandler::_drawBorder() {
    //Not happy with this. Going to look over the boid example to see how Lars did it later.
    auto boxGeo = BoxGeometry::create(100, 100, 100);
    auto material = MeshBasicMaterial::create();
    material->wireframe = true;
    auto mesh = Mesh::create(boxGeo, material);
    _scene->add(mesh);
}

int ThreeppHandler::addText(const std::string& label, int x, int y, float scale) {
    auto& textHandle = _textRenderer.createHandle(label);
    textHandle.setPosition(x, y);
    textHandle.scale = scale;

    _textHandles.push_back(&textHandle);
    return _textHandles.size() - 1;
}

int ThreeppHandler::addCircle(float radius, int segments) {
    auto geometry = CircleGeometry::create(radius, segments);
    auto material = MeshBasicMaterial::create();
    material->color.copy(Color::aliceblue);
    auto mesh = Mesh::create(geometry, material);

    _meshVector.push_back(mesh);
    _scene->add(mesh);

    return _meshVector.size() - 1;
}

int ThreeppHandler::addSphere(float radius) {
    auto geometry = SphereGeometry::create(radius);
    auto material = MeshBasicMaterial::create();
    material->color.copy(Color::green);
    auto mesh = Mesh::create(geometry, material);

    _meshVector.push_back(mesh);
    _scene->add(mesh);

    return _meshVector.size() - 1;
}

int ThreeppHandler::addSphere(Vec3 pos, float radius) {
    auto geometry = SphereGeometry::create(radius);
    auto material = MeshBasicMaterial::create();
    material->color.copy(Color::green);
    auto mesh = Mesh::create(geometry, material);
    mesh->position = Vector3(pos.x, pos.y, pos.z);

    _meshVector.push_back(mesh);
    _scene->add(mesh);

    return _meshVector.size() - 1;
}

void ThreeppHandler::setWindowResizeListener() {
    _canvas.onWindowResize([&](WindowSize size) {
        _camera->aspect = size.aspect();
        _camera->updateProjectionMatrix();
        _renderer.setSize(size);
    });
}

void ThreeppHandler::CanvasAnimate() {
    _canvas.animate([&] {
        auto dt = _clock.getDelta();
        _particleHandler.step(0.01, _maxCapasity);

        auto &particles = _particleHandler.getParticles();

        for (int index = 0; index < _meshVector.size(); index++) {
            Vec3 pos = particles.at(index).pos;
            _meshVector.at(index)->position = {static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(pos.z)};
        }

        for (int index = _meshVector.size(); index < particles.size(); index++) {
            Vec3 pos = particles.at(index).pos;
            addSphere({pos.x, pos.y, pos.z}, _particleHandler.getRadius());
        }

        frameCount++;
        auto fps = static_cast<int>(1.0 / dt);

        //Mostly for debugging
        _textHandles.at(0)->setText("Frame " + std::to_string(frameCount) + " | FPS: " + std::to_string((fps)) + " | dt: " + std::to_string(static_cast<int>(dt * 1000.0)));
        _textHandles.at(1)->setText("Particles: " + std::to_string(particles.size()));

        _renderer.render(*_scene, *_camera);
        _renderer.resetState();
        _textRenderer.render();
    });
}

void ThreeppHandler::CanvasAnimateOnce(const std::vector<Particle> &particles, double radius) {
    _canvas.animateOnce([&] {
        for (int index = 0; index < _meshVector.size(); index++) {
            Vec3 pos = particles.at(index).pos;
            _meshVector.at(index)->position = {static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(pos.z)};
        }

        for (int index = _meshVector.size(); index < particles.size(); index++) {
            Vec3 pos = particles.at(index).pos;
            addSphere({pos.x, pos.y, pos.z}, radius);
        }

        frameCount++;
        auto dt = _clock.getDelta();
        auto fps = static_cast<int>(1000.0 / dt);

        _textHandles.at(0)->setText("Frame " + std::to_string(frameCount) + " | FPS: " + std::to_string((fps)));
        _textHandles.at(1)->setText("Particles: " + std::to_string(particles.size()));

        _renderer.render(*_scene, *_camera);
        _renderer.resetState();
        _textRenderer.render();
    });
}
