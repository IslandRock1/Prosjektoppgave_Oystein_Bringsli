//
// Created by oyste on 10/17/2023.
//

#include "Vec3.hpp"
#include "Particle.hpp"

Particle::Particle(Vec3 pos, Vec3 vel): pos(pos), vel(vel) {};

void Particle::Move(double dt) {
    pos += vel * dt;
}