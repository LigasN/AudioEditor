#pragma once

#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H

#include <vector>
#include "SFML/Audio.hpp"
#include <assert.h>
#include <math.h>

namespace NL
{
	class SoundEffect
	{
	private:

		virtual void makeEffect(std::vector <sf::Int16> & soundSamples) = 0; //przylad funkcja uzywana wewnetrznie zeby ostatecznie przekazac efekt do remakeSound()

	protected:
		unsigned int parameterOnDisplay;
		bool effectStatus;

	public:

		SoundEffect();
		~SoundEffect();

		sf::SoundBuffer remakeSound(sf::SoundBuffer & sound);

		virtual void NextParameterSettings();
		virtual void PreviousParameterSettings();
		virtual void IncreaseParameter() = 0;
		virtual void DecreaseParameter() = 0;
		virtual void ChangeEffectStatus();
		virtual unsigned int GetParameterOnDisplay();
	};
}
#endif // !SOUNDEFFECT_H
