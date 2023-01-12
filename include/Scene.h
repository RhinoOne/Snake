#ifndef SCENE_H
#define SCENE_H

#include <conio.h>

#include "MenuWindow.h"
#include "GameWindow.h"
#include "GameOverWindow.h"
#include "SettingWindow.h"

typedef windowstype::windowType winType;

typedef buttons::windowChanges winChanges;

class Scene
{
public:
	
	Scene();

	void SwitchWindow();

	winType GetTypeWindow() { return m_type_win; };

	void CallGameOver();

	~Scene();

private:
	void InitWindow();

	void DelegateDrawWindow();

private:
	winType m_type_win;
	Window* m_window_imp;
	bool m_key_init_win;
};

#endif 
