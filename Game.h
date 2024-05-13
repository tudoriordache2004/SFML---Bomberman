#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
class Game
{
private:
	sf::RenderWindow* window;
	//private functions
	void InitializeWindow(); //initializing the window

	//world
	sf::Texture backgroundtexture;
	sf::Sprite background;

public:
	Game(); //constructor
	virtual ~Game(); //destructor

	//public functions
	void Run(); //for running the game

	void UpdatePollEvents();

	void RenderWorld(); //render the world
	void Render(); //rendering
	
};
#endif