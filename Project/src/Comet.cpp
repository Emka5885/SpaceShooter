#include "Comet.h"
#include "Definitions.h"

Comet::Comet(sf::Texture* texture)
{
	Init(texture);
}

void Comet::Init(sf::Texture* texture)
{
	shape.setSize({ 70,50 });
	shape.setTexture(texture);
	if (rand() % 2)
	{
		x = rand() % WIDTH + 100;
		y = -100;
	}
	else
	{
		x = WIDTH + 100;
		y = rand() % HEIGHT - 100;
	}
	
	shape.setPosition(x,y);
	shape.setRotation(-4);
}

void Comet::Update()
{
	shape.move(-5, 3 );
	CheckIfDestroy();
}

void Comet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Comet::CheckIfDestroy()
{
	if (shape.getPosition().x < WIDTH - 100 && shape.getPosition().y > HEIGHT + 100)
	{
		destroy = true;
	}
}

bool& Comet::GetDestroy()
{
	return destroy;
}
