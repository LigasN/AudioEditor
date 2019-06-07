#pragma once

#include "AudioEditorState.h"

class NoneEffectState : public AudioEditorState
{
public:
	NoneEffectState(const std::shared_ptr <Display> & display);
	~NoneEffectState();
	virtual States getStateName() override;
	virtual const std::shared_ptr <EffectManager> & getEffectManager() override;
	virtual void NextParameterSettings() override;
	virtual void PreviousParameterSettings() override;
	virtual void IncreaseParameter() override;
	virtual void DecreaseParameter() override;
	virtual void ChangeEffectStatus() override;
	virtual void UpdateDisplay() override;
};