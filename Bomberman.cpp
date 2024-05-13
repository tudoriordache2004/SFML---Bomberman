#include "Bomberman.h"

void Bomberman::InitializeVariables()
{
	this->MovementSpeed = 0.05f;

	this->animationState = BOMBERMAN_ANIMATION_STATES::IDLE;
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
	this->currentFrame = sf::IntRect(0, 128, 24, 32);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setPosition(sf::Vector2f(53.f, 53.f));

}

void Bomberman::InitializeAnimation()
{
	this->animationTimer.restart();
}

Bomberman::Bomberman()
{

	this->InitializeVariables();
	this->InitializeTexture();
	this->InitializeSprite();
	this->InitializeAnimation();

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
	this->UpdateAnimation();
}

void Bomberman::UpdateAnimation()
{
	if (this->animationState == BOMBERMAN_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 24.f;
			if (this->currentFrame.left >= 72.f)
				this->currentFrame.left = 0.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_UP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 64.f;
			if (this->currentFrame.left >= 72.f)
				this->currentFrame.left = 24.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_DOWN)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 32.f;
			if (this->currentFrame.left >= 72.f)
				this->currentFrame.left = 24.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 0.f;
			if (this->currentFrame.left >= 72.f)
				this->currentFrame.left = 0.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_LEFT)
	{
		this->sprite.setScale(-1.6f, 1.6f);
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->sprite.setScale(-1.6f, 1.6f);
			this->currentFrame.top = 0.f;
			if (this->currentFrame.left >= 72.f)
				this->currentFrame.left = 0.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	if (this->animationState != BOMBERMAN_ANIMATION_STATES::MOVING_LEFT)
	{
		this->sprite.setScale(1.6f, 1.6f);
	}

}

void Bomberman::UpdateMovement()
{
	this->animationState = BOMBERMAN_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
	{
		this->Move(-53.f/2, 0.f);
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_LEFT;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
	{
		this->Move(53.f/2, 0.f);
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //top
	{
		this->Move(0.f, -53.f/2);
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //down
	{
		this->Move(0.f, 53.f/2);
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_DOWN;
	}
}

void Bomberman::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
