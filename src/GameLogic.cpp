#include "..\include\GameLogic.h"

GameLogic::GameLogic() :
	m_score (0)
{
	m_obj_food = new Food;
	m_obj_snake = new Snake;

	Attach(m_obj_food);
	Attach(m_obj_snake);
}

GameLogic::~GameLogic()
{
	Detach(m_obj_food);
	Detach(m_obj_snake);

	delete m_obj_food;
	delete m_obj_snake;
}

void GameLogic::GenerateFood()
{
	static std::default_random_engine engX(time(0)); // генерация еды в переделах поля
	static std::uniform_int_distribution<unsigned short> uniX(0, constants::WINDOW_W_S -1);

	static std::default_random_engine engY(time(0));
	static std::uniform_int_distribution<unsigned short> uniY(0, constants::WINDOW_H_S - 1);

	m_obj_food->m_x_coord = uniX(engX);
	m_obj_food->m_y_coord = uniY(engY);

	m_obj_food->drawFood(m_score); //отрисовка еды
	++m_score; // увеличить счет игрока
}

bool GameLogic::CheckFoodIntake()
{
	int tempCoord = m_obj_snake->m_coordinate[m_obj_snake->m_coordinate.end() - 2 - m_obj_snake->m_coordinate.begin()];

	if (m_obj_food->m_x_coord == m_obj_snake->m_coordinate.back() // проверка перекрытий координат головы змеи и координат еды
		&& m_obj_food->m_y_coord == tempCoord)
	{
		m_obj_snake->Eat();
		GenerateFood();

		return true;
	}

	return false;
}

bool GameLogic::CheckBodyCollision()
{
	int tempXCoord, tempYCoord;

	bool statusColl = false; //ключ для определения наличия колизии

	tempXCoord = m_obj_snake->m_coordinate[m_obj_snake->m_coordinate.end() - m_obj_snake->m_coordinate.begin() - 2]; // координаты головы змеи x и y соответсвенно
	tempYCoord = m_obj_snake->m_coordinate.back();

	for (unsigned int  keyCheck = 0; keyCheck < m_obj_snake->m_coordinate.size() - 2; keyCheck += 2) {

		if (tempXCoord == m_obj_snake->m_coordinate[keyCheck] && 
			tempYCoord == m_obj_snake->m_coordinate[keyCheck + 1]) {

			statusColl = true;
			break;
		}
	}

	return statusColl;
}

bool GameLogic::CheckWallCollision()
{
	if (m_obj_snake->m_coordinate.back() > constants::WINDOW_W_S - 1 // проверка перекрытий координат змеи с заданнными параметрами окна 
		|| m_obj_snake->m_coordinate.back() < 0						//(отсчет координат идет от левого верхнего угла)
		|| m_obj_snake->m_coordinate[m_obj_snake->m_coordinate.end() - m_obj_snake->m_coordinate.begin() - 2]<0
		|| m_obj_snake->m_coordinate[m_obj_snake->m_coordinate.end() - m_obj_snake->m_coordinate.begin() - 2]>constants::WINDOW_H_S - 1)
	{
		return true;
	}
	return false;
}