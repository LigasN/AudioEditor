#include "NoneEffectState.h"

NoneEffectState::NoneEffectState(const std::shared_ptr <Display> & display) : AudioEditorState(display)
{
}


NoneEffectState::~NoneEffectState()
{
}

AudioEditorState::States NoneEffectState::getStateName()
{
	return AudioEditorState::States::NoneEffectState;
}

const std::shared_ptr<EffectManager>& NoneEffectState::getEffectManager()
{
	assert("NoneEffectState trying cause getEffectManager");
	return effectManager;
}

void NoneEffectState::NextParameterSettings()
{
	assert("NoneEffectState trying cause NextParameterSettings");
}

void NoneEffectState::PreviousParameterSettings()
{
	assert("NoneEffectState trying cause PreviousParameterSettings");
}

void NoneEffectState::IncreaseParameter()
{
	assert("NoneEffectState trying cause IncreaseParameter");
}

void NoneEffectState::DecreaseParameter()
{
	assert("NoneEffectState trying cause DecreaseParameter");
}

void NoneEffectState::UpdateEffectStatus(bool buttonStatus)
{
	assert("NoneEffectState trying cause UpdateEffectStatus");
}

void NoneEffectState::UpdateDisplay()
{
	assert("NoneEffectState trying cause UpdateDisplay");
}