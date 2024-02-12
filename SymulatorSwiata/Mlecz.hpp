#include "Roslina.hpp"

class Mlecz : public Roslina
{
public:
	Mlecz(int x, int y, Swiat& swiat);


	void wykonajAkcje() override;


	Organizm* stworzPotomka() const override;
};
