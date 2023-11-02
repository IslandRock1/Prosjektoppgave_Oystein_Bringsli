//
// Created by Øystein Bringsli on 10/17/2023.
//

#include "Vec3.hpp"
#include "Particle.hpp"

Particle::Particle(Vec3 pos, Vec3 prev_pos, int index)
    : GravityControl(pos), _pos_prev(prev_pos), _index(index) {}

void Particle::Move(double dt) {
    Vec3 newPrevPos = pos;
    //Uses Verlet integration instead of Eulers method for higher accuracy
    pos = pos * 2 - _pos_prev + _gravity * dt * dt;
    _pos_prev = newPrevPos;
}

int Particle::getIndex() const {return _index;}

Vec3 Particle::getPrevPos() {return _pos_prev;}

void Particle::setPrevPos(Vec3 newPos) {_pos_prev = newPos;}