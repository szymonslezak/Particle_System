#include "ParticleClass.h"

void ParticleClass::add_dead_particle(const unsigned int& i)
{
	if (m_dead_particles.size() >= 2 * m_count)
	{
		m_dead_particles.pop_back();
		m_dead_colors.pop_back();
	}
	else
	{

		m_dead_particles.push_front(m_pos[i]);
		m_dead_colors.push_front(m_col[i]);
	}
}

void ParticleClass::generate(const unsigned int& maxSize)
{
	m_count = maxSize;
	m_countAlive = 0;
	m_pos.clear();
	m_col.clear();
	m_vel.clear();
	m_acc.clear();
	m_time.clear();
	m_alive.clear();

	m_pos.resize(maxSize, std::vector<double>{0.0, 0.0, 0.0});
	m_vel.resize(maxSize, std::vector<double>{0.0, 0.0, 0.0});
	m_acc.resize(maxSize, std::vector<double>{0.0, 0.0, 0.0});
	m_time.resize(maxSize, 0.0);
	m_alive.resize(maxSize, false);
	m_col.resize(maxSize, std::vector<double>{0.0, 0.0, 0.0});
	m_flag.resize(maxSize,0);
}

void ParticleClass::kill(const unsigned int& id)
{//critial here
	if (this->m_countAlive > 0)
	{
		m_alive[id] = false;
		copy_last(id, m_countAlive - 1);
		m_countAlive--;
	}
}

void ParticleClass::wake(const unsigned int& id)
{// critical here plus prolly while(changed == true))
	if (m_countAlive < m_count)
	{
		m_alive[id] = true;
		copy_last(id, m_countAlive);
		m_countAlive++;
	}
}

void ParticleClass::swapData(const unsigned int& a,const unsigned int& b)
{
	std::swap(m_pos[a], m_pos[b]);
	std::swap(m_col[a], m_col[b]);
	std::swap(m_vel[a], m_vel[b]);
	std::swap(m_acc[a], m_acc[b]);
	std::swap(m_time[a], m_time[b]);
	std::swap(m_alive[a], m_alive[b]);

}

void ParticleClass::copy_last(const unsigned int& a,const unsigned int& b)
{
	m_pos[a] = m_pos[b];
	m_col[a] = m_col[b];
	m_vel[a] = m_vel[b];
	m_acc[a] = m_acc[b];
	m_time[a] = m_time[b];
	m_alive[a] = m_alive[b];
	m_flag[a] = m_flag[b];
}
