#include "spiel.hpp"

void testSpiel()
{

}

void Spiel::init()
{
	Console::verstecken();

}

void Spiel::ausgabeLogo()
{

	std::cout << " _______  _______  ___   _  _______        _______  _______  _______  ______    ___   _______" << std::endl;
	std::cout << "|       ||   _   ||   | | ||       |      |       ||       ||       ||    _ |  |   | |       | " << std::endl;
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
	int lengthY = offsetY + CONFIGURATION::SPIELFELD_DIMENSION_Y;
	
	Cursor::setze_Farbe(HINTERGRUND_WEISS);
	for (int x = offsetX; x < lengthX; x++)
	{
		for (int y = offsetY; y < lengthY; y++)
		{
			if (x == 10 || x == 34 || y == 5 || y == 9)
			{
				Console::zeichne_punkt(x, y, CONFIGURATION::SPIELFELD_BEGRENZUNG);
			}
		}
	}
		
	Cursor::bewegen(13, 7);
	Cursor::setze_Farbe(HINTERGRUND_SCHWARZ);
}

void Spiel::ausgabeLegende()
{

}

void Spiel::ausgabeSteuerung()
{

}

void Spiel::spielSchleife()
{

}

void Spiel::spielzug()
{

}

bool Spiel::eingabeErlaubt(char input) //optional
{
	return false;
}

void Spiel::draw()
{

}



