#pragma once

#include <vector>
#include "SFML/Audio.hpp"
#include <assert.h>
#include <math.h>

class SoundEffect
{
private:
	
	virtual void makeEffect(std::vector <sf::Int16> & soundSamples) = 0; //przylad funkcja uzywana wewnetrznie zeby ostatecznie przekazac efekt do remakeSound()

public:

	SoundEffect();
	~SoundEffect();

	sf::SoundBuffer remakeSound(sf::SoundBuffer & sound);
};

