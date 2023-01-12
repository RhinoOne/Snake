#include "..\include\Subject.h"


void UpdateCurrentObs(Observer* obs)
{
	obs->Update();
}

void Subject::Attach(Observer* obs)
{
	m_observe_.push_back(obs); // Добавить объект под наблюдение
}

void Subject::Detach(Observer* obs) 
{
	m_observe_.remove(obs); // убрать объtrn из-под наблюдения
}

void Subject::Notify()
{
	std::for_each(m_observe_.begin(),
		m_observe_.end(), UpdateCurrentObs ); // Обновление каждого объекта который находится под наблюдением
}