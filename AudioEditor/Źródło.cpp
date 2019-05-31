#pragma once

#ifndef ZRODLO_CPP
#define ZRODLO_CPP

/////////////////////////////////////////////////////////////////////////////
//
// List of design patterns in project:
// - Singleton
// - Handle-Body
// - Factory Method
// - 
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
// HEADERS
//
/////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Prog.h"
#include <cstdlib>
#include <memory>

namespace NL
{
	/////////////////////////////////////////////////////////////////////////////
	//
	// Program parameters in constexpr auto
	//
	/////////////////////////////////////////////////////////////////////////////
	constexpr auto WINDOW_WIDTH = 1200;
	constexpr auto WINDOW_HEIGHT = 700;

	int main() {

		std::shared_ptr <sf::RenderWindow> window = std::make_shared <sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "AudioEditor", sf::Style::Titlebar);

		while (window->isOpen())
		{
			if (Prog::getInstance(window)->Update() != EXIT_SUCCESS) return EXIT_FAILURE;
		}

		return EXIT_SUCCESS;
	}
}
#endif // !ZRODLO_CPP