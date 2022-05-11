#include "aufgabe.hpp"

Spielstein* Aufgabe::getSpielstein(size_t index)
{
	return steine[index];
}

bool Aufgabe::geloest() 
{
	
	for (int i = 0; i < loesung_ptr->felder[0][0].size(); i++)
	{
		for (int j = 0; j < steine.size(); j++)
		{
			if (!steine[j]->innerhalb(loesung_ptr->getPosition() + loesung_ptr->felder[0][0].at(i)))
			{
				return false;
			}
		}
	}
	return true;
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

Aufgabe::Aufgabe() {}; //default empty constructor

Aufgabe::Aufgabe(Spielstein* stein1_ptr, Spielstein* stein2_ptr, Spielstein* stein3_ptr, Spielstein* loesung_ptr)
{
	steine.push_back(stein1_ptr);
	steine.push_back(stein2_ptr);
	steine.push_back(stein3_ptr);
	this->loesung_ptr = loesung_ptr;	
}


