//
// Created by Øystein Bringsli on 12/11/2023.
//

#include <threepp/threepp.hpp>
#include "MyKeyListener.hpp"

using namespace threepp;

MyKeyListener::MyKeyListener(ParticleHandler handler): _particleHandler(handler) {}

void MyKeyListener::onKeyPressed(threepp::KeyEvent evt) {
    if (evt.key == Key::A) {
        return;
    }
}