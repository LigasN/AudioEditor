
#ifndef AUDIOPLAYER_CPP
#define AUDIOPLAYER_CPP

#include "AudioPlayer.h"

namespace NL
{
	AudioPlayer::AudioPlayer(const std::shared_ptr<Display>& display) : AudioEditorState(display)
	{
		sf::SoundBuffer buffer;
		buffer.loadFromFile("Gitara.wav");
		editedSound = cleanSound = buffer;
	}

	AudioPlayer::~AudioPlayer()
	{
	}

	AudioEditorState::States AudioPlayer::getStateName()
	{
		return AudioEditorState::States::Player;
	}

	void AudioPlayer::Play()
	{
		display->setText(C_TEXTS::TEXT_ID::Playing);
		Stop();
		playingSound.setBuffer(editedSound);
		playingSound.play();
	}

	void AudioPlayer::Clean()
	{
		display->setText(C_TEXTS::TEXT_ID::PlayingClean);
		Stop();
		playingSound.setBuffer(cleanSound);
		playingSound.play();

	}

	void AudioPlayer::Stop()
	{
		display->setText(C_TEXTS::TEXT_ID::Stopped);
		playingSound.stop();
	}

	bool AudioPlayer::GetStatus()
	{
		switch (playingSound.getStatus())
		{
		case sf::Sound::Playing:

			return true;

		case sf::Sound::Stopped:

			return false;

		case sf::Sound::Paused:

			assert("Sound is paused. How?");
		}

	}

	bool AudioPlayer::GetSavingState()
	{
		return savingState;
	}

	void AudioPlayer::ResetSavingState()
	{
		savingState = false;
	}

	void AudioPlayer::SetSavingState()
	{
		display->setText(C_TEXTS::TEXT_ID::SavingQuestion);
		savingState = true;
	}

	bool AudioPlayer::Save()
	{
		if (editedSound.saveToFile("TestSoundEdited.wav"))
			display->setText(C_TEXTS::TEXT_ID::TextSaved);
		else
			display->setText(C_TEXTS::TEXT_ID::ProblemWithSave);
	}

	sf::SoundBuffer AudioPlayer::getCleanSound()
	{
		return cleanSound;
	}

	void AudioPlayer::setCleanSound(sf::SoundBuffer cleanSound)
	{
		this->cleanSound = cleanSound;
	}

	void AudioPlayer::setEditedSound(sf::SoundBuffer newEditedSound)
	{
		editedSound = newEditedSound;
	}

	void AudioPlayer::UpdateEditedSound(const std::shared_ptr<FirstButtonEffect>& firstButtonEffect, const std::shared_ptr<SecondButtonEffect>& secondButtonEffect,
		const std::shared_ptr<ThirdButtonEffect>& thirdButtonEffect, const std::shared_ptr<FourthButtonEffect>& fourthButtonEffect)
	{
		std::shared_ptr<EffectManager> effectManager1(firstButtonEffect->getEffectManager());
		effectManager1->remakeSound(editedSound);
		std::shared_ptr<EffectManager> effectManager2(secondButtonEffect->getEffectManager());
		effectManager2->remakeSound(editedSound);
		std::shared_ptr<EffectManager> effectManager3(thirdButtonEffect->getEffectManager());
		effectManager3->remakeSound(editedSound);
		std::shared_ptr<EffectManager> effectManager4(fourthButtonEffect->getEffectManager());
		effectManager4->remakeSound(editedSound);
	}
}
#endif // !AUDIOPLAYER_CPP
