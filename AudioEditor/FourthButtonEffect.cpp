#include "FourthButtonEffect.h"
#include <iostream>

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

	std::cout << "effectManager->NextParameterSettings();\tFourthButtonEffect::NextParameterSettings() " << std::endl;
	effectManager->NextParameterSettings();
}

void FourthButtonEffect::PreviousParameterSettings()
{

	std::cout << "effectManager->PreviousParameterSettings();\tFourthButtonEffect::PreviousParameterSettings()" << std::endl;
	effectManager->PreviousParameterSettings();
}

void FourthButtonEffect::IncreaseParameter()
{

	std::cout << "effectManager->IncreaseParameter();\tFourthButtonEffect::IncreaseParameter()" << std::endl;
	effectManager->IncreaseParameter();
}

void FourthButtonEffect::DecreaseParameter()
{

	std::cout << "effectManager->DecreaseParameter();\tFourthButtonEffect::DecreaseParameter() " << std::endl;
	effectManager->DecreaseParameter();
}

void FourthButtonEffect::ChangeEffectStatus()
{

	std::cout << "effectManager->ChangeEffectStatus();\tFourthButtonEffect::ChangeEffectStatus()" << std::endl;
	effectManager->ChangeEffectStatus();
}

void FourthButtonEffect::UpdateDisplay()
{

	std::cout << "effectManager->ParamDisplay(display);\tFourthButtonEffect::UpdateDisplay() " << std::endl;
	effectManager->DisplayParameters(display);
}