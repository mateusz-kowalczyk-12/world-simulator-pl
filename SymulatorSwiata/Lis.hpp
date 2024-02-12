#include "Zwierze.hpp"

class Lis : public Zwierze
{
public:
	Lis(int x, int y, Swiat& swiat);

	Lis(int x, int y, int sila, int wiek, Swiat& swiat);


	void wykonajAkcje() override;


	Organizm* stworzPotomka() const override;

	bool daSieRuszyc() const;
};
