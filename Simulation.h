#pragma once
#include<vector>
#include<utility>
#include"Robot.h"
class Simulation
{
public:
	Simulation();
	~Simulation();
	void frameAdvance();
	//map
	int mapBoundaryXlow = 10;
	int mapBoundaryXhigh = 750;
	int mapBoundaryYlow = 10;
	int mapBoundaryYhigh = 410;
private:
	//time
	int Step = 0;
	
	//obstrucle box
	std::vector<int> box_xlow;
	std::vector<int> box_xhigh;
	std::vector<int> box_ylow;
	std::vector<int> box_yhigh;
	//robot
	std::vector<Robot> bots;
	bool robotCollision = false;
	//food
	std::vector<std::pair<int, int>> foods;
};

