#pragma once

#include <vector>
#include "SFML/Audio.hpp"

class SoundEffect
{
private:
	
	virtual std::vector <float> makeEffect() = 0; //przylad funkcja uzywana wewnetrznie zeby ostatecznie przekazac efekt do remakeSound()

public:

	SoundEffect();
	~SoundEffect();

	sf::SoundBuffer remakeSound(sf::SoundBuffer & sound);
};

