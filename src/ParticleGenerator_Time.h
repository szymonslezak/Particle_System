#pragma once
#include "ParticleGenerator.h"
class ParticleGenerator_Time :
    public ParticleGenerator
{
public:
    virtual void generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos) override;
};

