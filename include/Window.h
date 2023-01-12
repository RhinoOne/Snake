#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <iomanip> 
#include <Windows.h>
#include "Value.h"

using namespace std;

class Window
{
public:
	virtual void Draw() const {};

	virtual void SetConsoleColor(unsigned int) const;

	virtual void SetCursorPosition(int, int) const;

	virtual void HideCursor() const;

	virtual ~Window() {};

protected:
	HWND console = 0;

};

#endif 