#include "DistortionSoundEffect.h"

#ifndef DISTORTIONSOUNDEFFECT_CPP
#define DISTORTIONSOUNDEFFECT_CPP

namespace NL
{
	DistortionSoundEffect::DistortionSoundEffect() : clippingLevel(-10), drive(10), makeUpGain(10), parameterOnDisplay(0)
	{
	}

	DistortionSoundEffect::~DistortionSoundEffect()
	{
	}

	void DistortionSoundEffect::ParamDisplay(const std::shared_ptr <Display> & display)
	{
		parameterOnDisplay %= 4;

		switch (parameterOnDisplay)
		{
		case 0:
			display->setText(C_TEXTS::TEXT_ID::EffectName, C_TEXTS::TEXT_ID::Distortion);
			break;

		case 1:
			display->setText(C_TEXTS::TEXT_ID::Clipping_level, std::to_wstring(clippingLevel));
			break;

		case 2:
			display->setText(C_TEXTS::TEXT_ID::Drive, std::to_wstring(drive));
			break;

		case 3:
			display->setText(C_TEXTS::TEXT_ID::Make_up_Gain, std::to_wstring(makeUpGain));
			break;

		default:
			assert("Error in DistortionSoundEffect's parameters sended to display");
			break;
		}

	}

	void DistortionSoundEffect::IncreaseParameter()
	{
		parameterOnDisplay %= 4;

		switch (parameterOnDisplay)
		{
		case 1:
			if (clippingLevel < 0)
				clippingLevel++;
			break;

		case 2:
			drive++;
			drive %= 101;
			break;

		case 3:
			makeUpGain++;
			makeUpGain %= 101;
			break;

		case 0:
		default:
			assert("Error in DistortionSoundEffect's parameters sended to increase");
			break;
		}
	}

	void DistortionSoundEffect::DecreaseParameter()
	{
		parameterOnDisplay %= 4;

		switch (parameterOnDisplay)
		{
		case 1:
			clippingLevel--;
			clippingLevel %= -101;
			break;

		case 2:
			if (drive > 0)
				drive--;
			break;

		case 3:
			if (makeUpGain > 0)
				makeUpGain--;
			break;

		case 0:
		default:
			assert("Error in DistortionSoundEffect's parameters sended to decrease");
			break;
		}
	}

	void DistortionSoundEffect::makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate)
	{
		if (effectStatus == true)
		{
			assert(clippingLevel <= 0 && clippingLevel >= -100);
			assert(drive >= 0 && drive <= 100);
			assert(makeUpGain >= 0 && makeUpGain <= 100);

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
	}
}
#endif // !DISTORTIONSOUNDEFFECT_CPP