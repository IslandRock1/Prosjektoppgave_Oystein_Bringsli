//
// Created by Øystein Bringsli on 10/3/2023.
//

#include "../include/Vec3.hpp"

Vec3::Vec3(double x, double y, double z)
    :x(x), y(y), z(z) {};

Vec3::Vec3(float x, float y, float z)
    :x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z)){};

Vec3::Vec3(int x, int y, int z)
    :x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z)){};

void Vec3::operator+(const Vec3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
}

void Vec3::operator-(const Vec3 &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

void Vec3::operator*(const Vec3 &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
}

void Vec3::operator/(const Vec3 &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
}