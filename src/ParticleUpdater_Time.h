#pragma once
#include "ParticleUpdater.h"
class ParticleUpdater_Time
{
public:
    std::vector<std::vector<double>> update(const double& dt, ParticleClass& p);
};

