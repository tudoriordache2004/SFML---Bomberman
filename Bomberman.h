#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
class Bomberman
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float MovementSpeed;

	//private functions
	void InitializeVariables();
	void InitializeTexture();
	void InitializeSprite();
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

	void update();
	void render(sf::RenderTarget* target);

};

