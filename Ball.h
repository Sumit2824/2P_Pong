#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
public:
	//construction script - though here it can have argument
	Ball(float startX, float startY);

	//function prototype of FloatRect(a type that return four points)
	//Content will be in cpp but it call function name here
	//just like variable type we can have type like this that might return values or object
	FloatRect getPosition();
	RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBat();
	void rePosition();
	void update(Time dt);

private:
	Vector2f m_Position;
	RectangleShape m_Shape;
	float m_Speed = 900.0f;
	float m_DirectionX = 0.2f;
	float m_DirectionY = 0.2f;
};
