#pragma once
#include "ParticleClass.h"
#include "ParticleEmitter.h"
#include "ParticleUpdater.h"
#include "ParticleUpdater_Time.h"
#include "ParticleGenerator.h"
#include "ParticleGenerator_Acc.h"
#include "ParticleGenerator_Vel.h"
#include "ParticleGenerator_Positions.h"
#include "ParticleGenerator_Time.h"
#include "ParticleGenerator_Color.h"
#include "ParticleGenerator_Flag.h"
#include <deque>

#include <memory>
class ParticleSystem
{
	
	ParticleClass m_particles;
	ParticleClass m_aliveParticles;
	unsigned int m_count;
	std::vector<std::shared_ptr<ParticleEmitter>> m_emmiter;
	std::vector<std::shared_ptr<ParticleUpdater>> m_updater;
	std::shared_ptr<ParticleUpdater_Time> m_time_udpater;

public:
	ParticleSystem()
	{

	}
	ParticleSystem(const int& maxCount);
	void update(const double& dt);
	void reset();
	unsigned int numAllParticles() const{ return m_particles.m_count; }
	unsigned int numAliveParticles() const{ return m_particles.m_countAlive; }

	void addEmitter(std::shared_ptr<ParticleEmitter> em) { m_emmiter.push_back(em); }
	void addUpdater(std::shared_ptr<ParticleUpdater> em) { m_updater.push_back(em); }
	void setTimeUpdater(std::shared_ptr<ParticleUpdater_Time> em) { m_time_udpater = em; }

	ParticleClass* get_particles() { return &m_particles; }
	const std::vector<std::vector<double>>* get_data() const { return m_particles.get_postions(); }
	const std::deque<std::vector<double>>* get_dead_data() const { return m_particles.get_dead_postions(); }
	const std::deque<std::vector<double>>* get_dead_colors() const { return m_particles.get_dead_colors(); }
	const std::vector<std::vector<double>>* get_color_data() const { return m_particles.get_colors(); }
	const std::vector<int>* get_flags() const { return m_particles.get_flags(); }

};

