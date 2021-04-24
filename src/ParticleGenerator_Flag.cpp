#include "ParticleGenerator_Flag.h"

void ParticleGenerator_Flag::generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos)
{
	int i;
#pragma omp parallel for private(i)
	for (i = startId; i < endId; i++)
	{
		if (dt == 1.0)
			p.m_flag[i] = 1;
		else if (dt == 2.0)
			p.m_flag[i] = 2;
		else
			p.m_flag[i] = 0;
	}
}
