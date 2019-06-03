
#ifndef FIRSTBUTTONEFFECT_CPP
#define FIRSTBUTTONEFFECT_CPP

#include "FirstButtonEffect.h"

namespace NL
{

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

	void FirstButtonEffect::ChangeEffectStatus()
	{
		effectManager->ChangeEffectStatus();
	}

	void FirstButtonEffect::UpdateDisplay()
	{
		effectManager->ParamDisplay(display);
	}
}
#endif // !FIRSTBUTTONEFFECT_CPP