 #ifdef _DEBUG
 #include <Windows.h>
 #include <vld.h>
 #endif

#include <sfml/Graphics.hpp>
#include <iostream>
#include "Game.h"


 
 int main()
 {
 	try
	{
 	// Instanz des Spiels erzeugen
 	CGame Game;
 	// Spiel laufen lassen
 	//
 	Game.Run ();
	}
	catch(std::exception& e)
	{
		std::cout << "Ein Fehler ist aufgetreten! Beschreibung :\n" << e.what() << std::endl << "Beliebige Taste druecken um das Programm zu beenden...\n";
		std::cin.get();
	}

 	return (0);
 }// main
