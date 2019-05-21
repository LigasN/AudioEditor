#include "EffectManager.h"



EffectManager::EffectManager()
{
	effect = nullptr;
}


EffectManager::~EffectManager()
{
}

bool EffectManager::setEffect(Effects effectName)
{
	switch (effectName)
	{
	case Effects::Distortion:

		this->effect = std::make_shared<DistortionSoundEffect>();
		break;

	case Effects::Delay:

		this->effect = std::make_shared<DelaySoundEffect>();
		break;

	case Effects::Echo:

		this->effect = std::make_shared<EchoSoundEffect>();
		break;

	case Effects::Wah_wah:

		this->effect = std::make_shared<WahWahSoundEffect>();
		break;
	}
}

sf::SoundBuffer EffectManager::remakeSound(sf::SoundBuffer & sound)
{
	return effect->remakeSound(sound);
}
