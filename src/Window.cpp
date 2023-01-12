#include "..\include\Window.h"

void Window::SetConsoleColor(unsigned int color) const
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();

	SetConsoleTextAttribute(hOut, color);
}

void Window::HideCursor() const
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	cursorInfo.dwSize = 10;
	cursorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void Window::SetCursorPosition(int x, int y) const
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();

	COORD coord = {(SHORT)x,(SHORT)y};
	SetConsoleCursorPosition(hOut, coord);
}