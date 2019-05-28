#pragma once

#include "SoundEffect.h"
#include "FFT_IFFT.h"

class WahWahSoundEffect : public SoundEffect
{
public:

	enum class Parameters
	{
		LFO_Frequency,			//Sets the speed at which the band - pass filter is swept back and forth.
		LFO_Start_Phase,		//The start position of the LFO cycle.This determines whether the band - pass filter starts at its lowest, mid or highest frequencies.Another way to look at it is that it determines whether at the start of the effect the pitch is rising or falling.
		Depth,					//Determines the range of frequencies that are swept through by the band - pass filter.Higher values will sweep the filter to higher frequencies and so give more variation to the sound quality over a complete LFO cycle.Lower values will give a more constant sound effect.
		Resonance,				//Determines the degree of resonance in the band - pass filter.Higher values give a more "peaky" effect.
		Wah_Frequency_Offset,	//Determines the "base" frequency of the band - pass filter.Higher values will shift the filter's frequency range upwards. To achieve a Wah effect that's in the low frequencies the frequency offset needs to be set to a low value.
		Output_gain				//(dB)	Controls the amount of gain(volume) positive or negative that will be applied by the effect.
	};

	WahWahSoundEffect();
	~WahWahSoundEffect();

private:

	void  makeEffect(std::vector <sf::Int16> & soundSample, unsigned int sampleRate);			//funcja zmieniana przez design pattern strategy
};

