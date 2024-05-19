#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <ctime>
#include <iostream>
class Enemy
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	float MovementSpeed;
	bool moving_up;
	bool moving_down;
	bool moving_left;
	bool moving_right;

	//Animation
	sf::Clock animationTimer;
	int animationState;
	sf::IntRect currentFrame;

	void InitializeVariables();
	void InitializeTexture();
	void InitializeSprite();
	void InitializeAnimation();


public:
	//Constructor
	Enemy();

	//Getter
	const sf::Vector2f& GetEnemyPosition() const;
	sf::FloatRect GetEnemyBounds() const;

	//Setter
	void SetEnemyPosition(const float x, const float y);

	//Move the player
	void MoveEnemy(const float dir_x, const float dir_y);

	void UpdateEnemyAnimation();
	void UpdateEnemyMovement();
	void Update();
	void Render(sf::RenderTarget* target);
};

