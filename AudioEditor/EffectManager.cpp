#include "EffectManager.h"
#include <iostream>

EffectManager::EffectManager() : delaySoundEffect( std::make_shared < DelaySoundEffect > ()), distortionSoundEffect(std::make_shared < DistortionSoundEffect >()), 
echoSoundEffect(std::make_shared < EchoSoundEffect >()), tremoloSoundEffect(std::make_shared < TremoloSoundEffect >()), effect(std::make_shared < TremoloSoundEffect >())
{
}

EffectManager::~EffectManager()
{
}

void EffectManager::setEffect(SoundEffect::Effects effectName)
{
	switch (effectName)
	{
	case SoundEffect::Effects::Distortion:

		this->effect = distortionSoundEffect;
		break;

	case SoundEffect::Effects::Delay:

		this->effect = delaySoundEffect;
		break;

	case SoundEffect::Effects::Echo:

		this->effect = echoSoundEffect;
		break;

	case SoundEffect::Effects::Tremolo:

		this->effect = tremoloSoundEffect;
		break;

	default:
		assert("Error with setting effect");

	}
}

sf::SoundBuffer EffectManager::remakeSound(sf::SoundBuffer & sound)
{
	return effect->remakeSound(sound);
}

void EffectManager::DisplayParameters(const std::shared_ptr<Display>& display)
{
	effect->DisplayParameters(display);
}

void EffectManager::NextParameterSettings()
{
	effect->NextParameterSettings();
	std::cout << "ParameterOndisplay EffectManager::NextParameterSettings() " << effect->GetParameterOnDisplay() << std::endl;
}

void EffectManager::PreviousParameterSettings()
{
	effect->PreviousParameterSettings();
}

void EffectManager::IncreaseParameter()
{
	if (effect->GetParameterOnDisplay() == 0)
	{
		switch (effect->GetEffectName())
		{
		case SoundEffect::Effects::Distortion:
			setEffect(SoundEffect::Effects::Delay);
			std::cout << "setted delay" << std::endl;
			break;

		case SoundEffect::Effects::Delay:
			setEffect(SoundEffect::Effects::Tremolo);
			std::cout << "setted Tremolo" << std::endl;
			break;

		case SoundEffect::Effects::Tremolo:
			setEffect(SoundEffect::Effects::Echo);
			std::cout << "setted Echo" << std::endl;
			break;

		case SoundEffect::Effects::Echo:
			setEffect(SoundEffect::Effects::Distortion);
			std::cout << "setted Distortion" << std::endl;
			break;

		default:
			assert("Developer error in effect manager with increasing 0 parameter");
			break;
		}
	}

	else
	{
		effect->IncreaseParameter();
	}
}

void EffectManager::DecreaseParameter()
{
	if (effect->GetParameterOnDisplay() == 0)
	{
		switch (effect->GetEffectName())
		{
		case SoundEffect::Effects::Distortion:
			setEffect(SoundEffect::Effects::Echo);
			std::cout << "setted Echo" << std::endl;
			break;
		case SoundEffect::Effects::Delay:
			setEffect(SoundEffect::Effects::Distortion);
			std::cout << "setted Distortion" << std::endl;
			break;
		case SoundEffect::Effects::Tremolo:
			setEffect(SoundEffect::Effects::Delay);
			std::cout << "setted Delay" << std::endl;
			break;
		case SoundEffect::Effects::Echo:
			setEffect(SoundEffect::Effects::Tremolo);
			std::cout << "setted Tremolo" << std::endl;
			break;
		default:
			assert("Developer error in effect manager with increasing 0 parameter");
			break;
		}
	}
	else effect->DecreaseParameter();
}

void EffectManager::ChangeEffectStatus()
{
	effect->ChangeEffectStatus();
}

unsigned int EffectManager::GetParameterOnDisplay()
{
	return effect->GetParameterOnDisplay();
}