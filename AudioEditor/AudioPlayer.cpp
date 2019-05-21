#include "AudioPlayer.h"



AudioPlayer::AudioPlayer(const std::shared_ptr <Display> display) : AudioEditorState(display, States::Player)
{
}


AudioPlayer::~AudioPlayer()
{
}

AudioEditorState::States AudioPlayer::getStateName()
{
	return name;
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

