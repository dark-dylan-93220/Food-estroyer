#ifndef ENEMY_H
#define ENEMY_H

#include "game.h" // Surtout pour avoir accès aux propriétés de window

//SUGAR DROPPING FROM ENEMIES
class Sugar : public sf::Sprite {
private :
	char size = 'z';
	bool state = true;
public:
	char getSize() const { return size; }
	bool getState() const { return state; }

	void setState(bool newState) { state = newState; }
};

//CLASSE DE BASE : ENEMY
class Enemy : public sf::Sprite {
protected:
	bool alive = true;
	char size;
	float moveSpeedX = -300;
	float moveSpeedY = -300;
	float hp = 1;
	float hpSize = 3;
	bool dropedSugar = false;
	Enemy(float x, float y, char s, sf::RenderWindow &window);
public:
	bool getAlive() const { return alive; }
	char getSize() const { return size; }
	float getHp() const { return hp; }

	void setAlive(bool newState) { alive = newState; }
	void setHp(float degats) { hp -= degats; }

	void dropSugar(std::vector<Sugar*>& vectorSugar, Enemy& enemy);
};

//PROJECTILES
class Projectile : public sf::Sprite {
private:
	std::string id;
	bool state = true;
public:
	std::string getId() const { return id; }
	bool getState() const { return state; }

	void setId(std::string newId) { id = newId; }
	void setState(bool newState) { state = newState; }
};

//NORMAL ENEMIES (ONLY MOVING LEFT)
class Normal : public Enemy {
private:
	std::string id = "normal";
public:
	Normal(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed);

	std::string getId() const { return id; }
};

//SHOOTERS (FIXED POSITIONS, CAN SHOOT)
class Shooter : public Enemy {
private:
	std::string id = "shooter";
public:
	bool positionFound = false;
	bool positionReached = false;
	bool waitingForPosition = true;
	float moveDirX = 0;
	float moveDirY = 0;
	int randomPositionChoice = 0;
	float shootCooldown = 0;
	sf::Vector2f positionChoice = { 0, 0 };
	sf::Vector2f targetPosition = { getPosition().x - (getLocalBounds().width * getScale().x) / 2, getPosition().y - (getLocalBounds().height * getScale().y) / 2 };
	std::vector<sf::Vector2f> possiblePositions;

	Shooter(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed, std::vector<Shooter>& vectorShooters, std::vector<sf::Vector2f> &shooterPositions, std::vector<Projectile*> &projectiles, std::vector<bool>& positionsOccupied);

	std::string getId() const { return id; }
};

//ELITES (TRACK THE PLAYER, CAN SHOOT)
class Elite : public Enemy {
private:
	std::string id = "elite";
public:
	float shootCooldown = 0;
	float trackCooldown = 0;
	sf::Vector2f playerPosition = { 0,0 };

	Elite(float x, float y, char s, sf::RenderWindow& window);

	void behavior(float timeElapsed, sf::CircleShape player, std::vector<Projectile*> &projectiles, sf::RenderWindow &window);

	std::string getId() const { return id; }
};

#endif