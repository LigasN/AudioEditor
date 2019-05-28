#include "EchoSoundEffect.h"

EchoSoundEffect::EchoSoundEffect()
{
}

EchoSoundEffect::~EchoSoundEffect()
{
}

void EchoSoundEffect::makeEffect(std::vector<sf::Int16>& soundSamples, unsigned int sampleRate)
{
	assert(delayTime > 0);
	assert(decayFactor > 0 || decayFactor < 10);

	int delay = sampleRate * delayTime;
	int repetition = soundSamples.size() / delay;

	std::vector <sf::Int16> effectSamples = soundSamples;

	for (int i = 1; i <= repetition; i++)
	{
		for (int j{}; j < effectSamples.size(); j++)
		{
			if (j > delay * i)
			{
				soundSamples[j] += (effectSamples[j - delay * i] * pow(decayFactor, i));
			}
		}
	}
}
