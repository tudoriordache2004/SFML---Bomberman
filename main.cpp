#include "Game.h"
#include <ctime>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
	//Initializie a random seed
	srand(time(NULL));

	Game game;
	game.Run();


	//End of application
	return 0;
}
