#ifndef FOOD_H
#define FOOD_H

#include "Observer.h"

class Food : public Observer
{
public:
	Food() = default;

	void drawFood(int&);

	friend class GameLogic;

private:
	void PrintScore(int, int, unsigned short, int);\

private:
	int m_x_coord;
	int m_y_coord;
};

#endif 
