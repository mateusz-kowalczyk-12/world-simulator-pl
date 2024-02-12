#include <iostream>

#include "Swiat.hpp"
#include "Organizm.hpp"

Organizm::Organizm(int x, int y, Swiat& swiat)
	: swiat(swiat)
{
	this->x = x;
	this->y = y;

	nowyX = swiat.stale.testowaWartoscPoczatkowa;
	nowyY = swiat.stale.testowaWartoscPoczatkowa;
}


void Organizm::znajdzNowePolozenie()
{
	int ruchX, ruchY;
	do
	{
		losujRuchyDoZmianyPolozenia(ruchX, ruchY);
	}
	while (!swiat.poleIstnieje(x + ruchX, y + ruchY));

	nowyX = x + ruchX;
	nowyY = y + ruchY;
}

void Organizm::losujRuchyDoZmianyPolozenia(int& ruchX, int& ruchY)
{
	if (rand() % 2 == 0)
	{
		ruchX = 0;
		ruchY = rand() % 2;

		if (ruchY == 0)
			ruchY = 1;
		else
			ruchY = -1;
	}
	else
	{
		ruchY = 0;
		ruchX = rand() % 2;

		if (ruchX == 0)
			ruchX = 1;
		else
			ruchX = -1;
	}
}


std::string Organizm::stworzKomunikat(Organizm& podmiot, std::string haslo) const
{
	std::string nowyKomunikat = "";

	if (haslo != "zjedzony")
		if (haslo == "zatrul")
			nowyKomunikat = "Zjedzony ";
		else
			nowyKomunikat = "Zaatakowany ";

	nowyKomunikat += podmiot.odczytajSymbol();
	nowyKomunikat += " na (";
	nowyKomunikat += std::to_string(podmiot.odczytajX());
	nowyKomunikat += ", ";
	nowyKomunikat += std::to_string(podmiot.odczytajY());

	if (haslo == "odbil")
		nowyKomunikat += ") odbil atak ";
	if (haslo == "zabity")
		nowyKomunikat += ") zostal zabity przez ";
	if (haslo == "zabil")
		nowyKomunikat += ") zabil ";
	if (haslo == "uciekl")
		nowyKomunikat += ") uciekl przed ";
	if (haslo == "zatrul")
		nowyKomunikat += ") zatrul ";
	if (haslo == "zjedzony")
		nowyKomunikat += ") zostal zjedzony przez ";

	nowyKomunikat += symbol;
	nowyKomunikat += " z (";
	nowyKomunikat += std::to_string(x);
	nowyKomunikat += ", ";
	nowyKomunikat += std::to_string(y);
	nowyKomunikat += ')';

	return nowyKomunikat;
}


int Organizm::odczytajX() const
{
	return x;
}

int Organizm::odczytajNowyX() const
{
	return nowyX;
}

void Organizm::ustawNowyX(int nowyX)
{
	this->nowyX = nowyX;
}

int Organizm::odczytajY() const
{
	return y;
}

int Organizm::odczytajNowyY() const
{
	return nowyY;
}

void Organizm::ustawNowyY(int nowyY)
{
	this->nowyY = nowyY;
}

int Organizm::odczytajSile() const
{
	return sila;
}

int Organizm::odczytajInicjatywe() const
{
	return inicjatywa;
}

void Organizm::zwiekszSile(int zmiana)
{
	sila += zmiana;
}

char Organizm::odczytajSymbol() const
{
	return symbol;
}


std::string Organizm::serializuj() const
{
	std::string zserializowany = "";

	zserializowany += typeid(*this).name();
	zserializowany += '\n';

	zserializowany += std::to_string(x);
	zserializowany += '\n';
	zserializowany += std::to_string(y);

	return zserializowany;
}