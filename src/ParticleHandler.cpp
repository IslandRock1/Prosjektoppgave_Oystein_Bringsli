//
// Created by Øystein Bringsli on 10/23/2023.
//

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
            prevPos.x = p.pos.x  + distToPrevPos;
            p.setPrevPos(prevPos);
        }

        if ((p.pos.y < _bounding_box.y) or (p.pos.y > _bounding_box.y))
        {
            Vec3 prevPos = p.getPrevPos();
            double distToPrevPos = p.pos.y - prevPos.y;
            p.pos.y = (_bounding_box.y - _radius) * ((p.pos.y > 0) - (p.pos.y < 0));
            prevPos.y = p.pos.y  + distToPrevPos;
            p.setPrevPos(prevPos);
        }

        if ((p.pos.z < _bounding_box.z) or (p.pos.z > _bounding_box.z))
        {
            Vec3 prevPos = p.getPrevPos();
            double distToPrevPos = p.pos.z - prevPos.z;
            p.pos.z = (_bounding_box.z - _radius) * ((p.pos.z > 0) - (p.pos.z < 0));
            prevPos.z = p.pos.z  + distToPrevPos;
            p.setPrevPos(prevPos);
        }
    }
}

void ParticleHandler::step(double dt) {

    for (int current_substep = 0; current_substep < _substeps; current_substep++) {
        addGravity();

        handleWallColl();

        //Collision check and calculation here

        for (Particle &p : _particles) {
            p.Move(dt / _substeps);
        }
    }

    if (_currentAntall < _antall) {
        makeParticle();
    }
}

void ParticleHandler::makeParticle() {
    Vec3 prev = {_startPos.x + 0.1, _startPos.y, _startPos.z};
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