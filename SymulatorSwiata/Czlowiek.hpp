#include "Zwierze.hpp"

class Czlowiek : public Zwierze
{
	int pozostaloSzybkosciAntylopy;
public:
	Czlowiek(int x, int y, Swiat& swiat);

	Czlowiek(int x, int y, int sila, int wiek, int pozostaloSzybkosciAntylopy, Swiat& swiat);


	void wykonajAkcje() override;

	char wykonajKolizje(Organizm& napastnik) override;

	Organizm* stworzPotomka() const override;


	void wczytajInstrukcje();


	std::string serializuj() const override;
};
