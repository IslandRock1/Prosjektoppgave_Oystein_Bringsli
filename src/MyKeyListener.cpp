//
// Created by Øystein Bringsli on 12/11/2023.
//

#include <threepp/threepp.hpp>
#include "MyKeyListener.hpp"

using namespace threepp;

MyKeyListener::MyKeyListener(ParticleHandler &handler): _particleHandler(handler) {}

void MyKeyListener::onKeyPressed(threepp::KeyEvent evt) {
    switch (evt.key) {
        case Key::A:
        {
            _particleHandler.addToStartPos({-1, 0, 0});
        } break;

        case Key::D:
        {
            _particleHandler.addToStartPos({1, 0, 0});
        } break;

        case Key::Q:
        {
            _particleHandler.addToStartPos({0, 0, -1});
        } break;

        case Key::E:
        {
            _particleHandler.addToStartPos({0, 0, 1});
        } break;

        case Key::W:
        {
            _particleHandler.addToStartPos({0, -1, 0});
        } break;

        case Key::S:
        {
            _particleHandler.addToStartPos({0, 1, 0});
        } break;
    }
}

void MyKeyListener::onKeyRepeat(threepp::KeyEvent evt) {
    switch (evt.key) {
        case Key::A:
        {
            _particleHandler.addToStartPos({-1, 0, 0});
        } break;

        case Key::D:
        {
            _particleHandler.addToStartPos({1, 0, 0});
        } break;

        case Key::Q:
        {
            _particleHandler.addToStartPos({0, 0, -1});
        } break;

        case Key::E:
        {
            _particleHandler.addToStartPos({0, 0, 1});
        } break;

        case Key::W:
        {
            _particleHandler.addToStartPos({0, -1, 0});
        } break;

        case Key::S:
        {
            _particleHandler.addToStartPos({0, 1, 0});
        } break;
    }
}