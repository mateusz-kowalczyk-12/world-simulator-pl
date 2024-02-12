#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

#include "Swiat.hpp"

int main()
{
	srand(time(NULL));
	int rozmiarX, rozmiarY;
	Swiat* swiat;

	std::cout << "Czy chcesz wczytac zapis? (t/n)" << std::endl;
	if (getchar() == 't')
	{
		swiat = new Swiat();
		swiat->wczytajStanSymulacji();
	}
	else
	{
		std::cout << "Podaj rozmiary planszy:\nx: ";
		std::cin >> rozmiarX;
		std::cout << "y: ";
		std::cin >> rozmiarY;

		swiat = new Swiat(rozmiarX, rozmiarY);
	}

	system("CLS");
	while (true)
	{
		swiat->wykonajTure();
		
		system("CLS");
		swiat->ustawKomunikat("\nNacisnij SPACJE, aby przejsc do kolejnej tury\nNacisnij S, aby zapisac\nNacisnij Q, aby wyjsc");
		swiat->rysujSie();
		if (!swiat->kontynuowac())
			break;
		system("CLS");
	}

	delete swiat;
	return 0;
}