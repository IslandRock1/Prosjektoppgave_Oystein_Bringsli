//
// Created by Øystein Bringsli on 31/10/2023.
//

#include <functional>
#include <optional>

#include "Vec3.hpp"
#include "Particle.hpp"

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_GRAVITYCONTROL_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_GRAVITYCONTROL_HPP

enum GravityType {
    Between_Objects = 1,
    Center = 2,
    Ground = 3
    //No_Gravity = 4
};

class GravityControl {
public:
    Vec3 pos = {0, 0, 0};

    GravityControl(const GravityType &type);

    void resetGravity();
    std::function<void(const double &GravityStrength, const Particle& other)> addGravity;

private:
    Vec3 _gravity = {0, 0, 0};
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_GRAVITYCONTROL_HPP
