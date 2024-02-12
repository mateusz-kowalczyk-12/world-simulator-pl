#pragma once

#include <string>

class Swiat;

class Zwierze;

class Organizm
{
protected:
	int sila, inicjatywa;
	
	int x, y;
	int nowyX, nowyY;

	char symbol;

	Swiat& swiat;

public:
	Organizm(int x, int y, Swiat& swiat);


	virtual void wykonajAkcje() = 0;

	virtual char wykonajKolizje(Organizm& napastnik) = 0;


	void znajdzNowePolozenie();

	void losujRuchyDoZmianyPolozenia(int& ruchX, int& ruchY);


	std::string stworzKomunikat(Organizm& podmiot, std::string haslo) const;

	virtual Organizm* stworzPotomka() const = 0;


	int odczytajX() const;

	int odczytajNowyX() const;

	void ustawNowyX(int nowyX);

	int odczytajY() const;

	int odczytajNowyY() const;

	void ustawNowyY(int nowyY);

	int odczytajSile() const;

	int odczytajInicjatywe() const;

	void zwiekszSile(int zmiana);

	char odczytajSymbol() const;


	virtual std::string serializuj() const;
};