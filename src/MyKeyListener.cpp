

#include "MyKeyListener.hpp"
#include <threepp/threepp.hpp>

using namespace threepp;

MyKeyListener::MyKeyListener(ParticleHandler &handler): _particleHandler(handler) {}

void MyKeyListener::onKeyPressed(threepp::KeyEvent evt) {
    switch (evt.key) {
        case Key::A:
        {
            _particleHandler.addToStartPos({-3, 0, 0});
        } break;

        case Key::D:
        {
            _particleHandler.addToStartPos({3, 0, 0});
        } break;

        case Key::Q:
        {
            _particleHandler.addToStartPos({0, 0, -3});
        } break;

        case Key::E:
        {
            _particleHandler.addToStartPos({0, 0, 3});
        } break;

        case Key::S:
        {
            _particleHandler.addToStartPos({0, -3, 0});
        } break;

        case Key::W:
        {
            _particleHandler.addToStartPos({0, 3, 0});
        } break;

        case Key::U:
        {
            _particleHandler.addToMaxAntall(1);
        } break;

        case Key::J:
        {
            _particleHandler.addToMaxAntall(-1);
        } break;

        case Key::G:
        {
            _particleHandler.showPreview = true;
        } break;
    }
}

void MyKeyListener::onKeyRepeat(threepp::KeyEvent evt) {
    switch (evt.key) {
        case Key::A:
        {
            _particleHandler.addToStartPos({-5, 0, 0});
        } break;

        case Key::D:
        {
            _particleHandler.addToStartPos({5, 0, 0});
        } break;

        case Key::Q:
        {
            _particleHandler.addToStartPos({0, 0, -5});
        } break;

        case Key::E:
        {
            _particleHandler.addToStartPos({0, 0, 5});
        } break;

        case Key::S:
        {
            _particleHandler.addToStartPos({0, -5, 0});
        } break;

        case Key::W:
        {
            _particleHandler.addToStartPos({0, 5, 0});
        } break;

        case Key::U:
        {
            _particleHandler.addToMaxAntall(5);
        } break;

        case Key::J:
        {
            _particleHandler.addToMaxAntall(-5);
        } break;
    }
}

void MyKeyListener::onKeyReleased(threepp::KeyEvent evt) {
    switch (evt.key) {
        case Key::G:
        {
            _particleHandler.showPreview = false;
        } break;
    }
}