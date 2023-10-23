//
// Created by Øystein Bringsli on 10/17/2023.
//

#include "Vec3.hpp"
#include "Particle.hpp"

Particle::Particle(Vec3 pos, Vec3 vel, double dt, int index)
    : pos(pos), _pos_prev(pos), _index(index) {}; //_pos_prev(pos - vel * dt)

Particle::Particle(Vec3 pos, int index)
    : pos(pos), _pos_prev(pos), _index(index) {}

void Particle::Move(double dt) {
    pos = Vec3(0, 0, 0); //pos * 2 - _pos_prev + _gravity * dt * dt;
}
