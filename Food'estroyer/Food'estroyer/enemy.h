#ifndef ENEMY_H
#define ENEMY_H

#include "game.h" // Surtout pour avoir accès aux propriétés de window

class Enemy : public sf::CircleShape {
protected:
	bool alive = true;
	char size;
	std::string id;
	Enemy(float x, float y, char s, sf::RenderWindow &window);
public:
	std::string getId() {
		return id;
	}
};

class Normal : public Enemy {
public:
	std::string id = "normal";

	Normal(float x, float y, char s, sf::RenderWindow& window);

	void behavior();
};

class Shooter : public Enemy {
public:
	std::string id = "shooter";

	bool positionFound = false;
	bool waitingForPosition = true;
	float moveDirX = 0;
	float moveDirY = 0;
	int index = 0;
	int shootCooldown = 0;
	sf::Vector2f positionChoice = { 0, 0 };
	std::vector<sf::Vector2f> possiblePositions;

	Shooter(float x, float y, char s, sf::RenderWindow& window);

	void behavior(std::vector<Shooter>& vectorShooters, std::vector<sf::Vector2f> &shooterPositions, std::vector<sf::RectangleShape> &projectiles);
};

class Elite : public Enemy {
public:
	std::string id = "elite";

	float moveDirX = -5;
	int shootCooldown = 0;
	int trackCooldown = 0;

	Elite(float x, float y, char s, sf::RenderWindow& window);

	void behavior(sf::CircleShape player, std::vector<sf::RectangleShape> &projectiles, sf::RenderWindow &window);
};

#endif