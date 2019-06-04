#pragma once

#include "AudioEditorState.h"

class ThirdButtonEffect : public AudioEditorState
{
public:
	ThirdButtonEffect(const std::shared_ptr <Display> & display);
	~ThirdButtonEffect();
	virtual States getStateName();
	virtual const std::shared_ptr <EffectManager> & getEffectManager() override;
	virtual void NextParameterSettings() override;
	virtual void PreviousParameterSettings() override;
	virtual void IncreaseParameter() override;
	virtual void DecreaseParameter() override;
	virtual void ChangeEffectStatus() override;
	virtual void UpdateDisplay() override;
};