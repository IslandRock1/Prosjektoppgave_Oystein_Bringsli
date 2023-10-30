//
// Created by Øystein Bringsli on 10/23/2023.
//

#include <iostream>
#include <cmath>
#include <random>
#include <iostream>
#include "ParticleHandler.hpp"

ParticleHandler::ParticleHandler(Vec3 bounding_box_size, int max_antall, double radius)
    : _bounding_box(bounding_box_size / 2), _antall(max_antall), _radius(radius) {}

void ParticleHandler::addGravity() {
    for (Particle &p : _particles)
    {
        p.reset_Gravity();
    }

    switch (_gravityType) {
        case GravityType::Center:
        {
            for (Particle &p : _particles)
            {
                p.add_Gravity_Center({0, 0, 0}, _gravityStrength);
            }
        } break;

        case GravityType::Ground:
        {
            for (Particle &p : _particles)
            {
                p.add_Gravity_Ground(_gravityStrength);
            }
        } break;

        case GravityType::Between_Objects:
        {
            for (Particle &p0 : _particles)
            {
                for (Particle &p1 : _particles)
                {
                    if (p0.getIndex() == p1.getIndex()) { continue;}
                    p0.add_Gravity_Between(p1, _gravityStrength);
                }
            }
        } break;
            //Ignores default as the only remaining option is No Gravity.
    }
}

void ParticleHandler::handleWallColl() {
    for (Particle &p : _particles)
    {
        if (((p.pos.x - _radius) < (-_bounding_box.x)) or ((p.pos.x + _radius) > _bounding_box.x))
        {
            Vec3 prevPos = p.getPrevPos();
            double distToPrevPos = p.pos.x - prevPos.x;
            p.pos.x = (_bounding_box.x - _radius) * ((p.pos.x > 0) - (p.pos.x < 0));
            prevPos.x = p.pos.x  + distToPrevPos * _friction;

            p.setPrevPos(prevPos);
        }

        if (((p.pos.y - _radius) < (-_bounding_box.y)) or ((p.pos.y + _radius) > _bounding_box.y))
        {
            Vec3 prevPos = p.getPrevPos();
            double distToPrevPos = p.pos.y - prevPos.y;
            p.pos.y = (_bounding_box.y - _radius) * ((p.pos.y > 0) - (p.pos.y < 0));
            prevPos.y = p.pos.y  + distToPrevPos * _friction;
            p.setPrevPos(prevPos);
        }

        if (((p.pos.z - _radius) < (-_bounding_box.z)) or ((p.pos.z + _radius) > _bounding_box.z))
        {
            Vec3 prevPos = p.getPrevPos();
            double distToPrevPos = p.pos.z - prevPos.z;
            p.pos.z = (_bounding_box.z - _radius) * ((p.pos.z > 0) - (p.pos.z < 0));
            prevPos.z = p.pos.z  + distToPrevPos * _friction;
            p.setPrevPos(prevPos);
        }
    }
}

void ParticleHandler::handleCollision() {
    for (Particle &p0 : _particles) {
        for (Particle &p1 : _particles) {

            //Makes sure that collision only happens once between particles
            //This loop will be further optimized in the future. O(n^2) is not optimal
            if (p1.getIndex() <= p0.getIndex()) { continue;}

            Vec3 axis = p0.pos - p1.pos;
            double qdist = axis.length_cube();

            if (qdist < (_radius * _radius * 4)) { //qdist => (2r)^2, = 4r^2
                axis.norm_inline();
                double delta = (_radius * 2) - std::sqrt(qdist);

                Vec3 dist_to_prev_p0 = p0.pos - p0.getPrevPos();
                Vec3 dist_to_prev_p1 = p1.pos - p1.getPrevPos();

                p0.pos += axis * 0.5 * delta;
                p1.pos -= axis * 0.5 * delta;

                //Changes speed based on the law of preservation of momentum
                p0.setPrevPos(p0.pos - dist_to_prev_p1);
                p1.setPrevPos(p1.pos - dist_to_prev_p0);

            }
        }
    }
}

void ParticleHandler::step(double dt, bool max_capasity) {

    for (int current_substep = 0; current_substep < _substeps; current_substep++) {
        addGravity();

        handleWallColl();

        handleCollision();

        for (Particle &p : _particles) {
            p.Move(dt / _substeps);
        }
    }

    if (! max_capasity) {
        if (_currentAntall < _antall) {
            makeParticle();
        }
    }
}

void ParticleHandler::makeParticle() {
    //Makes sure the particles does not spawn in on top of eachother
    _time_since_last_particle++;
    if (_time_since_last_particle < _time_between_particles) {return;}
    _time_since_last_particle = 0;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> random(0,1000);
    std::uniform_int_distribution<std::mt19937::result_type> random_bool(0, 1);

    //rand => [0, 1000] | / 1000.0 => [0, 1.0]
    double x_speed = std::max(static_cast<double>(random(rng)) / 1000.0, _minSpeed);
    double y_speed = std::max(static_cast<double>(random(rng)) / 1000.0, _minSpeed);
    double z_speed = std::max(static_cast<double>(random(rng)) / 1000.0, _minSpeed);

    //[0, 1] * 2 => [0, 2] | -1 => [-1, 1]
    x_speed *= static_cast<double>(random_bool(rng)) * 2.0 - 1.0;
    y_speed *= static_cast<double>(random_bool(rng)) * 2.0 - 1.0;
    z_speed *= static_cast<double>(random_bool(rng)) * 2.0 - 1.0;

    Vec3 prev = {_startPos.x + x_speed, _startPos.y + y_speed, _startPos.z + z_speed};
    _particles.emplace_back(_startPos, prev, _currentAntall);
    _currentAntall++;
}

void ParticleHandler::makeParticle(Vec3 pos) {
    _particles.emplace_back(pos, _currentAntall);
    _currentAntall++;
}

void ParticleHandler::makeParticle(Vec3 pos, Vec3 prev_pos) {
    _particles.emplace_back(pos, prev_pos, _currentAntall);
    _currentAntall++;
}

void ParticleHandler::makeParticle(Vec3 pos, Vec3 vel, double dt) {
    _particles.emplace_back(pos, vel, dt, _currentAntall);
    _currentAntall++;
}

std::vector<Particle>& ParticleHandler::getParticles() {
    return _particles;
}

double ParticleHandler::getRadius() const {
    return _radius;
}

Vec3 ParticleHandler::getBounding() const {
    return _bounding_box;
}