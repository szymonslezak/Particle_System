#pragma once
#include "ParticleGenerator.h"
class ParticleGenerator_Positions :
    public ParticleGenerator
{
private:
    std::vector<double> spawn_position{ 0.0,0.0,0.0 };
    std::vector<double> circle_points(const double& R, const std::vector<double>& posMin, const std::vector<double>& posMax);
public:
    ParticleGenerator_Positions()
    {
        spawn_position[0] = 0.0;
        spawn_position[1] = 0.0;
        spawn_position[2] = 0.0;
    }
    ParticleGenerator_Positions(const std::vector<double> &pos)
    {
        spawn_position[0] = pos[0];
        spawn_position[1] = pos[1];
        spawn_position[2] = pos[2];
    }
    virtual void generate(const double& dt, ParticleClass& p, const double& R, const unsigned int& startId, const int& endId, const std::vector<double>& pos) override;
    void set_spawn_position(const std::vector<double> &pos)
    {
        spawn_position[0] = pos[0];
        spawn_position[1] = pos[1];
        spawn_position[2] = pos[2];
    }
};

