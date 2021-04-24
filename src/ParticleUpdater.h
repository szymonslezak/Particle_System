#pragma once
#include "ParticleClass.h"
#include <omp.h>
class ParticleUpdater
{
	
public:
	ParticleUpdater() {}

	virtual void update(const double& dt, ParticleClass& p) = 0;
};

