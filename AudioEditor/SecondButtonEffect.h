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
		std::shared_ptr <EffectManager> & getEffectManager();
	};
}
#endif // !SECONDBUTTONEFFECT_H
