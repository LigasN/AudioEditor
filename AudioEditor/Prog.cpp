
#ifndef PROG_CPP
#define PROG_CPP

#include "Prog.h"

namespace NL
{

	Prog::Prog(const std::shared_ptr < sf::RenderWindow > & window) : window(window), buttons(std::make_shared <Buttons >(window)),
		display(std::make_shared <Display>(sf::Vector2f(440.f, 132.f), sf::Vector2f(313.f, 148.f))), audioEditorManager(display, buttons)
	{
		Exit = 0;
	}

	Prog::~Prog()
	{
		delete instance;
	}

	Prog * Prog::instance = 0;

	Prog * Prog::getInstance(const std::shared_ptr < sf::RenderWindow > & window)
	{
		if (!instance)
		{
			instance = new Prog(window);

		}
		return instance;
	}

	bool Prog::Update()
	{

		sf::Texture backgroundTexture;
		if (backgroundTexture.loadFromFile("Background.png")) assert("Error with textures");

		sf::Sprite backgoundSprite;
		backgoundSprite.setTexture(backgroundTexture);

		window->clear();
		window->draw(backgoundSprite);
		window->draw(*buttons);
		window->draw(*display);
		window->display();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))  // do usuniecia kiedys
			{
				window->close();
				return EXIT_SUCCESS;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			audioEditorManager.updateState();
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
		}

		return EXIT_SUCCESS;
	}

	bool Prog::getExit()
	{
		return Exit;
	}
}

#endif // !PROG_CPP