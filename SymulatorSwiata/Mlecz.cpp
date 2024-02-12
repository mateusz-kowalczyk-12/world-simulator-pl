#include "Swiat.hpp"
#include "Mlecz.hpp"

Mlecz::Mlecz(int x, int y, Swiat& swiat)
	: Roslina(x, y, swiat)
{
	sila = 0;

	symbol = swiat.stale.mlecz;

	swiat.ustawSymbol(x, y, symbol);
}


void Mlecz::wykonajAkcje()
{
	for (int i = 0; i < 3; i++)
	{
		Roslina::wykonajAkcje();
	}
}


Organizm* Mlecz::stworzPotomka() const
{
	return new Mlecz(nowyX, nowyY, swiat);
}