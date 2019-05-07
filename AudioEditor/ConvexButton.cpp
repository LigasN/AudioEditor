#include "ConvexButton.h"

void ConvexButton::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	if (status)
	{
		target.draw(shape, state);
	}
}

ConvexButton::ConvexButton() : shape(3), status(false)
{
	shape.setPoint(0, sf::Vector2f(1.f, 1.f));
	shape.setPoint(1, sf::Vector2f(0.f, 2.f));
	shape.setPoint(2, sf::Vector2f(-1.f, 1.f));
	shape.setFillColor(sf::Color::Cyan);
}


ConvexButton::~ConvexButton()
{
}

ConvexButton::ConvexButton(sf::ConvexShape shape, bool status) : shape(shape), status(status)
{
	assert(this->shape.getGlobalBounds().width > 0.f && this->shape.getGlobalBounds().height > 0.f);
}

ConvexButton::ConvexButton(sf::Vector2f position, sf::Color color, float rotation, std::vector<sf::Vector2f> points, bool status) : status(status)
{
	this->shape.setFillColor(color);
	shape.setPointCount(points.size());
	for (int i = 0; i < points.size(); i++)
	{
		shape.setPoint(i, points[i]);
	}
	assert(this->shape.getLocalBounds().width > 0.f && this->shape.getLocalBounds().height > 0.f);
	this->shape.setPosition(position);
	this->shape.setRotation(rotation);
}

void ConvexButton::Push()
{
	status = 1;
}

void ConvexButton::Release()
{
	status = 0;
}

bool ConvexButton::OnTarget(const sf::Vector2f & sight)
{
	if (shape.getGlobalBounds().contains(sight)) return true;
	return false;
}

void ConvexButton::ChangeStatus()
{
	status = !status;
}