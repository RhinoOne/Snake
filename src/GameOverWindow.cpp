#include "..\include\GameOverWindow.h"

void GameOverWindow::Draw() const 
{
	string title = "GAME OVER";
	string message = "Press \" ESC \" to return Menu";

	SetConsoleColor(foregroundcolors::MAGENTA); // ��������� ����� ��� ���������

	cout << "\n\n" << setw((constants::WINDOW_W_S / 2) + (title.size() / 2)); //������������ ������� ��� ��������� �� ��������� ����� ���������
	cout << title << endl;

	cout << "\n\n" << setw((constants::WINDOW_W_S / 2) + (message.size() / 2));
	cout << message;
}
