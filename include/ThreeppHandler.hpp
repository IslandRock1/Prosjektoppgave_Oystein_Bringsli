//
// Created by Øystein Bringsli on 5/10/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP

#include <threepp/threepp.hpp>
#include <vector>
#include <string>

#include "ParticleHandler.hpp"
#include "Vec3.hpp"
#include "Particle.hpp"

using namespace threepp;

class ThreeppHandler {
public:
    ThreeppHandler(const std::string& title, ParticleHandler &particleHandler);
    int addText(const std::string& label, int x, int y, float scale);

    //Potentially used in future for 2D physics.
    int addCircle(float radius, int segments = 32);
    int addSphere(Vec3 pos, float radius);

    void setWindowResizeListener();
    void CanvasAnimate();

    int frameCount = 0;

    void setRandomColor(bool input);
    void setColor(const Color &color);
    void setColor(float r, float g, float b);

private:
    Canvas _canvas;
    GLRenderer _renderer;
    std::shared_ptr<PerspectiveCamera> _camera;
    std::shared_ptr<Scene> _scene;
    OrbitControls _controls;
    Clock _clock;

    void _drawBorder();

    TextRenderer _textRenderer;
    std::vector<TextHandle*> _textHandles;

    //Should be called something along the lines of "particleMeshes" or whatever
    std::vector<std::shared_ptr<Mesh>> _particleMeshes;
    bool _randomColor = false;
    Color _color = {1, 1, 1};

    ParticleHandler &_particleHandler;
    bool _maxCapasity = false;
};

#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
