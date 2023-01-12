#include "..\include\Scene.h"

Scene::Scene() :
	m_type_win(winType::Menu),
	m_window_imp(nullptr),
	m_key_init_win (true)
{
	InitWindow();
}

void Scene::InitWindow() // создание определенного окна
{
	if (m_window_imp != nullptr)
	{
		delete m_window_imp; // предотвращение утчеки памяти из предыдущих окон 
	}	

	if (m_key_init_win) 
	{
		switch (m_type_win)
		{
		case winType::Menu:

			m_window_imp = new MenuWindow;
			m_type_win = winType::Menu;
			m_key_init_win = false;
			break;

		case winType::Game:

			m_window_imp = new GameWindow;
			m_type_win = winType::Game;
			m_key_init_win = false;
			break;

		case winType::Setting:

			m_window_imp = new SettingWindow;
			m_type_win = winType::Setting;
			m_key_init_win = false;
			break;

		case winType::GameOver:

			m_window_imp = new GameOverWindow;
			m_type_win = winType::GameOver;
			m_key_init_win = false;
			break;
		}

		DelegateDrawWindow(); // делегирование отрисовки на основании паттерна Мост
	}
}

void Scene::DelegateDrawWindow()
{
	system("cls"); // отчистка окна от ненужного
	m_window_imp->Draw();
}

void Scene::SwitchWindow()
{
	if (_kbhit()) // изменение текущего окна на основании считаной клавиши
	{
		winChanges keyButton = static_cast<winChanges>(_getch());

		switch (m_type_win)
		{
		case winType::Menu:

			if (keyButton == winChanges::GO_TO_GAME)
			{
				m_type_win = winType::Game;
				m_key_init_win = true;
				InitWindow();
			}
			else if (keyButton == winChanges::GO_TO_SETTING)
			{
				m_type_win = winType::Setting;
				m_key_init_win = true;
				InitWindow();
			}

			break;

		case winType::Game:
			if (keyButton == buttons::RETURN_TO_MENU)
			{
				m_type_win = winType::Menu;
				m_key_init_win = true;
				InitWindow();
			}

			break;

		case winType::Setting:

			if (keyButton == buttons::RETURN_TO_MENU)
			{
				m_type_win = winType::Menu;
				m_key_init_win = true;
				InitWindow();
			}

			break;

		case winType::GameOver:

			if (keyButton == buttons::RETURN_TO_MENU) 
			{
				m_type_win = winType::Menu;
				m_key_init_win = true;
				InitWindow();
			}
			break;
		}
	}
}

void Scene::CallGameOver() // Вызов окна при поражении в случае коллизий тела или границ игрового окна
{
	m_type_win = winType::GameOver;
	m_key_init_win = true;
	InitWindow();
}

Scene::~Scene()
{
	delete m_window_imp;
}
