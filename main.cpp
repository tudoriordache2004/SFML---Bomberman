#include <iostream>
#include <ctime>
#include "Game.h"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

 
int main()
{
    //Initializie a random seed
    srand(time(NULL));

    Game game;
    game.Run();
    

    //End of application
    return 0;
}
