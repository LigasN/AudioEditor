#pragma once

/////////////////////////////////////////////////////////////////////////////
//
// HEADERS
//
/////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "C_TEXTS.h"
#include <memory>
#include <assert.h>
#include "Buttons.h"
#include "Display.h"
#include "AudioEditorManager.h"

class Prog
{
	/////////////////////////////////////////////////////////////////////////////
	//
	// Default constructor and others writed in private because Singleton
	//
	/////////////////////////////////////////////////////////////////////////////
	Prog(const std::shared_ptr < sf::RenderWindow > & window);
	Prog(const Prog&) = delete;
	Prog& operator=(const Prog&) = delete;
	~Prog();

	/////////////////////////////////////////////////////////////////////////////
	///
	/// Unique pointer to C_TEXTS class object to load texts from file
	/// and handle with it
	///
	/////////////////////////////////////////////////////////////////////////////
	std::unique_ptr < C_TEXTS > TEXTS_object;

	/////////////////////////////////////////////////////////////////////////////
	///
	/// Static pointer with adress of Prog class instance ( Singleton )
	///
	/////////////////////////////////////////////////////////////////////////////
	static Prog * instance;

	/////////////////////////////////////////////////////////////////////////////
	///
	/// Boolean variable which stores information about 
	/// user wish to exit the application
	///
	/////////////////////////////////////////////////////////////////////////////
	bool Exit;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///																													zedytowane
	/// Object of class Buttons in Prog class
	///
	/// Aim: Stores all the buttons of program
	///
	/// Type: Buttons
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	std::shared_ptr <Buttons> buttons;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///																												zedytowane
	/// Object of class Display in Prog class
	///
	/// Aim: Stores and control display apparent for user
	///
	/// Type: Display
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	std::shared_ptr < Display > display;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///																												zedytowane
	/// Object of class Display in Prog class
	///
	/// Aim: Stores and control display apparent for user
	///
	/// Type: Display
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	const std::shared_ptr < sf::RenderWindow > window;

	AudioEditorManager audioEditorManager;																					// <------------ napisac komentarz


public:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in Prog class
	///
	/// Aim: Return instance of Prog class (Singleton)
	///
	/// Way: - Returns static variable instance
	///
	/// Returns: static Prog *
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	static Prog * getInstance(const std::shared_ptr <sf::RenderWindow > & window);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in Prog class
	///
	/// Aim: Update status of Prog engine
	///
	/// Way: - Take sf::RenderWindow& object as argument
	///		 - All starts here and ends here
	///		 - Returns true if user is continuing
	///		 - Returns false if user ended
	///
	/// Returns: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool Update();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in Prog class
	///
	/// Aim: Return status of program
	///
	/// Way: - Returns true if user wants to exit
	///		 - Returns false if not
	///
	/// Returns: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool getExit();
};

