
#ifndef AUDIOEDITORSTATE_CPP
#define AUDIOEDITORSTATE_CPP

#include "AudioEditorState.h"

namespace NL
{

	AudioEditorState::AudioEditorState(const std::shared_ptr <Display> & display) : display(display), effectManager()
	{
	}

	AudioEditorState::~AudioEditorState()
	{
	}

	void AudioEditorState::NextParameterSettings()
	{
		effectManager->NextParameterSettings();
	}

	void AudioEditorState::PreviousParameterSettings()
	{
		effectManager->PreviousParameterSettings();
	}

	void AudioEditorState::IncreaseParameter()
	{
		effectManager->IncreaseParameter();
	}

	void AudioEditorState::DecreaseParameter()
	{
		effectManager->DecreaseParameter();
	}

	void AudioEditorState::ChangeEffectStatus()
	{
		effectManager->ChangeEffectStatus();
	}

	void AudioEditorState::UpdateDisplay()
	{
		effectManager->ParamDisplay(display);
	}

	const std::shared_ptr<EffectManager>& AudioEditorState::getEffectManager()
	{
		return effectManager;
	}

}

#endif // !AUDIOEDITORSTATE_CPP