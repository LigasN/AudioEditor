#pragma once

#include "AudioEditorState.h"

class NoneEffectState : public AudioEditorState
{
public:
	NoneEffectState();
	~NoneEffectState();
	States getStateName();
};

