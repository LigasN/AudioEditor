#pragma once

/////////////////////////////////////////////////////////////////////////////
//
// HEADERS
//
/////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <assert.h>

///////////////////////////////////////////////////////////////////////////////////////////////
///
///	Class ConvexButton
///
/// Aim: Stores some information about button like
///		-occupied area
///		-status
///		-other refered to class ConvexShape
///		-checks mouse positions
///
/// Description: This class makes impression on drawed background that the convex shaped 
///					 button is shining when his status is true (means that it is pushed). This 
///					 class only covers button from background with color when button is pushed.
///
///////////////////////////////////////////////////////////////////////////////////////////////
class ConvexButton : public sf::Drawable
{
private:
	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Object of class ConvexShape in ConvexButton class
	///
	/// Aim: Stores area of the button
	///
	/// Type: sf::RectangleShape
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	sf::ConvexShape shape;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Variable  in ConvexButton class
	///
	/// Aim: Stores information about status of button. If true it is pushed, if not it is not.
	///
	/// Type: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool status;

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in ConvexButton class
	///
	/// Aim: Draw button if status is true
	///
	/// Arguments: sf::RenderTarget&, sf::RenderStates
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Constructor in ConvexButton class
	///
	/// Aim: Set all variables
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	ConvexButton();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Destructor in ConvexButton class
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	~ConvexButton();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Parametrical constructor in ConvexButton class
	///
	/// Aim: Set all parametrs as wanted
	///
	/// Arguments:	-sf::ConvexShape	-shape of button(most important is size of button and position)
	///		-bool			-status of button (true if pushed)
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	ConvexButton(sf::ConvexShape shape, bool status);


	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Parametrical constructor in ConvexButton class
	///
	/// Aim: Set all parametrs as wanted
	///
	/// Arguments:	-sf::Vector2f		-position of button (origin of button is on the middle) 
	///		-sf::Color			-color of shining button
	///		-float			-rotation of button
	///		-std::vector<float>			-points of shape
	///		-bool			-status of button (true if pushed)
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	ConvexButton(sf::Vector2f position, sf::Color color, float rotation, std::vector<sf::Vector2f> points, bool status);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in ConvexButton class
	///
	/// Aim: Set status as true if it is not. Button is pushed.
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void Push();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in ConvexButton class
	///
	/// Aim: Set status as false if it is not. Button is released.
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void Release();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in ConvexButton class
	///
	/// Aim: Return information about being on target or not
	///
	/// Arguments: const sf::Vector2f
	///
	/// Returns: Boolean
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool OnTarget(const sf::Vector2f & sight);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in ConvexButton class
	///
	/// Aim: Changes button status
	///
	/// Arguments: void
	///
	/// Returns: void
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	void ChangeStatus();

	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Function in ConvexButton class
	///
	/// Aim: returns status of button
	///
	/// Arguments: void
	///
	/// Returns: bool
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool getStatus();
};