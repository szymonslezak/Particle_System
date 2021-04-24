#pragma once
#include "ParticleGenerator.h"
class ParticleGenerator_Flag :
    public ParticleGenerator
{
public:
    virtual void generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos) override;
};

