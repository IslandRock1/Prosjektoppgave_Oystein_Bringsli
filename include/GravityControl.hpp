//
// Created by Øystein Bringsli on 31/10/2023.
//

#include <functional>
#include <optional>

#include "Vec3.hpp"

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_GRAVITYCONTROL_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_GRAVITYCONTROL_HPP

enum GravityType {
    Ground = 0,
    Center = 1,
    BetweenObjects = 2,
    NoGravity = 3
};

class GravityControl {
public:
    Vec3 pos = {0, 0, 0};

    GravityControl();
    GravityControl(const Vec3 &pos);

    void resetGravity();
    void addGravity(const double &GravityStrength, const GravityType &type, const GravityControl &other = GravityControl());

protected:
    Vec3 _gravity = {0, 0, 0};
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_GRAVITYCONTROL_HPP
