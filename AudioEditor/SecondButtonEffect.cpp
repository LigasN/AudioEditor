
#ifndef SECONDBUTTONEFFECT_CPP
#define SECONDBUTTONEFFECT_CPP

#include "SecondButtonEffect.h"

namespace NL
{
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
	std::shared_ptr<EffectManager>& SecondButtonEffect::getEffectManager()
	{
		return effectManager;
	}
}
#endif // !SECONDBUTTONEFFECT_CPP