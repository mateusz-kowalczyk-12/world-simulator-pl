#include <iostream>
#include <windows.h>

#include "Swiat.hpp"
#include "Antylopa.hpp"

Antylopa::Antylopa(int x, int y, Swiat& swiat)
	: Zwierze(x, y, swiat)
{
	sila = 4;
	inicjatywa = 4;

	symbol = swiat.stale.antylopa;

	swiat.ustawSymbol(x, y, symbol);
}

Antylopa::Antylopa(int x, int y, int sila, int wiek, Swiat& swiat)
	: Zwierze(x, y, sila, wiek, swiat)
{
	inicjatywa = 4;

	symbol = swiat.stale.antylopa;

	swiat.ustawSymbol(x, y, symbol);
}


void Antylopa::wykonajAkcje()
{
	Antylopa::znajdzNowePolozenie();
	Organizm* zaatakowany = swiat.dajOrganizm(nowyX, nowyY);

	if (zaatakowany == nullptr)
	{
		zmienPole();
	}
	else
		przeprowadzWalke();
}

char Antylopa::wykonajKolizje(Organizm& napastnik)
{
	if (rand() % 2 == 0 && !dynamic_cast<Antylopa*>(&napastnik))
	{
		if (swiat.istniejeWolnePoleObok(x, y))
		{
			while (true)
			{
				Organizm::znajdzNowePolozenie();
				
				if (swiat.poleWolne(nowyX, nowyY))
				{
					zmienPole();
					return swiat.stale.ucieczkaPrzedWalka;
				}
			}
		}
	}

	return Zwierze::wykonajKolizje(napastnik);
}

Organizm* Antylopa::stworzPotomka() const
{
	return new Antylopa(nowyX, nowyY, swiat);
}


void Antylopa::znajdzNowePolozenie()
{
	char ruchX, ruchY;

	do
	{
		if (rand() % 2 == 0)
		{
			ruchX = 0;
			ruchY = rand() % 2;

			if (ruchY == 0)
				ruchY = 2;
			else
				ruchY = -2;
		}
		else
		{
			ruchY = 0;
			ruchX = rand() % 2;

			if (ruchX == 0)
				ruchX = 2;
			else
				ruchX = -2;
		}

	} while (!swiat.poleIstnieje(x + ruchX, y + ruchY));

	nowyX = x + ruchX;
	nowyY = y + ruchY;
}