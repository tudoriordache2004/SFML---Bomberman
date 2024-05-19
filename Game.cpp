#include "Game.h"

//private functions
void Game::InitializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(689, 795), "Bomberman", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setKeyRepeatEnabled(false);
}

void Game::InitializeMusic()
{
	if (!this->music.openFromFile("music_sounds/riot.wav"))
	{
		std::cout << "Game::InitializeMusic::Can't play riot.wav";
	}
	else
		this->music.play();
	this->music.setLoop(true);
}

void Game::InitializePlayer()
{
	this->bomberman = new Bomberman();
}

void Game::InitializeEnemy()
{
	this->enemy = new Enemy();
}

//game constructor
Game::Game()
{
	this->InitializeWindow();

	this->InitializeMusic();

	this->InitializePlayer();
	
	this->InitializeEnemy();
}

//game destructor
Game::~Game()
{
	delete this->bomberman;

	delete this->enemy;

	delete this->window;
}

void Game::Render()
{
	this->window->clear();

	this->RenderWorld();

	this->bomberman->Render(this->window);

	this->enemy->Render(this->window);

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
				this->WallSprites.push_back(std::make_pair(x, y));
				break;
			}
		}
	//for (auto& wallsprite : WallSprites)
	//	std::cout << wallsprite.first << " " << wallsprite.second << "\n";

}

void Game::UpdatePlayer()
{
	this->bomberman->Update();
	this->UpdateCollision();
}

//public functions

void Game::Update()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.Event::type == sf::Event::Closed)
			this->window->close();
		if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}

	this->UpdatePlayer();
}

void Game::UpdateCollision()
{
	//left collision
	if (this->bomberman->GetPosition().x < 53.f)
			this->bomberman->SetPosition(53.f, this->bomberman->GetPosition().y);
	//right collision
	else if (this->bomberman->GetPosition().x+this->bomberman->GetBounds().width > this->window->getSize().x - 53.f)
		this->bomberman->SetPosition(this->window->getSize().x - 53.f - this->bomberman->GetBounds().width, this->bomberman->GetPosition().y);
	//bottom collision
	if (this->bomberman->GetPosition().y+ this->bomberman->GetBounds().height > this->window->getSize().y - 53.f)
		this->bomberman->SetPosition(this->bomberman->GetPosition().x, this->window->getSize().y - 53.f - this->bomberman->GetBounds().height);
	//top collision
	else if (this->bomberman->GetPosition().y < 53.f)
		this->bomberman->SetPosition(this->bomberman->GetPosition().x, 53.f);
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		this->Update();

		this->Render();
	}

}