#ifndef ENEMY_H
#define ENEMY_H

#include "game.h" // Surtout pour avoir accès aux propriétés de window

class Enemy : public sf::Sprite {
protected:
	bool alive = true;
	char size;
	float moveSpeed = -300;
	Enemy(float x, float y, char s, sf::RenderWindow &window);
public:
	bool getAlive() { return alive; }
	char getSize(){ return size; }

	void setAlive(bool newState) { alive = newState; }
};

class Projectile : public sf::RectangleShape {
private:
	std::string id;
public:
	std::string getId() {
		return id;
	}
	void setId(std::string newId) {
		id = newId;
	}
};

class Normal : public Enemy {
private:
	std::string id = "normal";
public:
	Normal(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed);

	std::string getId() {
		return id;
	}
};

class Shooter : public Enemy {
private:
	std::string id = "shooter";
public:
	bool positionFound = false;
	bool waitingForPosition = true;
	float moveDirX = 0;
	float moveDirY = 0;
	int randomPositionChoice = 0;
	float shootCooldown = 0;
	sf::Vector2f positionChoice = { 0, 0 };
	std::vector<sf::Vector2f> possiblePositions;

	Shooter(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed, std::vector<Shooter>& vectorShooters, std::vector<sf::Vector2f> &shooterPositions, std::vector<Projectile*> &projectiles, std::vector<bool>& positionsOccupied);

	std::string getId() {
		return id;
	}
};

class Elite : public Enemy {
private:
	std::string id = "elite";
public:
	float shootCooldown = 0;
	float trackCooldown = 0;

	Elite(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed, sf::CircleShape player, std::vector<Projectile*> &projectiles, sf::RenderWindow &window);

	std::string getId() {
		return id;
	}
};

#endif