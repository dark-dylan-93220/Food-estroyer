#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

class Pie : public sf::CircleShape {
protected:

	bool state = true;
	float atkPower = 1;
	float speedX = 0;
	float speedY = 0;
	float size = 0;

public:

	std::string specialType = "not initialised";
	int hitCounter = 0;
	int maxHitNumber = 1;

	bool getState() const               { return state; }
	float getAtkPower() const           { return atkPower; }
	float getSpeedX() const             { return speedX; }
	float getSpeedY() const             { return speedY; }
	float getSize() const               { return size; }

	void setState(float newState)       { state = newState; }
	void setAtkPower(float newAtkPower) { atkPower = newAtkPower; }
	void setSpeedX(float newSpeed)      { speedX = newSpeed; }
	void setSpeedY(float newSpeed)      { speedY = newSpeed; }
	void setSize(float newSize)         { size = newSize; }

	bool behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Pie*>& vectorPie);
};

class Player : public sf::CircleShape {
private:
	bool alive = true;
	float hp = 100;               
	float maxHp = 100;             //COMMENCER A 100, AUGMENTER DE 10PV A CHAQUE LVL UP
	float speed = 400;             //COMMENCER A 400, AUGMENTER DE 100 A CHAQUE LVL UP
	float atkPower = 10;           //COMMENCER A 10, AUGMENTER DE 25% A CHAQUE LVL UP
	float pieSpeedX = 1000;																			 ////////////// PIE SPEED HERE
	float pieSize = 0.01f;
	float shootTimer = 0;
	float shootCooldown = 0.2f;
	float specialTimer = 0;
	float specialCooldown = 0; // on commence avec l'attaque spéciale chargée
	std::string specialAtkType = "base";
	int sugarCount = 100000;
	float bonusTimer = 0;
	float bonusCooldown = 0;
	bool shield = false; //le shield couvre les dégats des projectiles mais pas ceux d'une collision au cac (il annule le premier dégat mais n'active pas le timer d'invincibilité)
	bool x2 = false;
	bool oneUp = false;
	int rainVariation[15] = { 50,75,100,150,175,200,250,275,300,350,400,500,550,600,650 };

public:

	int hurtCount = 0;
	float hurtTimer = 0;
	bool raining = false;
	int rainCount = 0;
	int atkLvl = 1;
	int atkLvlUpCost = 300;
	int maxHpLvl = 1;
	int maxHpLvlUpCost = 500;
	int speedLvl = 1;
	int speedLvlUpCost = 1000;
	bool tripleBought = false;
	int tripleCost = 2000;
	bool rainBought = false;
	int rainCost = 3000;

	Player();

	void throwPie(std::vector<Pie*>& vectorPie, sf::RenderWindow& window);

	void specialAtk(std::vector<Pie*>& vectorPies, sf::RenderWindow& window);

	// Allez un peu d'encapsulation :)
	// Getters
	bool getPlayerLife() const             { return alive; }
	float getPlayerHP() const              { return hp; }
	float getPlayerMaxHP() const           { return maxHp; }
	float getSpeed() const                 { return speed; }
	float getAtkPower() const              { return atkPower; }
	float getPieSpeedX() const             { return pieSpeedX; }
	float getPieSize() const               { return pieSize; }
	float getShootTimer() const            { return shootTimer; }
	float getShootCooldown() const         { return shootCooldown; }
	float getSpecialTimer() const          { return specialTimer; }
	float getSpecialCooldown() const       { return specialCooldown; }
	std::string getSpectialAtkType() const { return specialAtkType; }
	int getSugarCount() const              { return sugarCount; }
	float getBonusTimer() const            { return bonusTimer; }
	float getBonusCooldown() const         { return bonusCooldown; }
	bool getShield() const                 { return shield; }
	bool getX2() const                     { return x2; }
	bool getOneUp() const                  { return oneUp; }
	// Setters
	void setPlayerLife(bool newState)                   { alive = false; }
	void setPlayerHP(float newHP)                       { hp = newHP; }
	void setPlayerMaxHP(float newMaxHP)                 { maxHp += newMaxHP; }
	void damagePlayer(float degats)                     { hp -= degats; }
	void setPlayerSpeed(float bonusSpeed)               { speed += bonusSpeed; }
	void setPlayerSpeedBackToNormal(int bonusSpeed)     { speed /= (0.01f * bonusSpeed); }// Opération inverse
	void setAtkPower(float atkMultiplier)               { atkPower *= atkMultiplier; } // Genre 1.2x, 1.55x etc...
	void setPieSpeedX(float newSpeed)                   { pieSpeedX = newSpeed; }
	void setPieSize(float newSize)                      { pieSize = newSize; }
	void setShootTimer(float timeElapsed)               { shootTimer += timeElapsed; }
	void resetShootTimer(float newSet)                  { shootTimer = newSet; }
	void setShootCooldown(float newCooldown)            { shootCooldown = newCooldown; }
	void setSpecialTimer(float timeElapsed)             { specialTimer += timeElapsed; }
	void resetSpecialTimer(float newSet)                { specialTimer = newSet; }
	void setSpecialCooldown(float newCooldown)          { specialCooldown = newCooldown; }
	void setSpecialAtkType(std::string newType)         { specialAtkType = newType; }
	void setSugarCount(int sugarNumber)                 { sugarCount += sugarNumber; }
	void setBonusTimer(float timeElapsed)               { bonusTimer += timeElapsed; }
	void setBonusCooldown(float newCooldown)            { bonusCooldown = newCooldown; }
	void resetBonusTimer(float time)                    { bonusTimer = time; }
	void setShield(bool newState)                       { shield = newState; }
	void setX2(bool newState)                           { x2 = newState; }
	void setOneUp(bool newState)                        { oneUp = newState; }

};

class Bonus : public sf::RectangleShape {
private:
	bool state = true;
	std::string id = "not Initialised";
	float moveSpeed = 100.f;
	float posX = 0;
	float posY = 0;
	float cooldown = 5;
public:

	Bonus(float PosX, float PosY, std::string setId, Player& player);

	bool getState() const          { return state; }
	std::string getId() const      { return id; }
	float getMooveSpeed() const    { return moveSpeed; }
	float getCooldown() const      { return cooldown; }

	void setState(bool newState)             { state = newState; }
	void setId(std::string newId)            { id = newId; }
	void setMooveSpeed(float newMoveSpeed)   { moveSpeed = newMoveSpeed; }
	void setCooldown(float newCooldown)      { cooldown = newCooldown; }

	bool behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Bonus*> &vectorBonus);
};
#endif
