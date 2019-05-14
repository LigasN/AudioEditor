#include "Prog.h"
#include <iostream>  //to delete after tests

Prog::Prog() : buttons(), display(sf::Vector2f(440.f,132.f), sf::Vector2f(313.f, 148.f))
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
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A))
		{
			display.setText(C_TEXTS::TEXT_ID::Error);
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::B))
		{
			display.setText(C_TEXTS::TEXT_ID::Upload_Sound);
		}
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Z))
		{
			display.setText(C_TEXTS::TEXT_ID::Zuzanka_TM);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		buttons.ButtonUpdate(window);
		while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
	}

	window.clear();
	window.draw(backgoundSprite);
	window.draw(buttons);
	window.draw(display);
	window.display();
	return EXIT_SUCCESS;
}

bool Prog::getExit()
{
	return Exit;
}
