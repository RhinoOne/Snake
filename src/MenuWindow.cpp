#include "..\include\MenuWindow.h"

MenuWindow::MenuWindow() :
	m_menu_list(menuitems::menuItem)
{

}

void MenuWindow::DrawLogo() const
{
	string title = "SNAKE GAME";
	
	SetConsoleColor(foregroundcolors::GREEN);

	cout <<"\n\n" << setw((constants::WINDOW_W_S / 2) + (title.size()) / 2);
	cout << title <<"\n\n";


	unsigned int valueIndent = constants::WINDOW_W_S / 5;
	cout << setw(valueIndent) << "" <<"                                                                 **  **\n";
	cout << setw(valueIndent) << "" <<"                                                                   **  \n";
	cout << setw(valueIndent) << "" <<"                                                                   **  \n";
	cout << setw(valueIndent) << "" <<"                                                                ********  \n";
	cout << setw(valueIndent) << "" <<"                                                               *  ****  * \n";
	cout << setw(valueIndent) << "" <<"                                                              ************\n";
	cout << setw(valueIndent) << "" <<"                                                              ************\n";
	cout << setw(valueIndent) << "" <<"                                                               **********\n";
	cout << setw(valueIndent) << "" <<"**********             ***************************            **********\n";
	cout << setw(valueIndent) << "" <<" **********           *****************************          ***********\n";
	cout << setw(valueIndent) << "" <<"  **********         ************        **********         ***********\n";
	cout << setw(valueIndent) << "" <<"   **********       ************          ****************************\n";
	cout << setw(valueIndent) << "" <<"    ***************************            **************************\n";
}


void MenuWindow::DrawMenuList() const
{
	int endKey = m_menu_list.size();

	for(unsigned int beginKey = 0; beginKey != endKey; ++beginKey)
	{
		string item = m_menu_list[beginKey];

		string idItem = (beginKey != 0) ? to_string(beginKey) : " "; // кастомизация. Отступы в пунктах

		cout << "\n\n" << setw(constants::WINDOW_W_S / 2.3) << idItem
					   << setw((constants::WINDOW_W_S / 12) + item.size()/2) << item;
	}

	cout << "\n\n"
		<< "\tPress \"1\" to start the game\n"
		<< "\tPress \"2\" to open game settings\n";
}

void MenuWindow::Draw() const
{
	DrawLogo();
	DrawMenuList();
}
