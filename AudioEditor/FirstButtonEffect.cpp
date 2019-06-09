#include "FirstButtonEffect.h"

FirstButtonEffect::FirstButtonEffect(const std::shared_ptr <Display> & display) : AudioEditorState(display)
{
}

FirstButtonEffect::~FirstButtonEffect()
{
}
	
AudioEditorState::States FirstButtonEffect::getStateName()
{
	return AudioEditorState::States::FirstButtonEffect;
}

const std::shared_ptr<EffectManager>& FirstButtonEffect::getEffectManager()
{
	return effectManager;
}

void FirstButtonEffect::NextParameterSettings()
{
	effectManager->NextParameterSettings();
}

void FirstButtonEffect::PreviousParameterSettings()
{
	effectManager->PreviousParameterSettings();
}

void FirstButtonEffect::IncreaseParameter()
{
	effectManager->IncreaseParameter();
}

void FirstButtonEffect::DecreaseParameter()
{
	effectManager->DecreaseParameter();
}

void FirstButtonEffect::UpdateEffectStatus(bool buttonStatus)
{
	effectManager->UpdateEffectStatus(buttonStatus);
}

void FirstButtonEffect::UpdateDisplay()
{
	effectManager->DisplayParameters(display);
}