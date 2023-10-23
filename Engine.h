#pragma once

#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;


class Engine
{
private:
	Clock m_Clock;
	Time m_DT;
	RenderWindow m_Window;
	int HHUDContext = 0;
	//unique_ptr<ScreenManager> m_ScreenManager;
	float m_FPS = 0;
	Vector2f m_Resolution;
public:
	//The engine constructor
	Engine();

	//Run will call all the private functions
	void run();
};