#pragma once

#ifndef AUDIOEDITORSTATE_H
#define AUDIOEDITORSTATE_H

#include "AudioEditorManager.h"
#include "EffectManager.h"
#include "AudioPlayer.h"
#include "Display.h"
#include "C_TEXTS.h"

namespace NL
{
	class AudioEditorState
	{
	public:

		enum class States
		{
			NoneEffectState,
			FirstButtonEffect,
			SecondButtonEffect,
			ThirdButtonEffect,
			FourthButtonEffect,
			Player
		};

	protected:

		const std::shared_ptr <Display> display;
		std::shared_ptr <EffectManager> effectManager;

	public:
		AudioEditorState(const std::shared_ptr <Display> & display);
		~AudioEditorState();
		virtual States getStateName() = 0;
		void NextParameterSettings();
		void PreviousParameterSettings();
		void IncreaseParameter();
		void DecreaseParameter();
		void ChangeEffectStatus();
		void UpdateDisplay();
		const std::shared_ptr <EffectManager> & getEffectManager();
	};
}

#endif // !AUDIOEDITORSTATE_H