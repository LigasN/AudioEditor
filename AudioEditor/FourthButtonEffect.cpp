

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
		return AudioEditorState::States::FourthButtonEffect;
	}
	std::shared_ptr<EffectManager>& FourthButtonEffect::getEffectManager()
	{
		return effectManager;
	}
}
#endif //!FOURTHBUTTONEFFECT_CPP