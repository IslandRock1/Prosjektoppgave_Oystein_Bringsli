//
// Created by Øystein Bringsli on 5/10/2023.
//

#include <threepp/threepp.hpp>

#include "ThreeppHandler.hpp"
#include <string>
#include <chrono>

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

    _particleMeshes.push_back(mesh);
    _scene->add(mesh);

    return _particleMeshes.size() - 1;
}

int ThreeppHandler::addSphere(Vec3 pos, float radius) {
    auto geometry = SphereGeometry::create(radius);
    auto material = MeshBasicMaterial::create();

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> random(0,255);

    auto r = static_cast<float>(random(rng)) / 255.0f;
    auto g = static_cast<float>(random(rng)) / 255.0f;
    auto b = static_cast<float>(random(rng)) / 255.0f;

    material->color.setRGB(r, g, b);

    auto mesh = Mesh::create(geometry, material);
    mesh->position = Vector3(pos.x, pos.y, pos.z);

    _particleMeshes.push_back(mesh);
    _scene->add(mesh);

    return _particleMeshes.size() - 1;
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
        auto t0 = std::chrono::high_resolution_clock::now();
        _particleHandler.step(0.01, _maxCapasity);
        auto t1 = std::chrono::high_resolution_clock::now();
        auto dt = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count());

        auto &particles = _particleHandler.getParticles();

        for (int index = 0; index < _particleMeshes.size(); index++) {
            Vec3 pos = particles.at(index).pos;
            _particleMeshes.at(index)->position = {static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(pos.z)};
        }

        for (int index = _particleMeshes.size(); index < particles.size(); index++) {
            Vec3 pos = particles.at(index).pos;
            addSphere({pos.x, pos.y, pos.z}, _particleHandler.getRadius());
        }

        frameCount++;
        auto fps = static_cast<int>(1000000.0 / dt);
        //Allocates 50% of time to particle collisions, and rest to rendering
        if (fps < 120.0) {_maxCapasity = true;}

        //Mostly for debugging
        _textHandles.at(0)->setText("Frame " + std::to_string(frameCount) + " | FPS: " + std::to_string((fps)) + " | dt: " + std::to_string(static_cast<int>(dt / 1000.0)) + "ms");
        _textHandles.at(1)->setText("Particles: " + std::to_string(particles.size()));

        _renderer.render(*_scene, *_camera);
        _renderer.resetState();
        _textRenderer.render();
    });
}