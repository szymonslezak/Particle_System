#include "ParticleUpdater_Time.h"

std::vector<std::vector<double>> ParticleUpdater_Time::update(const double& dt, ParticleClass& p)
{
	std::vector<std::vector<double>> emmiter_position;
	const int endId = p.m_countAlive;
	//std::cout << endId << std::endl;
	int i;
#pragma omp parallel for private(i)
	for (i = 0; i < endId; i++)
	{
		if (p.m_time[i] > -1.0)
		{
			p.m_time[i] -= dt;
			if (p.m_time[i] <= 0.0)
			{
				if (p.m_flag[i] == 1)
				{
					emmiter_position.push_back(p.m_pos[i]);
				}
				p.kill(i);
			}
		}

	}
	return emmiter_position;
}
