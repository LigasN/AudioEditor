#pragma once

#include "AudioEditorState.h"


class AudioPlayer : public AudioEditorState
{
private:
	bool savingState;

public:
	AudioPlayer();
	~AudioPlayer();
	States getStateName();
	void Play();
	void Clean();
	void Stop();
	//ma mi dac info czy muzyka gra czy nie true jak gra
	bool GetStatus();
	bool GetSavingState();
	void ResetSavingState();
	void SetSavingState();
	bool Save();
};
