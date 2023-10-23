//
// Created by Øystein Bringsli on 10/3/2023.
//

#include <cmath>
#include "Vec3.hpp"

Vec3::Vec3(double x, double y, double z)
    :x(x), y(y), z(z) {};

Vec3::Vec3(float x, float y, float z)
    :x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z)){};

Vec3::Vec3(int x, int y, int z)
    :x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z)){};

Vec3 Vec3::operator+(const Vec3 &other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vec3 Vec3::operator-(const Vec3 &other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vec3& Vec3::operator+=(const Vec3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

double Vec3::length_cube() const {
    return x * x + y * y + z * z;
}

double Vec3::length() const {
    //Unnecessary to invoke length_cube() function
    return std::cbrt(x * x + y * y + z * z);
}

Vec3 Vec3::norm() const {
    return Vec3(x, y, z) / length();
}

Vec3& Vec3::norm_inline() {
    *this /= length();
    return *this;
}