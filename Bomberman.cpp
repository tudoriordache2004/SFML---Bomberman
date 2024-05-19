#include "Bomberman.h"

void Bomberman::InitializeVariables()
{
	this->MovementSpeed = 2.f;

	this->animationState = BOMBERMAN_ANIMATION_STATES::IDLE;

	this->moving_up = false;

	this->moving_down = false;

	this->moving_left = false;

	this->moving_right = false;

}

void Bomberman::InitializeTexture()
{
	//Load a texture from a file
	if (!this->texture.loadFromFile("resources/sprite_sheet.png"))
	{
		std::cout << "Error::InitializeTexture::Could not load bomberman.gif\n";
	}
}

void Bomberman::InitializeSprite()
{
	//Set the texture to the sprite
	//nota pentru sine: sheet-ul cu un cadru pentru bomberman
	//are 30px height si 20px width
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.6f, 1.6f);
	this->currentFrame = sf::IntRect(80, 0, 20, 30);
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
		this->currentFrame.top = 0.f;
		this->currentFrame.left = 80.f;
		this->sprite.setTextureRect(this->currentFrame);
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_UP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			if (this->currentFrame.left >= 160.f)
				this->currentFrame.left = 120.f;
			else if (this->currentFrame.left != 120.f and this->currentFrame.left != 160.f)
				this->currentFrame.left = 120.f;
			else
				this->currentFrame.left += 40.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_DOWN)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			if (this->currentFrame.left >= 100.f)
				this->currentFrame.left = 60.f;
			else if (this->currentFrame.left != 100.f and this->currentFrame.left != 60.f)
				this->currentFrame.left = 60.f;
			else
				this->currentFrame.left += 40.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			if (this->currentFrame.left >= 220.f)
				this->currentFrame.left = 180.f;
			else if (this->currentFrame.left != 180.f and this->currentFrame.left != 220.f)
				this->currentFrame.left = 180.f;
			else
				this->currentFrame.left += 40.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == BOMBERMAN_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			if (this->currentFrame.left >= 40.f)
				this->currentFrame.left = 0.f;
			else
				this->currentFrame.left += 40.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
}

void Bomberman::UpdateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
	{
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_LEFT;
		this->Move(-1.f, 0.f);
		moving_left = true;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
	{
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_RIGHT;
		this->Move(1.f, 0.f);
		moving_right = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //top
	{
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_UP;
		this->Move(0.f, -1.f);
		moving_up = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //down
	{
		this->animationState = BOMBERMAN_ANIMATION_STATES::MOVING_DOWN;
		this->Move(0.f, 1.f);
		moving_down = true;
	}
	if(!moving_up && !moving_down && !moving_left &&!moving_right)
	{
		this->animationState = BOMBERMAN_ANIMATION_STATES::IDLE;
	}
	this->moving_up = false;

	this->moving_down = false;

	this->moving_left = false;

	this->moving_right = false;
}

void Bomberman::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
