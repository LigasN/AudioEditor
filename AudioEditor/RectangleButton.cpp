#include "RectangleButton.h"

void RectangleButton::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	if (status)
	{
		target.draw(shape, state);
	}
}

RectangleButton::RectangleButton() : shape(sf::Vector2f(5.f, 5.f)), status(false)
{
	shape.setFillColor(sf::Color::Cyan);
	this->shape.setOrigin(this->shape.getSize() / 2.f);
}


RectangleButton::~RectangleButton()
{
}

RectangleButton::RectangleButton(sf::RectangleShape shape, bool status) : shape(shape), status(status)
{
	assert(this->shape.getSize().x > 0.f && this->shape.getSize().y > 0.f);
}

RectangleButton::RectangleButton(sf::Vector2f size, sf::Vector2f position, sf::Color color, float rotation, bool status) : shape(size), status(status)
{
	this->shape.setFillColor(color);
	assert(this->shape.getSize().x > 0.f && this->shape.getSize().y > 0.f);
	this->shape.setOrigin(this->shape.getSize() / 2.f);
	this->shape.setPosition(position);
	this->shape.setRotation(rotation);
}

void RectangleButton::Push()
{
	status = 1;
}

void RectangleButton::Release()
{
	status = 0;
}

bool RectangleButton::OnTarget(const sf::Vector2f & sight)
{
	if (shape.getGlobalBounds().contains(sight)) return true;
	return false;
}

void RectangleButton::ChangeStatus()
{
	status = !status;
}