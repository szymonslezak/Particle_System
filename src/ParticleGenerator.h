#pragma once
#include <vector>
#include "ParticleClass.h"
#include <ofMath.h>
class ParticleGenerator
{

public:
	std::vector<double> m_pos{ 0.0,0.0,0.0 };
	std::vector<double> m_start_offset{ 0.0,50.0,200.0 };

public:
	ParticleGenerator()
	{

	}

	virtual ~ParticleGenerator()
	{
		delete &m_pos;
		delete &m_start_offset;
	}

	virtual void generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId,const std::vector<double> &pos) = 0;

};

