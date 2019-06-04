#pragma once

#include "Display.h"
#include "C_TEXTS.h"
#include "EffectManager.h"

class AudioEditorState
{
public:

	enum class States
	{
		BaseClass,
		NoneEffectState,
		FirstButtonEffect,
		SecondButtonEffect,
		ThirdButtonEffect,
		FourthButtonEffect,
		Player
	};

protected:

	const std::shared_ptr <Display> display;
	const std::shared_ptr <EffectManager> effectManager;

public:
	AudioEditorState();
	AudioEditorState(const std::shared_ptr <Display> & display);
	~AudioEditorState();
	virtual States getStateName();
	virtual void NextParameterSettings();
	virtual void PreviousParameterSettings();
	virtual void IncreaseParameter();
	virtual void DecreaseParameter();
	virtual void ChangeEffectStatus();
	virtual void UpdateDisplay();
	virtual const std::shared_ptr <EffectManager> & getEffectManager();
};