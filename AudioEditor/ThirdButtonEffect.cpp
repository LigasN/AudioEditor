#include "ThirdButtonEffect.h"



ThirdButtonEffect::ThirdButtonEffect(const std::shared_ptr <Display> display) : AudioEditorState(display, States::ThirdButtonEffect)
{
}


ThirdButtonEffect::~ThirdButtonEffect()
{
}

AudioEditorState::States ThirdButtonEffect::getStateName()
{
	return name;
}
