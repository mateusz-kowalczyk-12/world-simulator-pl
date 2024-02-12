#include "Swiat.hpp"
#include "BarszczSosnowskiego.hpp"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat& swiat)
	: Roslina(x, y, swiat)
{
	sila = 10;

	symbol = swiat.stale.barszczSosnowskiego;

	swiat.ustawSymbol(x, y, symbol);
}


void BarszczSosnowskiego::wykonajAkcje()
{
	for (int numerPola = 0; numerPola < 4; numerPola++)
	{
		int wzgledneX, wzgledneY;

		switch (numerPola)
		{
		case 0:
			wzgledneX = 0; wzgledneY = 1;
			break;
		case 1:
			wzgledneX = 1; wzgledneY = 0;
			break;
		case 2:
			wzgledneX = 0; wzgledneY = -1;
			break;
		case 3:
			wzgledneX = -1; wzgledneY = 0;
			break;
		}

		Organizm* organizm = swiat.dajOrganizm(x + wzgledneX, y + wzgledneY);

		if (organizm == nullptr)
			continue;
		if (dynamic_cast<Zwierze*>(organizm))
		{
			swiat.ustawKomunikat(stworzKomunikat(*organizm, "zabity"));
			swiat.usunOrganizm(organizm);
		}
	}

	Roslina::wykonajAkcje();
}


Organizm* BarszczSosnowskiego::stworzPotomka() const
{
	return new BarszczSosnowskiego(nowyX, nowyY, swiat);
}

char BarszczSosnowskiego::wykonajKolizje(Organizm& napastnik)
{
	return swiat.stale.zatrucie;
}