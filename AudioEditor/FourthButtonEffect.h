#pragma once

#include "AudioEditorState.h"

class FourthButtonEffect : public AudioEditorState
{
public:
	FourthButtonEffect(const std::shared_ptr <Display> display);
	~FourthButtonEffect();
	States getStateName();

};

