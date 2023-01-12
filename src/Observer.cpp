#include "..\include\Observer.h"

void Observer::DrawGameObject(int x, int y, unsigned short color)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x,(SHORT)y };

	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, color);

	std::cout << " ";
}