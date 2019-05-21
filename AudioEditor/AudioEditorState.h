#pragma once

#include "AudioEditorManager.h"
#include "SoundEffect.h"
#include "AudioPlayer.h"

class AudioEditorState
{
public:

	enum class States
	{
		NoneEffectState,
		FirstButtonEffect,
		SecondButtonEffect,
		ThirdButtonEffect,
		FourthButtonEffect,
		Player
	};

protected:

	States name;

public:

	virtual States getStateName() = 0;
	virtual void NextParameterSettings() = 0;				// do ustawienia w pozostalych stanach
	virtual void PreviousParameterSettings() = 0;				// do ustawienia w pozostalych stanach
	virtual void IncreaseParameter() = 0;				// do ustawienia w pozostalych stanach
	virtual void DecreaseParameter() = 0;				// do ustawienia w pozostalych stanach
	virtual void StartDisplay() = 0;				// do ustawienia w pozostalych stanach
	virtual void ChangeEffectStatus() = 0;				// do ustawienia w pozostalych stanach
};

