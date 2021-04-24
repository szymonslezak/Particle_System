#include "ParticleGenerator_Color.h"

void ParticleGenerator_Color::generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos)
{

	int i;
#pragma omp parallel for private(i)
	for (i = startId; i < endId; i++)
	{
		if (dt == 1.0)
			p.m_col[i] = { 166,28,46 };
		else if (dt == 2.0)
		{
			p.m_col[i] = { 0,168,107 };
		}
		else
			p.m_col[i] = { 255,255,255 };
	}
}
