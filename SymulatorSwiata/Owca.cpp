#include "Swiat.hpp"
#include "Owca.hpp"

Owca::Owca(int x, int y, Swiat& swiat)
	: Zwierze(x, y, swiat)
{
	sila = 4;
	inicjatywa = 4;

	symbol = swiat.stale.owca;

	swiat.ustawSymbol(x, y, symbol);
}

Owca::Owca(int x, int y, int sila, int wiek, Swiat& swiat)
	: Zwierze(x, y, sila, wiek, swiat)
{
	inicjatywa = 4;

	symbol = swiat.stale.owca;

	swiat.ustawSymbol(x, y, symbol);
}


Organizm* Owca::stworzPotomka() const
{
	return new Owca(nowyX, nowyY, swiat);
}