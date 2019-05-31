
#ifndef NONEEFFECTSTATE_CPP
#define NONEEFFECTSTATE_CPP

#include "NoneEffectState.h"

namespace NL
{
	NoneEffectState::NoneEffectState(const std::shared_ptr <Display> & display) : AudioEditorState(display)
	{
	}


	NoneEffectState::~NoneEffectState()
	{
	}

	AudioEditorState::States NoneEffectState::getStateName()
	{
		return AudioEditorState::States::NoneEffectState;
	}
}
#endif // !NONEEFFECTSTATE_CPP