#include "NoneEffectState.h"



NoneEffectState::NoneEffectState(const std::shared_ptr <Display> display) : AudioEditorState(display, States::NoneEffectState)
{
}


NoneEffectState::~NoneEffectState()
{
}

AudioEditorState::States NoneEffectState::getStateName()
{
	return name;
}
