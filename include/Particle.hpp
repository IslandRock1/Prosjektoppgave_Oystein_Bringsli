//
// Created by Øystein Bringsli on 10/17/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP

#include "Vec3.hpp"

class Particle {
public:
    Vec3 pos;
    Vec3 vel;

    Particle(Vec3 pos, Vec3 vel);
    void Move(double dt);

};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP
