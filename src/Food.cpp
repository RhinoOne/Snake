#include "..\include\Food.h"

void Food::drawFood(int& score)
{
	DrawGameObject(m_x_coord + 1, m_y_coord + 2, backgroundcolors::DARKRED); // Отображение еды
	PrintScore(15, 0, foregroundcolors::BLUE, score); // РИсование з жестко заданными координатами счет игрока
}

void Food::PrintScore(int x, int y, unsigned short color, int score)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x,(SHORT)y };

	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, color);

	std::cout << score;
	score++; // увелечение счета
}