#include "Display.h"

void Display::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	target.draw(display, state);															//<--------Trzeba tu wrocic jezeli zdefiniowane SOME_SHAPES
	target.draw(text, state);
}

#ifdef SOME_SHAPES

Display::Display() : display(&sf::RectangleShape(sf::Vector2f(20.f, 5.f))), font(),
TEXTS(TXT_Handle::LANGUAGES::Polish), text(sf::String(TEXTS.getText(C_TEXTS::TEXT_ID::Settings)), font, 20)
{
	assert(font.loadFromFile("DSEG14Modern-Regular.ttf"));
	text.setFont(font);
	display->setOrigin(display.getSize() / 2.f);
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
	text.setPosition(display->getPosition());
	text.setFillColor(textColor);
}


Display::Display(std::unique_ptr<sf::Shape> shape) : /*display(shape), */font(),			//<--------Trzeba tu wrocic
TEXTS(TXT_Handle::LANGUAGES::Polish), text(sf::String(TEXTS.getText(C_TEXTS::TEXT_ID::Settings)), font, 20)
{
	assert(font.loadFromFile("DSEG14Modern-Regular.ttf"));
	text.setFont(font);
	display->setOrigin(display.getSize() / 2.f);
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
	text.setPosition(display->getPosition());
	text.setFillColor(textColor);
}


Display::Display(const sf::Vector2f size, sf::Vector2f position) : display(&sf::RectangleShape(size)), font(),
TEXTS(TXT_Handle::LANGUAGES::Polish), text(sf::String(TEXTS.getText(C_TEXTS::TEXT_ID::Settings)), font, 40)
{
	assert(font.loadFromFile("DSEG14Modern-Regular.ttf"));
	text.setFont(font);
	display->setOrigin(display.getSize() / 2.f);
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 5.f);
	display->setPosition(position);
	text.setPosition(position);
	text.setFillColor(textColor);
	std::cout << "wstepne rozmiary i pozycja x text: " << text.getLocalBounds().width << "\t " << text.getPosition().x << "display: " << display->getLocalBounds().width << "\t " << display->getPosition().x << std::endl;
}
	//WARNING! here is commented function setText
void Display::setText(C_TEXTS::TEXT_ID textID)
{
	text.setString(sf::String(TEXTS.getText(textID)));

	bool ready{};
	do
	{
		//if (text.getLocalBounds().width > display->getLocalBounds().width - 50)
		//{
		std::cout << "wstepne rozmiary i pozycja x text: " << text.getLocalBounds().width << "\t " << text.getPosition().x << "display: " << display->getLocalBounds().width << "\t " << display->getPosition().x << std::endl;
		//text.setCharacterSize(text.getCharacterSize() - 50);
	//}
	//else if (text.getLocalBounds().width < display->getLocalBounds().width - 100)
	//{
		//std::cout << "wstepne rozmiary i pozycja x text: " << text.getLocalBounds().width << "\t " << text.getPosition().x << "display: " << display->getLocalBounds().width << "\t " << display->getPosition().x << std::endl;
		//text.setCharacterSize(text.getCharacterSize() + 50);
	//}
	//else
		std::cin >> ready;
		//{
			//ready = true;
		//}
	} while (!ready);
}
#endif // SOME_SHAPES

Display::~Display()
{
}

#ifndef SOME_SHAPES

Display::Display() : display(sf::RectangleShape(sf::Vector2f(20.f, 5.f))), font(),
TEXTS(TXT_Handle::LANGUAGES::Polish), text(sf::String(TEXTS.getText(C_TEXTS::TEXT_ID::Settings)), font, 20)
{
	assert(font.loadFromFile("DSEG14Modern-Regular.ttf"));
	text.setFont(font);
	display.setOrigin(display.getSize() / 2.f);
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
	text.setPosition(display.getPosition());
	text.setFillColor(textColor);
	display.setFillColor(sf::Color::Transparent);
}

Display::Display(sf::RectangleShape shape) : display(shape), font(), TEXTS(TXT_Handle::LANGUAGES::Polish),
text(sf::String(TEXTS.getText(C_TEXTS::TEXT_ID::Settings)), font, 20)
{
	assert(font.loadFromFile("DSEG14Modern-Regular.ttf"));
	text.setFont(font);
	display.setOrigin(display.getSize() / 2.f);
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
	text.setPosition(display.getPosition());
	text.setFillColor(textColor);
	display.setFillColor(sf::Color::Transparent);
}

Display::Display(const sf::Vector2f size, sf::Vector2f position) : display(sf::RectangleShape(size)), font(),
TEXTS(TXT_Handle::LANGUAGES::Polish), text(sf::String(TEXTS.getText(C_TEXTS::TEXT_ID::Settings)), font, 40)
{
	assert(font.loadFromFile("DSEG14Modern-Regular.ttf"));
	text.setFont(font);
	display.setOrigin(display.getSize() / 2.f);
	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 5.f);
	display.setPosition(position);
	text.setPosition(position);
	text.setFillColor(textColor);
	display.setFillColor(sf::Color::Transparent);
}

void Display::setText(const C_TEXTS::TEXT_ID textID)
{
	text.setString(sf::String(TEXTS.getText(textID)));

	bool ready{};
	do
	{
		if (text.getLocalBounds().width > display.getLocalBounds().width - 10)
		{
			text.setCharacterSize(text.getCharacterSize() - 1);
		}
		else if (text.getLocalBounds().width < display.getLocalBounds().width - 30)
		{
			text.setCharacterSize(text.getCharacterSize() + 1);
		}
		else
			ready = true;

	} while (!ready);

	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 5.f);
}

void Display::setText(const C_TEXTS::TEXT_ID textID, const std::wstring value)
{
	text.setString(sf::String(TEXTS.getText(textID)) + " : " + value);

	bool ready{};
	do
	{
		if (text.getLocalBounds().width > display.getLocalBounds().width - 10)
		{
			text.setCharacterSize(text.getCharacterSize() - 1);
		}
		else if (text.getLocalBounds().width < display.getLocalBounds().width - 30)
		{
			text.setCharacterSize(text.getCharacterSize() + 1);
		}
		else
			ready = true;

	} while (!ready);

	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 5.f);
}

void Display::setText(const C_TEXTS::TEXT_ID textID1, const C_TEXTS::TEXT_ID textID2)
{
	text.setString(sf::String(TEXTS.getText(textID1)) + " : " + TEXTS.getText(textID2));

	bool ready{};
	do
	{
		if (text.getLocalBounds().width > display.getLocalBounds().width - 10)
		{
			text.setCharacterSize(text.getCharacterSize() - 1);
		}
		else if (text.getLocalBounds().width < display.getLocalBounds().width - 30)
		{
			text.setCharacterSize(text.getCharacterSize() + 1);
		}
		else
			ready = true;

	} while (!ready);

	text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 5.f);
}

#endif // !SOME_SHAPES



