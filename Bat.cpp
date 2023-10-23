#include "Bat.h"

//This is constructor it is called when we create an object
Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(10, 75));
	m_Shape.setPosition(m_Position);

}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

int& Bat::getScore()
{
	return Score;
}

RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveUp()
{
	m_MoveUp = true;
}

void Bat::moveDown()
{
	m_MoveDown = true;
}

void Bat::stopUp()
{
	m_MoveUp = false;
}

void Bat::stopDown()
{
	m_MoveDown = false;
}

void Bat::update(Time dt)
{
	if (m_MoveUp)
	{
		m_Position.y -= m_Speed * dt.asSeconds();
	}
	if (m_MoveDown)
	{
		m_Position.y += m_Speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}