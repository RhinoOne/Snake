#ifndef GAME_W_H
#define GAME_W_H

#include "..\include\Window.h"
#include "Food.h"
#include "Snake.h"


class GameWindow : public  Window
{
public:
	void Draw() const override;

	~GameWindow();

private:
	void DrawTitleWindow() const;
};

#endif 