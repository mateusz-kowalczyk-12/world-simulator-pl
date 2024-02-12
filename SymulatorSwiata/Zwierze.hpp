#pragma once

#include <ctime>
#include <string>

#include "Organizm.hpp"

class Zwierze : public Organizm
{
protected:
	int wiek;
public:
	Zwierze(int x, int y, Swiat& swiat);

	Zwierze(int x, int y, int sila, int wiek, Swiat& swiat);


	virtual void wykonajAkcje() override;

	void przeprowadzWalke();

	void konsekwencjaWalki(Organizm& zaatakowany, char wynikWalki);


	virtual char wykonajKolizje(Organizm& napastnik) override;

	char rozmnozSie(Organizm& inicjator);

	char standardowaObrona(Organizm& napastnik) const;


	int odczytajWiek() const;

	void zwiekszWiek();

	void zmienPole();


	virtual std::string serializuj() const override;
};

