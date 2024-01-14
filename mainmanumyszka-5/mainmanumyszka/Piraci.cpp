#include<iostream>
#include<string>
#include<sstream>

#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include"Button.h"
#include"NaRazieSmieci.h"


using namespace std;


//tab[0] � MIEJSCE W FABULE
//tab[1] - TALARY
//tab[2] - WCI�NI�TY BUTTON
//tab[3] - POKONANIE HYDRY
//tab[4] - ZDOBYCIE PASU
//tab[5] - ILO�� PR�B PRZED OTRZYMANIEM PODPOWIEDZI OD ROMY
//tab[6] - LIST OD ROMY
//tab[7] - ROMA W DRU�YNIE
//tab[8] - UMOWA Z JASZCZURAMI
//tab[9] - TAK, TRZEBA I�� DO SYREN
//tab[10] - NIE, NIE ZGAD�E� ZA PIERWSZYM RAZEM
//tab[11] - JU� SI� PODDA�EM
//tab[12] - MAIN MENU (0) LUB OPCJE (1)
//tab[13] - AKCJA WALKI
//tab[14] - HP GRACZA
//tab[15] - ATAK GRACZA
//tab[16] - MAX ATAK GRACZA
//tab[17] - HP POTWORA
//tab[18] - ATAK POTWORA
//tab[19] - TRAFIONE OR NOT


string number(int n);

void opptions(sf::RenderWindow& piraci, int tab[]);

void piraci(int tab[])
{
	//Okno
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 635, (sf::VideoMode::getDesktopMode().height / 2) - 390);

	sf::RenderWindow piraci;
	piraci.create(sf::VideoMode(1280, 720), "Piraci", sf::Style::Default);
	piraci.setPosition(centerWindow);

	piraci.setKeyRepeatEnabled(true);

	//Fonts
	sf::Font arial;
	arial.loadFromFile("fonts/Arial.ttf");
	sf::Font sans;
	sans.loadFromFile("fonts/OpenSans-Regular.ttf");
	sf::Font AngerStyles;
	AngerStyles.loadFromFile("fonts/AngerStyles.ttf");
	sf::Font chanel;
	chanel.loadFromFile("fonts/Channel.ttf");
	sf::Font amarante;
	amarante.loadFromFile("fonts/Amarante-Regular.ttf");

	//Miejsce na tekst
	sf::RectangleShape poletekstowe;
	poletekstowe.setSize({1230, 470});
	poletekstowe.setFillColor(sf::Color::White);
	poletekstowe.setPosition({ 25, 100 });

	sf::Text historia;
	historia.setFont(sans);
	historia.setCharacterSize(30);
	historia.setPosition({ 50, 125 });
	historia.setColor(sf::Color::Black);
	historia.setString(L"\tFrancuski pirat, Olivier Levasseur, znany r�wnie� jako Myszo��w, \n17 lipca 1730, podczas w�asnej egzekucji wyrzuci� w  t�um �a�cuszek \nzawieraj�cy tajemniczy kod, krzycz�c przy tym: \n\t\t�Niech znajdzie m�j skarb, ten kto to zrozumie!\"\n \tPo pi�ciu latach, w ko�cu udaje ci si� zdoby� jego kopi�, \ni natychmiast ruszasz w drog�, w poszukiwaniu ukrytego skarbu Myszo�owa.");

	tab[0] = 1;

	//"Make a choice" buttons
	sf::RectangleShape ramka;
	ramka.setSize({ 1150, 145 });
	ramka.setPosition({ 65, 415 });
	ramka.setFillColor(sf::Color::Black);

	Button buttonA(L"Dalej", { 550, 50 }, 30, sf::Color::White, sf::Color::Black, arial);
	buttonA.setPosition({ 75, 430 });

	Button buttonB(L"", { 550, 50 }, 30, sf::Color::White, sf::Color::Black, arial);
	buttonB.setPosition({ 655, 430 });

	Button buttonC(L"", { 550, 50 }, 30, sf::Color::White, sf::Color::Black, arial);
	buttonC.setPosition({ 75, 495 });

	Button buttonD(L"", { 550, 50 }, 30, sf::Color::White, sf::Color::Black, arial);
	buttonD.setPosition({ 655, 495 });

	//Pieni��ki
	sf::RectangleShape polepieniedzy;
	polepieniedzy.setSize({ 200, 50 });
	polepieniedzy.setFillColor(sf::Color::White);
	polepieniedzy.setPosition({ 1055, 25 });

	sf::Text textpieniedzy;
	textpieniedzy.setFont(arial);
	textpieniedzy.setCharacterSize(30);
	textpieniedzy.setPosition({ 1060, 40});
	textpieniedzy.setColor(sf::Color::Black);

	//HP
	sf::RectangleShape hppole;
	hppole.setSize({ 200, 50 });
	hppole.setFillColor(sf::Color::White);
	hppole.setPosition({ 25, 620 });

	sf::Text hp;
	hp.setFont(arial);
	hp.setCharacterSize(30);
	hp.setPosition({ 30, 625 });
	hp.setColor(sf::Color::Black);

	//ATAK
	sf::RectangleShape atakpole;
	atakpole.setSize({ 200, 50 });
	atakpole.setFillColor(sf::Color::White);
	atakpole.setPosition({ 250, 620 });

	sf::Text atak;
	atak.setFont(arial);
	atak.setCharacterSize(30);
	atak.setPosition({ 255, 625 });
	atak.setColor(sf::Color::Black);

	//Wyposa�enie Button
	Button plecak(L"Plecak", { 125, 100 }, 30, sf::Color::Blue, sf::Color::White, arial);
	plecak.setPosition({ 1130, 595 });

	//Zagadka Button
	Button zagadka(L"Zagadka", { 150, 100 }, 30, sf::Color::Blue, sf::Color::White, arial);
	zagadka.setPosition({ 955, 595 });

	//Sklep Button
	Button sklep(L"Tortuga", { 200, 100 }, 30, sf::Color::Blue, sf::Color::White, arial);
	sklep.setPosition({ 730, 595 });

	//Options Button
	Button opcje(L"opcje", { 75, 50 }, 25, sf::Color::Blue, sf::Color::White, arial);
	opcje.setPosition({ 25, 25 });

	//Main Loop
	while (piraci.isOpen())
	{
		sf::Event ev;

		if (tab[0] == 16)
		{
			historia.setString(L"Walka z jaszczurkami");
			buttonA.changeString(L"Dalej");
			buttonB.changeString(L"");
			buttonC.changeString(L"");
			buttonD.changeString(L"");
			tab[0] = 17;
		}

		if (tab[0] == 28 && (tab[3] == 0 || tab[4] == 0))
		{
			historia.setString(L"Czego� ci jeszcze brakuje.Odpowiedz na zagadke\njeszcze raz, gdy zdob�dziesz ju� wszystko.");
			buttonA.changeString(L"dom hippolity");
			buttonB.changeString(L"w g��b wyspy");
			buttonC.changeString(L"bagienne jezioro");
			buttonD.changeString(L"");
			tab[0] = 18;
		}

		if (tab[0] == 28 && tab[3] == 1 && tab[4] == 1)
		{
			historia.setString(L"Zdajesz sobie spraw�, �e mimo odnalezienia odpowiedzi na kolejn� zagadk�, nie masz poj�cia, gdzie si� teraz uda�. ");
			buttonA.changeString(L"Przeszukaj dom czarownicy");
			buttonB.changeString(L"");
			buttonC.changeString(L"");
			buttonD.changeString(L"");

			if (tab[7] == 1)
				buttonB.changeString(L"Popro� Rom� o pomoc");

			if (tab[8] == 1)
				buttonC.changeString(L"Popro� jaszczuroludzi o pomoc");

			tab[0] = 29;
		}

		//Event Loop
		while (piraci.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				piraci.close();
			case sf::Event::MouseMoved:
				if (plecak.isMouseOver(piraci))
				{
					plecak.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					plecak.setBackColor(sf::Color::Blue, sf::Color::White);
				}

				if (zagadka.isMouseOver(piraci))
				{
					zagadka.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					zagadka.setBackColor(sf::Color::Blue, sf::Color::White);
				}

				if (sklep.isMouseOver(piraci))
				{
					sklep.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else {
					sklep.setBackColor(sf::Color::Blue, sf::Color::White);
				}
				if (opcje.isMouseOver(piraci))
				{
					opcje.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else {
					opcje.setBackColor(sf::Color::Blue, sf::Color::White);
				}
				if (buttonA.isMouseOver(piraci))
				{
					buttonA.setBackColor(sf::Color::Black, sf::Color::White);
				}
				else {
					buttonA.setBackColor(sf::Color::White, sf::Color::Black);
				}
				if (buttonB.isMouseOver(piraci))
				{
					buttonB.setBackColor(sf::Color::Black, sf::Color::White);
				}
				else {
					buttonB.setBackColor(sf::Color::White, sf::Color::Black);
				}
				if (buttonC.isMouseOver(piraci))
				{
					buttonC.setBackColor(sf::Color::Black, sf::Color::White);
				}
				else {
					buttonC.setBackColor(sf::Color::White, sf::Color::Black);
				}
				if (buttonD.isMouseOver(piraci))
				{
					buttonD.setBackColor(sf::Color::Black, sf::Color::White);
				}
				else {
					buttonD.setBackColor(sf::Color::White, sf::Color::Black);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (plecak.isMouseOver(piraci))
				{
					cout << "Plecaczek. :D\n";
					tab[1] += 1000;
				}
				if (zagadka.isMouseOver(piraci))
				{
					puzzels(tab);

				}
				if (sklep.isMouseOver(piraci))
				{
					cout << "Tortuga :D\n";
					tab[1] -= 1000;
				}
				if (opcje.isMouseOver(piraci))
				{
					tab[12] = 1;
					
					opptions(piraci, tab);

					tab[12] = 0;

					//window.create(sf::VideoMode(640, 680), "piraci", sf::Style::Default);

					




					cout << "Opcje :D\n";
				}
				
				//MAKING CHOICES
				if (buttonA.isMouseOver(piraci))
				{
					tab[2] = 65;

					if (tab[0] <= 15)
						plot(historia, buttonA, buttonB, buttonC, buttonD, tab);

					if (tab[0] >= 17)
						plot2(historia, buttonA, buttonB, buttonC, buttonD, tab);
					

					cout << "Po wyj�ciu z funkcji: " << tab[0] << std::endl;
				}
				if (buttonB.isMouseOver(piraci))
				{
					tab[2] = 66;

					if (tab[0] <= 15)
						plot(historia, buttonA, buttonB, buttonC, buttonD, tab);

					if (tab[0] >= 17)
						plot2(historia, buttonA, buttonB, buttonC, buttonD, tab);
					

					cout << "Po wyj�ciu z funkcji: " << tab[0] << std::endl;
				}
				if (buttonC.isMouseOver(piraci))
				{
					tab[2] = 67;

					if (tab[0] <= 15)
						plot(historia, buttonA, buttonB, buttonC, buttonD, tab);

					if (tab[0] >= 17)
						plot2(historia, buttonA, buttonB, buttonC, buttonD, tab);

					cout << "Po wyj�ciu z funkcji: " << tab[0] << std::endl;
				}
				if (buttonD.isMouseOver(piraci))
				{
					tab[2] = 68;

					if (tab[0] <= 15)
						plot(historia, buttonA, buttonB, buttonC, buttonD, tab);

					if (tab[0] >= 17)
						plot2(historia, buttonA, buttonB, buttonC, buttonD, tab);
					
					if (tab[0] == 33)
					{
						piraci.close();
						opptions(piraci, tab);
					}

					cout << "Po wyj�ciu z funkcji: " << tab[0] << std::endl;
				}
			}
		}

		string pieniadze = number(tab[1]);
		textpieniedzy.setString(pieniadze + " talar�w");

		string zycie = number(tab[14]);
		hp.setString(zycie + " hp");

		string dmg_max = number(tab[16]);
		string dmg_min = number(tab[16] - 5);
		atak.setString(dmg_min + "-" + dmg_max + " dmg");

		piraci.clear();

		plecak.drawTo(piraci);

		zagadka.drawTo(piraci);

		sklep.drawTo(piraci);

		opcje.drawTo(piraci);

		piraci.draw(poletekstowe);
		piraci.draw(historia);
		
		piraci.draw(ramka);
		buttonA.drawTo(piraci);
		buttonB.drawTo(piraci);
		buttonC.drawTo(piraci);
		buttonD.drawTo(piraci);

		piraci.draw(polepieniedzy);
		piraci.draw(textpieniedzy);

		piraci.draw(hppole);
		piraci.draw(hp);

		piraci.draw(atakpole);
		piraci.draw(atak);

		piraci.display();
	}
}

string number(int n)
{
	stringstream ss;
	ss << n;

	return ss.str();
}

void opptions(sf::RenderWindow& window, int tab[])
{
	//Okno
	sf::RenderWindow opcje;
	opcje.create(sf::VideoMode(640, 680), "Piraci", sf::Style::Default);
	opcje.setPosition({ 645, 170 });

	opcje.setKeyRepeatEnabled(true);


	//Fonts
	sf::Font chanel;
	chanel.loadFromFile("fonts/Channel.ttf");

	sf::Font amarante;
	amarante.loadFromFile("fonts/Amarante-Regular.ttf");

	//Wr�� do gry Button
	Button backgame(L"Powr�t do gry", { 550, 150 }, 50, sf::Color::Transparent, sf::Color::White, chanel);
	backgame.setPosition({ 50, 80 });

	//Zapisz Gr� Button
	Button savegame(L"Zapisz gr�", { 550, 150 }, 50, sf::Color::Transparent, sf::Color::White, chanel);
	savegame.setPosition({ 50, 280 });

	//Powr�t do menu Button
	Button exit(L"Wr�� do menu", { 550, 150 }, 50, sf::Color::Transparent, sf::Color::White, chanel);
	exit.setPosition({ 50, 480 });

	//Main Loop
	while (opcje.isOpen())
	{
		sf::Event ev;

		//NOWA GRA / WR�� DO GRY
		if (tab[12] == 1)
			backgame.changeString(L"Wzn�w gr�");

		else
			backgame.changeString(L"Nowa Gra");

		//WCZYTAJ / ZAPISZ GR�
		if (tab[12] == 1)
		{
			savegame.changeString(L"Zapisz gr�");
			savegame.setPosition({ 50, 280 });
		}
		else
		{
			savegame.changeString(L"Wczytaj gr�");
			savegame.setPosition({ 60, 280 });
		}

		//WYJD� Z GRY / WR�� DO MENU
		if (tab[12] == 1)
		{
			exit.changeString(L"Wr�c do menu");
			exit.setPosition({ 50, 480 });
		}
		else
		{
			exit.changeString(L"Wyj�cie z gry");
			exit.setPosition({ 50, 480 });
		}

		//Event Loop
		while (opcje.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				tab[12] = 0;
				opcje.close();
			case sf::Event::MouseMoved:
				if (backgame.isMouseOver(opcje))
				{
					backgame.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					backgame.setBackColor(sf::Color::Transparent, sf::Color::White);
				}

				if (savegame.isMouseOver(opcje))
				{
					savegame.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else
				{
					savegame.setBackColor(sf::Color::Transparent, sf::Color::White);
				}

				if (exit.isMouseOver(opcje))
				{
					exit.setBackColor(sf::Color::Cyan, sf::Color::Black);
				}
				else {
					exit.setBackColor(sf::Color::Transparent, sf::Color::White);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (backgame.isMouseOver(opcje))
				{
					if (tab[12] == 0)
					{
						int tab1[20] = {};
						tab1[14] = 50;
						tab1[1] = 10000;
						tab1[16] = 10;

						opcje.close();
						piraci(tab1);
					}
					else
					{
						opcje.close();
					}
				}
				if (savegame.isMouseOver(opcje))
				{
					if (tab[12] == 0)
					{
						cout << "Old game :D\n";

						//Miejsce na wczytywanie gry
					}
					else
					{
						//MIEJSCE NA ZAPISANIE STANU GRY
						cout << "Zapisano :D\n";
					}
				}
				if (exit.isMouseOver(opcje))
				{
					if(tab[12] == 0)
					{
						opcje.close();
					}
					else
					{
					window.close();
					tab[12] = 0;
					}
				}
			}

		}

		opcje.clear();

		backgame.drawTo(opcje);
		savegame.drawTo(opcje);
		exit.drawTo(opcje);

		opcje.display();
	}
}