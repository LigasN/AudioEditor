#pragma once

#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H


#include "SoundEffect.h"
#include "Display.h"
#include <memory>
#include "DelaySoundEffect.h"
#include "DistortionSoundEffect.h"
#include "EchoSoundEffect.h"
#include "TremoloSoundEffect.h"
#include "SFML/Audio.hpp"

namespace NL
{
	class EffectManager
	{
	private:
		std::shared_ptr <SoundEffect> effect;
		std::shared_ptr <DelaySoundEffect> delaySoundEffect;
		std::shared_ptr <DistortionSoundEffect> distortionSoundEffect;
		std::shared_ptr <EchoSoundEffect> echoSoundEffect;
		std::shared_ptr <TremoloSoundEffect> tremoloSoundEffect;


	public:
		EffectManager();
		~EffectManager();

		enum class Effects
		{
			Distortion,
			Delay,
			Tremolo,
			Echo
		};

		void setEffect(Effects effectName);

		sf::SoundBuffer remakeSound(sf::SoundBuffer & sound);

		virtual void ParamDisplay(const std::shared_ptr <Display> & display) = 0;

		void NextParameterSettings();
		void PreviousParameterSettings();
		void IncreaseParameter();
		void DecreaseParameter();
		void ChangeEffectStatus();
		unsigned int GetParameterOnDisplay();

	};
}
#endif // !EFFECTMANAGER_H