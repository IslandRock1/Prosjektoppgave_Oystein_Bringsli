//
// Created by Øystein Bringsli on 31/10/2023.
//

#include "GravityControl.hpp"

GravityControl::GravityControl(const GravityType &type) {
    switch (type) {
        case GravityType::Center:
            addGravity = [this](const double &GravityStrength, const Particle &other = Particle()) {
                Vec3 direction = pos;
                double length = direction.length();

                _gravity += direction.norm() * (GravityStrength / (length * length));
            };
        case GravityType::Ground:
            addGravity = [this](const double &GravityStrength, const Particle &other = Particle()) {
                _gravity += Vec3{0, -1, 0} * GravityStrength;
            };
        case GravityType::Between_Objects:
            addGravity = [this](const double &GravityStrength, const Particle &other = Particle()) {
                Vec3 direction = (other.pos - pos);
                double length = direction.length();

                _gravity += direction.norm() * (GravityStrength / (length * length));
            };
    }
}

void GravityControl::resetGravity() {_gravity = {0, 0, 0};}