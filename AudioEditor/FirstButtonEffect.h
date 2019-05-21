#pragma once

#include "AudioEditorState.h"

class FirstButtonEffect : public AudioEditorState
{
public:
	FirstButtonEffect();
	~FirstButtonEffect();
	States getStateName();
};

