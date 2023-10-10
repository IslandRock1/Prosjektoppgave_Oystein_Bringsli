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

private:
    Canvas _canvas;
    GLRenderer _renderer;
    std::shared_ptr<PerspectiveCamera> _camera;
    std::shared_ptr<Scene> _scene;

    TextRenderer _textRenderer;
    std::vector<TextHandle*> _textHandles;
};

#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
