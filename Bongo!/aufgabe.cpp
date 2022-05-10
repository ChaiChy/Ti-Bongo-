#include "aufgabe.hpp"

Spielstein* Aufgabe::getSpielstein(size_t index)
{
	return steine[index];
}

bool Aufgabe::geloest()
{
	for (int i = 0; i < steine.size(); i++)
	{
		
	}
	if (steine[i]->getPositionen()->at(i) == loesung_ptr->getPositionen()->at(i))
	{
		return
	}
}