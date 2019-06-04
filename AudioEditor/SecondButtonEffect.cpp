#include "SecondButtonEffect.h"
#include <iostream>

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

	std::cout << "effectManager->NextParameterSettings();\t SecondButtonEffect::NextParameterSettings()" << std::endl;
	effectManager->NextParameterSettings();
}

void SecondButtonEffect::PreviousParameterSettings()
{

	std::cout << "effectManager->PreviousParameterSettings();\tSecondButtonEffect::PreviousParameterSettings() " << std::endl;
	effectManager->PreviousParameterSettings();
}

void SecondButtonEffect::IncreaseParameter()
{

	std::cout << "effectManager->IncreaseParameter();\tSecondButtonEffect::IncreaseParameter()" << std::endl;
	effectManager->IncreaseParameter();
}

void SecondButtonEffect::DecreaseParameter()
{

	std::cout << "effectManager->DecreaseParameter();\tSecondButtonEffect::DecreaseParameter() " << std::endl;
	effectManager->DecreaseParameter();
}

void SecondButtonEffect::ChangeEffectStatus()
{

	std::cout << "effectManager->ChangeEffectStatus();\tSecondButtonEffect::ChangeEffectStatus() " << std::endl;
	effectManager->ChangeEffectStatus();
}

void SecondButtonEffect::UpdateDisplay()
{

	std::cout << "effectManager->ParamDisplay(display);\tSecondButtonEffect::UpdateDisplay() " << std::endl;
	effectManager->DisplayParameters(display);
}
