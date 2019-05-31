#pragma once

#ifndef DELAYSOUNDEFFECT_H
#define DELAYSOUNDEFFECT_H

#include "SoundEffect.h"
#include "Display.h"
#include "C_TEXTS.h"

namespace NL
{

	class DelaySoundEffect : public SoundEffect
	{
	public:

		enum class Parameters
		{
			Delay_level_per_echo,	//(dB)	This controls the amount in dB by which each successive echo will change loudness.The more negative this value, the more the echoes will die away.Positive values cause successive echoes to be louder.When set to 0.0, all echoes will be the same volume.Warning icon	Because echoes are often added to the original audio, the processed audio will often have a higher peak level than the original.If the output exceeds 0 dB(full track height) and so triggers the red clipping warning lights in Playback Meter Toolbar, you should open Effect > Amplify..., ensure "Amplification (dB)" shows a negative dB value(not "0.0 dB") then click OK.If "Amplification (dB)" in Amplify shows "0.0 dB", the track does not contain 32 - bit audio and the clipping cannot be repaired.In that case, Edit > Undo Delay, use Amplify to reduce the track to a lower amplitude then reapply Delay.
			Delay_time,				//(seconds)	This controls the time between echoes.For the Bouncing Ball types of delay, this sets the delay time for the longest(slowest) echo.
			Pitch_change_effect,	//	Pitch / Tempo: Changes the pitch in the same way that the Change Speed effect causes a change in pitch.The sound quality of each echo is very good, but an increase in pitch speeds up the delayed audio and a decrease in pitch slows it down.The echoes will be noticeably desynchronized with any comparable echoes in other tracks where "Pitch/Tempo" was not applied.
			Pitch_change_per_echo,	//This controls the amount in semitones by which each successive echo will change pitch.The change can be set to fractions of a semitone which can produce a "glissando" type of delay.When set to zero, the pitch change effect is disabled.
			Number_of_echoes,		//This controls how many echoes are produced.
		};

		DelaySoundEffect();
		~DelaySoundEffect();

		void ParamDisplay(const std::shared_ptr <Display> & display);
		virtual void IncreaseParameter();
		virtual void DecreaseParameter();

	private:

		float delayLevelPerEcho; //dowolne	//(dB)	This controls the amount in dB by which each successive echo will change loudness.The more negative this value, the more the echoes will die away.Positive values cause successive echoes to be louder.When set to 0.0, all echoes will be the same volume.Warning icon	Because echoes are often added to the original audio, the processed audio will often have a higher peak level than the original.If the output exceeds 0 dB(full track height) and so triggers the red clipping warning lights in Playback Meter Toolbar, you should open Effect > Amplify..., ensure "Amplification (dB)" shows a negative dB value(not "0.0 dB") then click OK.If "Amplification (dB)" in Amplify shows "0.0 dB", the track does not contain 32 - bit audio and the clipping cannot be repaired.In that case, Edit > Undo Delay, use Amplify to reduce the track to a lower amplitude then reapply Delay.
		unsigned int delayTime;	// bigger than 0							//(seconds)	This controls the time between echoes.For the Bouncing Ball types of delay, this sets the delay time for the longest(slowest) echo.
		float pitchChangeEffect;	//bigger than 1 or smaller but more than 0				//	Pitch / Tempo: Changes the pitch in the same way that the Change Speed effect causes a change in pitch.The sound quality of each echo is very good, but an increase in pitch speeds up the delayed audio and a decrease in pitch slows it down.The echoes will be noticeably desynchronized with any comparable echoes in other tracks where "Pitch/Tempo" was not applied.
		float pitchChangePerEcho;	// 1 or bigger				//This controls the amount in semitones by which each successive echo will change pitch.The change can be set to fractions of a semitone which can produce a "glissando" type of delay.When set to zero, the pitch change effect is disabled.
		int numberOfEchoes;					//This controls how many echoes are produced.

		unsigned int parameterOnDisplay;

		void  makeEffect(std::vector <sf::Int16> & soundSamples, unsigned int sampleRate);			//funcja zmieniana przez design pattern strategy

	};
}
#endif // !DELAYSOUNDEFFECT_H
