#include "Swiat.hpp"
#include "Roslina.hpp"

Roslina::Roslina(int x, int y, Swiat& swiat)
	: Organizm(x, y, swiat)
{
	inicjatywa = 0;
}


void Roslina::wykonajAkcje()
{
	if (rand() % 100 < swiat.stale.prawdopodobienstwoRozprzestrzenienia)
	{
		if (swiat.istniejeWolnePoleObok(x, y))
		{
			do
			{
				znajdzNowePolozenie();
			}
			while (!swiat.poleWolne(nowyX, nowyY));

			Organizm* potomek = stworzPotomka();
			swiat.dodajRosline((Roslina*)potomek);

			nowyX = swiat.stale.testowaWartoscPoczatkowa;
			nowyY = swiat.stale.testowaWartoscPoczatkowa;
		}
	}
}

char Roslina::wykonajKolizje(Organizm & napastnik)
{
	return swiat.stale.zjedzenie;
}