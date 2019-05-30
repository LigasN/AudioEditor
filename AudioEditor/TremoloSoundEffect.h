#pragma once

#include "SoundEffect.h"
#include <assert.h>

class TremoloSoundEffect : public SoundEffect
{
public:

	enum class Parameters
	{
		waveform_type,
		startingPhase,
		wetLevel,
		frequency
	};

	enum class WaveformType
	{
		sin,
		triangle,
		sawtooth,
		inverse_sawtooth,
		square
	};

	TremoloSoundEffect();
	~TremoloSoundEffect();

private:
	//Waveform type
	//Determines the "shape" of each tremolo(how it progresses between the lowest and highest volume as determined by the wetness level).Choice of sine, triangle, sawtooth, inverse sawtooth, square.

	WaveformType waveformType;

	//Starting phase(degrees)
	//Sets where to start the tremolo in the waveform cycle.The default (zero)starts the tremolo at the start of the cycle(as the waveform starts to rise from the lowest point).
	int startingPhase;

	//Wet level(percent)
	//Sets the depth of tremolo. 0 % is no tremolo, 100 % sweeps between zero and maximum volume based on the original amplitude level.
	int wetLevel; // (percent)

	//frequency(Hz) 10 is quite much
	//Controls the speed of the oscillation; use higher frequencies for faster oscillation.
	int frequency;

	void  makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate);			//funcja zmieniana przez design pattern strategy
};

