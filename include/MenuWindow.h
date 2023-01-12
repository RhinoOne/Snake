#ifndef MENU_W_H
#define MENU_W_H

#include "Window.h"

class MenuWindow : public Window
{
public:
	MenuWindow();

	void Draw() const override;

private:
	void DrawLogo() const;

	void DrawMenuList() const;

private:
	vector<string> m_menu_list;
};

#endif 
