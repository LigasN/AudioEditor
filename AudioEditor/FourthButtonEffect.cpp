

#ifndef FOURTHBUTTONEFFECT_CPP
#define FOURTHBUTTONEFFECT_CPP

#include "FourthButtonEffect.h"

namespace NL
{
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

	void FourthButtonEffect::ChangeEffectStatus()
	{
		effectManager->ChangeEffectStatus();
	}

	void FourthButtonEffect::UpdateDisplay()
	{
		effectManager->ParamDisplay(display);
	}
}
#endif //!FOURTHBUTTONEFFECT_CPP