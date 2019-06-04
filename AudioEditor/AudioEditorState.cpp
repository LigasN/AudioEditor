#include "AudioEditorState.h"
#include <iostream>

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
	std::cout << "effectManager->NextParameterSettings();\tAudioEditorState::NextParameterSettings() " << std::endl;
	effectManager->NextParameterSettings();
}

void AudioEditorState::PreviousParameterSettings()
{

	std::cout << "effectManager->PreviousParameterSettings();\tAudioEditorState::PreviousParameterSettings() " << std::endl;
	effectManager->PreviousParameterSettings();
}

void AudioEditorState::IncreaseParameter()
{

	std::cout << "effectManager->IncreaseParameter();\tAudioEditorState::IncreaseParameter() " << std::endl;
	effectManager->IncreaseParameter();
}

void AudioEditorState::DecreaseParameter()
{

	std::cout << "effectManager->DecreaseParameter();\tAudioEditorState::DecreaseParameter() " << std::endl;
	effectManager->DecreaseParameter();
}

void AudioEditorState::ChangeEffectStatus()
{

	std::cout << "effectManager->ChangeEffectStatus();\tAudioEditorState::ChangeEffectStatus() " << std::endl;
	effectManager->ChangeEffectStatus();
}

void AudioEditorState::UpdateDisplay()
{

	std::cout << "effectManager->UpdateDisplay();\tAudioEditorState::ParamDisplay() " << std::endl;
	effectManager->DisplayParameters(display);
}

const std::shared_ptr<EffectManager>& AudioEditorState::getEffectManager()
{
	return effectManager;
}