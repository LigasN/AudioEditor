#pragma once

#ifndef FIRSTBUTTONEFFECT_H
#define FIRSTBUTTONEFFECT_H

#include "AudioEditorState.h"

namespace NL
{

	class FirstButtonEffect : public AudioEditorState
	{
	public:
		FirstButtonEffect(const std::shared_ptr <Display> & display);
		~FirstButtonEffect();
		virtual States getStateName() override;
		std::shared_ptr <EffectManager> & getEffectManager();
	};
}
#endif // !FIRSTBUTTONEFFECT_H
