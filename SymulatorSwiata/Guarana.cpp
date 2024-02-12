#include "Swiat.hpp"
#include "Guarana.hpp"

Guarana::Guarana(int x, int y, Swiat& swiat)
	: Roslina(x, y, swiat)
{
	sila = 0;

	symbol = swiat.stale.guarana;

	swiat.ustawSymbol(x, y, symbol);
}


Organizm* Guarana::stworzPotomka() const
{
	return new Guarana(nowyX, nowyY, swiat);
}

char Guarana::wykonajKolizje(Organizm& napastnik)
{
	napastnik.zwiekszSile(3);
	return Roslina::wykonajKolizje(napastnik);
}