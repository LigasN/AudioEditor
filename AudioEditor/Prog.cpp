#include "Prog.h"
#include <iostream>  //to delete after tests

Prog::Prog()
{
	Exit = 0;
}

Prog::~Prog()
{
	delete instance;
}

Prog * Prog::instance = 0;

Prog * Prog::getInstance()
{
	if (!instance)
	{
		instance = new Prog;
	}
	return instance;
}

bool Prog::Update(sf::RenderWindow& window)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Event event;
	while (window.pollEvent(event))
	{
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{
			window.close();
			return EXIT_SUCCESS;
		}
	}

	window.clear();
	window.draw(shape);
	window.display();
	return EXIT_SUCCESS;
}

bool Prog::getExit()
{
	return Exit;
}
