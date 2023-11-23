//
// Created by Øystein Bringsli on 5/10/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP

#include <threepp/threepp.hpp>
#include <vector>
#include <string>

#include "ParticleHandler.hpp"
#include "MyKeyListener.hpp"
#include "Vec3.hpp"
#include "Particle.hpp"

using namespace threepp;

enum textHandles {
    frame,
    fps,
    dt,
    particles,
    maxAntall
};

class ThreeppHandler {
public:
    ThreeppHandler(const std::string& title, ParticleHandler &particleHandler);

    //Potentially used in future for 2D physics.
    int addCircle(float radius, int segments = 32);
    int addSphere(Vec3 pos, float radius);

    void addKeyListener(MyKeyListener &keyListener);
    void setWindowResizeListener();
    void CanvasAnimate();

    int frameCount = 0;
    double fps = 0;
    double dt = 0;

    void setRandomColor(bool input);
    void setColor(const Color &color);
    void setColor(float r, float g, float b);

    bool frameText = false;
    bool fpsText = false;
    bool dtText = false;
    bool particleText = false;
    bool maxParticleText = false;


private:
    Canvas _canvas;
    GLRenderer _renderer;
    std::shared_ptr<PerspectiveCamera> _camera;
    std::shared_ptr<Scene> _scene;
    OrbitControls _controls;
    Clock _clock;

    void _drawBorder();
    void _saveImage(); //Not implemented

    TextRenderer _textRenderer;
    std::vector<TextHandle*> _textHandles;
    std::unordered_map<textHandles, TextHandle*> _textMap;
    TextHandle* addText(const std::string& label, int x, int y, float scale);
    void updateTextPos();
    void _handleText();

    std::vector<std::shared_ptr<Mesh>> _particleMeshes;
    std::shared_ptr<Mesh> _spawnPointPreview;
    void makeSpawnPoint();
    bool _showSpawnPoint = false;

    bool _randomColor = false;
    Color _color = {1, 1, 1};

    ParticleHandler &_particleHandler;
};

#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
