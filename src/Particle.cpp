//
// Created by Øystein Bringsli on 10/17/2023.
//

#include "Vec3.hpp"
#include "Particle.hpp"

Particle::Particle(Vec3 pos, Vec3 vel, double dt, int index)
    : pos(pos), _pos_prev(pos - vel * dt), _index(index) {}

Particle::Particle(Vec3 pos, Vec3 prev_pos, int index)
    : pos(pos), _pos_prev(prev_pos), _index(index) {}

Particle::Particle(Vec3 pos, int index)
    : pos(pos), _pos_prev(pos), _index(index) {}

void Particle::Move(double dt) {
    pos = pos * 2 - _pos_prev + _gravity * dt * dt;
}
