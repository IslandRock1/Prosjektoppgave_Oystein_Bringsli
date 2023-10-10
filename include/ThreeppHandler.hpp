//
// Created by Øystein Bringsli on 10/5/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP

#include <threepp/threepp.hpp>
#include <vector>

using namespace threepp;

class ThreeppHandler {
public:
    ThreeppHandler();
    int addText(const std::string& label, int x, int y, float scale);

private:
    TextRenderer _textRenderer;
    std::vector<TextHandle*> _textHandles;
};

#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_THREEPPHANDLER_HPP
