//
// Created by Øystein Bringsli on 12/11/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_MYKEYLISTENER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_MYKEYLISTENER_HPP

#include <threepp/threepp.hpp>
#include "ParticleHandler.hpp"

using namespace threepp;

class MyKeyListener: public KeyListener {
public:
    explicit MyKeyListener(ParticleHandler &handler);
    void onKeyPressed(KeyEvent evt) override;
    void onKeyRepeat(KeyEvent evt) override;
private:
    ParticleHandler &_particleHandler;
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_MYKEYLISTENER_HPP
