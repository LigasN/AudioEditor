#pragma once

#ifndef AUDIOEDITORMANAGER_H
#define AUDIOEDITORMANAGER_H

#include "Buttons.h"
#include "Display.h"
#include "AudioEditorState.h"
#include <memory>
#include "NoneEffectState.h"
#include "FirstButtonEffect.h"
#include "SecondButtonEffect.h"
#include "ThirdButtonEffect.h"
#include "FourthButtonEffect.h"
#include "AudioPlayer.h"
#include <assert.h>
#include "C_TEXTS.h"

namespace NL
{
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
		bool updateState();
	};
}

#endif