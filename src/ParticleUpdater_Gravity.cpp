#include "ParticleUpdater_Gravity.h"
#include <iostream>

void ParticleUpdater_Gravity::update(const double& dt, ParticleClass& p)
{
	const int endId = p.m_countAlive;
	//std::cout << endId << std::endl;
	int i;
#pragma omp parallel for private(i)
	for (i = 0; i < endId; i++)
	{
		if (p.m_alive[i])
		{
			//std::cout << "I am here" << std::endl;
			p.m_acc[i] = acceleration;
			p.m_vel[i][0] += dt * p.m_acc[i][0];
			p.m_vel[i][1] += dt * p.m_acc[i][1];
			p.m_vel[i][2] += dt * p.m_acc[i][2];
			p.m_pos[i][0] += dt * p.m_vel[i][0];
			p.m_pos[i][1] += dt * p.m_vel[i][1];
			p.m_pos[i][2] += dt * p.m_vel[i][2];
		}

	}
}

void ParticleUpdater_Gravity::set_acceleration(const double& acc, const int& index)
{
	acceleration[index] = acc;
}
