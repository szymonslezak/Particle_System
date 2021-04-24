#include "ParticleGenerator_Positions.h"

std::vector<double> ParticleGenerator_Positions::circle_points(const double& R, const std::vector<double>& posMin, const std::vector<double>& posMax)
{

	std::vector<double> rng{ 0.0,0.0,0.0 };
	const float a = ofRandom(0, 1);
	const float b = ofRandom(0, 1);

	const double a_pos = ofRandom(posMin[0], posMax[0]);
	const double b_pos = ofRandom(posMin[1], posMax[1]);
	const double c_pos = ofRandom(posMin[2], posMax[2]);
	rng[0] = b * R * cos(2 * 3.14 * a / b) + a_pos + spawn_position[0];
	rng[2] = c_pos + spawn_position[2];
	rng[1] = b * R * sin(2 * 3.14 * a / b) + b_pos+spawn_position[1];
	return rng;
}

void ParticleGenerator_Positions::generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos)
{

	std::vector<double> posMin{ pos[0] - m_start_offset[0],
								pos[1] - m_start_offset[1],
								pos[2] - m_start_offset[2] };
	std::vector<double> posMax{ pos[0] + m_start_offset[0],
									pos[1] + m_start_offset[1],
									pos[2] + m_start_offset[2] };
	int i;
#pragma omp parallel for private(i)
	for (i = startId; i < endId; i++)
	{
		p.m_pos[i] = circle_points(R, posMin, posMax);
	} //Generator for each required function is needed
}
