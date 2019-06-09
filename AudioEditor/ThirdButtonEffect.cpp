#include "ThirdButtonEffect.h"

ThirdButtonEffect::ThirdButtonEffect(const std::shared_ptr <Display> & display) : AudioEditorState(display)
{
}


ThirdButtonEffect::~ThirdButtonEffect()
{
}

AudioEditorState::States ThirdButtonEffect::getStateName()
{
	return AudioEditorState::States::SecondButtonEffect;
}

const std::shared_ptr<EffectManager>& ThirdButtonEffect::getEffectManager()
{
	return effectManager;
}

void ThirdButtonEffect::NextParameterSettings()
{
	effectManager->NextParameterSettings();
}

void ThirdButtonEffect::PreviousParameterSettings()
{
	effectManager->PreviousParameterSettings();
}

void ThirdButtonEffect::IncreaseParameter()
{
	effectManager->IncreaseParameter();
}

void ThirdButtonEffect::DecreaseParameter()
{
	effectManager->DecreaseParameter();
}

void ThirdButtonEffect::UpdateEffectStatus(bool buttonStatus)
{
	effectManager->UpdateEffectStatus(buttonStatus);
}

void ThirdButtonEffect::UpdateDisplay()
{
	effectManager->DisplayParameters(display);
}

