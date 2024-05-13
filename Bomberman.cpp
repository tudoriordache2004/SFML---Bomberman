#include "Bomberman.h"

void Bomberman::InitializeVariables()
{
	this->MovementSpeed = 10.f;
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
	this->sprite.setScale(1.75f, 1.75f);
}

Bomberman::Bomberman()
{
	this->InitializeVariables();
	this->InitializeTexture();
	this->InitializeSprite();
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

void Bomberman::update()
{
}

void Bomberman::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
