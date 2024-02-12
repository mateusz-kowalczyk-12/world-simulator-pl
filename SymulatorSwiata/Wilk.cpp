#include "Swiat.hpp"
#include "Wilk.hpp"

Wilk::Wilk(int x, int y, Swiat& swiat)
	: Zwierze(x, y, swiat)
{
	sila = 9;
	inicjatywa = 5;

	symbol = swiat.stale.wilk;

	swiat.ustawSymbol(x, y, symbol);
}

Wilk::Wilk(int x, int y, int sila, int wiek, Swiat& swiat)
	: Zwierze(x, y, sila, wiek, swiat)
{
	inicjatywa = 5;

	symbol = swiat.stale.wilk;

	swiat.ustawSymbol(x, y, symbol);
}


Organizm* Wilk::stworzPotomka() const
{
	return new Wilk(nowyX, nowyY, swiat);
}