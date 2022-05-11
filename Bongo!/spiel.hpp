#ifndef SPIEL
#define SPIEL

#include "spielstein.hpp"
#include "aufgabe.hpp"
#include "simpleInput.hpp"

class Spiel
{
private:
	Aufgabe aktuelleAufgabe;
public:
	friend void testSpiel();
	int selectedStein = 0;
	void init();
	void ausgabeLogo();
	void ausgabeRahmen();
	void ausgabeLegende();
	void ausgabeSteuerung();
	void spielSchleife();
	void spielzug();
	bool eingabeErlaubt(char input);
	void draw();

	Spiel(Aufgabe* aufgabe);
};

#endif