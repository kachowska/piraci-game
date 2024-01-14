#include<iostream>
#include<string>
#include<sstream>

#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include"Button.h"
#include"Textbox.h"
#include"NaRazieSmieci.h"

using namespace std;

string sortowanie(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] > 64 && text[i] < 91)
		{
			text[i] += 32;
		}
	}

	text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());

	return text;
}

void puzzels(int tab[])
{
	string answer;
	string goodanswer;

	//Okno
	sf::RenderWindow zagadki;
	zagadki.create(sf::VideoMode(640, 360), "Obecna zagadka", sf::Style::Default);
	zagadki.setPosition({ 645, 150 });

	zagadki.setKeyRepeatEnabled(true);


	//Fonts
	sf::Font arial;
	arial.loadFromFile("fonts/Arial.ttf");

	sf::Font AngerStyles;
	AngerStyles.loadFromFile("fonts/AngerStyles.ttf");

	sf::Font sans;
	sans.loadFromFile("fonts/OpenSans-Regular.ttf");


	//Tresc zagadki
	sf::RectangleShape polezagadki;
	polezagadki.setSize({ 545, 150 });
	polezagadki.setFillColor(sf::Color::White);
	polezagadki.setPosition({ 50, 25 });

	sf::Text textzagadki;
	textzagadki.setCharacterSize(30);
	textzagadki.setColor(sf::Color::Black);
	textzagadki.setFont(sans);
	textzagadki.setPosition({ 75, 50 });

	if (tab[0] <= 15)
	{
		textzagadki.setString(L"Hydra");
		goodanswer = "hydra";
	}
	if (tab[0] >= 16)
	{
		textzagadki.setString(L"Wyspa wied�my");
		goodanswer = "pashipolity";
	}

	//Pole odpowiedzi
	Button poleodpowiedzi(L" ", { 545, 75 }, 1, sf::Color::White, sf::Color::Transparent, arial);
	poleodpowiedzi.setPosition({ 50, 200 });

	Textbox odpowiedz(25, sf::Color::Black, false);
	odpowiedz.setFont(sans);
	odpowiedz.setPosition({ 100,205 });
	odpowiedz.setLimit(true, 12);

	//Przyciski wyjdz i zapisz
	Button zapisz(L"Zapisz", {250, 50}, 30, sf::Color::Blue, sf::Color::White, sans);
	zapisz.setPosition({ 50, 290 });

	Button wyjdz(L"Wyj�cie", { 250, 50 }, 30, sf::Color::Blue, sf::Color::White, sans);
	wyjdz.setPosition({ 345, 290 });

	//Z�a odpowied�
	sf::Text adam;
	adam.setCharacterSize(20);
	adam.setColor(sf::Color::Transparent);
	adam.setPosition({ 235, 245 });
	adam.setString(L"Z�a odpowied�");
	adam.setFont(sans);

	//Main Loop
	while (zagadki.isOpen())
	{
		sf::Event ev;

		if (answer == "pas" && tab[0] >= 16)
			adam.setString(L"Czyj?");
		else
			adam.setString(L"Z�a odpowied�");

		if (poleodpowiedzi.isMouseOver(zagadki))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				odpowiedz.setSelected(true);
				if(odpowiedz.getText()=="")
				{
					odpowiedz.write("_");
				}
				else
				{
					odpowiedz.write(odpowiedz.getText() + "_");
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			odpowiedz.setSelected(false);

			answer = sortowanie(odpowiedz.getText());
			cout << "Zapisano :D\n" << answer << endl;
			if (answer == goodanswer)
			{
				if (tab[0] <= 15)
					tab[0] = 16;
				else
					tab[0] = 28;

				zagadki.close();
			}
			else
			{
				adam.setColor(sf::Color::Red);
				tab[5]++;
			}

		}

		//Event Loop
		while (zagadki.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				zagadki.close();
			case sf::Event::TextEntered:
				odpowiedz.typedOn(ev);
				break;
			case sf::Event::MouseMoved:
				if (zapisz.isMouseOver(zagadki))
				{
					zapisz.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					zapisz.setBackColor(sf::Color::Blue, sf::Color::Black);
				}
				if (wyjdz.isMouseOver(zagadki))
				{
					wyjdz.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					wyjdz.setBackColor(sf::Color::Blue, sf::Color::Black);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (zapisz.isMouseOver(zagadki))
				{
					answer = sortowanie(odpowiedz.getText());
				
					cout << "Zapisano :D\n" << answer << endl;

					if (answer == goodanswer)
					{
						if (tab[0] <= 15)
							tab[0] = 16;
						else
							tab[0] = 28;

						zagadki.close();
					}
					else
					{
						adam.setColor(sf::Color::Red);
						tab[5]++;
					}
				}
				if (wyjdz.isMouseOver(zagadki))
				{
					zagadki.close();
				}
				break;
			}
		}

		

		zagadki.clear();

		poleodpowiedzi.drawTo(zagadki);
		odpowiedz.drawTo(zagadki);
		zagadki.draw(adam);
		zagadki.draw(polezagadki);
		zagadki.draw(textzagadki);
		zapisz.drawTo(zagadki);
		wyjdz.drawTo(zagadki);

		zagadki.display();
	}
}