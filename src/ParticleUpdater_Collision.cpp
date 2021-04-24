#include "ParticleUpdater_Collision.h"
#include <omp.h>
#include <iostream>

void ParticleUpdater_Collision::update(const double& dt, ParticleClass& p)
{
	const int endId = p.m_countAlive;
	int i;
//#pragma omp parallel for private(i)
	for (i = (endId - 1); i > 0; i--)
	{
		if (p.m_flag[i] == 0)
		{


			//omp_set_lock(&writelock);
			std::vector<double> postion = p.m_pos[i];
			//omp_unset_lock(&writelock);
			const double d = sqrt(pow((pos[0] - postion[0]), 2) + pow((pos[1] - postion[1]), 2) + pow((pos[2] - postion[2]), 2));

			if (d >= r)
			{
				//omp_set_lock(&writelock);
				p.add_dead_particle(i);
				p.kill(i); /// 1 zamienia siê z 2 i jest tragedia fix
				//omp_unset_lock(&writelock);
			}
			else if (postion[0] >= cross_pos[0] - cross_bounds[1] && postion[0] <= cross_bounds[1] + cross_pos[0] &&
				postion[1] >= cross_pos[1] && postion[1] <= cross_bounds[0] + cross_pos[1] &&
				postion[2] >= cross_pos[2] - cross_bounds[1] && postion[2] <= cross_bounds[1] + cross_pos[2])
			{
				p.m_col[i] = { 15,82,186 };
				p.add_dead_particle(i);
				p.kill(i);
			}
			else if (postion[0] >= -cross_belk_pos[0] && postion[0] <= cross_belk_pos[0] &&
				postion[1] >= cross_belk_pos[1] - cross_bounds[1] && postion[1] <= cross_belk_pos[1] + cross_bounds[1] &&
				postion[2] >= cross_belk_pos[2] - cross_bounds[1] && postion[2] <= cross_bounds[1] + cross_belk_pos[2])
			{
				p.m_col[i] = { 15,82,186 };
				p.add_dead_particle(i);
				p.kill(i);//dodaj particle generator color na niebieski jak siê tu uderzy
			}
		}

	}
}
