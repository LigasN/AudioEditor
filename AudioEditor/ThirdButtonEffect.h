#pragma once

#ifndef THIRDBUTTONEFFECT_H
#define THIRDBUTTONEFFECT_H

#include "AudioEditorState.h"

namespace NL
{
	class ThirdButtonEffect : public AudioEditorState
	{
	public:
		ThirdButtonEffect(const std::shared_ptr <Display> & display);
		~ThirdButtonEffect();
		virtual States getStateName() override;
		virtual const std::shared_ptr <EffectManager> & getEffectManager() override;
		virtual void NextParameterSettings() override;
		virtual void PreviousParameterSettings() override;
		virtual void IncreaseParameter() override;
		virtual void DecreaseParameter() override;
		virtual void ChangeEffectStatus() override;
		virtual void UpdateDisplay() override;
	};
}
#endif // !THIRDBUTTONEFFECT_H
