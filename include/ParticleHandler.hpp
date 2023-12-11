
#ifndef PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
#define PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP

#include <vector>
#include <array>
#include <random>
#include "Particle.hpp"

class ParticleHandler {
public:
    ParticleHandler(Vec3 bounding_box_size, int max_antall, double radius);

    void step(double dt);
    void makeParticle();
    std::vector<Particle>& getParticles();
    double getRadius() const;
    Vec3 getBounding() const;

    void setMinSpeed(const double &speed);
    void setTimeBetweenParticles(const int &time);
    void setGravityType(const GravityType &type);
    void setGravityStrength(const double &strenght);
    void setFriction(const double &friction);
    void setSubSteps(const int &SubSteps);

    void addToMaxAntall(signed int deltaAntall);
    int getAntall() const;
    int getCurrentAntall() const;
    void addToStartPos(const Vec3& deltaPosition);
    Vec3 getStartPos();

    bool showPreview = false;

private:
    int _antall;
    int _currentAntall = 0;
    double _radius;
    std::vector<Particle> _particles;

    Vec3 _startPos = {0, 0, 0};
    double _minSpeed = 0.01;
    int _timeSinceLastParticle = 0;
    int _timeBetweenParticles = 10;

    GravityType _gravityType = GravityType::Ground;

    //Random ass numbers, looks decent
    double _gravityStrength = 1000;
    double _friction = 0.95; //speed *= _friction

    Vec3 _boundingBox;
    int _substeps = 8;

    void addGravity();
    void handleWallColl();
    void handleCollision();
};


#endif//PROSJEKTOPPGAVE_OYSTEIN_BRINGSLI_PARTICLEHANDLER_HPP
