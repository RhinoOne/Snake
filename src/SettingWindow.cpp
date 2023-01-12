#include "..\include\SettingWindow.h"

SettingWindow::SettingWindow() :
	m_setting_list(settingitems::settingItem)
{

}
void SettingWindow::DrawSettingList() const
{
	for(unsigned int keyItem = 0; keyItem != m_setting_list.size(); ++keyItem) // перебор елементов вектора меню для его вывода 
	{
		cout <<"\n\n" << m_setting_list[keyItem][0] << "\n\n";

		for (unsigned int keyValue = 1; keyValue != m_setting_list[keyItem].size(); ++keyValue)
		{
			cout << " " << m_setting_list[keyItem][keyValue] ;
		}
	}
}

void SettingWindow::Draw() const
{
	string title = "SETTINGS";

	SetConsoleColor(foregroundcolors::MAGENTA);

	cout << "\n\n" << setw((constants::WINDOW_W_S / 2) + (title.size() / 2));
	cout << title << endl;

	DrawSettingList();
}