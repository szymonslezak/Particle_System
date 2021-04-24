#include "ParticleRenderer.h"
#include <omp.h>
#include <deque>

void ParticleRenderer::generate(ParticleSystem* sys,const double &r)
{
	assert(sys != nullptr);
	m_system = sys;
	sphere.setRadius(r);
}

void ParticleRenderer::destroy()
{
}

void ParticleRenderer::update()
{

}

void ParticleRenderer::render()
{
	//added comment
	assert(m_system != nullptr);
	int alivepar = m_system->numAliveParticles();
	if (alivepar > 0)
	{
		const std::vector<std::vector<double>>* data = m_system->get_data();
		const std::vector<int>* flags = m_system->get_flags();
		const std::vector<std::vector<double>>* colors = m_system->get_color_data();
		
		//std::cout << data->size() << std::endl;
		int i;
//#pragma omp parallel for private(i)
		for (i = 0; i < alivepar /*data->size()*/; i++)
		{
			const std::vector<double> col = colors->at(i);
			const std::vector<double>* pos = &data->at(i);
			ofSetColor(col[0],col[1],col[2]);
			if (flags->at(i) == 1)
			{
				ofDrawRectangle(pos->at(0), pos->at(1), pos->at(2), 40, 40);
			}
			else
			{
				this->sphere.setPosition(pos->at(0), pos->at(1), pos->at(2));
				this->sphere.draw();
			}


		}
		
	}
}

void ParticleRenderer::render_dead()
{
	assert(m_system != nullptr);
	const std::deque<std::vector<double>>* dead_data = m_system->get_dead_data();
	const std::deque<std::vector<double>>* dead_colors = m_system->get_dead_colors();
	int dead = dead_data->size();
	//#pragma omp parallel for private(i)
	for (int j = 0; j < dead /*data->size()*/; j++)
	{
		const std::vector<double>* pos = &dead_data->at(j);
		const std::vector<double> col = dead_colors->at(j);



		//	std::coutjk << "X:" << pos->at(0) << " Y:" << pos->at(1) << " Z:" << pos->at(2) << std::endl;
		ofSetColor(col[0], col[1], col[2]);
		this->sphere.setPosition(pos->at(0), pos->at(1), pos->at(2));
		this->sphere.draw();
		//ofDrawSphere(pos->at(0), pos->at(1), pos->at(2), 10);
	}
}
