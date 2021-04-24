#pragma once
#include "ParticleUpdater.h"
#include <omp.h>

class ParticleUpdater_Collision :
    public ParticleUpdater
{
    std::vector<double> pos;
    double r;
    omp_lock_t writelock;
    std::vector<double> cross_pos = { 0.0,-400.0,-100.0 };
    std::vector<double> cross_belk_pos = { 150.0,-200.0,-100.0 };
    std::vector<double> cross_bounds{ 300.0,20.0 }; //poz height,belk_y,belk_x,grub

public:
    ParticleUpdater_Collision(const double &R, const std::vector<double> &p)
    {
        r = R;
        pos = p;
        omp_init_lock(&writelock);
    }
    ParticleUpdater_Collision(const double& R)
    {
        r = R;
        pos = { 0.0,0.0,0.0 };
        //omp_init_lock(&writelock);
    }
    virtual void update(const double& dt, ParticleClass& p) override;
    void set_r(const double &R)
    {
        r = R;
    }
};

