#include "TremoloSoundEffect.h"

TremoloSoundEffect::TremoloSoundEffect() : startingPhase(0), wetLevel(100), frequency(3), waveformType(WaveformType::sin)
{
}

TremoloSoundEffect::~TremoloSoundEffect()
{
}

void TremoloSoundEffect::makeEffect(std::vector<sf::Int16>& soundSamples, unsigned int sampleRate)
{
	assert(wetLevel > 0 && wetLevel < 100);
	assert(frequency > 0 && frequency < 20);
	const float pi = 3.14159265359;
	float trem;

	if (wetLevel >= 50)
	{
		for (auto & iter : soundSamples)
		{
			iter /= 2 * wetLevel / 100;
		}
	}

	for (int i{}; i < soundSamples.size(); i++)
	{
		switch (waveformType)
		{
		case WaveformType::sin:
			trem = 1 + wetLevel / 100 * (sin(startingPhase + 2 * pi * i * frequency / sampleRate));
			break;

		case WaveformType::triangle:
			trem = 1 + wetLevel / 100 * (2 * abs(remainder(((startingPhase + 270) / 60 + 2 * pi * i * frequency / sampleRate), 6) - 3) / 3 - 1);
			break;

		case WaveformType::sawtooth:
			trem = 1 + wetLevel / 100 * ((remainder(((startingPhase + 180) / 180 + 2 * pi * i / 3 * frequency / sampleRate), 2) - 1));
			break;

		case WaveformType::inverse_sawtooth:
			trem = 1 + wetLevel / 100 * -1 * (remainder(((startingPhase + 180) / 180 + 2 * pi * i / 3 * frequency / sampleRate), 2) - 1);
			break;

		case WaveformType::square:
			trem = (1 + wetLevel / 100 * remainder(((startingPhase) / 60 + 2 * pi * i * frequency / sampleRate), 6) < 3 ? 1 : -1);
			break;

		default:
			assert("In waves choice error");
			break;
		}

		soundSamples[i] *= trem;
	}
}
