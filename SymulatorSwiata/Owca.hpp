#include "Zwierze.hpp"

class Owca : public Zwierze
{
public:
	Owca(int x, int y, Swiat& swiat);

	Owca(int x, int y, int sila, int wiek, Swiat& swiat);


	Organizm* stworzPotomka() const override;
};