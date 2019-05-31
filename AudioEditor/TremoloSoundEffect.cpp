
#ifndef TREMOLOSOUNDEFFECT_CPP
#define TREMOLOSOUNDEFFECT_CPP

#include "TremoloSoundEffect.h"

namespace NL
{
	TremoloSoundEffect::TremoloSoundEffect() : startingPhase(0), wetLevel(100), frequency(3), waveformType(WaveformType::sin), parameterOnDisplay(0)
	{
	}

	TremoloSoundEffect::~TremoloSoundEffect()
	{
	}

	void TremoloSoundEffect::ParamDisplay(const std::shared_ptr <Display> & display)
	{
		parameterOnDisplay %= 6;

		switch (parameterOnDisplay)
		{
		case 0:

			display->setText(C_TEXTS::TEXT_ID::EffectName, C_TEXTS::TEXT_ID::Tremolo);
			break;

		case 1:
			switch (waveformType)
			{
			case TremoloSoundEffect::WaveformType::sin:

				display->setText(C_TEXTS::TEXT_ID::waveform_type, C_TEXTS::TEXT_ID::sin);
				break;

			case TremoloSoundEffect::WaveformType::triangle:

				display->setText(C_TEXTS::TEXT_ID::waveform_type, C_TEXTS::TEXT_ID::triangle);
				break;

			case TremoloSoundEffect::WaveformType::sawtooth:

				display->setText(C_TEXTS::TEXT_ID::waveform_type, C_TEXTS::TEXT_ID::sawtooth);
				break;

			case TremoloSoundEffect::WaveformType::inverse_sawtooth:

				display->setText(C_TEXTS::TEXT_ID::waveform_type, C_TEXTS::TEXT_ID::inverse_sawtooth);
				break;

			case TremoloSoundEffect::WaveformType::square:

				display->setText(C_TEXTS::TEXT_ID::waveform_type, C_TEXTS::TEXT_ID::square);
				break;

			default:
				assert("Error in TremoloSoundEffect's parameters sended to display");
				break;
			}

		case 2:

			display->setText(C_TEXTS::TEXT_ID::Drive, std::to_wstring(startingPhase));
			break;

		case 3:

			display->setText(C_TEXTS::TEXT_ID::Drive, std::to_wstring(wetLevel));
			break;

		case 4:

			display->setText(C_TEXTS::TEXT_ID::Drive, std::to_wstring(frequency));
			break;

		default:
			assert("Error in TremoloSoundEffect's parameters sended to display");
			break;
		}

	}

	void TremoloSoundEffect::IncreaseParameter()
	{
		parameterOnDisplay %= 6;
		switch (parameterOnDisplay)
		{
		case 1:
			switch (waveformType)
			{
			case TremoloSoundEffect::WaveformType::sin:
				waveformType = WaveformType::triangle;
				break;

			case TremoloSoundEffect::WaveformType::triangle:
				waveformType = WaveformType::sawtooth;
				break;

			case TremoloSoundEffect::WaveformType::sawtooth:
				waveformType = WaveformType::inverse_sawtooth;
				break;

			case TremoloSoundEffect::WaveformType::inverse_sawtooth:
				waveformType = WaveformType::square;
				break;

			case TremoloSoundEffect::WaveformType::square:
				waveformType = WaveformType::sin;
				break;

			default:
				assert("Error in increasing waveformType");
				break;
			}
			break;

		case 2:
			startingPhase++;
			break;

		case 3:
			wetLevel++;
			wetLevel %= 100;
			break;

		case 4:
			frequency++;
			frequency %= 20;
			break;

		case 0:
		default:
			assert("Error in TremoloSoundEffect's parameters sended to increase");
			break;
		}
	}

	void TremoloSoundEffect::DecreaseParameter()
	{
		parameterOnDisplay %= 6;
		switch (parameterOnDisplay)
		{
		case 1:
			switch (waveformType)
			{
			case TremoloSoundEffect::WaveformType::sin:
				waveformType = WaveformType::square;
				break;

			case TremoloSoundEffect::WaveformType::triangle:
				waveformType = WaveformType::sin;
				break;

			case TremoloSoundEffect::WaveformType::sawtooth:
				waveformType = WaveformType::triangle;
				break;

			case TremoloSoundEffect::WaveformType::inverse_sawtooth:
				waveformType = WaveformType::sawtooth;
				break;

			case TremoloSoundEffect::WaveformType::square:
				waveformType = WaveformType::inverse_sawtooth;
				break;

			default:
				assert("Error in increasing waveformType");
				break;
			}
			break;

		case 2:
			startingPhase--;
			break;

		case 3:
			if (wetLevel > 1)
				wetLevel--;
			break;

		case 4:
			if (frequency > 1)
				frequency--;
			break;

		case 0:
		default:
			assert("Error in TremoloSoundEffect's parameters sended to decrease");
			break;
		}
	}

	void TremoloSoundEffect::makeEffect(std::vector<sf::Int16>& soundSamples, unsigned int sampleRate)
	{
		if (effectStatus == true)
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
	}
}
#endif // !TREMOLOSOUNDEFFECT_CPP
