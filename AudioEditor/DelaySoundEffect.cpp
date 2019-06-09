#include "DelaySoundEffect.h"

DelaySoundEffect::DelaySoundEffect() : SoundEffect(), delayLevelPerEcho(1), delayTime(1), pitchChangeEffect(1.5), pitchChangePerEcho(1.5), numberOfEchoes(5), parameterOnDisplay(0), numberOfParameters(5), effectStatus(false)
{
}

DelaySoundEffect::~DelaySoundEffect()
{
}

void DelaySoundEffect::makeEffect(std::vector<sf::Int16>& soundSamples, unsigned int sampleRate)
{
	if (effectStatus == true)
	{
		assert(delayTime >= 0);
		assert(pitchChangePerEcho >= 0.0);
		assert(numberOfEchoes >= 0);
		assert(pitchChangeEffect > 0);

		int delay = sampleRate * delayTime;

		std::vector <sf::Int16> effectSamples = soundSamples;

		for (unsigned int i = 1; i <= numberOfEchoes; i++)
		{
			for (unsigned int j{}; j < effectSamples.size(); j++)
			{
				if (j > delay * i)
				{
					if ((j - delay * i) * (unsigned int)(pitchChangeEffect * pow(pitchChangePerEcho, i)) < effectSamples.size())
					{
						soundSamples[j] += effectSamples[(j - delay * i) * (unsigned int)(pitchChangeEffect * pow(pitchChangePerEcho, i))] * (pow(delayLevelPerEcho, i));
					}

					else
					{
						soundSamples[j] += effectSamples[j];
					}
				}
			}
		}
	}
}

void DelaySoundEffect::ParamDisplay(const std::shared_ptr <Display> & display)
{
	parameterOnDisplay %= numberOfParameters + 1;
	switch (parameterOnDisplay)
	{
	case 0:

		display->setText(C_TEXTS::TEXT_ID::EffectName, C_TEXTS::TEXT_ID::Delay);
		break;

	case 1:

		display->setText(C_TEXTS::TEXT_ID::Delay_level_per_echo, std::to_wstring(delayLevelPerEcho));
		break;

	case 2:

		display->setText(C_TEXTS::TEXT_ID::Delay_time, std::to_wstring(delayTime));
		break;

	case 3:

		display->setText(C_TEXTS::TEXT_ID::Pitch_change_effect, std::to_wstring(pitchChangeEffect));
		break;

	case 4:

		display->setText(C_TEXTS::TEXT_ID::Pitch_change_per_echo, std::to_wstring(pitchChangePerEcho));
		break;

	case 5:

		display->setText(C_TEXTS::TEXT_ID::Number_of_echoes, std::to_wstring(numberOfEchoes));
		break;

	default:
		assert("Error in DelaySoundEffect's parameters sended to display");
		break;
	}
}

void DelaySoundEffect::IncreaseParameter()
{
	parameterOnDisplay %= numberOfParameters + 1;


	switch (parameterOnDisplay)
	{
	case 1:
		delayLevelPerEcho += 0.1f;
		break;

	case 2:
		delayTime++;
		break;

	case 3:
		pitchChangeEffect += 0.1f;
		break;

	case 4:
		pitchChangePerEcho += 0.1f;
		break;

	case 5:
		numberOfEchoes++;
		break;

	case 0:
	default:
		assert("Error in DelaySoundEffect's parameters sended to increase");
		break;
	}
}

void DelaySoundEffect::DecreaseParameter()
{
	parameterOnDisplay %= numberOfParameters + 1;

	switch (parameterOnDisplay)
	{
	case 1:
		if (delayLevelPerEcho > 0)
			delayLevelPerEcho -= 0.1f;
		else
			delayLevelPerEcho = 2;
		break;

	case 2:
		if (delayTime > 0)
			delayTime--;
		else
			delayTime = 5;
		break;

	case 3:
		if (pitchChangeEffect > 0)
			pitchChangeEffect -= 0.1f;
		else
			pitchChangeEffect = 2;
		break;

	case 4:
		if (pitchChangePerEcho > 0)
			pitchChangePerEcho -= 0.1f;
		else
			pitchChangePerEcho = 2;
		break;

	case 5:
		if (numberOfEchoes > 0)
			numberOfEchoes--;
		else
			numberOfEchoes = 5;
		break;

	case 0:
	default:
		assert("Error in TremoloSoundEffect's parameters sended to increase");
		break;
	}
}

void DelaySoundEffect::NextParameterSettings()
{
	parameterOnDisplay++;
	parameterOnDisplay %= numberOfParameters + 1;
}

void DelaySoundEffect::PreviousParameterSettings()
{
	if (parameterOnDisplay == 0)
		parameterOnDisplay = numberOfParameters;
	else
		parameterOnDisplay--;
}

SoundEffect::Effects DelaySoundEffect::GetEffectName()
{
	return SoundEffect::Effects::Delay;
}

unsigned int DelaySoundEffect::GetParameterOnDisplay()
{
	return parameterOnDisplay;
}

void DelaySoundEffect::UpdateEffectStatus(bool buttonStatus)
{
	switch (buttonStatus)
	{
	case true:
		effectStatus = true;
		break;

	case false:
		effectStatus = false;
		break;
	}
}
