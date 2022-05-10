#include <iostream>
#include "spielstein.hpp"
#include "configuration.hpp"
#include "aufgabe.hpp"
#include "spiel.hpp"





void testSpielsteine()
{
	for (int i = 0; i <= 11; i++)
	{
		Spielstein* stein_ptr = new Spielstein(i);
		stein_ptr->position.setX(i * 6);
		stein_ptr->position.setY(15);
		stein_ptr->zeichne();
	}
}

int main()
{
	/*
	Console::init();
	Cursor::setze_Farbe(HINTERGRUND_HELL_LILA);
	for (int x = 10; x < 35; x++)
		for (int y = 5; y < 10; y++)
		{
			if (x == 10 || x == 34 || y == 5 || y == 9)
				Console::zeichne_punkt(x, y, ' ');
		}
	Cursor::bewegen(13, 7);
	Cursor::setze_Farbe(HINTERGRUND_SCHWARZ);

	std::cout << "Hochschule Augsburg";

	//testSpielsteine();
	*/
	Position position(10, 10);
	
	Spielstein test(SPIELSTEIN_Z3);
	test.setPosition(position);
	test.flip();
	test.rotation_links();
	
	test.zeichne();
	

	return 0;
}
