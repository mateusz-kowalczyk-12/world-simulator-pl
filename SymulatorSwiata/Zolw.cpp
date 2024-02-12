#include "Swiat.hpp"
#include "Zolw.hpp"

Zolw::Zolw(int x, int y, Swiat& swiat)
	: Zwierze(x, y, swiat)
{
	sila = 2;
	inicjatywa = 1;

	symbol = swiat.stale.zolw;

	swiat.ustawSymbol(x, y, symbol);
}

Zolw::Zolw(int x, int y, int sila, int wiek, Swiat& swiat)
	: Zwierze(x, y, sila, wiek, swiat)
{
	inicjatywa = 1;

	symbol = swiat.stale.zolw;

	swiat.ustawSymbol(x, y, symbol);
}


void Zolw::wykonajAkcje()
{
	if (!ruszycSie())
		return;

	Zwierze::wykonajAkcje();
}

char Zolw::wykonajKolizje(Organizm& napastnik)
{
	if (odbilAtak(napastnik))
		return swiat.stale.odbicieAtaku;

	return Zwierze::wykonajKolizje(napastnik);
}

Organizm* Zolw::stworzPotomka() const
{
	return new Zolw(nowyX, nowyY, swiat);
}


bool Zolw::odbilAtak(Organizm& napastnik) const
{
	if (napastnik.odczytajSile() < 5 && !dynamic_cast<Zolw*>(&napastnik))
		return true;

	return false;
}

bool Zolw::ruszycSie() const
{
	if (rand() % 4 < 3)
		return false;

	return true;
}