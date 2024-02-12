#include "Swiat.hpp"
#include "Lis.hpp"

Lis::Lis(int x, int y, Swiat& swiat)
	: Zwierze(x, y, swiat)
{
	sila = 3;
	inicjatywa = 7;

	symbol = swiat.stale.lis;

	swiat.ustawSymbol(x, y, symbol);
}

Lis::Lis(int x, int y, int sila, int wiek, Swiat& swiat)
	: Zwierze(x, y, sila, wiek, swiat)
{
	inicjatywa = 7;

	symbol = swiat.stale.lis;

	swiat.ustawSymbol(x, y, symbol);
}


void Lis::wykonajAkcje()
{
	if (daSieRuszyc())
	{
		while (true)
		{
			znajdzNowePolozenie();
			Organizm* zaatakowany = swiat.dajOrganizm(nowyX, nowyY);

			if (zaatakowany == nullptr)
			{
				zmienPole();
				break;
			}
			if (zaatakowany->odczytajSile() <= sila)
			{
				przeprowadzWalke();
				break;
			}
		}
	}
}


Organizm* Lis::stworzPotomka() const
{
	return new Lis(nowyX, nowyY, swiat);
}

bool Lis::daSieRuszyc() const
{
	for (int numerPola = 0; numerPola < 4; numerPola++)
	{
		int wzgledneX, wzgledneY;

		switch (numerPola)
		{
		case 0:
			wzgledneX = 0; wzgledneY = 1;
			break;
		case 1:
			wzgledneX = 1; wzgledneY = 0;
			break;
		case 2:
			wzgledneX = 0; wzgledneY = -1;
			break;
		case 3:
			wzgledneX = -1; wzgledneY = 0;
			break;
		}

		if (swiat.poleIstnieje(x + wzgledneX, y + wzgledneY))
		{
			Organizm* kandydatDoZaatakowania = swiat.dajOrganizm(x + wzgledneX, y + wzgledneY);

			if (kandydatDoZaatakowania == nullptr)
				return true;
			else
			{
				if (kandydatDoZaatakowania->odczytajSile() <= sila)
					return true;
			}
		}
	}

	return false;
}