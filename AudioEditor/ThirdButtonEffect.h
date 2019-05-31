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
		std::shared_ptr <EffectManager> & getEffectManager();
	};
}
#endif // !THIRDBUTTONEFFECT_H
