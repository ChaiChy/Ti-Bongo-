#ifndef SPIEL
#define SPIEL

#include "spielstein.hpp"
#include "aufgabe.hpp"

class Spiel
{
private:
	//Aufgabe aktuelleAufgabe;
public:
	friend void testSpiel();
	void init();
	void ausgabeLogo();
	void ausgabeRahmen();
	void ausgabeLegende();
	void ausgabeSteuerung();
	void spielSchleife();
	void spielzug();
	bool eingabeErlaubt(char input);
	void draw();

};

#endif