
#ifndef EFFECTMANAGER_CPP
#define EFFECTMANAGER_CPP

#include "EffectManager.h"

namespace NL
{

	EffectManager::EffectManager() : delaySoundEffect(), distortionSoundEffect(), echoSoundEffect(), tremoloSoundEffect(), effect(delaySoundEffect)
	{
	}


	EffectManager::~EffectManager()
	{
	}

	void EffectManager::setEffect(Effects effectName)
	{
		switch (effectName)
		{
		case Effects::Distortion:

			this->effect = distortionSoundEffect;
			break;

		case Effects::Delay:

			this->effect = delaySoundEffect;
			break;

		case Effects::Echo:

			this->effect = echoSoundEffect;
			break;

		case Effects::Tremolo:

			this->effect = tremoloSoundEffect;
			break;
		}
	}

	sf::SoundBuffer EffectManager::remakeSound(sf::SoundBuffer & sound)
	{
		return effect->remakeSound(sound);
	}

	void EffectManager::NextParameterSettings()
	{
		effect->NextParameterSettings();
	}

	void EffectManager::PreviousParameterSettings()
	{
		effect->PreviousParameterSettings();
	}

	void EffectManager::IncreaseParameter()
	{
		effect->IncreaseParameter();
	}

	void EffectManager::DecreaseParameter()
	{
		effect->DecreaseParameter();
	}

	void EffectManager::ChangeEffectStatus()
	{
		effect->ChangeEffectStatus();
	}

	unsigned int EffectManager::GetParameterOnDisplay()
	{
		return effect->GetParameterOnDisplay();
	}
}
#endif // !EFFECTMANAGER_CPP