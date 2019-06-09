#include "AudioEditorState.h"

AudioEditorState::AudioEditorState(): display(std::make_shared <Display> ()), effectManager(std::make_shared <EffectManager>())
{
}

AudioEditorState::AudioEditorState(const std::shared_ptr <Display> & display) : display(display), effectManager(std::make_shared <EffectManager> ())
{
}

AudioEditorState::~AudioEditorState()
{
}

AudioEditorState::States AudioEditorState::getStateName()
{
	return States::BaseClass;
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

void AudioEditorState::UpdateEffectStatus(bool buttonStatus)
{
	effectManager->UpdateEffectStatus(buttonStatus);
}

void AudioEditorState::UpdateDisplay()
{
	effectManager->DisplayParameters(display);
}

const std::shared_ptr<EffectManager>& AudioEditorState::getEffectManager()
{
	return effectManager;
}