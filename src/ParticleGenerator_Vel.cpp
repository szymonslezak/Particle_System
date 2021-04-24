#include "ParticleGenerator_Vel.h"

std::vector<double> ParticleGenerator_Vel::circle_points(const double& R,const std::vector<double> &spawn_position)
{
	std::vector<double> rng{ 0.0,0.0,0.0 };
	const float a = ofRandom(0, 1);
	const float b = ofRandom(0, 1);

	const double a_pos = ofRandom(-300, 300);
	const double b_pos = ofRandom(-300, 300);
	const double c_pos = ofRandom(-100,100);
	const double check = ofRandom(0, 2);
	rng[0] = b * R * cos(2 * 3.14 * a / b) + a_pos + spawn_position[0];
	if (check > 1)
		rng[0] = -rng[0];
	rng[2] = c_pos + spawn_position[2];
	rng[1] = b * R * sin(2 * 3.14 * a / b) + b_pos + spawn_position[1];
	return rng;
}

void ParticleGenerator_Vel::generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos)
{
	int i;
#pragma openmp parallel for private(i)
	for (i = startId; i < endId; i++)
	{
		if (p.m_flag[i] == 1)
		{
			p.m_vel[i] = std::vector<double>{ 2,300.0,0.0 };
		}
		else if (p.m_flag[i] == 2)
		{
			p.m_vel[i] = circle_points(30,p.m_pos[i]);
		}
		else
			p.m_vel[i] = std::vector<double>{ 0.0,0.0,0.0 };
	} 
}
