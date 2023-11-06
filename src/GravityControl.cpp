//
// Created by Øystein Bringsli on 31/10/2023.
//

#include "GravityControl.hpp"

GravityControl::GravityControl() = default;

GravityControl::GravityControl(const Vec3& pos): pos(pos) {}

void GravityControl::resetGravity() {_gravity = {0, 0, 0};}

void GravityControl::addGravity(const double& GravityStrength, const GravityType& type, const GravityControl& other) {
    switch (type) {
        case GravityType::Ground: {
            _gravity += Vec3{0, -1, 0} * GravityStrength;
        } break;

        case GravityType::Center: {
            Vec3 direction = pos;
            double length = direction.length();

            _gravity -= direction.norm() * (GravityStrength / (length * length));
        } break;

        case GravityType::BetweenObjects: {
            Vec3 direction = (other.pos - pos);
            double length = direction.length();

            _gravity += direction.norm() * (GravityStrength / (length * length));
        } break;

            //Not needed to handle "NoGravity"
    }
}