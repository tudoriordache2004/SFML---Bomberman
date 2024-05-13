#include "Game.h"

//private functions
void Game::InitializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(689, 795), "Bomberman", sf::Style::Default);
	this->window->setFramerateLimit(144);
}

//game constructor
Game::Game()
{
	this->InitializeWindow();

}


//game destructor
Game::~Game()
{
	delete this->window;
}

void Game::Render()
{
	this->window->clear();

	this->RenderWorld();

	this->window->display();

}

void Game::RenderWorld()
{
	unsigned int Map[13][15] =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	sf::Texture WallTexture;
	WallTexture.loadFromFile("resources/wall.png");
	sf::Texture GrassTexture;
	GrassTexture.loadFromFile("resources/grass.png");
	sf::Texture BorderTexture;
	BorderTexture.loadFromFile("resources/border.png");

	sf::Sprite WallSprite(WallTexture);
	sf::Sprite GrassSprite(GrassTexture);
	sf::Sprite BorderSprite(BorderTexture);

	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 15; j++)
		{
			float x = static_cast<float>(i * 53);
			float y = static_cast<float>(j * 53);
			switch (Map[i][j])
			{
			case 0:
				BorderSprite.setPosition(x, y);
				this->window->draw(BorderSprite);
				break;
			case 1:
				GrassSprite.setPosition(x, y);
				this->window->draw(GrassSprite);
				break;
			case 2:
				WallSprite.setPosition(x, y);
				this->window->draw(WallSprite);
				break;
			}
		}
}

//public functions

void Game::UpdatePollEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.Event::type == sf::Event::Closed)
			this->window->close();
		if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		this->UpdatePollEvents();

		this->Render();
	}

}