#include "game.h"
//#include "enemy.cpp"                                     // "déjà défini" pb

std::vector<sf::CircleShape> vectorPies;

class Player : public sf::CircleShape {
public:
	bool alive = true;
	float hp;
	float speed;
	float atkPower;

	Player() {
		this->setRadius(30);
		this->setPosition(50,540);
	}

	/*bool collision(Enemy enemy) {
		if (getGlobalBounds().intersects(enemy.getGlobalBounds())) {
			hp -= 1;                                                     //dégats de collision fixes ou varient selon ennemi ?
			return true;
		}
		else { return false; }
	}*/

	void throwPie() { //ajouter le cooldown dans les KeyPressed ?
		sf::CircleShape pie(10);                                        //quel rayon
		//pie.setTexture();
		pie.setPosition(getPosition().x + pie.getRadius() * 2, getPosition().y);
		vectorPies.push_back(pie);  //pour faire les collisions des pies et leurs mouvements
	}

};