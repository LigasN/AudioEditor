#include "FirstButtonEffect.h"



FirstButtonEffect::FirstButtonEffect(const std::shared_ptr <Display> display) : AudioEditorState(display, States::FirstButtonEffect)
{
}


FirstButtonEffect::~FirstButtonEffect()
{
}

AudioEditorState::States FirstButtonEffect::getStateName()
{
	return name;
}
