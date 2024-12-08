#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

class Player : public sf::CircleShape {
public:
	bool alive = true;
	float hp;
	float speed;
	float atkPower;

	Player();

	/*bool collision(Enemy enemy) {
		if (getGlobalBounds().intersects(enemy.getGlobalBounds())) {
			hp -= 1;                                                     //dégats de collision fixes ou varient selon ennemi ?
			return true;
		}
		else { return false; }
	}*/

	void throwPie();

};
#endif
