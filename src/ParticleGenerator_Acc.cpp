#include "ParticleGenerator_Acc.h"

void ParticleGenerator_Acc::generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos)
{
	int i;
#pragma omp parallel for private(i)
	for (i = startId; i < endId; i++)
	{
		p.m_acc[i] = std::vector<double>{ 0.0,0.0,0.0 };
	}
}
