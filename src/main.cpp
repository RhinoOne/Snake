#include "..\include\SnakeGame.h"
#include <iostream>
#include <iomanip>

int main()
{ 
	system("color 0F");
	SnakeGame::instance()->start(); // паттерн Одиночка для возможности единственого входа в приложение
	
	return 0;
}