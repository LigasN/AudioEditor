#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// HEADERS
///
///////////////////////////////////////////////////////////////////////////////////////////////
#include "AudioEditorState.h"

///////////////////////////////////////////////////////////////////////////////////////////////
///
/// FirstButtonEffect class	
///
/// Aim: Stores information about state of first button and effects turned on in it.
///
/// Inherits in public relations from AudioEditorState
///
/// Children of state design pattern
///
///////////////////////////////////////////////////////////////////////////////////////////////
class FirstButtonEffect : public AudioEditorState
{
public:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Parametrical constructor in FirstButtonEffect class
	///
	///	Arguments:	- const std::shared_ptr <Display> &	- pointer to main dispaly in program
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	FirstButtonEffect(const std::shared_ptr <Display> & display);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Destructor in FirstButtonEffect class
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	~FirstButtonEffect();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Public virtual function in FirstButtonEffect class
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
	/// Public virtual override function in FirstButtonEffect class
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
	/// Public virtual override function in FirstButtonEffect class
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
	/// Public virtual override function in FirstButtonEffect class
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
	/// Public virtual override function in FirstButtonEffect class
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
	/// Public virtual override function in FirstButtonEffect class
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
	/// Public virtual override function in FirstButtonEffect class
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
	/// Public virtual override function in FirstButtonEffect class
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
