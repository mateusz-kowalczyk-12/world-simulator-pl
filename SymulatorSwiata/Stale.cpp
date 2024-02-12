#include "Stale.hpp"

Stale::Stale() :
	testowaWartoscPoczatkowa(-1),

	autor("Autor: Mateusz Kowalczyk, s188717"),

	wolne(' '),

	wilk('W'),
	owca('O'),
	lis('L'),
	zolw('Z'),
	antylopa('A'),
	trawa('t'),
	mlecz('m'),
	guarana('g'),
	wilczeJagody('j'),
	barszczSosnowskiego('b'),
	czlowiek('C'),

	liczbaRodzajowOrganizmow(10),
	wilkID(0),
	owcaID(1),
	lisID(2),
	zolwID(3),
	antylopaID(4),
	trawaID(5),
	mleczID(6),
	guaranaID(7),
	wilczeJagodyID(8),
	barszczSosnowskiegoID(9),

	krokInicjalizowaniaOrganizmow(3),
	odstepMiedzyRuchami(1500), //ms

	wygralNapastnik(0),
	wygralZaatakowany(1),
	odbicieAtaku(2),
	ucieczkaPrzedWalka(3),
	rozmnozenie(4),
	probaRozmnozenia(5),
	zatrucie(6),
	zjedzenie(7),

	prawdopodobienstwoRozprzestrzenienia(60) //%
{}
