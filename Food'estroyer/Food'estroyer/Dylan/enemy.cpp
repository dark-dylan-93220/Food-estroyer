#include "game.h"

std::vector<sf::RectangleShape> projectiles;

class Enemy : public sf::CircleShape {
protected:
	bool alive = true;
	Enemy(float x, float y, float s) {
		this->setPosition(x, y);
		this->setRadius(s);
	}
};

class Normals : public Enemy {
public:
	Normals(float x, float y, float s) : Enemy(x, y, s) {}

	void moovement(){
		move(-1, 0);                                                                  //valeurs à modifier
	}
};

class Shooter : public Enemy {
public:
	float moveDir = 1;
	Shooter(float x, float y, float s) : Enemy(x, y, s) {}

	void moovement() { //inverser direction si on touche un bord
		move(0, moveDir);
		if (getPosition().y + getRadius() >= 1080                                     //pas réussi un WINDOW_WIDTH dans game.cpp
			|| getPosition().y + getRadius() <= 1080)
			moveDir = -moveDir;
	}
	void shoot() {
		sf::RectangleShape projectile(sf::Vector2f(5, 1));
		projectile.setPosition(getPosition().x - getRadius() / 2, getPosition().y);
		projectile.setFillColor(sf::Color::Red);
		projectiles.push_back(projectile);
	}
};

class Elite : public Enemy {
public:
	int trackCooldown = 0;
	Elite(float x, float y, float s) : Enemy(x, y, s) {}

	void moovement(sf::CircleShape player){ //pour tracker le personnage après un délai
		if (getPosition().x > player.getPosition().x || getPosition().x < player.getPosition().x) {
			trackCooldown++;
		}
		if (trackCooldown > 10) { //à varier selon l'agressivité voulue
			if (getPosition().x > player.getPosition().x) move(-1, 0);
			else if (getPosition().x < player.getPosition().x) move(1, 0);
			else { trackCooldown = 0; }
		} 
	}
};






