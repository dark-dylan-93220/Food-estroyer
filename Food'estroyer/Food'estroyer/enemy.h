#ifndef ENEMY_H
#define ENEMY_H

//#include "game.h" // Surtout pour avoir accès aux propriétés de window
#include "player.h"

// SUGAR DROPPING FROM ENEMIES
class Sugar : public sf::Sprite {
private:
	char size = 'z';
	bool state = true;
	int quantity = 0;
public:
	float healValue = 0;
	float healValuePerSize = 0;
	float healValuePerType = 0;
	std::string id = "nothing";
	
	char getSize() const { return size; }
	bool getState() const { return state; }
	int getValue() const { return quantity; }

	void setState(bool newState) { state = newState; }
	void setValue(int newValue) { quantity = newValue; }

	bool behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Sugar*>& vectorSugar);
};

// CLASSE DE BASE : ENEMY
class Enemy : public sf::Sprite {
protected:
	bool hasBeenWaiting = false;
	bool alive = true;
	bool deadID = false;
	bool dropedSugar = false;
	char size = 'z';
	float moveSpeedX = -300;
	float moveSpeedY = -300;
	float hp = 1;
	float hpPerSize = 0;
	float atkPower = 1;
	float atkPowerPerSize = 1;
	int sugarValue = 0;
	float sugarValuePerSize = 0;
	std::string idForSugar = "nothing";

	Enemy(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture); // Constrcuteur pour les normaux, shooters et élites
	Enemy(); // Constructeur pour le boss
public:
	float deathAnimationTimer = 0;

	bool getAlive() const { return alive; }
	char getSize() const { return size; }
	float getHp() const { return hp; }
	float getAtkPower() const { return atkPower; }
	int getSugarValue() const { return sugarValue; }

	void setAlive(bool newState) { alive = newState; }
	void setHp(float degats) { hp += degats; }
	void setAtkPower(float newAtkPower) { atkPower = newAtkPower; }
	void setSugarValue(int newValue) { sugarValue = newValue; }

	void dropSugar(std::vector<Sugar*>& vectorSugar, Enemy& enemy);
};

// PROJECTILES
class Projectile : public sf::Sprite {
private:
	std::string id;
	float atkPower = 1;
	bool state = true;
	float speedX = -350;
	float speedY = 0;
public:
	sf::Vector2f startPosition = { 0, 0 };

	Projectile();

	std::string getId() const { return id; }
	float getAtkPower() const { return atkPower; }
	bool getState() const { return state; }
	float getSpeedX() const { return speedX; }
	float getSpeedY() const { return speedY; }

	void setId(std::string newId) { id = newId; }
	void setAtkPower(float newPower) { atkPower = newPower; }
	void setState(bool newState) { state = newState; }
	void setSpeedX(float newSpeed) { speedX = newSpeed; }
	void setSpeedY(float newSpeed) { speedY = newSpeed; }

	bool behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Projectile*>& vectorProjectiles, Player &player);
};

// NORMAL ENEMIES (ONLY MOVING LEFT)
class Normal : public Enemy {
private:
	std::string id = "normal";
public:
	Normal(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture);

	void behavior(float timeElapsed, std::vector<Normal>& vectorNormal, sf::RenderWindow& window);

	std::string getId() const { return id; }
};

// SHOOTERS (FIXED POSITIONS, CAN SHOOT)
class Shooter : public Enemy {
private:
	std::string id = "shooter";
	int idNum = -1;
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

	//COMPORTEMENT DE BASE
	//Shooter(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture);
	//NOUVEAU COMPORTEMENT
	Shooter(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture, Player &player);

	//void behavior(float timeElapsed, std::vector<Shooter>& vectorShooters, std::vector<sf::Vector2f>& shooterPositions, std::vector<Projectile*>& vectorProjectile, std::vector<bool>& positionsOccupied, sf::RenderWindow& window);
	void behavior(float timeElapsed, std::vector<Shooter>& vectorShooters, std::vector<Projectile*>& vectorProjectile, sf::RenderWindow& window);

	void setId(int newId) { idNum = newId; }
	std::string getId() const { return id; }
	int getIdNum() const { return idNum; }
};

// ELITES (TRACK THE PLAYER, CAN SHOOT)
class Elite : public Enemy {
private:
	std::string id = "elite";
public:
	float shootCooldown = 0;
	float trackCooldown = 0;
	sf::Vector2f playerPosition = { 0,0 };

	Elite(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture);

	void behavior(float timeElapsed, Player &player, std::vector<Projectile*>& vectorProjectile, sf::RenderWindow& window);

	std::string getId() const { return id; }
};

// BOSS (PROJECTILES TRACKS THE PLAYER, CAN SHOOT AND TAKES ALL THE HEIGHT OF THE SCREEN)
class Boss : public Enemy {
private:
	std::string id = "boss";
	float projectileSpeedX = -800;
	float updatingSpeedY = 0;
	float updatingSpeedYSetter = 79;
	float shootCooldown = 0;
	float secondCooldown = 0;
	float specialCooldown = 0;
	float switchCooldown = 0;
public:
	bool spawned = false;
	bool spawning = false;

	Boss();

	bool behavior(float timeElapsed, Player& player, std::vector<Projectile*>& vectorProjectile, sf::RenderWindow& window);

	std::string getId() const { return id; }
	void setupBoss() {
		hp = 10000;
		atkPower = 20;
		sugarValue = 5000;
		moveSpeedY = 0;
		alive = true;
	}
};

#endif