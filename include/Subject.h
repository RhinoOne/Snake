#ifndef SUBJECT_H
#define SUBJECT_H


#include <list>
#include <algorithm>
#include "Observer.h"



class Subject
{
public:
	virtual void Attach(Observer*);

	virtual void Detach(Observer*);

	virtual void Notify();

	virtual ~Subject() { }

protected:

	Subject() = default;

private:
	std::list<Observer*> m_observe_;
};

#endif 