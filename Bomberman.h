#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

enum BOMBERMAN_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };
class Bomberman
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float MovementSpeed;
	sf::Clock animationTimer;
	bool moving;

	//Animation
	int animationState;
	sf::IntRect currentFrame;

	//private functions
	void InitializeVariables();
	void InitializeTexture();
	void InitializeSprite();
	void InitializeAnimation();
public:
	//Constructor
	Bomberman();

	//Getter
	const sf::Vector2f& GetPosition() const;
	sf::FloatRect GetBounds() const;

	//Setter
	void SetPosition(const float x, const float y);

	//Move the player
	void Move(const float dir_x, const float dir_y);

	void UpdateAnimation();
	void UpdateMovement();
	void Update();
	void Render(sf::RenderTarget* target);

};

