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

int Particle::getIndex() const {return _index;}

void Particle::reset_Gravity() {_gravity = {0, 0, 0};}

void Particle::add_Gravity_Ground(double gravity_strength) {
    _gravity += Vec3{0, -1, 0} * gravity_strength;
}

void Particle::add_Gravity_Center(Vec3 center_pos, double gravity_strength) {
    Vec3 direction = (center_pos - pos);
    double length = direction.length();

    _gravity += direction.norm() * (gravity_strength / (length * length));
}

void Particle::add_Gravity_Between(const Particle& p, double gravity_strength) {
    Vec3 direction = (p.pos - pos);
    double length = direction.length();

    _gravity += direction.norm() * (gravity_strength / (length * length));
}