#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Alien.h"
#include "Player.h"

class Collision
{
private:

public:
	Collision();

	bool CheckIfAlienHitPlayer(std::vector<Alien*>& aliens, Player& player);
	int CheckIfBulletHitAlien(std::vector<Alien*>& aliens, std::vector<Bullet>& bullet);
};