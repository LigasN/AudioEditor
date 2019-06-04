#include "Buttons.h"

void Buttons::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(FirstEffectButton, state);
	target.draw(SecondEffectButton, state);
	target.draw(ThirdEffectButton, state);
	target.draw(FourthEffectButton, state);
	target.draw(PlayButtonArea, state);
	target.draw(CleanButtonArea, state);
	target.draw(StopButtonArea, state);
	target.draw(RightArrowButtonArea, state);
	target.draw(LeftArrowButtonArea, state);
	target.draw(UpArrowButtonArea, state);
	target.draw(DownArrowButtonArea, state);
}

Buttons::~Buttons()
{
}

Buttons::Buttons(const std::shared_ptr <sf::Window> relativeTo) : FirstEffectButton(effectButtonSize, sf::Vector2f(181.f, 499.f), color, 0.f, false),
SecondEffectButton(effectButtonSize, sf::Vector2f(462.f, 499.f), color, 0.f, false),
ThirdEffectButton(effectButtonSize, sf::Vector2f(743.f, 499.f), color, 0.f, false),
FourthEffectButton(effectButtonSize, sf::Vector2f(1024.f, 499.f), color, 0.f, false),
relativeTo(relativeTo)
{
	PlayButtonArea = ConvexButton(sf::Vector2f(656.5f, 117.f), color, 0.f, ellipticalPoints, false);
	StopButtonArea = ConvexButton(sf::Vector2f(656.5f, 293.f), color, 0.f, ellipticalPoints, false);
	CleanButtonArea = ConvexButton(sf::Vector2f(656.5f, 205.f), color, 0.f, ellipticalPoints, false);
	LeftArrowButtonArea = ConvexButton(sf::Vector2f(896.f, 101.5f), color, 0.f, triangularPoints, false);
	RightArrowButtonArea = ConvexButton(sf::Vector2f(1037.f, 221.5f), color, 180.f, triangularPoints, false);
	UpArrowButtonArea = ConvexButton(sf::Vector2f(1027.f, 91.f), color, 90.f, triangularPoints, false);
	DownArrowButtonArea = ConvexButton(sf::Vector2f(906.f, 232.5f), color, -90.f, triangularPoints, false);
}

Buttons::MousePositions Buttons::ButtonUpdate()
{
	sf::Vector2f position = (sf::Vector2f)sf::Mouse::getPosition(*relativeTo);

	if (FirstEffectButton.OnTarget(position))
	{
		FirstEffectButton.ChangeStatus();
		return MousePositions::firstEffectButton;
	}
	else if (SecondEffectButton.OnTarget(position))
	{
		SecondEffectButton.ChangeStatus();
		return MousePositions::secondEffectButton;
	}
	else if (ThirdEffectButton.OnTarget(position))
	{
		ThirdEffectButton.ChangeStatus();
		return MousePositions::thirdEffectButton;
	}
	else if (FourthEffectButton.OnTarget(position))
	{
		FourthEffectButton.ChangeStatus();
		return MousePositions::fourthEffectButton;
	}
	else if (PlayButtonArea.OnTarget(position))
	{
		PlayButtonArea.ChangeStatus();
		return MousePositions::playButton;
	}
	else if (CleanButtonArea.OnTarget(position))
	{
		CleanButtonArea.ChangeStatus();
		return MousePositions::cleanButton;
	}
	else if (StopButtonArea.OnTarget(position))
	{
		StopButtonArea.ChangeStatus();
		return MousePositions::stopButton;
	}
	else if (RightArrowButtonArea.OnTarget(position))
	{
		RightArrowButtonArea.ChangeStatus();
		return MousePositions::rightArrowButton;
	}
	else if (LeftArrowButtonArea.OnTarget(position))
	{
		LeftArrowButtonArea.ChangeStatus();
		return MousePositions::leftArrowButton;
	}
	else if (UpArrowButtonArea.OnTarget(position))
	{
		UpArrowButtonArea.ChangeStatus();
		return MousePositions::upArrowButton;
	}
	else if (DownArrowButtonArea.OnTarget(position))
	{
		DownArrowButtonArea.ChangeStatus();
		return MousePositions::downArrowButton;
	}
	else return MousePositions::noneButton;

}

void Buttons::setOn(Buttons::MousePositions button)
{
	switch (button)
	{
	case Buttons::MousePositions::firstEffectButton:
		FirstEffectButton.Push();
		break;
	case Buttons::MousePositions::secondEffectButton:
		SecondEffectButton.Push();
		break;
	case Buttons::MousePositions::thirdEffectButton:
		ThirdEffectButton.Push();
		break;
	case Buttons::MousePositions::fourthEffectButton:
		FourthEffectButton.Push();
		break;
	case Buttons::MousePositions::playButton:
		PlayButtonArea.Push();
		break;
	case Buttons::MousePositions::stopButton:
		StopButtonArea.Push();
		break;
	case Buttons::MousePositions::cleanButton:
		CleanButtonArea.Push();
		break;
	case Buttons::MousePositions::rightArrowButton:
		RightArrowButtonArea.Push();
		break;
	case Buttons::MousePositions::leftArrowButton:
		LeftArrowButtonArea.Push();
		break;
	case Buttons::MousePositions::upArrowButton:
		UpArrowButtonArea.Push();
		break;
	case Buttons::MousePositions::downArrowButton:
		DownArrowButtonArea.Push();
		break;
	case Buttons::MousePositions::noneButton:
	default:
		break;
	}
}

void Buttons::setOff(Buttons::MousePositions button)
{
	switch (button)
	{
	case Buttons::MousePositions::firstEffectButton:
		FirstEffectButton.Release();
		break;
	case Buttons::MousePositions::secondEffectButton:
		SecondEffectButton.Release();
		break;
	case Buttons::MousePositions::thirdEffectButton:
		ThirdEffectButton.Release();
		break;
	case Buttons::MousePositions::fourthEffectButton:
		FourthEffectButton.Release();
		break;
	case Buttons::MousePositions::playButton:
		PlayButtonArea.Release();
		break;
	case Buttons::MousePositions::stopButton:
		StopButtonArea.Release();
		break;
	case Buttons::MousePositions::cleanButton:
		CleanButtonArea.Release();
		break;
	case Buttons::MousePositions::rightArrowButton:
		RightArrowButtonArea.Release();
		break;
	case Buttons::MousePositions::leftArrowButton:
		LeftArrowButtonArea.Release();
		break;
	case Buttons::MousePositions::upArrowButton:
		UpArrowButtonArea.Release();
		break;
	case Buttons::MousePositions::downArrowButton:
		DownArrowButtonArea.Release();
		break;
	case Buttons::MousePositions::noneButton:
	default:
		break;
	}
}

bool Buttons::getButtonsStatus(Buttons::MousePositions button)
{
	switch (button)
	{
	case Buttons::MousePositions::firstEffectButton:
		return FirstEffectButton.getStatus();

	case Buttons::MousePositions::secondEffectButton:
		return SecondEffectButton.getStatus();

	case Buttons::MousePositions::thirdEffectButton:
		return ThirdEffectButton.getStatus();

	case Buttons::MousePositions::fourthEffectButton:
		return FourthEffectButton.getStatus();

	case Buttons::MousePositions::playButton:
		return PlayButtonArea.getStatus();

	case Buttons::MousePositions::stopButton:
		return StopButtonArea.getStatus();

	case Buttons::MousePositions::cleanButton:
		return CleanButtonArea.getStatus();

	case Buttons::MousePositions::rightArrowButton:
		return RightArrowButtonArea.getStatus();

	case Buttons::MousePositions::leftArrowButton:
		return LeftArrowButtonArea.getStatus();

	case Buttons::MousePositions::upArrowButton:
		return UpArrowButtonArea.getStatus();

	case Buttons::MousePositions::downArrowButton:
		return DownArrowButtonArea.getStatus();

	case Buttons::MousePositions::noneButton:
	default:
		break;
	}
}
