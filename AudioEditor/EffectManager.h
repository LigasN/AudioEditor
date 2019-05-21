#pragma once

#include "SoundEffect.h"
#include <memory>
#include "DelaySoundEffect.h"
#include "DistortionSoundEffect.h"
#include "EchoSoundEffect.h"
#include "WahWahSoundEffect.h"
#include "SFML/Audio.hpp"

class EffectManager
{
private:
	std::shared_ptr <SoundEffect> effect;

public:
	EffectManager();
	~EffectManager();

	enum class Effects
	{
		Distortion,
		Delay,
		Wah_wah,
		Echo
	};

	bool setEffect(Effects effectName);

	sf::SoundBuffer remakeSound(sf::SoundBuffer & sound);

};
