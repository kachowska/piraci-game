#include<iostream>
#include<string>

#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include"Button.h"
#include "NaRazieSmieci.h"


using namespace std;

int main()
{

	//Okno
	sf::RenderWindow mainMenu;
	//sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 635, (sf::VideoMode::getDesktopMode().height / 2) - 390);

	mainMenu.create(sf::VideoMode(640, 680), "Piraci", sf::Style::Default);
	mainMenu.setPosition({ 645, 170 });

	mainMenu.setKeyRepeatEnabled(true);

	int tab[20] = {};
	tab[14] = 50;
	tab[1] = 10000;
	tab[16] = 10;

	//Fonts
	sf::Font arial;
	arial.loadFromFile("fonts/Arial.ttf");
	sf::Font chanel;
	chanel.loadFromFile("fonts/Channel.ttf");
	sf::Font AngerStyles;
	AngerStyles.loadFromFile("fonts/AngerStyles.ttf");

	//New Game Button / Wzn�w gr� Button
	Button newgame(L"Nowa Gra", { 500, 150 }, 50, sf::Color::Transparent, sf::Color::White, chanel);
	newgame.setPosition({ 50, 80 });

	//Wczytaj Gr� Button / Zapisz gr� Button
	Button oldgame(L"Wczytaj gr�", { 500, 150 }, 50, sf::Color::Transparent, sf::Color::White, chanel);
	oldgame.setPosition({ 60, 280 });
	

	//Exit Button / Wr�c do menu Button
	Button exit(L"Wyj�cie z gry", { 550, 150 }, 50, sf::Color::Transparent, sf::Color::White, chanel);
	exit.setPosition({50, 480});


	//Main Loop
	while (mainMenu.isOpen())
	{
		sf::Event ev;

		

		//Event Loop
		while (mainMenu.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				mainMenu.close();
			case sf::Event::MouseMoved:
				if (newgame.isMouseOver(mainMenu)) 
				{
					newgame.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					newgame.setBackColor(sf::Color::Transparent, sf::Color::White);
				}

				if (oldgame.isMouseOver(mainMenu))
				{
					oldgame.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					oldgame.setBackColor(sf::Color::Transparent, sf::Color::White);
				}

				if (exit.isMouseOver(mainMenu))
				{
					exit.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else {
					exit.setBackColor(sf::Color::Transparent, sf::Color::White);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (newgame.isMouseOver(mainMenu))
				{
					mainMenu.close();
					piraci(tab);
				}
				if (oldgame.isMouseOver(mainMenu))
				{
					cout << "Old game :D\n";
				}
				if (exit.isMouseOver(mainMenu))
				{
					mainMenu.close();
				}

			}
		}

		
		mainMenu.clear();
		newgame.drawTo(mainMenu);
		oldgame.drawTo(mainMenu);
		exit.drawTo(mainMenu);
		mainMenu.display();
	}

	return 0;
}