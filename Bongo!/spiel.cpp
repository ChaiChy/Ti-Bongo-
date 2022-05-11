#include "spiel.hpp"

void testSpiel()
{

}

void Spiel::init()
{
	Console::verstecken();
	ausgabeRahmen();
	ausgabeLogo();
	ausgabeSteuerung();
	ausgabeLegende();
}

void Spiel::ausgabeLogo()
{
	Cursor::bewegen(0, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 2);
	std::cout << " _______  _______  ___   _  _______        _______  _______  _______  ______    ___   _______ " << std::endl;
	std::cout << "|       ||   _   ||   | | ||       |      |       ||       ||       ||    _ |  |   | |       |" << std::endl;
	std::cout << "|    ___||  |_|  ||   |_| ||    ___|      |_     _||    ___||_     _||   | ||  |   | |  _____|" << std::endl;
	std::cout << "|   |___ |       ||      _||   |___         |   |  |   |___   |   |  |   |_||_ |   | | |_____ " << std::endl;
	std::cout << "|    ___||       ||     |_ |    ___|        |   |  |    ___|  |   |  |    __  ||   | |_____  |" << std::endl;
	std::cout << "|   |    |   _   ||    _  ||   |___         |   |  |   |___   |   |  |   |  | ||   |  _____| |" << std::endl;
	std::cout << "|___|    |__| |__||___| |_||_______|        |___|  |_______|  |___|  |___|  |_||___| |_______|" << std::endl;
}

void Spiel::ausgabeRahmen() //framework
{
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
		
	Cursor::bewegen(13, 7);
	Cursor::setze_Farbe(HINTERGRUND_SCHWARZ);
}

void Spiel::ausgabeLegende() //incomplete
{
	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 2);
	aktuelleAufgabe.steine[0]->zeichne();
	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 6);
	std::cout << "1";

	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X + 5, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 2);
	aktuelleAufgabe.steine[1]->zeichne();
	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X + 5, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 6);
	std::cout << "2";

	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X + 10, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 2);
	aktuelleAufgabe.steine[1]->zeichne();
	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X + 10, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 6);
	std::cout << "2";

	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X + 15, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 2);
	aktuelleAufgabe.steine[2]->zeichne();
	Cursor::bewegen(CONFIGURATION::SPIELFELD_OFFSET_X + 15, CONFIGURATION::SPIELFELD_OFFSET_Y + CONFIGURATION::SPIELFELD_DIMENSION_Y + 6);
	std::cout << "3";
}

void Spiel::ausgabeSteuerung()
{
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
}

void Spiel::spielSchleife() //loop
{
	while (true)
	{
		spielzug();
		if (aktuelleAufgabe.geloest())
		{
			return;
		}
	}
}

void Spiel::spielzug() //input
{
	char input = SimpleInput::getSteuerung(CONFIGURATION::INTERVALL);
	if (input == CONFIGURATION::EINGABE_UNGUELTIG) //terminates function if input is invalid.
	{
		return;
	}
	aktuelleAufgabe.loesche();
	//W,A,S,D
	if (input == CONFIGURATION::SPIELSTEIN_BEWEGEN_HOCH)
	{
		aktuelleAufgabe.steine[selectedStein]->bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_HOCH);
	}
	else if (input == CONFIGURATION::SPIELSTEIN_BEWEGEN_RUNTER)
	{
		aktuelleAufgabe.steine[selectedStein]->bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_RUNTER);
	}
	else if (input == CONFIGURATION::SPIELSTEIN_BEWEGEN_LINKS)
	{
		aktuelleAufgabe.steine[selectedStein]->bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_LINKS);
	}
	else if (input == CONFIGURATION::SPIELSTEIN_BEWEGEN_RECHTS)
	{
		aktuelleAufgabe.steine[selectedStein]->bewegen(CONFIGURATION::SPIELSTEIN_BEWEGEN_RECHTS);
	}
	//flip
	else if (input == CONFIGURATION::SPIELSTEIN_FLIP)
	{
		aktuelleAufgabe.steine[selectedStein]->flip();
	}
	//rotation
	else if (input == CONFIGURATION::SPIELSTEIN_ROTIEREN_LINKS)
	{
		aktuelleAufgabe.steine[selectedStein]->rotation_links();
	}
	else if (input == CONFIGURATION::SPIELSTEIN_ROTIEREN_RECHTS)
	{
		aktuelleAufgabe.steine[selectedStein]->rotation_rechts();
	}
	//stein selection
	else if (input == CONFIGURATION::SPIELSTEIN_1_INDEX)
	{
		selectedStein = 0;
	}
	else if (input == CONFIGURATION::SPIELSTEIN_2_INDEX)
	{
		selectedStein = 1;
	}
	else if (input == CONFIGURATION::SPIELSTEIN_3_INDEX)
	{
		selectedStein = 2;
	}
	else if (input == CONFIGURATION::SPIELSTEIN_4_INDEX)
	{
		selectedStein = 3;
	}

	aktuelleAufgabe.zeichne();
}

bool Spiel::eingabeErlaubt(char input) //optional
{
	return false;
}

void Spiel::draw() //?
{

}

Spiel::Spiel(Aufgabe* aufgabe)
{
	aktuelleAufgabe = *aufgabe;
	init();
	spielSchleife();
}



