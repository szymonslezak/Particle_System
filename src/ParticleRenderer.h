#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"

class ParticleRenderer
{
	ofSpherePrimitive sphere;
	ParticleSystem * m_system = nullptr;
	unsigned int m_X = 0;
	unsigned int m_Y = 0;
	unsigned int m_Z = 0;
	unsigned int m_vao = 0;

public:
	ParticleRenderer()
	{
		sphere.setRadius(1);
	}

	void generate(ParticleSystem * sys,const double &r);
	void destroy();
	void update();
	void render();
	void render_dead();
};

