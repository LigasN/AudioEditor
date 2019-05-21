#pragma once

#include "AudioEditorState.h"

class NoneEffectState : public AudioEditorState
{
public:
	NoneEffectState(const std::shared_ptr <Display> display);
	~NoneEffectState();
	States getStateName();
};

