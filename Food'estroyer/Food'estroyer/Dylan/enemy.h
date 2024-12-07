#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"

class Enemy : public sf::CircleShape {
protected:
	bool alive = true;
	char size;
	Enemy(float x, float y, char s);
};

class Normals : public Enemy {
public:
	Normals(float x, float y, float s);

	void behavior();
};

class Shooter : public Enemy {
public:
	float moveDirX = 0;
	float moveDirY = 0;
	bool pFound = false;
	sf::Vector2f pChoice = { 0, 0 };
	std::vector<sf::Vector2f> occupied;
	int shootCD = 0;

	Shooter(float x, float y, float s);

	void behavior(std::vector<sf::Vector2f> shooterPositions);
};

class Elite : public Enemy {
public:
	int trackCooldown = 0;
	Elite(float x, float y, float s);

	void behavior(sf::CircleShape player);
};
#endif