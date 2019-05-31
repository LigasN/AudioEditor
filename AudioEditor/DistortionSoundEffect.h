#pragma once

#ifndef DISTORTIONSOUNDEFFECT_H
#define DISTIONSOUNDEFFECT_H

#include "SoundEffect.h"
#include "Display.h"
#include "C_TEXTS.h"

namespace NL
{

	class DistortionSoundEffect : public SoundEffect
	{
	public:

		enum class Parameters
		{
			Clipping_level, //(-100 to 0 dB) : Peaks greater than this level are cut off.The slider control has a logarithmic scale to allow settings close to 0 dB to be made more easily and accurately.
			Drive,			//(0 to 100) : When set to greater than 0, the waveform is amplified this amount(dB) prior to being clipped.
			Make_up_Gain	//(0 to 100) : When set greater than 0, the output from the effect is amplified.When set to 100, the amplification is such that an input level of 0 dB(full track height) will produce an output level of 0 dB.
		};

		DistortionSoundEffect();
		~DistortionSoundEffect();

		void ParamDisplay(const std::shared_ptr <Display> & display);
		virtual void IncreaseParameter();
		virtual void DecreaseParameter();

	private:
		int clippingLevel;
		int drive;
		int makeUpGain;
		unsigned int parameterOnDisplay;
		void makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate);			//funcja zmieniana przez design pattern strategy
	};

}
#endif // !DISTORTIONSOUNDEFFECT_H