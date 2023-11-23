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
    makeSpawnPoint();

    _textMap = {
        {textHandles::frame, addText("", 0, 0, 1.5)},
        {textHandles::fps, addText("", 0, 0, 1.5)},
        {textHandles::dt, addText("", 0, 0, 1.5)},
        {textHandles::particles, addText("", 0, 0, 1.5)},
        {textHandles::maxAntall, addText("", 0, 0, 1.5)}
    };
}

void ThreeppHandler::makeSpawnPoint() {
    auto startPos = _particleHandler.getStartPos();
    auto geo = SphereGeometry::create(_particleHandler.getRadius());
    auto material = MeshBasicMaterial::create();
    material->color.setRGB(0.2, 0.7, 1.0);
    auto mesh = Mesh::create(geo, material);
    mesh->position.set(startPos.x, startPos.y, startPos.y);

    _spawnPointPreview = mesh;

    //_scene->add(_spawnPointPreview);
    //_scene->remove(*_spawnPointPreview);
}

void ThreeppHandler::updateTextPos() {
    int offset = 20;
    int framePos = 0;
    int fpsPos;
    int dtPos;
    int particlePos;
    int maxPos;

    if (frameText) {fpsPos = framePos + offset;} else {fpsPos = framePos;}
    if (fpsText) {dtPos = fpsPos + offset;} else {dtPos = fpsPos;}
    if (dtText) {particlePos = dtPos + offset;} else {particlePos = dtPos;}
    if (particleText) {maxPos = particlePos + offset;} else {maxPos = particlePos;}

    _textMap.at(textHandles::frame)->setPosition(0, framePos);
    _textMap.at(textHandles::fps)->setPosition(0, fpsPos);
    _textMap.at(textHandles::dt)->setPosition(0, dtPos);
    _textMap.at(textHandles::particles)->setPosition(0, particlePos);
    _textMap.at(textHandles::maxAntall)->setPosition(0, maxPos);

}

void ThreeppHandler::setRandomColor(bool input) {_randomColor = input;}

void ThreeppHandler::setColor(const Color &color) {_color = color;}

void ThreeppHandler::setColor(float r, float g, float b) {_color = {r, g, b};}

void ThreeppHandler::_drawBorder() {
    //Not happy with this. Going to look over the boid example to see how Lars did it later.
    float sizeX = _particleHandler.getBounding().x;
    float sizeY = _particleHandler.getBounding().y;
    float sizeZ = _particleHandler.getBounding().z;

    static Box3 box{{-sizeX, -sizeY, -sizeZ},{sizeX, sizeY, sizeZ}};
    auto boxHelper = Box3Helper::create(box, {1.0, 1.0, 1.0});
    _scene->add(boxHelper);
}

TextHandle* ThreeppHandler::addText(const std::string& label, int x, int y, float scale) {
    auto& textHandle = _textRenderer.createHandle(label);
    textHandle.setPosition(x, y);
    textHandle.scale = scale;

    return &textHandle;
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

    if (_randomColor) {
        auto r = static_cast<float>(random(rng)) / 255.0f;
        auto g = static_cast<float>(random(rng)) / 255.0f;
        auto b = static_cast<float>(random(rng)) / 255.0f;

        material->color.setRGB(r, g, b);
    } else {
        material->color.copy(_color);
    }

    auto mesh = Mesh::create(geometry, material);
    mesh->position = Vector3(pos.x, pos.y, pos.z);

    _particleMeshes.push_back(mesh);
    _scene->add(mesh);

    return _particleMeshes.size() - 1;
}

void ThreeppHandler::addKeyListener(MyKeyListener& keyListener) {_canvas.addKeyListener(&keyListener);}

void ThreeppHandler::setWindowResizeListener() {
    _canvas.onWindowResize([&](WindowSize size) {
        _camera->aspect = size.aspect();
        _camera->updateProjectionMatrix();
        _renderer.setSize(size);
    });
}

void ThreeppHandler::CanvasAnimate() {
    updateTextPos();

    _canvas.animate([&] {
        auto t0 = std::chrono::high_resolution_clock::now();
        _particleHandler.step(0.005);
        auto t1 = std::chrono::high_resolution_clock::now();
        dt = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count());
        fps = static_cast<int>(1000000.0 / dt);

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

        _handleText();

        _renderer.render(*_scene, *_camera);
        _renderer.resetState();
        _textRenderer.render();
    });
}

void ThreeppHandler::_handleText() {
    if (frameText) {
        _textMap.at(textHandles::frame)->setText("Frame " + std::to_string(frameCount));
    }

    if (fpsText && ((frameCount & 10) == 0)) {
        if (fps > 999) {_textMap.at(textHandles::fps)->setText("FPS (particle calculations): 999+");}
        else if (fps > 10) {_textMap.at(textHandles::fps)->setText("FPS (particle calculations): " + std::to_string(static_cast<int>(fps)));}
        else {_textMap.at(textHandles::fps)->setText("FPS (particle calculations): " + std::to_string(fps));}
    }

    if (dtText && ((frameCount & 10) == 0)) {
        _textMap.at(textHandles::dt)->setText("dt (particle calculations): " + std::to_string(static_cast<int>(dt / 1000.0)) + "ms");
    }

    if (particleText) {
        _textMap.at(textHandles::particles)->setText("Particles: " + std::to_string(_particleHandler.getCurrentAntall()));
    }

    if (maxParticleText) {
        _textMap.at(textHandles::maxAntall)->setText("Max antall: " + std::to_string(_particleHandler.getAntall()));
    }
}