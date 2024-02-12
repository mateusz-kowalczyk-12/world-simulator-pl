#include "Zwierze.hpp"

class Zolw : public Zwierze
{
public:
	Zolw(int x, int y, Swiat& swiat);

	Zolw(int x, int y, int sila, int wiek, Swiat& swiat);


	void wykonajAkcje() override;

	char wykonajKolizje(Organizm& napastnik) override;

	Organizm* stworzPotomka() const override;


	bool odbilAtak(Organizm& napastnik) const;

	bool ruszycSie() const;
};