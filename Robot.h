#pragma once
class Robot
{
public:
	Robot();
	~Robot();
	void execution();

	void setDirection(int degree);
private:
	int smell();
	bool move(int dist);
	void turn(int degree);
	void scanSensors();

	bool checkSensor(int x, int y);
	bool checkWall(int x, int y);

	int ir[8];
	int direction;
	int pos_y;
	int pos_x;
	int target;
	bool collided;

	//Fuzzy Logic Control
};

