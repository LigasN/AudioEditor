#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Prog.h"
#include <cstdlib>

int main() {

	sf::RenderWindow window(sf::VideoMode(500, 500), "AudioEditor", sf::Style::Titlebar);

	while (window.isOpen())
	{
		if (Prog::getInstance()->Update(window) != EXIT_SUCCESS) return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}