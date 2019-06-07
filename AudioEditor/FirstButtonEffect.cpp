#include "FirstButtonEffect.h"
#include <iostream>

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

	std::cout << "effectManager->NextParameterSettings();\tFirstButtonEffect::NextParameterSettings()" << std::endl;
	effectManager->NextParameterSettings();
}

void FirstButtonEffect::PreviousParameterSettings()
{

	std::cout << "effectManager->PreviousParameterSettings();\tFirstButtonEffect::PreviousParameterSettings() " << std::endl;
	effectManager->PreviousParameterSettings();
}
void FirstButtonEffect::IncreaseParameter()
{

	std::cout << "effectManager->IncreaseParameter();\tFirstButtonEffect::IncreaseParameter() " << std::endl;
	effectManager->IncreaseParameter();
}

void FirstButtonEffect::DecreaseParameter()
{

	std::cout << "effectManager->DecreaseParameter();\tFirstButtonEffect::DecreaseParameter() " << std::endl;
	effectManager->DecreaseParameter();
}

void FirstButtonEffect::ChangeEffectStatus()
{

	std::cout << "effectManager->ChangeEffectStatus();\tFirstButtonEffect::ChangeEffectStatus() " << std::endl;
	effectManager->ChangeEffectStatus();
}

void FirstButtonEffect::UpdateDisplay()
{

	std::cout << "effectManager->ParamDisplay();\tFirstButtonEffect::UpdateDisplay() " << std::endl;
	effectManager->DisplayParameters(display);
}