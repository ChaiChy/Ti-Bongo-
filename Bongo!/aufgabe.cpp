#include "aufgabe.hpp"

Spielstein* Aufgabe::getSpielstein(size_t index)
{
	return steine[index];
}

bool Aufgabe::geloest() //?
{
	for (int i = 0; i < steine.size(); i++)
	{
		return false;
	}
	/*
	if (steine[i]->getPositionen()->at(i) == loesung_ptr->getPositionen()->at(i))
	{
		return true;
	}
	*/
}

void Aufgabe::zeichne() //first draw the "Lösungstein", then the rest of the Spielsteine.
{
	loesung_ptr->zeichne();
	for (int i = 0; i < steine.size(); i++)
	{
		getSpielstein(i)->zeichne();
	}
}

void Aufgabe::loesche()
{
	loesung_ptr->loesche();
	for (int i = 0; i < steine.size(); i++)
	{
		getSpielstein(i)->loesche();
	}
}


