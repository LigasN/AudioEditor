#include "DistortionSoundEffect.h"


DistortionSoundEffect::DistortionSoundEffect()
{
}

DistortionSoundEffect::~DistortionSoundEffect()
{
}

void DistortionSoundEffect::makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate)
{
	assert(clippingLevel < 0 || clippingLevel > -100);
	assert(drive > 0 || drive < 100);
	assert(makeUpGain > 0 || makeUpGain < 100);

	int cutOffLevel{};

	if (clippingLevel < 0)
	{
		cutOffLevel = 23001 + (23000 / 100) * clippingLevel;
	}

	else
	{
		cutOffLevel = 23000;
	}

	auto max = max_element(std::begin(soundSamples), std::end(soundSamples));
	auto min = min_element(std::begin(soundSamples), std::end(soundSamples));

	auto ratio = -*min / cutOffLevel;

	if (*max > -*min)
	{
		auto ratio = *max / cutOffLevel;
	}

	for (auto iter = soundSamples.begin(); iter != soundSamples.end(); ++iter)
	{
		*iter *= (drive / 10) + 1;

		if (*iter > cutOffLevel) {

			*iter = cutOffLevel;

		}

		else if (*iter < -1 * cutOffLevel)
		{

			*iter = -1 * cutOffLevel;

		}

		*iter *= (1 + (makeUpGain / 100)) * ratio;
	}
}
