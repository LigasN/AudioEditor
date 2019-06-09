#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include "AudioEditorState.h"

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// SecondButtonEffect class	
///
/// Aim: Stores information about state of second button and effects turned on in it.
///
/// Inherits in public relations from AudioEditorState
///
/// Children of state design pattern
///
///////////////////////////////////////////////////////////////////////////////////////////////
class SecondButtonEffect : public AudioEditorState
{
public:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Parametrical constructor in SecondButtonEffect class
	///
	///	Arguments:	- const std::shared_ptr <Display> &	- pointer to main display in program
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	SecondButtonEffect(const std::shared_ptr <Display> & display);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Destructor in SecondButtonEffect class
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	~SecondButtonEffect();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual function in SecondButtonEffect class
	///
	/// Aim: Returns name of state in which program is
	///
	///	Arguments:	- void
	///
	/// Returns: States
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual States getStateName();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual override function in SecondButtonEffect class
	///
	/// Aim: Returns pointer to effect manager from base class
	///
	///	Arguments:	- void	
	///
	/// Returns: const std::shared_ptr <EffectManager> &
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual const std::shared_ptr <EffectManager> & getEffectManager() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual override function in SecondButtonEffect class
	///
	/// Aim: Sets next parameter on Display by calling function from effectmanager
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void NextParameterSettings() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual override function in SecondButtonEffect class
	///
	/// Aim: Sets previous parameter on Display by calling function from effectmanager
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void PreviousParameterSettings() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual override function in SecondButtonEffect class
	///
	/// Aim: Increase parameter on Display by calling function from effectmanager
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void IncreaseParameter() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual override function in SecondButtonEffect class
	///
	/// Aim: Decrease parameter on Display by calling function from effectmanager
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void DecreaseParameter() override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual override function in SecondButtonEffect class
	///
	/// Aim: Update status(on/off) of effect by calling effectmanager function
	///
	///	Arguments:	- bool	-status of button on which effect is setted
	///
	/// Returns: void
	///
	///	It could be update because it dont need any argument. It knows in which button status is intrested.
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void UpdateEffectStatus(bool buttonStatus) override;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual override function in SecondButtonEffect class
	///
	/// Aim: Update display by calling effectmanager function.
	///
	///	Arguments:	- void	
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void UpdateDisplay() override;
};
