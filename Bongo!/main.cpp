#include <iostream>
#include "spielstein.hpp"
#include "configuration.hpp"
#include "aufgabe.hpp"
#include "spiel.hpp"
#include "simpleInput.hpp"
#include "position.hpp"
#include "cursor.hpp"
#include "console.hpp"




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
	*/

	//testSpielsteine();
	/*
	Console::init();
	Position position(10, 10);
	
	Spielstein test(SPIELSTEIN_Z3);
	test.setPosition(position);
	test.flip();
	test.rotation_links();
	
	test.zeichne();
	Cursor::bewegen(0, 0);
	*/

	/*
	int offsetX = CONFIGURATION::SPIELFELD_OFFSET_X;
	int offsetY = CONFIGURATION::SPIELFELD_OFFSET_Y;
	int lengthX = offsetX + (CONFIGURATION::SPIELFELD_DIMENSION_X * 2);
	int lengthY = offsetY + CONFIGURATION::SPIELFELD_DIMENSION_Y - 3;

	//Cursor::setze_Farbe(HINTERGRUND_WEISS);
	for (int x = offsetX; x < lengthX; x++)
	{
		for (int y = offsetY; y < lengthY; y++)
		{
			if (x == offsetX || x == lengthX - 1 || y == offsetY || y == lengthY - 1)
			{
				Console::zeichne_punkt(x, y, CONFIGURATION::SPIELFELD_BEGRENZUNG);
			}
		}
	}
	
	int x_start = CONFIGURATION::SPIELFELD_DIMENSION_X * 4;
	int x_length = x_start + 30;
	int y_start = CONFIGURATION::SPIELFELD_OFFSET_Y;
	int y_length = (y_start + CONFIGURATION::SPIELFELD_DIMENSION_Y - 3);
	//Cursor::setze_Farbe(HINTERGRUND_WEISS);

	for (int x = x_start; x < x_length; x++)
	{
		for (int y = y_start; y < y_length; y++)
		{
			if (x == x_start || x == x_length - 1 || y == y_start || y == y_length - 1)
			{
				Console::zeichne_punkt(x, y, CONFIGURATION::SPIELFELD_BEGRENZUNG);
			}
		}
	}

	Cursor::bewegen(61, 3);
	std::cout << " SPIELSTEIN - BEWEGUNG";
	Cursor::bewegen(61, 4);
	std::cout << " ---------------------" << std::endl;
	Cursor::bewegen(61, 5);
	std::cout << " W - HOCH";
	Cursor::bewegen(61, 6);
	std::cout << " A - LINKS";
	Cursor::bewegen(61, 7);
	std::cout << " S - RUNTER";
	Cursor::bewegen(61, 8);
	std::cout << " D - RECHTS";
	Cursor::bewegen(61, 9);
	std::cout << " Q - LINKSROTATION";
	Cursor::bewegen(61, 10);
	std::cout << " E - RECHTSROTATION";
	Cursor::bewegen(61, 11);
	std::cout << " F - FLIP";
	Cursor::bewegen(61, 12);
	std::cout << " 1, 2, 3, 4 - STEINAUSWAHL";

	Cursor::bewegen(0, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 2);
	std::cout << " _______  _______  ___   _  _______        _______  _______  _______  ______    ___   _______ " << std::endl;
	std::cout << "|       ||   _   ||   | | ||       |      |       ||       ||       ||    _ |  |   | |       |" << std::endl;
	std::cout << "|    ___||  |_|  ||   |_| ||    ___|      |_     _||    ___||_     _||   | ||  |   | |  _____|" << std::endl;
	std::cout << "|   |___ |       ||      _||   |___         |   |  |   |___   |   |  |   |_||_ |   | | |_____ " << std::endl;
	std::cout << "|    ___||       ||     |_ |    ___|        |   |  |    ___|  |   |  |    __  ||   | |_____  |" << std::endl;
	std::cout << "|   |    |   _   ||    _  ||   |___         |   |  |   |___   |   |  |   |  | ||   |  _____| |" << std::endl;
	std::cout << "|___|    |__| |__||___| |_||_______|        |___|  |_______|  |___|  |___|  |_||___| |_______|" << std::endl;
	*/

	Spielstein* s1 = new Spielstein(SPIELSTEIN_I3);
	Spielstein* s2 = new Spielstein(SPIELSTEIN_I4);
	Spielstein* s3 = new Spielstein(SPIELSTEIN_L4);

	Spielstein* ls = new Spielstein(SPIELSTEIN_LOESUNG);

	Aufgabe* test = new Aufgabe(s1, s2, s3, ls);
	
	Spiel TestSpiel(test);

	test->zeichne();


	return 0;

}
