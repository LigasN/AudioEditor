#pragma once

#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "AudioEditorState.h"
#include "SFML/Audio.hpp"
#include "Buttons.h"

namespace NL
{
	class AudioPlayer : public AudioEditorState
	{
	private:
		bool savingState;
		sf::SoundBuffer cleanSound;
		sf::SoundBuffer editedSound;
		sf::Sound playingSound;

	public:
		AudioPlayer(const std::shared_ptr <Display> & display);
		~AudioPlayer();
		virtual States getStateName() override;
		void Play();
		void Clean();
		void Stop();
		bool GetStatus();
		bool GetSavingState();
		void ResetSavingState();
		void SetSavingState();
		bool Save();
		sf::SoundBuffer getCleanSound();
		void setCleanSound(sf::SoundBuffer cleanSound);
		void setEditedSound(sf::SoundBuffer newEditedSound);
		void UpdateEditedSound(const std::shared_ptr <FirstButtonEffect> & firstButtonEffect, const std::shared_ptr <SecondButtonEffect> & secondButtonEffect,
			const std::shared_ptr <ThirdButtonEffect> & thirdButtonEffect, const std::shared_ptr <FourthButtonEffect> & fourthButtonEffect);
	};
}
#endif // !AUDIOPLAYER_H