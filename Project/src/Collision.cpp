#include "Collision.h"

Collision::Collision()
{
}

bool Collision::CheckIfAlienHitPlayer(std::vector<Alien*>& aliens, Player& player)
{
	for (int i = 0; i < aliens.size(); i++)
	{
		float alienXPos = aliens[i]->GetShape().getPosition().x;
		float alienYPos = aliens[i]->GetShape().getPosition().y;
		sf::FloatRect alienBounds(aliens[i]->GetShape().getGlobalBounds());
		bool isIntersecting = alienBounds.intersects(player.GetCollisionCircle().getGlobalBounds());
		float distance = std::sqrt(std::pow(player.GetCollisionCircle().getPosition().x - alienXPos, 2) + std::pow(player.GetCollisionCircle().getPosition().y - alienYPos, 2));
		isIntersecting = isIntersecting || distance < (player.GetCollisionCircle().getRadius() + std::sqrt(std::pow(aliens[i]->GetShape().getSize().x / 2, 2) + std::pow(aliens[i]->GetShape().getSize().y / 2, 2)));
		
		if (isIntersecting)
		{
			aliens[i]->SetDestroy(true);
			return isIntersecting;
		}
	}

	return false;
}

void Collision::CheckIfBulletHitAlien(std::vector<Alien*>& aliens, std::vector<Bullet>& bullet)
{
}
