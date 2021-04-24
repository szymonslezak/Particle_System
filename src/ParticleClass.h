#include <memory>
#include <vector>
#include <deque>

#pragma once
class ParticleClass
{
public:
	std::vector<std::vector<double>> m_pos;
	std::deque<std::vector<double>> m_dead_particles;
	std::vector<std::vector<double>> m_col;
	std::deque<std::vector<double>> m_dead_colors;
	std::vector<std::vector<double>> m_vel;
	std::vector<std::vector<double>> m_acc;
	std::vector<double> m_time;
	std::vector<bool> m_alive;
	std::vector<int> m_flag; //0 normal, 1 fajerwerka

	unsigned int m_count = 0;
	unsigned int m_countAlive = 0;

public:
	ParticleClass(const unsigned int& maxCount)
	{
		generate(maxCount);
	}
	ParticleClass()
	{

	}
	void add_dead_particle(const unsigned int& i);
	void generate(const unsigned int& maxSize);
	void kill(const unsigned int& id);
	void wake(const unsigned int& id);
	void swapData(const unsigned int& a,const unsigned int& b);
	void copy_last(const unsigned int& a,const unsigned int& b);

	const std::vector<std::vector<double>>* get_postions() const { return &m_pos; }
	const std::vector<std::vector<double>>* get_colors() const { return &m_col; }
	const std::vector<int>* get_flags() const { return &m_flag; }
	const std::deque<std::vector<double>>* get_dead_postions() const { return &m_dead_particles; }
	const std::deque<std::vector<double>>* get_dead_colors() const { return &m_dead_colors; }
};

