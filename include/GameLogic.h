#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <random>
#include <conio.h>

#include "Snake.h"
#include "Food.h"
#include "Subject.h"




class GameLogic : public Subject
{
public:
	GameLogic();

	void GenerateFood();

	bool CheckFoodIntake();

	bool CheckBodyCollision();

	bool CheckWallCollision();

	~GameLogic();

private:
	Food* m_obj_food;
	Snake* m_obj_snake;
	int m_score;
};

#endif 