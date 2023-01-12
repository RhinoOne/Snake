#include "..\include\GameWindow.h"

void GameWindow::DrawTitleWindow() const
{
    SetCursorPosition(0, 0);
    SetConsoleColor(foregroundcolors::DARKCYAN);

    cout << "YOUR SCORE";
}

void GameWindow::Draw() const
{

    DrawTitleWindow();
    cout << "\n";

    SetConsoleColor(backgroundcolors::DARKYELLOW);

    for (unsigned int keyDrawWall = 0; keyDrawWall != constants::WINDOW_W_S + 2; ++keyDrawWall)// отрисовка верхней границы окна
        cout << " ";

    cout << "\n";

  for(unsigned int keyMainDraw = 0; keyMainDraw != constants::WINDOW_H_S; ++keyMainDraw) // отрисовка боковых стен 
  {

    for(unsigned int  keyDrawSide = 0; keyDrawSide != constants::WINDOW_W_S + 2; ++keyDrawSide)
    {
      if(keyDrawSide == 0 || keyDrawSide == constants::WINDOW_W_S + 1)
        SetConsoleColor(backgroundcolors::DARKYELLOW);
      else 
        SetConsoleColor(backgroundcolors::BLACK);
      cout << " ";
    }

    cout << "\n";
  }

  SetConsoleColor(backgroundcolors::DARKYELLOW);

  for (unsigned int  keyDrawWall = 0; keyDrawWall < constants::WINDOW_W_S + 2; ++keyDrawWall) // отрисовка нижней границы окна
    cout << " ";

  SetConsoleColor(backgroundcolors::BLACK); // изменения цвета для последущего запуска
  HideCursor(); // скрыть курсор для удобной игры
}

GameWindow::~GameWindow()
{
    SetConsoleColor(backgroundcolors::BLACK); // изменения цвета для последущего запуска
}
