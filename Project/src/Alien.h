#pragma once
#include <SFML/Graphics.hpp>
#include "Spaceship.h"

class Alien : public Spaceship
{
private:
	bool diagonalMovement = false;
	bool destroy = false;
	sf::Vector2f endPosition;

public:
	Alien(sf::Texture* texture, sf::Vector2f size = { 64, 64 });

	sf::Vector2f InitPosition();
	void TurnToMove(int rotation);

	void Move(sf::Vector2f move);
	void Update();

	void CheckIfDestroy();
	void SetDestroy(bool destroy);

	const bool& GetDestroy();
};