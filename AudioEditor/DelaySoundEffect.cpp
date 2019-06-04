
#ifndef DELAYSOUNDEFFECT_CPP
#define DELAYSOUNDEFFECT_CPP

#include "DelaySoundEffect.h"

namespace NL
{
	DelaySoundEffect::DelaySoundEffect() : delayLevelPerEcho(1), delayTime(1), pitchChangeEffect(1.5), pitchChangePerEcho(1.5), numberOfEchoes(5), parameterOnDisplay(0)
	{
	}

	DelaySoundEffect::~DelaySoundEffect()
	{
	}

	void DelaySoundEffect::makeEffect(std::vector<sf::Int16>& soundSamples, unsigned int sampleRate)
	{
		if (effectStatus == true)
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
	}

	void DelaySoundEffect::ParamDisplay(const std::shared_ptr <Display> & display)
	{
		parameterOnDisplay %= 6;

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
		parameterOnDisplay %= 6;

		switch (parameterOnDisplay)
		{
		case 1:
			delayLevelPerEcho++;
			break;

		case 2:
			delayTime++;
			break;

		case 3:
			pitchChangeEffect++;
			break;

		case 4:
			pitchChangePerEcho++;
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
		parameterOnDisplay %= 6;

		switch (parameterOnDisplay)
		{
		case 1:
			delayLevelPerEcho--;
			break;

		case 2:
			if (delayTime > 1)
				delayTime--;
			break;

		case 3:
			if (pitchChangeEffect > 1)
				pitchChangeEffect--;
			break;

		case 4:
			if (pitchChangePerEcho > 1)
				pitchChangePerEcho--;
			break;

		case 5:
			if (pitchChangePerEcho > 0)
				pitchChangePerEcho--;
			break;

		case 0:
		default:
			assert("Error in TremoloSoundEffect's parameters sended to increase");
			break;
		}
	}
}
#endif // !DELAYSOUNDEFFECT_CPP