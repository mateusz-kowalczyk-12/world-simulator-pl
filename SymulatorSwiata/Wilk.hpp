#include "Zwierze.hpp"

class Wilk : public Zwierze
{
public:
	Wilk(int x, int y, Swiat& swiat);

	Wilk(int x, int y, int sila, int wiek, Swiat& swiat);


	Organizm* stworzPotomka() const override;
};

