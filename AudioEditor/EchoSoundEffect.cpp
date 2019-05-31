#include "EchoSoundEffect.h"

#ifndef ECHOSOUNDEFFECT_CPP
#define ECHOSOUNDEFFECT_CPP

namespace NL
{
	EchoSoundEffect::EchoSoundEffect() : delayTime(3), decayFactor(1), parameterOnDisplay(0)
	{
	}

	EchoSoundEffect::~EchoSoundEffect()
	{
	}

	void EchoSoundEffect::ParamDisplay(const std::shared_ptr <Display> & display)
	{
		parameterOnDisplay %= 3;

		switch (parameterOnDisplay)
		{
		case 0:
			display->setText(C_TEXTS::TEXT_ID::EffectName, C_TEXTS::TEXT_ID::Echo);

		case 1:
			display->setText(C_TEXTS::TEXT_ID::Delay_time, std::to_wstring(delayTime));

		case 2:
			display->setText(C_TEXTS::TEXT_ID::Decay_factor, std::to_wstring(decayFactor));

		default:
			assert("Error in EchoSoundEffect's parameters sended to display");
			break;
		}

	}

	void EchoSoundEffect::IncreaseParameter()
	{
		parameterOnDisplay %= 3;

		switch (parameterOnDisplay)
		{
		case 1:
			delayTime++;
			break;

		case 3:
			decayFactor++;
			decayFactor = remainderf(decayFactor, 100);
			break;

		case 0:
		default:
			assert("Error in EchoSoundEffect's parameters sended to increase");
			break;
		}
	}

	void EchoSoundEffect::DecreaseParameter()
	{
		parameterOnDisplay %= 3;

		switch (parameterOnDisplay)
		{
		case 1:
			if (delayTime > 1)
				delayTime--;
			break;

		case 2:
			if (decayFactor > 1)
				decayFactor--;
			break;

		case 0:
		default:
			assert("Error in TremoloSoundEffect's parameters sended to increase");
			break;
		}
	}

	void EchoSoundEffect::makeEffect(std::vector<sf::Int16>& soundSamples, unsigned int sampleRate)
	{
		if (effectStatus == true)
		{
			assert(delayTime > 0);
			assert(decayFactor > 0 || decayFactor < 10);

			int delay = sampleRate * delayTime;
			int repetition = soundSamples.size() / delay;

			std::vector <sf::Int16> effectSamples = soundSamples;

			for (int i = 1; i <= repetition; i++)
			{
				for (int j{}; j < (int)effectSamples.size(); j++)
				{
					if (j > delay * i)
					{
						soundSamples[j] += (sf::Int16)(effectSamples[j - delay * i] * pow(decayFactor, i));
					}
				}
			}
		}
	}
}
#endif // !ECHOSOUNDEFFECT_CPP
