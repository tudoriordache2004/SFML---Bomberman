#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bomberman.h"
class Game
{
private:
	sf::RenderWindow* window;
	
	//world
	sf::Texture backgroundtexture;
	sf::Sprite background;

	//music
	//sf::Music music;

	//bomberman
	Bomberman* bomberman;

	//private functions
	void InitializeWindow(); //initializing the window
	void InitializePlayer(); //initializing the player
	void InitializeMusic(); //initializing the music

public:
	Game(); //constructor
	virtual ~Game(); //destructor

	//public functions
	void Run(); //for running the game

	void Update();
	void UpdatePlayer();

	void RenderWorld(); //render the world
	void Render(); //rendering
	
};
#endif