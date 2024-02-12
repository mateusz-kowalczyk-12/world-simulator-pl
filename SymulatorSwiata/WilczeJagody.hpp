#include "Roslina.hpp"

class WilczeJagody : public Roslina
{
public:
	WilczeJagody(int x, int y, Swiat& swiat);


	Organizm* stworzPotomka() const override;

	char wykonajKolizje(Organizm& napastnik) override;
};
