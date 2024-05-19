#include "Enemy.h"

void Enemy::InitializeVariables()
{
	this -> MovementSpeed = 2.f;
	this -> moving_up = false;
	this -> moving_down = false;
	this -> moving_left = false;
	this -> moving_right = false;
}

void Enemy::InitializeTexture()
{
	//Load a texture from a file
	if (!this->texture.loadFromFile("resources/sprite_sheet.png"))
	{
		std::cout << "Error::InitializeTexture::Could not load bomberman.gif\n";
	}
}

void Enemy::InitializeSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.6f, 1.6f);
	this->currentFrame = sf::IntRect(100, 120, 20, 30);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setPosition(sf::Vector2f(583.f, 689.f));
}

void Enemy::InitializeAnimation()
{
}

Enemy::Enemy()
{
	this->InitializeVariables();
	this->InitializeTexture();
	this->InitializeSprite();
	this->InitializeAnimation();
}

const sf::Vector2f& Enemy::GetEnemyPosition() const
{
	return this->sprite.getPosition();
}

sf::FloatRect Enemy::GetEnemyBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Enemy::SetEnemyPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Enemy::MoveEnemy(const float dir_x, const float dir_y)
{
	this->sprite.move(this->MovementSpeed * dir_x, this->MovementSpeed * dir_y);
}

void Enemy::Update()
{
	this->UpdateEnemyMovement();
	this->UpdateEnemyAnimation();
}

void Enemy::UpdateEnemyAnimation()
{
}

void Enemy::UpdateEnemyMovement()
{
}


void Enemy::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
