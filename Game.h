#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Bomberman.h"
class Game
{
private:
	sf::RenderWindow* window;

	//world
	std::vector<std::pair<float, float> > walltextures;
	//music
	sf::Music music;

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
	void UpdateCollision();

	void RenderWorld(); //render the world
	void Render(); //rendering

};
#endif