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
		std::shared_ptr <EffectManager> & getEffectManager();

	};
}
#endif // !FIRSTBUTTONEFFECT_H
