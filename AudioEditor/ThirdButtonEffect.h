#pragma once

#include "AudioEditorState.h"

class ThirdButtonEffect : public AudioEditorState
{
public:
	ThirdButtonEffect(const std::shared_ptr <Display> display);
	~ThirdButtonEffect();
	States getStateName();
};

