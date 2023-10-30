//
// Created by Øystein Bringsli on 10/23/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP

#include <vector>
#include <array>
#include <random>
#include "Particle.hpp"

enum GravityType {
    Between_Objects = 1,
    Center = 2,
    Ground = 3,
    No_Gravity = 4
};

class ParticleHandler {
public:
    ParticleHandler(Vec3 bounding_box_size, int max_antall, double radius);

    void step(double dt);
    void makeParticle();
    void makeParticle(Vec3 pos);
    void makeParticle(Vec3 pos, Vec3 prev_pos);
    void makeParticle(Vec3 pos, Vec3 vel, double dt);
    std::vector<Particle>& getParticles();
    double getRadius() const;

private:
    int _antall;
    int _currentAntall = 0;
    double _radius;
    std::vector<Particle> _particles;

    Vec3 _startPos = {0, 0, 0};
    double _minSpeed = 0.1;
    int _time_since_last_particle = 0;
    int _time_between_particles = 60;

    GravityType _gravityType = GravityType::No_Gravity;
    double _gravityStrength = 0;

    Vec3 _bounding_box;
    int _substeps = 8;

    void addGravity();
    void handleWallColl();
    void handleCollision();
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
