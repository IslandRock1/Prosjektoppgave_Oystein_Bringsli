//
// Created by Øystein Bringsli on 10/23/2023.
//

#include "ParticleHandler.hpp"
ParticleHandler::ParticleHandler(Vec3 bounding_box_size, int max_antall, double radius)
    : _bounding_box(bounding_box_size / 2), _antall(max_antall), _radius(radius) {}
