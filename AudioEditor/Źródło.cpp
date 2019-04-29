#pragma once


/////////////////////////////////////////////////////////////////////////////
//
// HEADERS
//
/////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Prog.h"
#include <cstdlib>

/////////////////////////////////////////////////////////////////////////////
//
// Program parameters in constexpr auto
//
/////////////////////////////////////////////////////////////////////////////
constexpr auto WINDOW_WIDTH = 1200;
constexpr auto WINDOW_HEIGHT = 700;

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "AudioEditor", sf::Style::Titlebar);

	while (window.isOpen())
	{
		if (Prog::getInstance()->Update(window) != EXIT_SUCCESS) return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}