#include "Swiat.hpp"
#include "Trawa.hpp"

Trawa::Trawa(int x, int y, Swiat& swiat)
	: Roslina(x, y, swiat)
{
	sila = 0;

	symbol = swiat.stale.trawa;

	swiat.ustawSymbol(x, y, symbol);
}


Organizm* Trawa::stworzPotomka() const
{
	return new Trawa(nowyX, nowyY, swiat);
}