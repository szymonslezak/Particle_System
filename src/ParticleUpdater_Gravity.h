#pragma once
#include "ParticleUpdater.h"
#include <omp.h>
class ParticleUpdater_Gravity :
    public ParticleUpdater
{
    std::vector<double> acceleration = { 0.0,-9.81,0.0 };
public:
    virtual void update(const double& dt, ParticleClass& p) override;
    void set_acceleration(const double& acc, const int& index);
};

