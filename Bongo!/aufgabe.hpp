#ifndef AUFGABE
#define AUFGABE


#include "spiel.hpp"
#include "spielstein.hpp"
#include "position.hpp"

class Aufgabe
{
private:
	std::vector<Spielstein*> steine;
public:
	friend class Spiel;
	Spielstein* loesung_ptr;

	Spielstein* getSpielstein(size_t index);
	bool geloest(); //solved
	void zeichne();
	void loesche();

	Aufgabe();
	Aufgabe(Spielstein* stein1_ptr, Spielstein* stein2_ptr, Spielstein* stein3_ptr, Spielstein* loesung_ptr);
};

#endif