#include "DelaySoundEffect.h"

DelaySoundEffect::DelaySoundEffect()
{
}

DelaySoundEffect::~DelaySoundEffect()
{
}

void DelaySoundEffect::makeEffect(std::vector<sf::Int16>& soundSamples, unsigned int sampleRate)
{
	assert(delayTime > 0);
	assert(pitchChangePerEcho > 0);
	assert(numberOfEchoes >= 0);
	assert(pitchChangeEffect > 0);

	int delay = sampleRate * delayTime;

	std::vector <sf::Int16> effectSamples = soundSamples;

	for (int i = 1; i <= numberOfEchoes; i++)
	{
		for (int j{}; j < effectSamples.size(); j++)
		{
			if (j > delay * i)
			{
				if ((j - delay * i) * pitchChangeEffect * pitchChangePerEcho < effectSamples.size())
				{
					soundSamples[j] += effectSamples[(j - delay * i) * pitchChangeEffect * pow(pitchChangePerEcho, i)] * pow(delayLevelPerEcho, i);
				}

				else
				{
					soundSamples[j] += effectSamples[j];
				}
			}
		}
	}
}
