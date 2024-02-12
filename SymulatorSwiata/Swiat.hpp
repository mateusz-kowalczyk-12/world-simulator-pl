#include <vector>
#include <string>

#include "Stale.hpp"
#include "Zwierze.hpp"
#include "Roslina.hpp"

class Czlowiek;

class Swiat
{
	int rozmiarX, rozmiarY;
	char** plansza;

	std::vector<Zwierze*> zwierzeta;
	std::vector<Roslina*> rosliny;

	std::string komunikat;

public:
	Stale stale;


	Swiat(int rozmiarX, int rozmiarY);

	Swiat();

	void konstruujSwiat(int rozmiarX, int rozmiarY);

	void dodajOrganizmy();

	~Swiat();


	int odczytajRozmiarX() const;

	int odczytajRozmiarY() const;

	void dodajZwierze(Zwierze* noweZwierze);

	void dodajRosline(Roslina* nowaRoslina);

	void usunOrganizm(Organizm* organizm);

	Organizm* dajOrganizm(int x, int y) const;

	Czlowiek* dajCzlowieka() const;

	void ustawSymbol(int x, int y, char symbol);

	void ustawKomunikat(std::string komunikat);

	std::string odczytajKomunikat() const;


	void rysujSie() const;

	void wykonajTure();


	void wypiszNumeryKolumn() const;

	void sortujZwierzeta();


	bool istniejeWolnePoleObok(int x, int y) const;

	bool poleWolne(int x, int y) const;

	bool poleIstnieje(int x, int y) const;

	int policzCyfry(int liczba) const;

	bool zwierzeNadalIstnieje(Zwierze* poczatkoweZwierze) const;


	void czekajNaSpacje() const;

	bool kontynuowac();


	void zapiszStanSymulacji();

	void wczytajStanSymulacji();
};