#ifndef SNAKE_H
#define SNAKE_H

#include "Observer.h"

typedef buttons::snakeControl buttonControl;

class Snake : public Observer
{
public:
	Snake();

	void Update() override;

	void Eat();

	void Move(int move, unsigned short);
	
	~Snake();

	friend class GameLogic;

private:
	void MotionChangeCheck();

	void CheckDirectionCollision();

private:
	std::vector<int> m_coordinate;
	buttonControl m_pressedButton;
	buttonControl m_key_avoid;
};

#endif 
