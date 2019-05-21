#pragma once

#include "AudioEditorState.h"

class ThirdButtonEffect : public AudioEditorState
{
public:
	ThirdButtonEffect();
	~ThirdButtonEffect();
	States getStateName();
};

