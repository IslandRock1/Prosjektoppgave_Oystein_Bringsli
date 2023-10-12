//
// Created by Øystein Bringsli on 10/5/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP

#include <threepp/threepp.hpp>
#include <vector>
#include <string>

using namespace threepp;

class ThreeppHandler {
public:
    ThreeppHandler(const std::string& title);
    int addText(const std::string& label, int x, int y, float scale);

    int addCircle(float radius, int segments = 32);
    int addSphere(float radius);

    void setWindowResizeListener();
    void setCanvasAnimate(int ix0, int ix1);

    int frameCount = 0;

private:
    Canvas _canvas;
    GLRenderer _renderer;
    std::shared_ptr<PerspectiveCamera> _camera;
    std::shared_ptr<Scene> _scene;
    OrbitControls _controls;
    Clock _clock;

    TextRenderer _textRenderer;
    std::vector<TextHandle*> _textHandles;
    std::vector<std::shared_ptr<Mesh>> _meshVector;
};

#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
