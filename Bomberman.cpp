#include "Bomberman.h"

void Bomberman::InitializeVariables()
{
	this->MovementSpeed = 0.5f;
}

void Bomberman::InitializeTexture()
{
	//Load a texture from a file
	if (!this->texture.loadFromFile("resources/bomberman.gif"))
	{
		std::cout << "Error::InitializeTexture::Could not load bomberman.gif\n";
	}
}

void Bomberman::InitializeSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.6f, 1.6f);
	this->sprite.setTextureRect(sf::IntRect(0, 34, 25, 35));
}

Bomberman::Bomberman()
{
	this->InitializeTexture();
	this->InitializeSprite();

	this->InitializeVariables();

}

const sf::Vector2f& Bomberman::GetPosition() const
{
	return this->sprite.getPosition();
}

sf::FloatRect Bomberman::GetBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Bomberman::SetPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Bomberman::Move(const float dir_x, const float dir_y)
{
	this->sprite.move(this->MovementSpeed * dir_x, this->MovementSpeed * dir_y);
}

void Bomberman::Update()
{
	this->UpdateMovement();
}

void Bomberman::UpdateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
	{
		this->Move(-53.f, 0.f);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
	{
		this->Move(53.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //top
	{
		this->Move(0.f, -53.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //down
	{
		this->Move(0.f, 53.f);
	}
}

void Bomberman::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
