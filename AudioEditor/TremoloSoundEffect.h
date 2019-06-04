#pragma once

#ifndef TREMOLOSOUNDEFFECT_H
#define TREMOLOSOUNDEFFECT_H

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include "SoundEffect.h"
#include <assert.h>
#include "C_TEXTS.h"
#include "Display.h"

namespace NL
{
	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// TremoloSoundEffect class	
	///
	/// Aim: Add tremolo sound effect to sound
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	class TremoloSoundEffect : public SoundEffect
	{
	public:


		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Enum class in TremoloSoundEffect class
		///
		/// Aim: Stores names of waves which can be used in effect
		///
		/// Arguments: void
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		enum class WaveformType
		{
			sin,
			triangle,
			sawtooth,
			inverse_sawtooth,
			square
		};


		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Constructor in TremoloSoundEffect class
		///
		/// Aim: Set all variables
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		TremoloSoundEffect();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Destructor in TremoloSoundEffect class
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		~TremoloSoundEffect();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Virtual override function in TremoloSoundEffect class
		///
		/// Aim: Display effect options
		///
		/// Arguments: const std::shared_ptr <Display> &
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		virtual void ParamDisplay(const std::shared_ptr <Display> & display) override;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Virtual override function in TremoloSoundEffect class
		///
		/// Aim: Increase parameter
		///
		/// Arguments: void
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		virtual void IncreaseParameter();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Virtual override function in TremoloSoundEffect class
		///
		/// Aim: Decrease parameter
		///
		/// Arguments: void
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		virtual void DecreaseParameter();

	private:

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in TremoloSoundEffect class
		///
		/// Aim: Determines the "shape" of tremolo. Choice of sine, triangle, 
		///		 sawtooth, inverse sawtooth, square.
		///
		/// Type: WaveformType
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		WaveformType waveformType;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in TremoloSoundEffect class
		///
		/// Aim: Sets starting phase for tremolo wave.
		///
		/// Type: int
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		int startingPhase;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in TremoloSoundEffect class
		///
		/// Aim: 0 % is no tremolo, 100 % sweeps between zero and maximum 
		///		 volume of sample based on the original amplitude level.
		///
		/// Type: int
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		int wetLevel;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in TremoloSoundEffect class
		///
		/// Aim: frequency(Hz) 10 is quite much. Controls the speed of the oscillation.
		///
		/// Type: int 
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		int frequency;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in TremoloSoundEffect class
		///
		/// Aim: Stores information about number of displayed parameter.
		///
		/// Type: unsigned int
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		unsigned int parameterOnDisplay;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Virtual override function in TremoloSoundEffect class
		///
		/// Aim: Makes the main task of this class. Edits sound with tremolo effect on specific parameters
		///
		/// Arguments: std::vector <sf::Int16> & soundSamples, unsigned int sampleRate
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		void  makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate);
	};
}
#endif // !TREMOLOSOUNDEFFECT_H
