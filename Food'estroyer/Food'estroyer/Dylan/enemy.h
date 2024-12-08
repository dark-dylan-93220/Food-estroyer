#ifndef ENEMY_H
#define ENEMY_H

//#include "game.h"

class Enemy : public sf::CircleShape {
protected:
	bool alive = true;
	char size;
	std::string id;
	Enemy(float x, float y, char s);
public:
	std::string getId() { //useful if every enemy is in one vector
		return id;
	}
};

class Normal : public Enemy {
public:
	std::string id = "normal";
	Normal(float x, float y, char s);

	void behavior();
};

class Shooter : public Enemy {
public:
	std::string id = "shooter";
	float moveDirX = 0;
	float moveDirY = 0;
	bool pFound = false;
	bool pWait = true;
	int index = 0;
	int shootCD = 0;
	sf::Vector2f pChoice = { 0, 0 };
	std::vector<sf::Vector2f> occupied;

	Shooter(float x, float y, char s);

	void behavior(std::vector<sf::Vector2f> &shooterPositions,
		std::vector<sf::RectangleShape> &projectiles, std::vector<Shooter> &vectorShooters);
};

class Elite : public Enemy {
public:
	std::string id = "elite";
	float moveDirX = -5;
	int shootCD = 0;
	int trackCooldown = 0;
	Elite(float x, float y, char s);

	void behavior(sf::CircleShape player, std::vector<sf::RectangleShape> &projectiles, sf::RenderWindow &window);
};
#endif