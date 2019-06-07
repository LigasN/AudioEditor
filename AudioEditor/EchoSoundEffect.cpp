#include "EchoSoundEffect.h"
#include <iostream>

EchoSoundEffect::EchoSoundEffect() : delayTime(3), decayFactor(1), parameterOnDisplay(0), numberOfParameters(2), effectStatus(false)
{
	std::cout << "EchoSoundEffect::EchoSoundEffect() CONSTRUCTOR" << std::endl;
}

EchoSoundEffect::~EchoSoundEffect()
{
}

void EchoSoundEffect::ParamDisplay(const std::shared_ptr <Display> & display)
{
	parameterOnDisplay %= numberOfParameters + 1;
	std::cout << "EchoSoundEffect::ParamDisplay(" << parameterOnDisplay << std::endl;

	switch (parameterOnDisplay)
	{
	case 0:
		display->setText(C_TEXTS::TEXT_ID::EffectName, C_TEXTS::TEXT_ID::Echo);
		break;

	case 1:
		display->setText(C_TEXTS::TEXT_ID::Delay_time, std::to_wstring(delayTime));
		break;

	case 2:
		display->setText(C_TEXTS::TEXT_ID::Decay_factor, std::to_wstring(decayFactor));
		break;

	default:
		assert("Error in EchoSoundEffect's parameters sended to display");
		break;
	}

}

void EchoSoundEffect::IncreaseParameter()
{
	parameterOnDisplay %= numberOfParameters + 1;

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
	parameterOnDisplay %= numberOfParameters + 1;

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
		assert("Error in EchoSoundEffect's parameters sended to increase");
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

void EchoSoundEffect::NextParameterSettings()
{
	parameterOnDisplay++;
	parameterOnDisplay %= numberOfParameters + 1;
	std::cout << "EchoSoundEffect::NextParameterSettings():\t" << parameterOnDisplay << std::endl;
}

void EchoSoundEffect::PreviousParameterSettings()
{
	if (parameterOnDisplay == 0)
		parameterOnDisplay = numberOfParameters;
	else
		parameterOnDisplay--;
	std::cout << "EchoSoundEffect::PreviousParameterSettings():\t" << parameterOnDisplay << std::endl;
}

SoundEffect::Effects EchoSoundEffect::GetEffectName()
{
	return SoundEffect::Effects::Echo;
}

unsigned int EchoSoundEffect::GetParameterOnDisplay()
{
	return parameterOnDisplay;
}

void EchoSoundEffect::ChangeEffectStatus()
{
	effectStatus = !effectStatus;
	std::cout << "EchoSoundEffect::ChangeEffectStatus():\t" << effectStatus << std::endl;
}
