//#define DEBUG

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <fstream>

#include "Swiat.hpp"
#include "Wilk.hpp"
#include "Owca.hpp"
#include "Lis.hpp"
#include "Zolw.hpp"
#include "Antylopa.hpp"
#include "Trawa.hpp"
#include "Mlecz.hpp"
#include "Guarana.hpp"
#include "WilczeJagody.hpp"
#include "BarszczSosnowskiego.hpp"
#include "Czlowiek.hpp"

Swiat::Swiat(int rozmiarX, int rozmiarY)
{
	konstruujSwiat(rozmiarX, rozmiarY);

	dodajOrganizmy();
}

Swiat::Swiat()
{}

void Swiat::konstruujSwiat(int rozmiarX, int rozmiarY)
{
	this->rozmiarX = rozmiarX;
	this->rozmiarY = rozmiarY;

	this->plansza = new char* [rozmiarY];
	for (int y = 0; y < rozmiarY; y++)
	{
		this->plansza[y] = new char[rozmiarX];
		for (int x = 0; x < rozmiarX; x++)
		{
			this->plansza[y][x] = stale.wolne;
		}
	}

	komunikat = "";
}

void Swiat::dodajOrganizmy()
{
	dodajZwierze(new Czlowiek(0, 0, *this));

	int pole = stale.krokInicjalizowaniaOrganizmow;
	int x, y;
	int dodanyOrganizm = 1;

	while (true)
	{
		x = pole % rozmiarX;
		y = pole / rozmiarX;
		int rodzajOrganizmu = dodanyOrganizm % stale.liczbaRodzajowOrganizmow;

		if (poleIstnieje(x, y))
		{
			if (rodzajOrganizmu == stale.wilkID)
				dodajZwierze(new Wilk(x, y, *this));
			if (rodzajOrganizmu == stale.owcaID)
				dodajZwierze(new Owca(x, y, *this));
			if (rodzajOrganizmu == stale.lisID)
				dodajZwierze(new Lis(x, y, *this));
			if (rodzajOrganizmu == stale.zolwID)
				dodajZwierze(new Zolw(x, y, *this));
			if (rodzajOrganizmu == stale.antylopaID)
				dodajZwierze(new Antylopa(x, y, *this));

			if (rodzajOrganizmu == stale.trawaID)
				dodajRosline(new Trawa(x, y, *this));
			if (rodzajOrganizmu == stale.mleczID)
				dodajRosline(new Mlecz(x, y, *this));
			if (rodzajOrganizmu == stale.guaranaID)
				dodajRosline(new Guarana(x, y, *this));
			if (rodzajOrganizmu == stale.wilczeJagodyID)
				dodajRosline(new WilczeJagody(x, y, *this));
			if (rodzajOrganizmu == stale.barszczSosnowskiegoID)
				dodajRosline(new BarszczSosnowskiego(x, y, *this));

			dodanyOrganizm++;
			pole += stale.krokInicjalizowaniaOrganizmow;
		}
		else
			break;
	}
}

Swiat::~Swiat()
{
	for (Zwierze* zwierze : zwierzeta)
	{
		delete zwierze;
	}
	for (Roslina* roslina : rosliny)
	{
		delete roslina;
	}

	for (int y = 0; y < rozmiarY; y++)
	{
		delete[] this->plansza[y];
	}

	delete[] this->plansza;
}


int Swiat::odczytajRozmiarX() const
{
	return rozmiarX;
}

int Swiat::odczytajRozmiarY() const
{
	return rozmiarY;
}

void Swiat::dodajZwierze(Zwierze* noweZwierze)
{
	for (Zwierze* zwierze : zwierzeta)
	{
		zwierze->zwiekszWiek();
	}

	zwierzeta.push_back(noweZwierze);
}

void Swiat::dodajRosline(Roslina* nowaRoslina)
{
	rosliny.push_back(nowaRoslina);
}

void Swiat::usunOrganizm(Organizm* organizm)
{
	if (dynamic_cast<Zwierze*>(organizm))
	{
		for (int z = 0; z < zwierzeta.size(); z++)
		{
			if ((Zwierze*)organizm == zwierzeta[z])
			{
				ustawSymbol(organizm->odczytajX(), organizm->odczytajY(), stale.wolne);
				zwierzeta.erase(zwierzeta.begin() + z);
				return;
			}
		}
	}
	else
	{
		for (int r = 0; r < rosliny.size(); r++)
		{
			if ((Roslina*)organizm == rosliny[r])
			{
				ustawSymbol(organizm->odczytajX(), organizm->odczytajY(), stale.wolne);
				rosliny.erase(rosliny.begin() + r);
				return;
			}
		}
	}

	delete organizm;
}

Organizm* Swiat::dajOrganizm(int x, int y) const
{
	Organizm* zaatakowany;

	for (Zwierze* zwierze : zwierzeta)
	{
		if (zwierze->odczytajX() == x && zwierze->odczytajY() == y)
			return zwierze;
	}
	for (Roslina* roslina : rosliny)
	{
		if (roslina->odczytajX() == x && roslina->odczytajY() == y)
			return roslina;
	}

	return nullptr;
}

Czlowiek* Swiat::dajCzlowieka() const
{
	for (Zwierze* zwierze : zwierzeta)
	{
		if (dynamic_cast<Czlowiek*>(zwierze))
			return (Czlowiek*)zwierze;
	}

	return nullptr;
}

void Swiat::ustawSymbol(int x, int y, char symbol)
{
	if ((x >= 0 && x < rozmiarX) && (y >= 0 && y < rozmiarY))
		plansza[y][x] = symbol;
}

void Swiat::ustawKomunikat(std::string komunikat)
{
	if (komunikat == "")
		this->komunikat = komunikat;
	else
		this->komunikat += (komunikat + '\n');
}

std::string Swiat::odczytajKomunikat() const
{
	return komunikat;
}


void Swiat::rysujSie() const
{
	std::cout << stale.autor << std::endl << std::endl;

	wypiszNumeryKolumn();
	for (int y = 0; y < rozmiarY; y++)
	{
		std::cout << std::setw(policzCyfry(rozmiarY - 1)) << std::setfill('0') << y;

		for (int x = 0; x < rozmiarX; x++)
		{
			std::cout << plansza[y][x];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << komunikat << std::endl;
}

void Swiat::wykonajTure()
{
	sortujZwierzeta();

	ustawKomunikat("");
	rysujSie();

	Czlowiek* czlowiek = dajCzlowieka();
	if (czlowiek != nullptr)
	{
		system("CLS");
		czlowiek->wczytajInstrukcje();
		ustawKomunikat("");
		system("CLS");
	}

	std::vector<Zwierze*> poczatkoweZwierzeta = zwierzeta;
	for (Zwierze* zwierze : poczatkoweZwierzeta)
	{
		if (zwierzeNadalIstnieje(zwierze))
		{
			zwierze->wykonajAkcje();
		}
	}

	int liczbaRoslin = rosliny.size();
	for (int r = 0; r < liczbaRoslin; r++)
	{
		rosliny[r]->wykonajAkcje();
	}
}


void Swiat::wypiszNumeryKolumn() const
{
	int liczbaCyfr = policzCyfry(rozmiarX - 1);

	for (int numerCyfry = 0; numerCyfry < liczbaCyfr; numerCyfry++) {
		for (int i = 0; i < policzCyfry(rozmiarY - 1); i++) {
			std::cout << ' ';

		}
		for (int x = 0; x < rozmiarX; x++) {
			int cyfra = (x % (int)pow(10, liczbaCyfr - numerCyfry)) / (int)pow(10, liczbaCyfr - 1 - numerCyfry);

			std::cout << cyfra;

		}
		std::cout << std::endl;

	}
}

void Swiat::sortujZwierzeta()
{
	for (int i = zwierzeta.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++)
		{
			if (zwierzeta[j]->odczytajWiek() < zwierzeta[j + 1]->odczytajWiek())
				std::swap(zwierzeta[j], zwierzeta[j + 1]);
		}
	}

	for (int i = zwierzeta.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++)
		{
			if (zwierzeta[j]->odczytajInicjatywe() < zwierzeta[j + 1]->odczytajInicjatywe())
				std::swap(zwierzeta[j], zwierzeta[j + 1]);
		}
	}
}


bool Swiat::istniejeWolnePoleObok(int x, int y) const
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

		if (poleIstnieje(x + wzgledneX, y + wzgledneY))
		{
			if (plansza[y + wzgledneY][x + wzgledneX] == stale.wolne)
				return true;
		}
	}

	return false;
}

bool Swiat::poleWolne(int x, int y) const
{
	if (plansza[y][x] == stale.wolne)
		return true;
	return false;
}

bool Swiat::poleIstnieje(int x, int y) const
{
	if ((x >= 0 && x < rozmiarX) && (y >= 0 && y < rozmiarY))
		return true;
	return false;
}

int Swiat::policzCyfry(int liczba) const
{
	int wynik = 1;
	while (liczba >= 10) {
		wynik++;
		liczba /= 10;

	}
	return wynik;
}

bool Swiat::zwierzeNadalIstnieje(Zwierze* poczatkoweZwierze) const
{
	for (Zwierze* zwierze : zwierzeta)
	{
		if (zwierze == poczatkoweZwierze)
			return true;
	}
	return false;
}


void Swiat::czekajNaSpacje() const
{
	char klawisz;
	do
	{
		klawisz = _getch();
	}
	while(klawisz != ' ');
}

bool Swiat::kontynuowac()
{
	char klawisz;
	while (true)
	{
		klawisz = _getch();

		if (klawisz == ' ')
			return true;
		if (klawisz == 's')
			zapiszStanSymulacji();
		if (klawisz == 'q')
			return false;
	}
}


void Swiat::zapiszStanSymulacji()
{
	std::fstream plik;
	plik.open("zapis" + std::to_string(time(NULL)) + ".txt", std::ios::out);

	plik << std::to_string(rozmiarX) << std::endl << std::to_string(rozmiarY) << std::endl;

	for (Zwierze* zwierze : zwierzeta)
	{
		plik << zwierze->serializuj() << std::endl;
	}
	for (Roslina* roslina : rosliny)
	{
		plik << roslina->serializuj() << std::endl;
	}
}

void Swiat::wczytajStanSymulacji()
{
	std::cout << "Podaj nazwe pliku z zapisem: ";
	std::string nazwaPliku;
	std::cin >> nazwaPliku;

	std::fstream plik;
	plik.open(nazwaPliku, std::ios::in);

	std::string linia;
	int rozmiarX, rozmiarY;

	getline(plik, linia);
	rozmiarX = stoi(linia);
	getline(plik, linia);
	rozmiarY = stoi(linia);

	konstruujSwiat(rozmiarX, rozmiarY);

	while (getline(plik, linia))
	{
		std::string linia2;
		int x, y;

		getline(plik, linia2);
		x = stoi(linia2);
		getline(plik, linia2);
		y = stoi(linia2);

		if (linia == "class Trawa")
		{
			dodajRosline(new Trawa(x, y, *this));
			continue;
		}
		if (linia == "class Mlecz")
		{
			dodajRosline(new Mlecz(x, y, *this));
			continue;
		}
		if (linia == "class Guarana")
		{
			dodajRosline(new Guarana(x, y, *this));
			continue;
		}
		if (linia == "class WilczeJagody")
		{
			dodajRosline(new WilczeJagody(x, y, *this));
			continue;
		}
		if (linia == "class BarszczSosnowskiego")
		{
			dodajRosline(new BarszczSosnowskiego(x, y, *this));
			continue;
		}

		int sila, wiek;

		getline(plik, linia2);
		sila = stoi(linia2);
		getline(plik, linia2);
		wiek = stoi(linia2);

		if (linia == "class Wilk")
		{
			dodajZwierze(new Wilk(x, y, sila, wiek, *this));
			continue;
		}
		if (linia == "class Owca")
		{
			dodajZwierze(new Owca(x, y, sila, wiek, *this));
			continue;
		}
		if (linia == "class Lis")
		{
			dodajZwierze(new Lis(x, y, sila, wiek, *this));
			continue;
		}
		if (linia == "class Zolw")
		{
			dodajZwierze(new Zolw(x, y, sila, wiek, *this));
			continue;
		}
		if (linia == "class Antylopa")
		{
			dodajZwierze(new Antylopa(x, y, sila, wiek, *this));
			continue;
		}
		if (linia == "class Czlowiek")
		{
			int pozostaloSzybkosciAntylopy;

			getline(plik, linia2);
			pozostaloSzybkosciAntylopy = stoi(linia2);

			dodajZwierze(new Czlowiek(x, y, sila, wiek, pozostaloSzybkosciAntylopy, *this));
			continue;
		}
	}
}