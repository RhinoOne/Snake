#include "..\include\SnakeGame.h"

SnakeGame* SnakeGame::m_instance = nullptr;

SnakeGame* SnakeGame::instance()
{
	if (m_instance == nullptr)
		m_instance = new SnakeGame();

	return m_instance;
}

SnakeGame::~SnakeGame() 
{ 
	delete m_instance;
}