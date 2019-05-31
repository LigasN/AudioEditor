#pragma once

#ifndef ECHOSOUNDEFFECT_H
#define ECHOSOUNDEFFECT_H

#include "SoundEffect.h"
#include "Display.h"
#include "C_TEXTS.h"

namespace NL
{
	class EchoSoundEffect : public SoundEffect
	{
	public:

		enum class Parameters
		{
			Delay_time,		//(seconds)	The amount of delay between the echoes, in other words the length of each echo.
			Decay_factor	//Usually a number between 0 and 1. A value of 0 means no echo, and a value of 1 means that each echo is exactly as loud as the original, so this merely extends the current selection unchanged.A value of 0.5 reduces the amplitude or loudness of each echo by half each time, so the audio dies out quite slowly.Smaller values make it die out more quickly.Values above 1 increase the amplitude of the echo each time, which you could use as a special effect.
		};

		EchoSoundEffect();
		~EchoSoundEffect();

		void ParamDisplay(const std::shared_ptr <Display> & display);
		virtual void IncreaseParameter();
		virtual void DecreaseParameter();

	private:
		int delayTime;		//(seconds)	The amount of delay between the echoes, in other words the length of each echo.
		float decayFactor;	 //Usually a number between 0 and 1. A value of 0 means no echo, and a value of 1 means that each echo is exactly as loud as the original, so this merely extends the current selection unchanged.A value of 0.5 reduces the amplitude or loudness of each echo by half each time, so the audio dies out quite slowly.Smaller values make it die out more quickly.Values above 1 increase the amplitude of the echo each time, which you could use as a special effect.
		unsigned int parameterOnDisplay;
		void makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate);			//funcja zmieniana przez design pattern strategy
	};
}
#endif // !ECHOSOUNDEFFECT_H
