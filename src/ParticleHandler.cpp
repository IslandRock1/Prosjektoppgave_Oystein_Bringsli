//
// Created by Øystein Bringsli on 10/23/2023.
//

#include <iostream>
#include <cmath>
#include <random>
#include "ParticleHandler.hpp"

ParticleHandler::ParticleHandler(Vec3 bounding_box_size, int max_antall, double radius)
    : _bounding_box(bounding_box_size / 2), _antall(max_antall), _radius(radius) {
    _startPos.y = _bounding_box.y * 0.8;
}

void ParticleHandler::addGravity() {
    for (Particle &p : _particles)
    {
        p.resetGravity();
    }

    if (_gravityType == GravityType::BetweenObjects)
    {
        for (Particle &p0 : _particles)
        {
            for (Particle &p1 : _particles)
            {
                if (p0.getIndex() >= p1.getIndex()) { continue;}

                p0.addGravity(_gravityStrength, _gravityType, p1);
                p1.addGravity(_gravityStrength, _gravityType, p0);
            }
        }
    } else {
        for (Particle& p : _particles) {
            p.addGravity(_gravityStrength, _gravityType);
        }
    }
}

void ParticleHandler::handleWallColl() {
    for (Particle &p : _particles)
    {
        //Could be separate functions, maybe a single function too
        //But would need to know witch axis hits the wall
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
                p0.setPrevPos(p0.pos - dist_to_prev_p1 * _friction);
                p1.setPrevPos(p1.pos - dist_to_prev_p0 * _friction);

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
    //Makes sure the particles does not spawn in on top of each-other
    _time_since_last_particle++;
    if (_time_since_last_particle < _time_between_particles) {return;}
    _time_since_last_particle = 0;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::mt19937 rng2(dev());
    int rand_size = 1000;
    std::uniform_int_distribution<std::mt19937::result_type> random(0,rand_size);
    std::uniform_int_distribution<std::mt19937::result_type> random_bool(0, 1);

    float divisor = static_cast<float>(rand_size) / _minSpeed;

    //rand => [0, 1000] | / 10000.0 => [0, 0.1]
    double x_speed = static_cast<double>(random(rng)) / divisor;
    //double y_speed = std::max(static_cast<double>(random(rng)) / 10000.0, _minSpeed);
    double z_speed = static_cast<double>(random(rng2)) / divisor;

    //[0, 1] * 2 => [0, 2] | -1 => [-1, 1]
    x_speed *= static_cast<double>(random_bool(rng)) * 2.0 - 1.0;
    //y_speed *= static_cast<double>(random_bool(rng)) * 2.0 - 1.0;
    z_speed *= static_cast<double>(random_bool(rng)) * 2.0 - 1.0;

    //Creates a random speed, with random direction.
    Vec3 prev = {_startPos.x + x_speed, _startPos.y, _startPos.z + z_speed};
    _particles.emplace_back(_startPos, prev, _currentAntall);
    _currentAntall++;
}

std::vector<Particle>& ParticleHandler::getParticles() {return _particles;}
double ParticleHandler::getRadius() const {return _radius;}
Vec3 ParticleHandler::getBounding() const {return _bounding_box;}
void ParticleHandler::setMinSpeed(const double& speed) {_minSpeed = speed;}
void ParticleHandler::setTimeBetweenParticles(const int& time) {_time_between_particles = time;}
void ParticleHandler::setGravityType(const GravityType& type) {_gravityType = type;}
void ParticleHandler::setGravityStrength(const double& strenght) {_gravityStrength = strenght;}
void ParticleHandler::setFriction(const double& friction) {_friction = friction;}
void ParticleHandler::setSubSteps(const int& SubSteps) {_substeps = SubSteps;}