#pragma once

#ifndef FOURTHBUTTONEFFECT_H
#define FOURTHBUTTONEFFECT_H

#include "AudioEditorState.h"

namespace NL
{
	class FourthButtonEffect : public AudioEditorState
	{
	public:
		FourthButtonEffect(const std::shared_ptr <Display> & display);
		~FourthButtonEffect();
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
#endif // !FIRSTBUTTONEFFECT_H
