#include "FirstButtonEffect.h"



FirstButtonEffect::FirstButtonEffect() : name(States::FirstButtonEffect)
{
}


FirstButtonEffect::~FirstButtonEffect()
{
}

AudioEditorState::States FirstButtonEffect::getStateName()
{
	return name;
}
