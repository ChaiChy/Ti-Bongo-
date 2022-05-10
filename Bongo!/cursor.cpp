#include "cursor.hpp"
#include <iostream>

//Positioniere Cursor an Position x,y
void Cursor::bewegen(int x, int y)
{
	//printf("\33[%d;%dH", y, x);	
	std::cout << "\33[" << y << ";" << x << "H";	//Kommandos	\033[<L>; <C>H oder \033[<L>; <C>f
}

//Move the cursor up N lines
void Cursor::hoch(int n)
{
	//printf("\033[%dA", n);
	std::cout << "\033[" << n << "A";
}
//Move the cursor down N lines:  \033[<N>B
void Cursor::runter(int n)
{
	//printf("\033[%dB", n);
	std::cout << "\033[" << n << "B";
}
//Bewege Cursor um n Stellen/Spalten nach rechts:  \033[<N>C
void Cursor::rechts(int n)
{
	//printf("\033[%dC", n);
	std::cout << "\033[" << n << "C";
}
//Bewege Cursor um n Stellen/Spalten nach links:  \033[<N>D
void Cursor::links(int n)
{
	//printf("\033[%dD", n);
	std::cout << "\033[" << n << "D";
}
//Setze Schriftfarbe oder Hintergrundfarbe
void Cursor::setze_Farbe(std::string farbe)
{
	std::cout << farbe;
}

//Speichert die aktuelle Cursor Position
void Cursor::speicherePosition()
{
	std::cout << "\033[s";
}
//Stellt die gespeicherte Cursor Position wieder her
void Cursor::gehezu_letzteGespeichertePosition()
{
	std::cout << "\033[u";
};