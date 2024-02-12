#include "Zwierze.hpp"

class Antylopa : public Zwierze
{
public:
	Antylopa(int x, int y, Swiat& swiat);

	Antylopa(int x, int y, int sila, int wiek, Swiat& swiat);


	void wykonajAkcje() override;

	char wykonajKolizje(Organizm& napastnik) override;

	Organizm* stworzPotomka() const override;


	void znajdzNowePolozenie();
};