#include "AudioPlayer.h"

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

void AudioPlayer::NextParameterSettings()
{
	assert("AudioPlayer trying cause NextParameterSettings");
}

void AudioPlayer::PreviousParameterSettings()
{
	assert("AudioPlayer trying cause PreviousParameterSettings");
}

void AudioPlayer::IncreaseParameter()
{
	assert("AudioPlayer trying cause IncreaseParameter");
}

void AudioPlayer::DecreaseParameter()
{
	assert("AudioPlayer trying cause DecreaseParameter");
}

void AudioPlayer::ChangeEffectStatus()
{
	assert("AudioPlayer trying cause ChangeEffectStatus");
}

void AudioPlayer::UpdateDisplay()
{
	assert("AudioPlayer trying cause UpdateDisplay");
}

const std::shared_ptr<EffectManager>& AudioPlayer::getEffectManager()
{
	assert("AudioPlayer trying cause getEffectManager");
	return effectManager;
}

void AudioPlayer::Play()
{
	Stop();
	display->setText(C_TEXTS::TEXT_ID::Playing);
	playingSound.setBuffer(editedSound);
	playingSound.play();
}

void AudioPlayer::Clean()
{
	Stop();
	display->setText(C_TEXTS::TEXT_ID::PlayingClean);
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
		return false;
	}
	return false;
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
	{
		display->setText(C_TEXTS::TEXT_ID::TextSaved);
		return true;
	}
	else
	{
		display->setText(C_TEXTS::TEXT_ID::ProblemWithSave);
		return false;
	}
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

void AudioPlayer::UpdateEditedSound(const std::shared_ptr<EffectManager>& firstButtonManager, const std::shared_ptr<EffectManager>& secondButtonManager,
	const std::shared_ptr<EffectManager>& thirdButtonManager, const std::shared_ptr<EffectManager>& fourthButtonManager)
{
	firstButtonManager->remakeSound(editedSound);
	secondButtonManager->remakeSound(editedSound);
	thirdButtonManager->remakeSound(editedSound);
	fourthButtonManager->remakeSound(editedSound);
}
