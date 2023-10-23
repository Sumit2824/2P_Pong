#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	int& getScore();
	RectangleShape getShape();
	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();
	void update(Time dt);

private:
	Vector2f m_Position;
	
	//A rctangleShape Object
	RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	bool m_MoveDown = false;
	bool m_MoveUp = false;
	int Score = 0;
};
