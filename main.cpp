#include "Bat.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
	VideoMode vm(1600, 900);
	RenderWindow window(vm, "Pong", Style::Default);
	int score = 0;
	int lives = 3;

	//Middle of the screen, up 20 from he bottom
	Bat bat(1600 / 2, 900 - 20);

	Text hud;
	Font font;
	font.loadFromFile("fonts/DS-DIGIT.TTF");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setPosition(20, 20);
	hud.setFillColor(Color::White);

	Clock clock;

	//Beggining of the window
	//*********************
	while (window.isOpen())
	{
		//Handle Player Event
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		//If player presses the escape key
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
				window.close();
		}

		//If player presses left key
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		// If player presses right key
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		//Update the objects
		Time dt = clock.restart();
		bat.update(dt);
		stringstream ss;
		ss << "Score: " << score << "    Lives: " << lives;
		hud.setString(ss.str());

		//Draw on the window
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.display();


	}


}