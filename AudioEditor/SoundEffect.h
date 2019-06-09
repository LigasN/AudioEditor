#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include "SFML/Audio.hpp"
#include <assert.h>
#include <math.h>
#include "Display.h"

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// SoundEffect class
///
/// Aim: Parent for Effect's classes.
///
/// Base class for Strategy design pattern
///
///////////////////////////////////////////////////////////////////////////////////////////////
class SoundEffect
{
private:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: inner function to edit sound with effect
	///
	/// Arguments: std::vector <sf::Int16> & - sound samples
	///				unsigned int - samples rate
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate) = 0;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: Displays parameter's settings on screen
	///
	/// Arguments: const std::shared_ptr <Display> & display
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void ParamDisplay(const std::shared_ptr <Display> & display) = 0;
	
public:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Constructor in SoundEffect class
	///
	/// Aim: Set all variables
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	SoundEffect();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Destructor in SoundEffect class
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	~SoundEffect();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Enum class in EffectManager class
	///
	/// Aim: Stores effects names
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	enum class Effects
	{
		Distortion,
		Delay,
		Tremolo,
		Echo
	};

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual override function in SoundEffect class
	///
	/// Aim: Remakes sound with proper sound effect by reference
	///
	/// Arguments: sf::SoundBuffer & sound
	///
	/// Returns: sf::SoundBuffer
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	sf::SoundBuffer remakeSound(sf::SoundBuffer & sound);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual function in SoundEffect class
	///
	/// Aim: Displays parameter's settings on screen
	///
	/// Arguments: const std::shared_ptr <Display> & display
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void DisplayParameters(const std::shared_ptr <Display> & display);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: change parameter on setting by increasing parameterOnDisplay variable
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void NextParameterSettings() = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: change parameter on setting by decreasing parameterOnDisplay variable
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void PreviousParameterSettings() = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: Increase proper  parameter
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void IncreaseParameter() = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: Decrease proper parameter
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void DecreaseParameter() = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: Changes effect status to opposite by changing effectStatus variable
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void UpdateEffectStatus(bool buttonStatus) = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: returns variable parameterOnDisplay
	///
	/// Arguments: void
	///
	/// Returns: unsigned int 
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual unsigned int GetParameterOnDisplay() = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Virtual abstract function in SoundEffect class
	///
	/// Aim: Returns names of effects
	///
	/// Arguments: void
	///
	/// Returns: EffectManager::Effects 
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual SoundEffect::Effects GetEffectName() = 0;
};
