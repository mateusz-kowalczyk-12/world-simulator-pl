#include <iostream>
#include <conio.h>
#include <windows.h>

#include "Swiat.hpp"
#include "Czlowiek.hpp"

Czlowiek::Czlowiek(int x, int y, Swiat& swiat)
	: Zwierze(x, y, swiat)
{
	sila = 5;
	inicjatywa = 4;

	symbol = swiat.stale.czlowiek;

	swiat.ustawSymbol(x, y, symbol);

	pozostaloSzybkosciAntylopy = -5;
}

Czlowiek::Czlowiek(int x, int y, int sila, int wiek, int pozostaloSzybkosciAntylopy, Swiat& swiat)
	: Zwierze(x, y, sila, wiek, swiat)
{
	inicjatywa = 4;

	symbol = swiat.stale.czlowiek;

	swiat.ustawSymbol(x, y, symbol);

	this->pozostaloSzybkosciAntylopy = pozostaloSzybkosciAntylopy;
}


void Czlowiek::wykonajAkcje()
{
	if (swiat.dajOrganizm(nowyX, nowyY) == nullptr)
	{
		zmienPole();
	}
	else
		przeprowadzWalke();

	if (pozostaloSzybkosciAntylopy > -5)
		pozostaloSzybkosciAntylopy--;
}

char Czlowiek::wykonajKolizje(Organizm& napastnik)
{
	return standardowaObrona(napastnik);
}

Organizm* Czlowiek::stworzPotomka() const
{
	return new Czlowiek(nowyX, nowyY, swiat);
}


void Czlowiek::wczytajInstrukcje()
{
	if(pozostaloSzybkosciAntylopy > -5)
		swiat.ustawKomunikat("Wybierz kierunek ruchu strzalkami");
	else
		swiat.ustawKomunikat("P - wlacz szybkosc antylopy\nWybierz kierunek ruchu strzalkami");
	
	swiat.rysujSie();

	while (true)
	{
		int kod = _getch();
		if (kod == 'p' && pozostaloSzybkosciAntylopy == -5)
		{
			std::cout << "Aktywowano szybkosc antylopy!" << std::endl;
			pozostaloSzybkosciAntylopy = 5;
		}
		if (kod == 224) //wcisnieto strzalke
		{
			int ruch;
			if ((pozostaloSzybkosciAntylopy >= 4) || (pozostaloSzybkosciAntylopy >= 1 && pozostaloSzybkosciAntylopy <= 3 && rand() % 2 == 0))
				ruch = 2;
			else
				ruch = 1;

			char kierunek = _getch();
			if (kierunek == 72) //wcisnieto stralke w gore
			{
				if (swiat.poleIstnieje(x, y - ruch))
				{
					nowyX = x;
					nowyY = y - ruch;
					break;
				}
			}
			if (kierunek == 80) //wcisnieto stralke w dol
			{
				if (swiat.poleIstnieje(x, y + ruch))
				{
					nowyX = x;
					nowyY = y + ruch;
					break;
				}
			}
			if (kierunek == 77) //wcisnieto stralke w prawo
			{
				if (swiat.poleIstnieje(x + ruch, y))
				{
					nowyX = x + ruch;
					nowyY = y;
					break;
				}
			}
			if (kierunek == 75) //wcisnieto stralke w lewo
			{
				if (swiat.poleIstnieje(x - ruch, y))
				{
					nowyX = x - ruch;
					nowyY = y;
					break;
				}
			}
		}
	}
}


std::string Czlowiek::serializuj() const
{
	std::string zserializowany = Zwierze::serializuj();
	zserializowany += '\n';
	zserializowany += std::to_string(pozostaloSzybkosciAntylopy);

	return zserializowany;
}