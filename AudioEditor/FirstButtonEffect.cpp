
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

	std::shared_ptr<EffectManager>& FirstButtonEffect::getEffectManager()
	{
		return effectManager;
	}
}
#endif // !FIRSTBUTTONEFFECT_CPP