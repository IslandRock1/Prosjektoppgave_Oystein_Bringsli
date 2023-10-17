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

    void operator+(const Vec3 &other);
    void operator-(const Vec3 &other);
    void operator*(const Vec3 &other);
    void operator/(const Vec3 &other);

    template <typename T>
    void operator+(T other);
    template <typename T>
    void operator-(T other);
    template <typename T>
    void operator*(T other);
    template <typename T>
    void operator/(T other);

    double x, y, z;
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_VEC3_HPP
