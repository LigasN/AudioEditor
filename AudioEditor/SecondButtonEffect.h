#pragma once

#ifndef SECONDBUTTONEFFECT_H
#define SECONDBUTTONEFFECT_H

#include "AudioEditorState.h"

namespace NL
{
	class SecondButtonEffect : public AudioEditorState
	{
	public:
		SecondButtonEffect(const std::shared_ptr <Display> & display);
		~SecondButtonEffect();
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
#endif // !SECONDBUTTONEFFECT_H
