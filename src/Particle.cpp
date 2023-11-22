//
// Created by Øystein Bringsli on 10/17/2023.
//

#include "Vec3.hpp"
#include "Particle.hpp"

Particle::Particle(Vec3 pos, Vec3 prev_pos, int index)
    : GravityObject(pos), _posPrev(prev_pos), _index(index) {}

void Particle::Move(double dt) {
    Vec3 newPrevPos = pos;
    //Uses Verlet integration instead of Eulers method for higher accuracy
    pos = pos * 2 - _posPrev + _gravity * dt * dt;
    _posPrev = newPrevPos;
}

int Particle::getIndex() const {return _index;}

Vec3 Particle::getPrevPos() {return _posPrev;}

void Particle::setPrevPos(Vec3 newPos) { _posPrev = newPos;}