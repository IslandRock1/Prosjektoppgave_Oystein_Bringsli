//
// Created by Øystein Bringsli on 17/10/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP

#include <array>
#include "Vec3.hpp"

class Particle {
public:
    Vec3 pos;

    Particle(Vec3 pos, Vec3 vel, double dt, int index);
    Particle(Vec3 pos, Vec3 prev_pos, int index);
    Particle(Vec3 pos, int index);

    void Move(double dt);
    int getIndex() const;

    Vec3 getPrevPos();
    void setPrevPos(Vec3 newPos);

    void reset_Gravity();
    void add_Gravity_Ground(double gravity_strength);
    void add_Gravity_Center(Vec3 center_pos, double gravity_strength);
    void add_Gravity_Between(const Particle &p, double gravity_strength);

private:
    Vec3 _pos_prev;
    Vec3 _gravity = {0, 0, 0};

    int _index;

    //To be used later for a more visually stimulating friction between objects. (Aka, not physically based)
    //bool coll_this_frame = false;
    //std::array<bool, 100> _past_collision = {false};
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLE_HPP
