#include "Swiat.hpp"
#include "WilczeJagody.hpp"

WilczeJagody::WilczeJagody(int x, int y, Swiat& swiat)
	: Roslina(x, y, swiat)
{
	sila = 99;

	symbol = swiat.stale.wilczeJagody;

	swiat.ustawSymbol(x, y, symbol);
}


Organizm* WilczeJagody::stworzPotomka() const
{
	return new WilczeJagody(nowyX, nowyY, swiat);
}

char WilczeJagody::wykonajKolizje(Organizm& napastnik)
{
	return swiat.stale.zatrucie;
}