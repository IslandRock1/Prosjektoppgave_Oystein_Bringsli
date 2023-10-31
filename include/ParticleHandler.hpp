//
// Created by Øystein Bringsli on 23/10/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP

#include <vector>
#include <array>
#include <random>
#include "Particle.hpp"

class ParticleHandler {
public:
    ParticleHandler(Vec3 bounding_box_size, int max_antall, double radius);

    void step(double dt, bool max_capacity = false);
    void makeParticle();
    std::vector<Particle>& getParticles();
    double getRadius() const;
    Vec3 getBounding() const;

    void setMinSpeed(const double &speed);
    void setTimeBetweenParticles(const int &time);
    void setGravityType(const GravityType &type);
    void setGravityStrength(const double &strenght);
    void setFriction(const double &friction);

private:
    int _antall;
    int _currentAntall = 0;
    double _radius;
    std::vector<Particle> _particles;

    Vec3 _startPos = {0, 0, 0};
    double _minSpeed = 0.01;
    int _time_since_last_particle = 0;
    int _time_between_particles = 10;

    GravityType _gravityType = GravityType::Ground;

    //Random ass numbers, looks decent
    double _gravityStrength = 1000;
    double _friction = 0.95; //speed *= _friction

    Vec3 _bounding_box;
    int _substeps = 8;

    void addGravity();
    void handleWallColl();
    void handleCollision();
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
