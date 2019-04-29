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

	sf::Texture backgroundTexture;
	if (backgroundTexture.loadFromFile("Background.png")) assert("Error with textures");

	sf::Sprite backgoundSprite;
	backgoundSprite.setTexture(backgroundTexture);

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
	window.draw(backgoundSprite);
	window.display();
	return EXIT_SUCCESS;
}

bool Prog::getExit()
{
	return Exit;
}
