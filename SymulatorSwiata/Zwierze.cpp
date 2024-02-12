#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

#include "Zwierze.hpp"
#include "Swiat.hpp"

Zwierze::Zwierze(int x, int y, Swiat& swiat)
	: Organizm(x, y, swiat)
{
	wiek = 0;
}

Zwierze::Zwierze(int x, int y, int sila, int wiek, Swiat& swiat)
	: Organizm(x, y, swiat)
{
	this->sila = sila;

	this->wiek = wiek;
}


void Zwierze::wykonajAkcje()
{
	znajdzNowePolozenie();

	if (swiat.dajOrganizm(nowyX, nowyY) == nullptr)
	{
		zmienPole();
	}
	else
		przeprowadzWalke();
}

void Zwierze::przeprowadzWalke()
{
	Organizm* zaatakowany = swiat.dajOrganizm(nowyX, nowyY);

	char wynikWalki = zaatakowany->wykonajKolizje(*this);
	konsekwencjaWalki(*zaatakowany, wynikWalki);
}

void Zwierze::konsekwencjaWalki(Organizm& zaatakowany, char wynikWalki)
{
	if (wynikWalki == swiat.stale.wygralNapastnik)
	{
		swiat.ustawKomunikat(stworzKomunikat(zaatakowany, "zabity"));
		swiat.usunOrganizm(&zaatakowany);
		zmienPole();
	}
	if (wynikWalki == swiat.stale.wygralZaatakowany)
	{
		swiat.ustawKomunikat(stworzKomunikat(zaatakowany, "zabil"));
		zaatakowany.ustawNowyX(swiat.stale.testowaWartoscPoczatkowa);
		zaatakowany.ustawNowyY(swiat.stale.testowaWartoscPoczatkowa);
		swiat.usunOrganizm(this);
	}
	if (wynikWalki == swiat.stale.odbicieAtaku)
	{
		swiat.ustawKomunikat(stworzKomunikat(zaatakowany, "odbil"));
		nowyX = swiat.stale.testowaWartoscPoczatkowa;
		nowyY = swiat.stale.testowaWartoscPoczatkowa;
	}
	if (wynikWalki == swiat.stale.ucieczkaPrzedWalka)
	{
		swiat.ustawKomunikat(stworzKomunikat(zaatakowany, "uciekl"));
		zmienPole();
	}
	if (wynikWalki == swiat.stale.zjedzenie)
	{
		swiat.ustawKomunikat(stworzKomunikat(zaatakowany, "zjedzony"));
		swiat.usunOrganizm(&zaatakowany);
		zmienPole();
	}
	if (wynikWalki == swiat.stale.zatrucie)
	{
		swiat.ustawKomunikat(stworzKomunikat(zaatakowany, "zatrul"));
		swiat.usunOrganizm(&zaatakowany);
		swiat.usunOrganizm(this);
	}
}


char Zwierze::wykonajKolizje(Organizm& napastnik)
{
	if (typeid(napastnik).name() == typeid(*this).name())
		return rozmnozSie(napastnik);
	else
		return standardowaObrona(napastnik);
}

char Zwierze::rozmnozSie(Organizm& inicjator)
{
	if (swiat.istniejeWolnePoleObok(x, y))
	{
		do
		{
			znajdzNowePolozenie();
		} while (!swiat.poleWolne(nowyX, nowyY));
	}
	else
	{
		int xInicjatora = inicjator.odczytajX();
		int yInicjatora = inicjator.odczytajY();

		if (swiat.istniejeWolnePoleObok(xInicjatora, yInicjatora))
		{
			int ruchX, ruchY;
			do
			{
				do
				{
					losujRuchyDoZmianyPolozenia(ruchX, ruchY);
				}
				while (!swiat.poleIstnieje(xInicjatora + ruchX, yInicjatora + ruchY));
			}
			while (!swiat.poleWolne(xInicjatora + ruchX, yInicjatora + ruchY));

			nowyX = xInicjatora + ruchX;
			nowyY = yInicjatora + ruchY;
		}
	}

	if (nowyX != swiat.stale.testowaWartoscPoczatkowa)
	{
		Zwierze* potomek = (Zwierze*)stworzPotomka();
		swiat.dodajZwierze(potomek);

		return swiat.stale.rozmnozenie;
	}

	return swiat.stale.probaRozmnozenia;
}

char Zwierze::standardowaObrona(Organizm& napastnik) const
{
	if (napastnik.odczytajSile() < sila)
		return swiat.stale.wygralZaatakowany;

	return swiat.stale.wygralNapastnik;
}


int Zwierze::odczytajWiek() const
{
	return wiek;
}

void Zwierze::zwiekszWiek()
{
	wiek++;
}

void Zwierze::zmienPole()
{
	swiat.ustawSymbol(x, y, swiat.stale.wolne);
	x = nowyX;
	y = nowyY;
	swiat.ustawSymbol(x, y, symbol);

	nowyX = swiat.stale.testowaWartoscPoczatkowa;
	nowyY = swiat.stale.testowaWartoscPoczatkowa;
}


std::string Zwierze::serializuj() const
{
	std::string zserializowany = Organizm::serializuj();
	zserializowany += '\n';
	zserializowany += std::to_string(sila);
	zserializowany += '\n';
	zserializowany += std::to_string(wiek);

	return zserializowany;
}