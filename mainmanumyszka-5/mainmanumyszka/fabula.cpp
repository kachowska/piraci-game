#include<iostream>
#include<string>
#include<sstream>
#include<ctime>

#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include"Button.h"
#include"NaRazieSmieci.h"

void walka(sf::Text& tekst, Button& A, Button& B, Button& C, Button& D, int tab[], int n)
{
    srand(time(NULL));

    A.changeString(L"Atak");
    B.changeString(L"Unik");
    C.changeString(L"Użyj przedimotu");
    D.changeString(L"");

    if (n == 1)
    {
        tekst.setString(L"Walka z jaszczuroludźmi.");
        tab[17] = 30;
    }

    while (tab[14] > 0 && tab[17] > 0)
    {
        if (tab[13] == 0)
        {
            switch (tab[2])
            {
                case 65:
                    tab[15] = (rand() % 10) + 5;
                    std::cout << tab[15] << " " << tab[17];
                    tab[17] -= tab[15];
                    break;
            }
        }
    }

}

void plot(sf::Text& tekst, Button& A, Button& B, Button& C, Button& D, int tab[])
{
    tab[5] = 0;

    if (tab[2] == 'A')
    {
        switch (tab[0])
        {
            case 1:
                tekst.setString(L"Wybór miejsca do poszukiwania odpowiedzi:");
                A.changeString(L"Karczma");
                B.changeString(L"Doki");
                if (tab[6] == 1)
                {
                    C.changeString(L"Tajemniczy pirat");
                }
                tab[0] = 2;
                break;
            case 2:
                tekst.setString(L"Z kim chcesz rozmawiać?");
                A.changeString(L"Pijany pirat pod stołem");
                B.changeString(L"Parczmarz");
                C.changeString(L"Pirat przy barze");
                D.changeString(L"Wyjdź z karczmy");
                tab[0] = 3;
                break;
            case 3:
                tekst.setString(L"Pirat okazuje się był twoim starym znajomym. Nie daje ci żadnych podpowiedzi,\nale jest na tyle nietrzezwy, że możesz go obrabować z pieniędzy bez żadnych konsekwencji.");
                A.changeString(L"Rabujesz");
                B.changeString(L"Nie rabujesz");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 5;
                break;
            case 4:
                tekst.setString(L"Piraci są zmęczeni podróżą i nie chcą z tobą rozmawiać.\nJeden z nich w ciebie wpada. Po tym, jak znikaje z twojego pola widzenia,\nwidzisz, że jeden z nich zostawił ci kartkę z proźbą o spotkanie.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[6] = 1;
                tab[0] = 13;
                break;
            case 5:
                tekst.setString(L"Dostajesz kasę.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[1] += 100;
                tab[0] = 12;
                break;
            case 6:
                tekst.setString(L"Przede wszystkim straszy potworami morskimi, które gracz może spotkać.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[1] -= 100;
                tab[0] = 12;
                break;
            case 7:
                tekst.setString(L"Płacisz mu. Coś ci tam mówi.\nChcesz go teraz okraść?");
                A.changeString(L"Oczywiście.");
                B.changeString(L"Nie! Miejće serce.");
                C.changeString(L"");
                D.changeString(L"");
                tab[1] -= 20;
                tab[0] = 8;
                break;
            case 8:
                tekst.setString(L"Okradasz go. Ale on pomyślał o tym samym. Wychodzisz na zero.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 13;
                break;
            case 12:
                tekst.setString(L"Z kim chcesz rozmawiać?");
                A.changeString(L"Pijany pirat pod stołem");
                B.changeString(L"Karczmarz");
                C.changeString(L"Pirat przy barze");
                D.changeString(L"Wyjdź z karczmy");
                tab[0] = 3;
                break;
            case 13:
                tekst.setString(L"Z kim chcesz rozmawiać?");
                A.changeString(L"Piraci schodzący z pokładu");
                B.changeString(L"Sprzedawca statk�w� ?");
                C.changeString(L"Żebrak");
                D.changeString(L"Wyjdź z doków");
                tab[0] = 4;
                break;
            case 14:
                tekst.setString(L"Według legend, hydra żyje na bagiennej wyspie morskiej wiedźmy\ni tam też postanawiacie się udać.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 16;
                tab[7] = 1;
                break;
            default:
                std::wcout << "Sth is wrong\n?";
        }

        std::cout << tab[0] << std::endl;
    }

    if (tab[2] == 'B')
    {
        switch (tab[0])
        {
            case 1:
                if(tab[6] == 1)
                {
                    tekst.setString(L"Piratem okazuje się był babka, Roma, która proponuje,\nże podzielicie się skarbem po połowie.\nMa już statek (nie można go wybrać w sklepie)\ni zna odpowiedź na zagadkę.\nCzy zgadzasz się na jej warunki?");
                    A.changeString(L"Tak");
                    B.changeString(L"Nie");
                    C.changeString(L"");
                    D.changeString(L"");
                    tab[0] = 14;
                }
                break;
            case 2:
                tekst.setString(L"Z kim chcesz rozmawiać?");
                A.changeString(L"Piraci schodzący z pokładu");
                B.changeString(L"Handlarz okrętów");
                C.changeString(L"Żebrak");
                D.changeString(L"Wyjdź z doków");
                tab[0] = 4;
                break;
            case 3:
                tekst.setString(L"Daje podpowiedź za opłatę.");
                A.changeString(L"Płacisz");
                B.changeString(L"Jeszcze czego...");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 6;
                break;
            case 4:
                tekst.setString(L"Sprzedawca nic nie wie, ale możesz u niego kupić, a póniej również ulepszyć statek.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 13;
                break;
            case 5:
                tekst.setString(L"Ok.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 12;
                break;
            case 6:
                tekst.setString(L"Ok.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 12;
                break;
            case 7:
                tekst.setString(L"Zostawiasz żebraka samego.\nChcesz go przy okazji okraść?");
                A.changeString(L"Oczywiście.");
                B.changeString(L"Nie! Miejće serce.");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 8;
                break;
            case 8:
                tekst.setString(L"Tyle ci z tego serca, że staruch cię okradł.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[1] -= 100;
                tab[0] = 13;
                break;
            case 14:
                tekst.setString(L"Musisz teraz poprawnie odpowiedzieć na zagadkę.");
                A.changeString(L"");
                B.changeString(L"");
                C.changeString(L"Ok");
                D.changeString(L"Poddaję się � biegnij za Romą.");
                tab[0] = 15;
                break;
            default:
                std::wcout << "Sth is wrong\n";
        }

        std::cout << tab[0] << std::endl;
    }

    if (tab[2] == 'C')
    {
        switch (tab[0])
        {
            case 2:
                if (tab[6] == 1)
                {
                    tekst.setString(L"Na pewno? Po wybraniu tej opcji nie możesz już wrócić.");
                    A.changeString(L"Jeszcze się zastanowię.");
                    B.changeString(L"Na pewno.");
                    C.changeString(L"");
                    D.changeString(L"");
                    tab[0] = 1;
                }
                break;
            case 3:
                tekst.setString(L"Też daje jakieś podpowiedzi.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 12;
                break;
            case 4:
                tekst.setString(L"Żebrak, za opłatę, daje podpowiedź.");
                A.changeString(L"Jasne.");
                B.changeString(L"Chyba go coś.");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 7;
                break;
                /*case 9:
                    tekst.setString(L"Musisz teraz poprawnie odpowiedzie� na zagadk�.");
                    A.changeString(L"");
                    B.changeString(L"");
                    C.changeString(L"Ok");
                    D.changeString(L"Poddaj� si� � biegnij za Rom�.");
                    tab[0] = 15;
                    break;*/
            case 15:
                puzzels(tab);

                break;
            default:
                std::wcout << "Sth is wrong\n?";
        }

        std::cout << tab[0] << std::endl;
    }

    if (tab[2] == 'D')
    {
        switch (tab[0])
        {
            case 3:
                tekst.setString(L"Gdzie teraz?");
                A.changeString(L"Karczma");
                B.changeString(L"Doki");
                C.changeString(L"");
                D.changeString(L"");
                if (tab[6] == 1)
                {
                    C.changeString(L"Tajemniczy pirat");
                }
                tab[0] = 2;
                break;
            case 4:
                tekst.setString(L"Gdzie teraz?");
                A.changeString(L"Karczma");
                B.changeString(L"Doki");
                C.changeString(L"");
                D.changeString(L"");
                if (tab[6] == 1)
                {
                    C.changeString(L"Tajemniczy pirat");
                }
                tab[0] = 2;
                break;
            case 15:
                tekst.setString(L"Zgadza się, ale tym\nrazem jednak wymaga zapłaty (w wysokości wszystkiego,\nco masz w kieszeni).");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[1] = 0;
                tab[7] = 1;
                tab[0] = 16;
                break;
            default:
                std::wcout << "Sth is wrong\n?";
        }

        std::cout << tab[0] << std::endl;
    }

}

void plot2(sf::Text& tekst, Button& A, Button& B, Button& C, Button& D, int tab[])
{
    if (tab[2] == 'A')
    {
        switch (tab[0])
        {
            case 17:
                tekst.setString(L"Po przesłuchaniu jaszczuroludzi dowiadujesz się, że wysłała ich\nna ciebie morska wiedźma, Hippolilta.Przynajmniej\nwiecie, że nie ma dobrych intencji.\nGdzie chcesz się teraz udać ?");
                A.changeString(L"Dom Hippolity");
                B.changeString(L"W głęb wyspy");
                C.changeString(L"Bagienne jezioro");
                D.changeString(L"");
                tab[0] = 18;
                break;
            case 18:
                tekst.setString(L"Cool rozmowa z wiedźmą,\nktóra probuje przekonać gracza do rezygnacji\nze skarbu Myszołowa. Po tym kolejna walka i guess.");
                A.changeString(L"Dalej");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 19;
                break;
            case 19:
                tekst.setString(L"Walka");
                if (tab[4] == 0)
                {
                    A.changeString(L"Wygrana");
                    B.changeString(L"");
                    C.changeString(L"");
                    D.changeString(L"");
                    tab[0] = 25;

                    if (tab[8] == 1)
                        tab[1] += 1000;
                }
                else {
                    puzzels(tab);
                }
                tab[4] = 1;
                break;
            case 20:
                tekst.setString(L"Znajdujesz jaskinię.\nCzy chcesz do niej wejść?");
                A.changeString(L"Tak");
                B.changeString(L"Nie");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 21;
                break;
            case 21:
                tekst.setString(L"Znajdujesz fajne kwiatki. Zrywasz je. Nie masz wyboru.");
                A.changeString(L"");
                B.changeString(L"Powrót na ścieżkę");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 22;
                break;
            case 23:
                while (tab[14] > 0 && tab[17] > 0)
                {
                    walka(tekst, A, B, C, D, tab, 1);
                }

                tekst.setString(L"Walka z jaszczuroludźmi. Po wygranej dowiadujesz się,\nże czarownica ma słabość w postaci kwiatów,\nktóre rosną sobie w jaskini.");
                A.changeString(L"");
                B.changeString(L"Powrót na ścieżkę");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 22;
                break;
            case 25:
                tekst.setString(L"Musisz teraz poprawnie odpowiedzieć na zagadkę.");
                A.changeString(L"");
                B.changeString(L"");
                C.changeString(L"Ok");
                D.changeString(L"");

                if(tab[5]>=3 && tab[7] == 1)
                    D.changeString(L"Poddaję się � poproś Romę o pomoc.");

                tab[0] = 26;
                break;
            case 29:
                tekst.setString(L"Opis domku Hipolity.\nGdzie teraz?");
                A.changeString(L"Jakaś zła odpowiedź");
                B.changeString(L"Laguna syren");
                C.changeString(L"Jakaś zła odpowiedź");
                D.changeString(L"");
                tab[0] = 30;
                break;
            case 30:
                tekst.setString(L"Postaraj się bardziej.");

                tab[10] = 1;

                tab[0] = 30;
                break;
        }
    }

    if (tab[2] == 'B')
    {
        switch (tab[0])
        {
            case 18:
                tekst.setString(L"W prawo, lewo czy prosto?\nLub powrót.");
                A.changeString(L"prawo");
                B.changeString(L"lewo");
                C.changeString(L"prosto");
                D.changeString(L"powrót");
                tab[0] = 20;
                break;
            case 20:
                tekst.setString(L"Trafiasz do wioski jaszczuroludzi.");
                A.changeString(L"Atakujesz ich.");
                B.changeString(L"Rozmawiasz z nimi.");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 23;
                break;
            case 21:
                tekst.setString(L"Nie to nie.");
                A.changeString(L"");
                B.changeString(L"Powrót na ścieżkę");
                C.changeString(L"");
                D.changeString(L"");
                tab[0] = 22;
                break;
            case 22:
                tekst.setString(L"W prawo, lewo czy prosto?\nLub powrót.");
                A.changeString(L"prawo");
                B.changeString(L"lewo");
                C.changeString(L"prosto");
                D.changeString(L"powrót");
                tab[0] = 20;
                break;
            case 23:
                tekst.setString(L"They are pretty chill actually. Some lore dumping.\nCzarownica ich zakl�a czy podobny shit. W sumie zapłacę ci,\njeśli ją pokonasz. Teraz po zabiciu czarownicy automatycznie\ndostajesz hajs.");
                A.changeString(L"");
                B.changeString(L"Powrót na ścieżkę");
                C.changeString(L"");
                D.changeString(L"");
                tab[8] = 1;
                tab[0] = 22;
                break;
            case 29:
                if (tab[7] == 1)
                {
                    tekst.setString(L"\nWiedźma ewidentnie była syreną.");
                    A.changeString(L"");
                    B.changeString(L"");
                    C.changeString(L"");
                    D.changeString(L"Dalej");

                    tab[0] = 31;
                }
                break;
            case 30:
                tekst.setString(L"Czas ruszyć w stronę Laguny.");
                A.changeString(L"");
                B.changeString(L"");
                C.changeString(L"");
                D.changeString(L"Dalej");

                if(tab[10] == 0)
                    tab[1] += 100;

                tab[0] = 31;
                break;
        }
    }

    if (tab[2] == 'C')
    {
        switch (tab[0])
        {
            case 18:
                tekst.setString(L"U found hydra. :D Rozpoczyna się walka.");
                A.changeString(L"");
                B.changeString(L"");
                C.changeString(L"Wygrana.");
                D.changeString(L"");
                tab[1] += 100;;
                tab[0] = 24;
                break;
            case 20:
                tekst.setString(L"Znajdujesz zwłoki piratów, którzy trafili tu przed tobą.\nIch śmierć jest ewidentnie sprawką czarownicy.");
                A.changeString(L"");
                B.changeString(L"Powrót na ścieżkę");
                C.changeString(L"");
                D.changeString(L"");
                tab[1] += 100;
                tab[0] = 22;
                break;
            case 24:
                tekst.setString(L"Przeszukując ciało Hydry znajdujesz fragment klucza z �wyrze�bion��?� (tak, zapomniałem słowa) cyfrą 1.\nGdzie teraz?");
                A.changeString(L"Dom Hippolity");
                B.changeString(L"W głęb wyspy");
                C.changeString(L"Bagienne jezioro");
                D.changeString(L"");
                tab[3] = 1;
                tab[0] = 18;
                break;
            case 26:
                puzzels(tab);

                if (tab[5] >= 3 && tab[7] == 1 && tab[11]==0)
                    D.changeString(L"Poddaję się i poproś Romę o pomoc.");

                break;
            case 29:
                if (tab[8] == 1)
                {
                    tekst.setString(L"\nWiedźma ewidentnie była syreną.");
                    A.changeString(L"");
                    B.changeString(L"");
                    C.changeString(L"");
                    D.changeString(L"Dalej");

                    tab[0] = 31;
                }
                break;
            case 30:
                tekst.setString(L"Postaraj się bardziej.");

                tab[10] = 1;

                tab[0] = 30;
                break;
        }
    }

    if (tab[2] == 'D')
    {
        switch (tab[0])
        {
            case 20:
                tekst.setString(L"Gdzie teraz");
                A.changeString(L"Dom Hippolity");
                B.changeString(L"W głęb wyspy");
                C.changeString(L"Bagienne jezioro");
                D.changeString(L"");
                tab[0] = 18;
                break;
            case 26:
                if(tab[5] >= 3 && tab[7] == 1)
                {
                    tekst.setString(L"Sprobuj Pas Hipolity.");
                    A.changeString(L"");
                    B.changeString(L"");
                    C.changeString(L"Ok");
                    D.changeString(L"");

                    tab[11] = 1;
                }
                break;
                /*case 27:
                    tekst.setString(L"Sprub�j Pas Hipolity.");
                    A.changeString(L"");
                    B.changeString(L"");
                    C.changeString(L"");
                    D.changeString(L"Dalej");
                    tab[0] = 28;
                    break;*/
            case 31:
                tekst.setString(L"Do zobaczenia w lagunie!");
                tekst.setCharacterSize(30);
                D.changeString(L"Exit");
                tab[0] = 32;
                break;
            case 32:
                tab[0] = 33;
                break;
        }
    }

}