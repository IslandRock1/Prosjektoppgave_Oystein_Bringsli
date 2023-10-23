//
// Created by Øystein Bringsli on 10/3/2023.
//

#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_VEC3_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_VEC3_HPP

class Vec3 {
public:
    Vec3(double x, double y, double z);
    Vec3(float x, float y, float z);
    Vec3(int x, int y, int z);

    Vec3 operator+(const Vec3 &other) const;
    Vec3 operator-(const Vec3 &other) const;

    Vec3& operator+=(const Vec3 &other);
    Vec3& operator-=(const Vec3 &other);

    template<class T>
    Vec3 operator +(T other) const;
    template<class T>
    Vec3 operator -(T other) const;
    template<class T>
    Vec3 operator *(T other) const;
    template<class T>
    Vec3 operator /(T other) const;

    template <typename T>
    Vec3& operator+=(T other);
    template <typename T>
    Vec3& operator-=(T other);
    template <typename T>
    Vec3& operator*=(T other);
    template <typename T>
    Vec3& operator/=(T other);

    double x;
    double y;
    double z;
};

template<class T>
Vec3 Vec3::operator+(T other) const {
    return {x + other, y + other, z + other};
}

template<class T>
Vec3 Vec3::operator-(T other) const {
    return {x - other, y - other, z - other};
}

template<class T>
Vec3 Vec3::operator*(T other) const {
    return {x * other, y * other, z * other};
}

template<class T>
Vec3 Vec3::operator/(T other) const {
    return {x / other, y / other, z / other};
}

template<typename T>
Vec3& Vec3::operator+=(T other) {
    x += other;
    y += other;
    z += other;
    return *this;
}

template<typename T>
Vec3& Vec3::operator-=(T other) {
    x -= other;
    y -= other;
    z -= other;
    return *this;
}

template<typename T>
Vec3& Vec3::operator*=(T other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
}

template<typename T>
Vec3& Vec3::operator/=(T other) {
    x /= other;
    y /= other;
    z /= other;
    return *this;
}


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_VEC3_HPP
