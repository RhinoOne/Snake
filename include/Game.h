#ifndef GAME_H
#define GAME_H

#include <thread>
#include <chrono>

#include "Scene.h"
#include "GameLogic.h"


class Game
{
public:
	Game();

	void Start();

	~Game();

private:
	bool PlayGameLogic();

private:
	GameLogic *m_logic_imp;
};

#endif
