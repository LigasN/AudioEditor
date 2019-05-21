#pragma once

#include "AudioEditorState.h"
#include "SFML/Audio.hpp"

class AudioPlayer : public AudioEditorState
{
private:
	bool savingState;
	sf::SoundBuffer cleanSound;
	sf::SoundBuffer editedSound;
	sf::Sound playingSound;
public:
	AudioPlayer(std::shared_ptr <Display> display);
	~AudioPlayer();
	States getStateName();
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

};
