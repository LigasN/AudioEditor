
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
		return AudioEditorState::States::ThirdButtonEffect;
	}

	std::shared_ptr<EffectManager>& ThirdButtonEffect::getEffectManager()
	{
		return effectManager;
	}

}
#endif // !THIRDBUTTONEFFECT_CPP