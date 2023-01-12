#include "..\include\Snake.h"

Snake::Snake():

	m_pressedButton(buttonControl::DOWN),
	m_key_avoid(buttonControl::DOWN) // Ќачальное направление змеи
{

	for (unsigned int keyInit = 0; keyInit != 2; ++keyInit)
	{
		m_coordinate.push_back(0);
		m_coordinate.push_back(keyInit); // Ќачальна инициализаци€ змеи
	}

	Eat(); // кормим чтобы было видно тело а не только голову :)
}

Snake::~Snake()
{
	m_coordinate.clear(); // чистим данные при окончании игровой сессии
}

buttonControl read()
{
	if (_kbhit())
	return static_cast<buttonControl>(_getch()); // поток читает нажатие клавиш 
}
void Snake::MotionChangeCheck() // на основании нажатой клавиши мен€е направление змеи
								// провер€ем обратную коллизию движени€
{
	if (m_pressedButton == buttonControl::DOWN && m_key_avoid != buttonControl::UP)
	{
		Move(1, direction::Vertical);
		m_key_avoid = m_pressedButton;
	}
	else if (m_pressedButton == buttonControl::UP && m_key_avoid != buttonControl::DOWN)
	{
		Move(-1, direction::Vertical);
		m_key_avoid = m_pressedButton;
	}
	else if (m_pressedButton == buttonControl::RIGHT && m_key_avoid != buttonControl::LEFT)
	{
		Move(1, direction::Horizontal);
		m_key_avoid = m_pressedButton;
	}
	else if (m_pressedButton == buttonControl::LEFT && m_key_avoid != buttonControl::RIGHT)
	{
		Move(-1, direction::Horizontal);
		m_key_avoid = m_pressedButton;
	}
}

void Snake::CheckDirectionCollision() // холостой ход змеи
{
	if (m_key_avoid != m_pressedButton) 
	{
		if (m_key_avoid == buttonControl::DOWN)
		{
			Move(1, direction::Vertical);
		}
		else if (m_key_avoid == buttonControl::UP)
		{
			Move(-1, direction::Vertical);
		}
		else if (m_key_avoid == buttonControl::RIGHT)
		{
			Move(1, direction::Horizontal);
		}
		else if (m_key_avoid == buttonControl::LEFT)
		{
			Move(-1, direction::Horizontal);
		}
	}
}
void Snake::Update()
{
	m_pressedButton = read(); //движение змеи на основнаии потока который использует паттерн Ќаблюдатель

	MotionChangeCheck();
	CheckDirectionCollision();
}

void Snake::Move(int move, unsigned short dir)
{
	if(dir == direction::Vertical) // проверка направлени€ движени€ | вертикально или горизонтально 
	{
		m_coordinate.push_back(m_coordinate[m_coordinate.end() - 2 - m_coordinate.begin()] + move);
		m_coordinate.push_back(m_coordinate[m_coordinate.end() - 2 - m_coordinate.begin()]);
	}
	else
	{
		m_coordinate.push_back(m_coordinate[m_coordinate.end() - 2 - m_coordinate.begin()] );
		m_coordinate.push_back(m_coordinate[m_coordinate.end() - 2 - m_coordinate.begin()] + move);
	}

	DrawGameObject(m_coordinate[1] + 1, m_coordinate[0] + 2, backgroundcolors::BLACK); 

	m_coordinate.erase(m_coordinate.begin()); // удалеиние змеи начина€ с хвоста дл€ имитации передвижени€
	m_coordinate.erase(m_coordinate.begin());

	DrawGameObject(m_coordinate.back()+1, m_coordinate[m_coordinate.end() - m_coordinate.begin()-2] +2, backgroundcolors::WHITE); //отрисовка головы змеи на основании полученных координат
																																 // после предыдущей операции

	DrawGameObject(m_coordinate[m_coordinate.end() - m_coordinate.begin()  -3 ] + 1, // отрисовка тела змеи
				   m_coordinate[m_coordinate.end() - m_coordinate.begin() - 4 ]  +2,
		backgroundcolors::DARKCYAN);
}

void Snake::Eat()
{
	m_coordinate.insert(m_coordinate.begin(), m_coordinate[1]); // добавление размеров змеи после поедание еды
	m_coordinate.insert(m_coordinate.begin(), m_coordinate[1]);
}