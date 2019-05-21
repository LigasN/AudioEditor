#pragma once

#include <vector>
//#include "AudioEditorState.h"

class SoundEffect
{
private:
	
	virtual std::vector <float> generateEffectSamples() = 0; //przylad funkcja uzywana wewnetrznie zeby ostatecznie przekazac efekt do updateSound()

public:

	SoundEffect();
	~SoundEffect();

	bool updateSound();

};

