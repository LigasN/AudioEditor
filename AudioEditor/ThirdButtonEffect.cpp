#include "ThirdButtonEffect.h"
#include <iostream>

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

	std::cout << "effectManager->NextParameterSettings();\tThirdButtonEffect::NextParameterSettings() " << std::endl;
	effectManager->NextParameterSettings();
}

void ThirdButtonEffect::PreviousParameterSettings()
{

	std::cout << "effectManager->PreviousParameterSettings();\tThirdButtonEffect::PreviousParameterSettings() " << std::endl;
	effectManager->PreviousParameterSettings();
}

void ThirdButtonEffect::IncreaseParameter()
{

	std::cout << "effectManager->IncreaseParameter();\tThirdButtonEffect::IncreaseParameter() " << std::endl;
	effectManager->IncreaseParameter();
}

void ThirdButtonEffect::DecreaseParameter()
{

	std::cout << "effectManager->DecreaseParameter();\tThirdButtonEffect::DecreaseParameter()" << std::endl;
	effectManager->DecreaseParameter();
}

void ThirdButtonEffect::ChangeEffectStatus()
{

	std::cout << "effectManager->ChangeEffectStatus();\tThirdButtonEffect::ChangeEffectStatus() " << std::endl;
	effectManager->ChangeEffectStatus();
}

void ThirdButtonEffect::UpdateDisplay()
{

	std::cout << "effectManager->ParamDisplay(display);\tThirdButtonEffect::UpdateDisplay() " << std::endl;
	effectManager->DisplayParameters(display);
}

