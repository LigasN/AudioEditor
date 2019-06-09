#include "FourthButtonEffect.h"

FourthButtonEffect::FourthButtonEffect(const std::shared_ptr <Display> & display) : AudioEditorState(display)
{
}

FourthButtonEffect::~FourthButtonEffect()
{
}

AudioEditorState::States FourthButtonEffect::getStateName()
{
	return AudioEditorState::States::SecondButtonEffect;
}

const std::shared_ptr<EffectManager>& FourthButtonEffect::getEffectManager()
{
	return effectManager;
}

void FourthButtonEffect::NextParameterSettings()
{
	effectManager->NextParameterSettings();
}

void FourthButtonEffect::PreviousParameterSettings()
{
	effectManager->PreviousParameterSettings();
}

void FourthButtonEffect::IncreaseParameter()
{
	effectManager->IncreaseParameter();
}

void FourthButtonEffect::DecreaseParameter()
{
	effectManager->DecreaseParameter();
}

void FourthButtonEffect::UpdateEffectStatus(bool buttonStatus)
{
	effectManager->UpdateEffectStatus(buttonStatus);
}

void FourthButtonEffect::UpdateDisplay()
{
	effectManager->DisplayParameters(display);
}