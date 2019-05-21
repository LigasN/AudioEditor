#include "SecondButtonEffect.h"



SecondButtonEffect::SecondButtonEffect(const std::shared_ptr <Display> display) : AudioEditorState(display, States::SecondButtonEffect)
{
}


SecondButtonEffect::~SecondButtonEffect()
{
}

AudioEditorState::States SecondButtonEffect::getStateName()
{
	return name;
}
