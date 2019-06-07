#pragma once

#include "AudioEditorState.h"

class FirstButtonEffect : public AudioEditorState
{
public:
	FirstButtonEffect(const std::shared_ptr <Display> & display);
	~FirstButtonEffect();
	virtual States getStateName() override;
	virtual const std::shared_ptr <EffectManager> & getEffectManager() override;
	virtual void NextParameterSettings() override;
	virtual void PreviousParameterSettings() override;
	virtual void IncreaseParameter() override;
	virtual void DecreaseParameter() override;
	virtual void ChangeEffectStatus() override;
	virtual void UpdateDisplay() override;
};
