#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "Game.h"

class SnakeGame
{
public:
	SnakeGame(const SnakeGame&) = delete;

	SnakeGame& operator=(const SnakeGame&) = delete;

	

	static SnakeGame* instance();

	void start() 
	{
		m_game.Start(); 
	}

	~SnakeGame();

protected:
	SnakeGame() = default;

private:
	static SnakeGame* m_instance;
	Game m_game;
};

#endif