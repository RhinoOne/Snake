#ifndef SETTING_W_H
#define SETTING_W_H

#include "..\include\Window.h"

class SettingWindow : public Window
{
public:
	SettingWindow();

	void Draw() const override;

private:
	void DrawSettingList() const;

private:
	vector<vector<string>> m_setting_list;
};

#endif 
