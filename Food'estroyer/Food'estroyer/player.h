#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

class Pie : public sf::CircleShape {
private:

	bool state = true;
	float atkPower = 1;
	float speed;
	float size;

public:

	float getState() const    { return state; }
	float getAtkPower() const { return atkPower; }
	float getSpeed() const    { return speed; }
	float getSize() const     { return size; }

	void setState(float newState) { state = newState; }
	void setAtkPower(float newAtkPower) { atkPower = newAtkPower; }
	void setSpeed(float newSpeed)       { speed = newSpeed; }
	void setSize(float newSize)         { size = newSize; }
};

class Player : public sf::CircleShape {
private:
	bool alive = true;
	float hp;
	float speed;
	float atkPower;
	float pieSpeed = 1000;																			 ////////////// PIE SPEED HERE
	float pieSize = 0.01;
	float shootCooldown = 0;

public:
	
	Player();

	void throwPie(std::vector<Pie*> &vectorPies, sf::RenderWindow &window);

	void specialAtk(std::vector<Pie*>& vectorPies, sf::RenderWindow window);

	// Allez un peu d'encapsulation :)
	// Getters
	bool getPlayerLife() const     { return alive; }
	float getPlayerHP() const      { return hp; }
	float getSpeed() const         { return speed; }
	float getAtkPower() const      { return atkPower; }
	float getPieSpeed() const      { return pieSpeed; }
	float getPieSize() const       { return pieSize; }
	float getShootCooldown() const { return shootCooldown; }
	// Setters
	void damagePlayer(float degats)						{ hp -= degats; }
	void setPlayerSpeed(int bonusSpeed)					{ speed *= (0.01f * bonusSpeed); }// Bonus speed entre 0 et 100 comme un pourcentage
	void setPlayerSpeedBackToNormal(int bonusSpeed)		{ speed /= (0.01f * bonusSpeed); }// Opération inverse
	void setAtkPower(float atkMultiplier)				{ atkPower *= atkMultiplier; } // Genre 1.2x, 1.55x etc...
	void setPieSpeed(float newSpeed) { pieSpeed = newSpeed; }
	void setPieSize(float newSize) { pieSize = newSize; }
	void setShootCooldown(float timeElapsed) { shootCooldown += timeElapsed; }

};
#endif
