//
// Created by Øystein Bringsli on 10/23/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP

#include <vector>
#include <array>
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
    void makeParticle(Vec3 pos)
    std::vector<Particle> getParticles();

private:
    int _antall;
    double _radius;

    GravityType _gravityType = GravityType::No_Gravity;
    Vec3 _gravityStrength = {0, 0, 0};

    Vec3 _bounding_box;
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
