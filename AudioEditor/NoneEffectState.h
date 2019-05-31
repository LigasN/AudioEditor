#pragma once

#ifndef NONEEFFECTSTATE_H
#define NONEEFFECTSTATE_H

#include "AudioEditorState.h"

namespace NL
{
	class NoneEffectState : public AudioEditorState
	{
	public:
		NoneEffectState(const std::shared_ptr <Display> & display);
		~NoneEffectState();
		virtual States getStateName() override;
	};
}

#endif // !NONEEFFECTSTATE_H