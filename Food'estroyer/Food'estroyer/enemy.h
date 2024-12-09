#ifndef ENEMY_H
#define ENEMY_H

#include "game.h" // Surtout pour avoir accès aux propriétés de window

class Enemy : public sf::Sprite {
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

	void behavior(float timeElapsed);
};

class Shooter : public Enemy {
public:
	std::string id = "shooter";

	bool positionFound = false;
	bool waitingForPosition = true;
	float moveDirX = 0;
	float moveDirY = 0;
	int randomPositionChoice = 0;
	float shootCooldown = 0;
	sf::Vector2f positionChoice = { 0, 0 };
	std::vector<sf::Vector2f> possiblePositions;

	Shooter(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed, std::vector<Shooter>& vectorShooters, std::vector<sf::Vector2f> &shooterPositions, std::vector<sf::RectangleShape*> &projectiles, std::vector<bool>& positionsOccupied);
};

class Elite : public Enemy {
public:
	std::string id = "elite";

	float moveDirX = -400;
	float shootCooldown = 0;
	float trackCooldown = 0;

	Elite(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed, sf::CircleShape player, std::vector<sf::RectangleShape*> &projectiles, sf::RenderWindow &window);
};

#endif