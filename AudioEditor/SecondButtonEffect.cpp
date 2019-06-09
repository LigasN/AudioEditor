#include "SecondButtonEffect.h"

SecondButtonEffect::SecondButtonEffect(const std::shared_ptr <Display> & display) : AudioEditorState(display)
{
}


SecondButtonEffect::~SecondButtonEffect()
{
}

AudioEditorState::States SecondButtonEffect::getStateName()
{
	return AudioEditorState::States::SecondButtonEffect;
}

const std::shared_ptr<EffectManager>& SecondButtonEffect::getEffectManager()
{
	return effectManager;
}

void SecondButtonEffect::NextParameterSettings()
{
	effectManager->NextParameterSettings();
}

void SecondButtonEffect::PreviousParameterSettings()
{
	effectManager->PreviousParameterSettings();
}

void SecondButtonEffect::IncreaseParameter()
{
	effectManager->IncreaseParameter();
}

void SecondButtonEffect::DecreaseParameter()
{
	effectManager->DecreaseParameter();
}

void SecondButtonEffect::UpdateEffectStatus(bool buttonStatus)
{
	effectManager->UpdateEffectStatus(buttonStatus);
}

void SecondButtonEffect::UpdateDisplay()
{
	effectManager->DisplayParameters(display);
}
