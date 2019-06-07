#pragma once

#include "SFML/Audio.hpp"
#include "AudioEditorState.h"
#include "Buttons.h"

class AudioPlayer : public AudioEditorState
{
private:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Private variable in AudioPlayer class
	///
	/// Aim: Stores information about working state. If true we are saving file right now.
	///
	/// Type: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool savingState;

	sf::SoundBuffer cleanSound;
	sf::SoundBuffer editedSound;
	sf::Sound playingSound;

public:
	AudioPlayer(const std::shared_ptr <Display> & display);
	~AudioPlayer();
	virtual States getStateName() override;
	virtual void NextParameterSettings() override;
	virtual void PreviousParameterSettings() override;
	virtual void IncreaseParameter() override;
	virtual void DecreaseParameter() override;
	virtual void ChangeEffectStatus() override;
	virtual void UpdateDisplay() override;
	virtual const std::shared_ptr <EffectManager> & getEffectManager() override;
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
	void UpdateEditedSound(const std::shared_ptr<EffectManager>& firstButtonManager, const std::shared_ptr<EffectManager>& secondButtonManager,
		const std::shared_ptr<EffectManager>& thirdButtonManager, const std::shared_ptr<EffectManager>& fourthButtonManager);
};