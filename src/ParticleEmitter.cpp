#include "ParticleEmitter.h"
#include <iostream>

bool ParticleEmitter::emit(const double& dt, ParticleClass& p)
{
	if (lifetime <= -1.0 || lifetime > 0.0)
	{
		unsigned int maxNewParticles = dt * m_emitRate;
		if (maxNewParticles == 0)
			maxNewParticles = 1;
		const unsigned int startId = p.m_countAlive;
		//const size_t startId = id;
		const size_t endId = std::min(startId + maxNewParticles, p.m_count - 1);
		//std::cout << "start: " << startId << " endId: " << endId << std::endl;

		for (auto& gen : m_generators)
		{
			if (_dt != 0)
				gen->generate(_dt, p, radius, startId, endId, spawn_position);
			else
			{
				gen->generate(dt, p, radius, startId, endId, spawn_position);
			}

		}
		for (unsigned int i = startId; i < endId; i++)
		{
			//std::cout << "waking" << std::endl;
			p.wake(i);
		}
		if (lifetime > -1.0)
		{
			lifetime -= dt;
			if (lifetime < 0.0)
			{
				return true;
			}
		}
		return false;
	}
	return false;
}
