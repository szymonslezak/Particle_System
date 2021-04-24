#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(const int& maxCount)
{
	m_count = maxCount;
	m_particles.generate(maxCount);
	//m_aliveParticles.generate(maxCount);
	int i;
#pragma omp parallel for private(i)
	for (i = 0; i < maxCount; i++)
	{
		m_particles.m_alive[i] = false;
	}
}

void ParticleSystem::update(const double& dt)
{
	/*std::vector<int> kill_emit;
	for (size_t i = 0; i < m_emmiter.size(); i++)
	{
		auto& em = m_emmiter[i];
		if (em->emit(dt, m_particles))
		{
			kill_emit.push_back(i);
		}
	}*/
	for (auto& em : m_emmiter)
	{
		em->emit(dt, m_particles);
	}/*
	if (kill_emit.size() > 0) {
		for (size_t i = 0; i < kill_emit.size(); i++)
		{
			int j = kill_emit[i] - i;
			m_emmiter.erase(m_emmiter.begin() + j);// - i bo siê zmienia wektor
		}
	}*/
	/*for (unsigned int i = 0; i < m_count; i++)
	{
		m_particles.m_acc[i] = std::vector<double>{0.01,0.0,0.0 };
	}*/
	for (auto& up : m_updater)
	{
		up->update(dt, m_particles);
	}
	if (m_time_udpater != nullptr)
	{
		std::vector<std::vector<double>> emit_pos = m_time_udpater->update(dt, m_particles);
		for (size_t i = 0; i < emit_pos.size(); i++)
		{
			std::shared_ptr<ParticleEmitter> emitter(new ParticleEmitter(2000,emit_pos[i],0.01,2.0));
			std::shared_ptr<ParticleGenerator_Flag> gen_flag(new ParticleGenerator_Flag());
			std::shared_ptr<ParticleGenerator_Color> gen_col(new ParticleGenerator_Color());
			std::shared_ptr<ParticleGenerator_Vel> gen_vel(new ParticleGenerator_Vel());
			std::shared_ptr<ParticleGenerator_Acc> gen_acc(new ParticleGenerator_Acc());
			std::shared_ptr<ParticleGenerator_Positions> gen_pos(new ParticleGenerator_Positions());
			std::shared_ptr<ParticleGenerator_Time> gen_time(new ParticleGenerator_Time());

			emitter->addGenerator(gen_flag);
			emitter->addGenerator(gen_col);
			emitter->addGenerator(gen_pos);
			emitter->addGenerator(gen_vel);
			emitter->addGenerator(gen_acc);
			emitter->addGenerator(gen_time);
			m_emmiter.push_back(emitter);
		}
	}
}

void ParticleSystem::reset()
{
	m_particles.m_countAlive = 0;
}
