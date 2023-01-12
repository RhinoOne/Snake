#include "..\include\Game.h"

Game::Game() :
	m_logic_imp(nullptr)
{

}

Game::~Game()
{
	delete m_logic_imp;
}

bool Game::PlayGameLogic()
{
	thread play(&GameLogic::Notify, m_logic_imp); // привязка объекта паттерна "Наблюдатель" для запуска игрового процесса
	this_thread::sleep_for(std::chrono::milliseconds(30)); // Прерывание потокак который отвечает за игровой процесс

	m_logic_imp->CheckFoodIntake();

	if (m_logic_imp->CheckBodyCollision() // Провекра коллизий
		|| m_logic_imp->CheckWallCollision()) {
		play.join();
		return true;
	}

	play.join(); 

	return false;
}

void WindowManagement(Scene& currentScene)
{
	thread windowControl(&Scene::SwitchWindow, std::ref(currentScene)); // поток отвечающий за управление переходами между окон
	windowControl.join();
}

void Game::Start()
{

	Scene scene;

	while (true)
	{
		m_logic_imp = new GameLogic; //Создание все что необходимо для игры

		WindowManagement(scene); // запуск потока

		if (scene.GetTypeWindow() == winType::Game) // провекра навозможность начать игровой процесс
		{
			m_logic_imp->GenerateFood();


			while (true)
			{
				WindowManagement(scene);

				if (scene.GetTypeWindow() != winType::Game) // выход из игрового процесса по нажатию кнопки
					break;

				if (PlayGameLogic()) // выход из игрового процесса по состоянию коллизий
				{
					scene.CallGameOver();
				}
			}	
		}
		delete m_logic_imp;
	}
}