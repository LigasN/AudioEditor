#pragma once

#include "AudioEditorState.h"

class FirstButtonEffect : public AudioEditorState
{
public:
	FirstButtonEffect(const std::shared_ptr <Display> display);
	~FirstButtonEffect();
	States getStateName();
};

