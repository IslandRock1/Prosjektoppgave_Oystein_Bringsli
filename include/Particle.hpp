//
// Created by Øystein Bringsli on 17/10/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP

#include <array>
#include "Vec3.hpp"
#include "GravityControl.hpp"

class Particle: public GravityControl {
public:
    Particle(Vec3 pos, Vec3 prev_pos, int index);

    void Move(double dt);
    int getIndex() const;

    Vec3 getPrevPos();
    void setPrevPos(Vec3 newPos);

private:
    Vec3 _posPrev = {0, 0, 0};
    int _index;
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP
