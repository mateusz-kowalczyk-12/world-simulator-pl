#include "Roslina.hpp"

class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(int x, int y, Swiat& swiat);


	void wykonajAkcje() override;


	Organizm* stworzPotomka() const override;

	char wykonajKolizje(Organizm& napastnik) override;
};
