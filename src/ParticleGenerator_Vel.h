#pragma once
#include "ParticleGenerator.h"
class ParticleGenerator_Vel :
    public ParticleGenerator
{
    std::vector<double> circle_points(const double& R, const std::vector<double>& spawn_position);
public:
    virtual void generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos) override;
};

