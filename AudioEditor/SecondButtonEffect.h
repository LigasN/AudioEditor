#pragma once

#include "AudioEditorState.h"

class SecondButtonEffect : public AudioEditorState
{
public:
	SecondButtonEffect();
	~SecondButtonEffect();
	States getStateName();
};

