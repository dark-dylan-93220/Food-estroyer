#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

class Player : public sf::CircleShape {
private:
	bool alive = true;
	float hp;
	float speed;
	float atkPower;

public:
	
	Player();

	/*bool collision(Enemy enemy) {
		if (getGlobalBounds().intersects(enemy.getGlobalBounds())) {
			hp -= 1;                                                     // Dégats de collision fixes ou varient selon ennemi ?
			return true;												 // Varient selon les ennemis.
		}
		else { return false; }
	}*/

	void throwPie();

	// Allez un peu d'encapsulation :)
	// Getters
	bool getPlayerLife() const {
		return alive;
	}
	float getPlayerHP() const {
		return hp;
	}
	float getSpeed() const {
		return speed;
	}
	float getAtkPower() const {
		return atkPower;
	}
	// Setters
	void damagePlayer(float degats) {
		hp -= degats;
	}
	void setPlayerSpeed(int bonusSpeed) { // Bonus speed entre 0 et 100 comme un pourcentage
		speed *= (0.01f * bonusSpeed);
	}
	void setPlayerSpeedBackToNormal(int bonusSpeed) { // Opération inverse
		speed /= (0.01f * bonusSpeed);
	}
	void setAtkPower(float atkMultiplier) { // Genre 1.2x, 1.55x etc...
		atkPower *= atkMultiplier;
	}

};
#endif
