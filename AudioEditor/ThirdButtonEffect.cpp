
#ifndef THIRDBUTTONEFFECT_CPP
#define THIRDBUTTONEFFECT_CPP

#include "ThirdButtonEffect.h"

namespace NL
{
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

	void ThirdButtonEffect::ChangeEffectStatus()
	{
		effectManager->ChangeEffectStatus();
	}

	void ThirdButtonEffect::UpdateDisplay()
	{
		effectManager->ParamDisplay(display);
	}

}
#endif // !THIRDBUTTONEFFECT_CPP