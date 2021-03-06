#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include "SFML/Audio.hpp"
#include "AudioEditorState.h"
#include "Buttons.h"

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// AudioPlayer class	
///
/// Aim: Stores sound in clean and edited version, update it, play and save to 
///		 "TestSoundEdited.wav". Next state of AudioEditorState with which is in 
///		 inheritance relation. Part of State design pattern.
///
///////////////////////////////////////////////////////////////////////////////////////////////
class AudioPlayer : public AudioEditorState
{
private:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Private variable in AudioPlayer class
	///
	/// Aim: Stores information about working state. If true we are saving file right now.
	///		 If not it means that we want to stop playing it only.
	///
	/// Type: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool savingState;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Private object of class SoundBuffer in AudioPlayer class
	///
	/// Aim: Stores clean version of sound.
	///
	/// Type: sf::SoundBuffer
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	sf::SoundBuffer cleanSound;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Private object of class SoundBuffer in AudioPlayer class
	///
	/// Aim: Stores edited version of sound.
	///
	/// Type: sf::SoundBuffer
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	sf::SoundBuffer editedSound;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Private object of class Sound in AudioPlayer class
	///
	/// Aim: Stores sound ready to play. Required in SFML libraries to play any SoundBuffer object.
	///
	/// Type: sf::Sound
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	sf::Sound playingSound;


public:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Parametrical constructor in AudioPlayer class
	///
	///	Arguments:	- const std::shared_ptr <Display> &	- stores pointer to main display in program
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	AudioPlayer(const std::shared_ptr <Display> & display);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Destructor in AudioPlayer class
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	~AudioPlayer();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Returns name of this state. Needed for other part of program.
	///
	///	Arguments:	- void
	///
	/// Returns: States
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual States getStateName() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Empty in this class. Needed in other children.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void NextParameterSettings() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Empty in this class. Needed in other children.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void PreviousParameterSettings() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Empty in this class. Needed in other children.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void IncreaseParameter() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Empty in this class. Needed in other children.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void DecreaseParameter() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Empty in this class. Needed in other children.
	///
	///	Arguments:	- bool buttonStatus	- nedded in other children	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void UpdateEffectStatus(bool buttonStatus) override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Empty in this class. Needed in other children.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void UpdateDisplay() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual overriding function in AudioPlayer class
	///
	/// Aim: Empty in this class. Needed in other children.
	///
	///	Arguments:	- void	
	///
	/// Returns: const std::shared_ptr <EffectManager> & 
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual const std::shared_ptr <EffectManager> & getEffectManager() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Play edited version of sound.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void Play();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Play clean version of sound (without effects)
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void Clean();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Stops playing any sound.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void Stop();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Returns status of playing sound. If true it's playing now, if false it is stopped.
	///
	///	Arguments:	- void	
	///
	/// Returns: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool GetStatus();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Returns state of saving file by private variable savingState which stores this info.
	///
	///	Arguments:	- void	
	///
	/// Returns: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool GetSavingState();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Set savingState as 0. Means nothing is saving now.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void ResetSavingState();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Set savingState as 1. Means edited sound is saving now to file.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void SetSavingState();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Saves edited version of sound to wav file named "TestSoundEdited.wav". 
	///		 Returns true if success.
	///
	///	Arguments:	- void	
	///
	/// Returns: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool Save();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Returns clean version of sound.
	///
	///	Arguments:	- void	
	///
	/// Returns: sf::SoundBuffer 
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	sf::SoundBuffer getCleanSound();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Sets clean version of sound.
	///
	///	Arguments:	- sf::SoundBuffer	- clean version to set	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void setCleanSound(sf::SoundBuffer cleanSound);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Sets edited version of sound.
	///
	///	Arguments:	- sf::SoundBuffer	- edited version to set	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void setEditedSound(sf::SoundBuffer newEditedSound);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public function in AudioPlayer class
	///
	/// Aim: Updates edited sound with effects stored on some others states of program.
	///
	///	Arguments:	- const std::shared_ptr<EffectManager>&	- first storing state
	///				- const std::shared_ptr<EffectManager>& - second storing state
	///				- const std::shared_ptr<EffectManager>&	- third storing state
	///				- const std::shared_ptr<EffectManager>&	- fourth storing state
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void UpdateEditedSound(const std::shared_ptr<EffectManager>& firstButtonManager, const std::shared_ptr<EffectManager>& secondButtonManager,
		const std::shared_ptr<EffectManager>& thirdButtonManager, const std::shared_ptr<EffectManager>& fourthButtonManager);
};
