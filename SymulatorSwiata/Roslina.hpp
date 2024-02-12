#pragma once

#include "Organizm.hpp"

class Roslina : public Organizm
{
public:
	Roslina(int x, int y, Swiat& swiat);


	virtual void wykonajAkcje() override;

	virtual char wykonajKolizje(Organizm& napastnik) override;
};

