#include "ParticleGenerator_Time.h"

void ParticleGenerator_Time::generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos)
{
	int i;
#pragma omp parallel for private(i)
	for (i = startId; i < endId; i++)
	{
		if (p.m_flag[i] == 1)
			p.m_time[i] = 2.0;
		else if (p.m_flag[i] == 2)
			p.m_time[i] = 1.0;
		else
			p.m_time[i] = -2.0;
		//p.m_alive[i] = true;
		//p.m_countAlive += 1;
	}
}
