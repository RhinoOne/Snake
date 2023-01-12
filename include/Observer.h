#ifndef OBSERVER_H
#define OBSERVER_H

#include <Windows.h>
#include <conio.h>
#include <iostream>

#include "Value.h"



class Subject;

class Observer
{
public:
	virtual void Update() {};

	virtual void DrawGameObject(int, int, unsigned short);

	virtual ~Observer() {};
};

#endif