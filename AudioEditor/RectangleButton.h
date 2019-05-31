#pragma once


#ifndef RECTANGLEBUTTON_H
#define RECTANGLEBUTTON_H

/////////////////////////////////////////////////////////////////////////////
//
// HEADERS
//
/////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <assert.h>

namespace NL
{
	///////////////////////////////////////////////////////////////////////////////////////////////
	///
	///	Class RectangleButton
	///
	/// Aim: Stores some information about button like
	///		-occupied area
	///		-status
	///		-other refered to class RectangleShape
	///		-checks mouse positions
	///
	/// Description: This class makes impression on drawed background that the rectangle shaped 
	///					 button is shining when his status is true (means that it is pushed). This 
	///					 class only covers button from background with color when button is pushed.
	///
	///////////////////////////////////////////////////////////////////////////////////////////////
	class RectangleButton : public sf::Drawable
	{
	private:

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Object of class RectangleShape in RectangleButton class
		///
		/// Aim: Stores area of the button
		///
		/// Type: sf::RectangleShape
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		sf::RectangleShape shape;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Variable in RectangleButton class
		///
		/// Aim: Stores information about status of button. If true it is pushed, if not it is not.
		///
		/// Type: Boolean
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		bool status;

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Function in RectangleButton class
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
		/// Constructor in RectangleButton class
		///
		/// Aim: Set all variables
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		RectangleButton();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Destructor in RectangleButton class
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		~RectangleButton();

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Parametrical constructor in RectangleButton class
		///
		/// Aim: Set all parametrs as wanted
		///
		/// Arguments:	-sf::RectangleShape	-shape of button(most important is size of button and position)
		///		-bool			-status of button (true if pushed)
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		RectangleButton(sf::RectangleShape shape, bool status);


		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Parametrical constructor in RectangleButton class
		///
		/// Aim: Set all parametrs as wanted
		///
		/// Arguments:	-sf::Vector2f		-size of button
		///		-sf::Vector2f		-position of button (origin of button is on the middle) 
		///		-sf::Color			-color of shining button
		///		-float			-rotation of button
		///		-bool			-status of button (true if pushed)
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		RectangleButton(sf::Vector2f size, sf::Vector2f position, sf::Color color, float rotation, bool status);

		///////////////////////////////////////////////////////////////////////////////////////////////
		///
		/// Function in RectangleButton class
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
		/// Function in RectangleButton class
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
		/// Function in RectangleButton class
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
		/// Function in RectangleButton class
		///
		/// Aim: Changes button status
		///
		/// Arguments: void
		///
		/// Returns: void
		///
		///////////////////////////////////////////////////////////////////////////////////////////////
		void ChangeStatus();

	};

}
#endif // !RECTANGLEBUTTON_H