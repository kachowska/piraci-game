#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include<SFML/Graphics.hpp>

class Button {
public:
	Button() { }

	Button(std::wstring t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor, sf::Font& font)
	{
		text.setString(t);
		text.setColor(textColor);
		text.setCharacterSize(charSize);
		text.setFont(font);

		button.setSize(size);
		button.setFillColor(bgColor);

	}

	void setFont(sf::Font& font)
	{
		text.setFont(font);
	}

	void changeString(std::wstring a)
	{
		text.setString(a);
		
		float xPos = (button.getPosition().x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
		float yPos = (button.getPosition().y + button.getLocalBounds().height / 3) - (text.getLocalBounds().height / 4);

		text.setPosition({ xPos, yPos });
	}

	void setBackColor(sf::Color color, sf::Color innyColor)
	{
		button.setFillColor(color);
		text.setColor(innyColor);
	}

	void setTextColor(sf::Color color)
	{
		text.setColor(color);
	}

	void setPosition(sf::Vector2f pos)
	{
		button.setPosition(pos);

		float xPos = (pos.x + button.getLocalBounds().width/2) - (text.getLocalBounds().width/2);
		float yPos = (pos.y + button.getLocalBounds().height / 3) - (text.getLocalBounds().height / 4);

		text.setPosition({ xPos, yPos });
	}

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(button);
		window.draw(text);
	}

	bool isMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
		{
			return true;
		}
		return false;
	}
private: 
	sf::RectangleShape button;
	sf::Text text;
};
