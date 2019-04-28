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


class Prog
{
	/////////////////////////////////////////////////////////////////////////////
	//
	// Default constructor and others writed in private because Singleton
	//
	/////////////////////////////////////////////////////////////////////////////
	Prog();
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
	static Prog * getInstance();

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
	bool Update(sf::RenderWindow & window);

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

