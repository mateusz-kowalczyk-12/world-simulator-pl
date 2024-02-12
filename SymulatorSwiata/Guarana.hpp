#include "Roslina.hpp"

class Guarana : public Roslina
{
public:
	Guarana(int x, int y, Swiat& swiat);


	Organizm* stworzPotomka() const override;

	char wykonajKolizje(Organizm& napastnik) override;
};
