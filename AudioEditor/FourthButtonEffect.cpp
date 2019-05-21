#include "FourthButtonEffect.h"



FourthButtonEffect::FourthButtonEffect(const std::shared_ptr <Display> display) : AudioEditorState(display, States::FourthButtonEffect)
{
}


FourthButtonEffect::~FourthButtonEffect()
{
}

AudioEditorState::States FourthButtonEffect::getStateName()
{
	return name;
}
