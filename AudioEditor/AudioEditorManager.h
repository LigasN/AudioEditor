#pragma once

#include "Buttons.h"
#include "Display.h"
#include "AudioEditorState.h"
#include "SoundStorage.h"
#include <memory>
#include "NoneEffectState.h"
#include "FirstButtonEffect.h"
#include "SecondButtonEffect.h"
#include "ThirdButtonEffect.h"
#include "FourthButtonEffect.h"
#include <assert.h>
#include "C_TEXTS.h"

class AudioEditorManager
{
private:
	std::shared_ptr <AudioEditorState> currentState;
	std::shared_ptr <FirstButtonEffect> firstButtonEffect;
	std::shared_ptr <SecondButtonEffect> secondButtonEffect;
	std::shared_ptr <ThirdButtonEffect> thirdButtonEffect;
	std::shared_ptr <FourthButtonEffect> fourthButtonEffect;
	std::shared_ptr <AudioPlayer> audioPlayer;
	const std::shared_ptr < Display > display;
	const std::shared_ptr < Buttons > buttons;

public:
	AudioEditorManager(const std::shared_ptr <Display> display, const std::shared_ptr <Buttons> buttons);
	~AudioEditorManager();
	bool updateState();
	bool updateSound(const std::shared_ptr <SoundStorage> & sound );
};

