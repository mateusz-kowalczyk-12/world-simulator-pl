#include "Roslina.hpp"

class Trawa : public Roslina
{
public:
	Trawa(int x, int y, Swiat& swiat);


	Organizm* stworzPotomka() const override;
};
