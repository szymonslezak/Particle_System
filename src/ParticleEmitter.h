#pragma once
#include "ParticleClass.h"
#include "ParticleGenerator.h"
class ParticleEmitter
{
	std::vector<std::shared_ptr<ParticleGenerator>> m_generators;
	std::vector<double> spawn_position{ 0.0,0.0,0.0 };
	double radius = 0.0;
	size_t id = 0;
	double lifetime = -1.0;
	double _dt = 0.0;
public:
	float m_emitRate = 10.0;

	ParticleEmitter() {}

	ParticleEmitter(const float &em)
	{
		m_emitRate = em;
	}
	ParticleEmitter(const float& em,const std::vector<double>& pos)
	{
		m_emitRate = em;
		spawn_position[0] = pos[0];
		spawn_position[1] = pos[1];
		spawn_position[2] = pos[2];
	}
	ParticleEmitter(const float& em, const std::vector<double>& pos,double time)
	{
		m_emitRate = em;
		spawn_position[0] = pos[0];
		spawn_position[1] = pos[1];
		spawn_position[2] = pos[2];
		lifetime = time;
	}
	ParticleEmitter(const float& em, const std::vector<double>& pos, double time, double t)
	{
		m_emitRate = em;
		spawn_position[0] = pos[0];
		spawn_position[1] = pos[1];
		spawn_position[2] = pos[2];
		lifetime = time;
		_dt = t;
	}

	virtual void addGenerator(std::shared_ptr<ParticleGenerator> gen) { m_generators.push_back(gen); }
	virtual bool emit(const double& dt, ParticleClass& p);
	void set_radius(const double &r) { radius = r; }

};

