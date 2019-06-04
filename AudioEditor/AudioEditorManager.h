#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include "Buttons.h"
#include "Display.h"
#include <memory>
#include "FirstButtonEffect.h"
#include "SecondButtonEffect.h"
#include "ThirdButtonEffect.h"
#include "FourthButtonEffect.h"
#include "AudioPlayer.h"
#include "NoneEffectState.h"
#include <assert.h>
#include "C_TEXTS.h"
#include <Windows.h>

class AudioEditorManager
{
private:
	std::shared_ptr <AudioEditorState> currentState;
	const std::shared_ptr <FirstButtonEffect> firstButtonEffect;
	const std::shared_ptr <SecondButtonEffect> secondButtonEffect;
	const std::shared_ptr <ThirdButtonEffect> thirdButtonEffect;
	const std::shared_ptr <FourthButtonEffect> fourthButtonEffect;
	const std::shared_ptr <AudioPlayer> audioPlayer;
	const std::shared_ptr < Display > display;
	const std::shared_ptr < Buttons > buttons;

public:
	AudioEditorManager(const std::shared_ptr <Display> & display, const std::shared_ptr <Buttons> & buttons);
	~AudioEditorManager();
	void updateState();
};