#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat 
{
	private:
	// m stands for member variable
		Vector2f m_Position;
		// Rectangle Shape from SFML 
		RectangleShape m_Shape;
		float m_Speed = 1000.0f;
		bool m_MovingRight = false;
		bool m_MovingLeft = false;
	public:
		Bat(float startX, float startY);
		FloatRect getPosition(); //Value returned from RectanlgeShape object, top left corner of the sprite
		RectangleShape getShape();
		void moveLeft();
		void moveRight();
		void stopLeft();
		void stopRight();
		void update(Time dt);
};