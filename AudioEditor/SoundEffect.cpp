#include "SoundEffect.h"


SoundEffect::SoundEffect()
{
}

SoundEffect::~SoundEffect()
{
}

sf::SoundBuffer SoundEffect::remakeSound(sf::SoundBuffer & sound)
{
	std::vector <sf::Int16> soundSamples{};

	for (auto iter = sound.getSamples(); iter != sound.getSamples() + sound.getSampleCount(); iter++) {
		soundSamples.push_back(*iter);
	}

	makeEffect(soundSamples);

	sf::Int16 * soundSamplesTab = new sf::Int16[soundSamples.size()];

	for (int i{}; i < soundSamples.size(); i++) {
		soundSamplesTab[i] = soundSamples[i];
	}

	sf::SoundBuffer soundBuffer;

	soundBuffer.loadFromSamples(soundSamplesTab, soundSamples.size(), sound.getChannelCount(), sound.getSampleRate());

	delete[] soundSamplesTab;

	return soundBuffer;
}

