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
	thread play(&GameLogic::Notify, m_logic_imp); // �������� ������� �������� "�����������" ��� ������� �������� ��������
	this_thread::sleep_for(std::chrono::milliseconds(30)); // ���������� ������� ������� �������� �� ������� �������

	m_logic_imp->CheckFoodIntake();

	if (m_logic_imp->CheckBodyCollision() // �������� ��������
		|| m_logic_imp->CheckWallCollision()) {
		play.join();
		return true;
	}

	play.join(); 

	return false;
}

void WindowManagement(Scene& currentScene)
{
	thread windowControl(&Scene::SwitchWindow, std::ref(currentScene)); // ����� ���������� �� ���������� ���������� ����� ����
	windowControl.join();
}

void Game::Start()
{

	Scene scene;

	while (true)
	{
		m_logic_imp = new GameLogic; //�������� ��� ��� ���������� ��� ����

		WindowManagement(scene); // ������ ������

		if (scene.GetTypeWindow() == winType::Game) // �������� ������������� ������ ������� �������
		{
			m_logic_imp->GenerateFood();


			while (true)
			{
				WindowManagement(scene);

				if (scene.GetTypeWindow() != winType::Game) // ����� �� �������� �������� �� ������� ������
					break;

				if (PlayGameLogic()) // ����� �� �������� �������� �� ��������� ��������
				{
					scene.CallGameOver();
				}
			}	
		}
		delete m_logic_imp;
	}
}