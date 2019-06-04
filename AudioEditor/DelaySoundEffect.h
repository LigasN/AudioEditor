#pragma once

#ifndef DELAYSOUNDEFFECT_H
#define DELAYSOUNDEFFECT_H

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include "SoundEffect.h"
#include "Display.h"
#include "C_TEXTS.h"

namespace NL
{

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// DelaySoundEffect class
///
/// Aim: Add delay to sound
///
///////////////////////////////////////////////////////////////////////////////////////////////
	class DelaySoundEffect : public SoundEffect
	{
	public:

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Constructor in DelaySoundEffect class
		///
		/// Aim: Set all variables
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		DelaySoundEffect();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Destructor in DelaySoundEffect class
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		~DelaySoundEffect();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Virtual override function in DelaySoundEffect class
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
		/// Virtual override function in DelaySoundEffect class
		///
		/// Aim: Increase parameter
		///
		/// Arguments: void
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		virtual void IncreaseParameter() override;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Virtual override function in DelaySoundEffect class
		///
		/// Aim: Decrease parameter
		///
		/// Arguments: void
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		virtual void DecreaseParameter() override;


	private:

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in DelaySoundEffect class
		///
		/// Aim: (dB)Controls the quickness of dying each echo. When set 1 volume of each echo is the same
		///		 when more the volume is increasing and when less each echo is dying in time
		///
		/// Type: float
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		float delayLevelPerEcho; 

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in DelaySoundEffect class
		///
		/// Aim: Bigger than 0. In seconds.	Controls the time between echoes.
		///
		/// Type: unsigned int
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		unsigned int delayTime;	

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in DelaySoundEffect class
		///
		/// Aim: bigger than 1 or smaller but more than 0. Changes speed and tone of sound with each echo
		///		 but in equal gap between.
		///
		/// Type: float
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		float pitchChangeEffect;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in DelaySoundEffect class
		///
		/// Aim: 1 or bigger. Controls the amount by which each successive echo will change pitch.
		///
		/// Type: float
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		float pitchChangePerEcho;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in DelaySoundEffect class
		///
		/// Aim: Zero or more. Controls how many echoes are produced.
		///
		/// Type: int
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		int numberOfEchoes;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Private variable in DelaySoundEffect class
		///
		/// Aim: Stores information about number of displayed parameter.
		///
		/// Type: unsigned int
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		unsigned int parameterOnDisplay;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Function in DelaySoundEffect class
		///
		/// Aim: Makes the main task of this class. Edits sound with delay effect on specific parameters
		///
		/// Arguments: std::vector <sf::Int16> & soundSamples, unsigned int sampleRate
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		void  makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate);

	};
}
#endif // !DELAYSOUNDEFFECT_H


//
/////////////////////////////////////////////////////////////////////////////////////////////////
/////
///// Public enum in DelaySoundEffect class
/////
///// Aim: Stores names of parameters
/////
///// Arguments: sf::RenderTarget&, sf::RenderStates
/////
///// Returns: void
/////
/////////////////////////////////////////////////////////////////////////////////////////////////
//enum class Parameters
//{
//	Delay_level_per_echo,	//(dB)	This controls the amount in dB by which each successive echo will change loudness.The more negative this value, the more the echoes will die away.Positive values cause successive echoes to be louder.When set to 0.0, all echoes will be the same volume.Warning icon	Because echoes are often added to the original audio, the processed audio will often have a higher peak level than the original.If the output exceeds 0 dB(full track height) and so triggers the red clipping warning lights in Playback Meter Toolbar, you should open Effect > Amplify..., ensure "Amplification (dB)" shows a negative dB value(not "0.0 dB") then click OK.If "Amplification (dB)" in Amplify shows "0.0 dB", the track does not contain 32 - bit audio and the clipping cannot be repaired.In that case, Edit > Undo Delay, use Amplify to reduce the track to a lower amplitude then reapply Delay.
//	Delay_time,				//(seconds)	This controls the time between echoes.For the Bouncing Ball types of delay, this sets the delay time for the longest(slowest) echo.
//	Pitch_change_effect,	//	Pitch / Tempo: Changes the pitch in the same way that the Change Speed effect causes a change in pitch.The sound quality of each echo is very good, but an increase in pitch speeds up the delayed audio and a decrease in pitch slows it down.The echoes will be noticeably desynchronized with any comparable echoes in other tracks where "Pitch/Tempo" was not applied.
//	Pitch_change_per_echo,	//This controls the amount in semitones by which each successive echo will change pitch.The change can be set to fractions of a semitone which can produce a "glissando" type of delay.When set to zero, the pitch change effect is disabled.
//	Number_of_echoes,		//This controls how many echoes are produced.
//};