#pragma once

#include "AudioEditorState.h"

class SecondButtonEffect : public AudioEditorState
{
public:
	SecondButtonEffect(const std::shared_ptr <Display> display);
	~SecondButtonEffect();
	States getStateName();
};

