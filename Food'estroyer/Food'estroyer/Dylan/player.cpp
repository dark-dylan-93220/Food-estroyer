#include "game.h"
#include "player.h"
//#include "enemy.cpp"

std::vector<sf::CircleShape> vectorPies;

Player::Player() : hp(100), speed(20), atkPower(10) {
	this->setRadius(50);
	this->setPosition(50,50);
	this->setFillColor(sf::Color::Green);
}

/*bool Player::collision(Enemy enemy) {
	if (getGlobalBounds().intersects(enemy.getGlobalBounds())) {
		hp -= 1;                                                     //dégats de collision fixes ou varient selon ennemi ?
		return true;
	}
	else { return false; }
}*/

void Player::throwPie() { //ajouter le cooldown dans les KeyPressed ?
	sf::CircleShape pie(10);                                        //quel rayon
	//pie.setTexture();
	pie.setPosition(getPosition().x + pie.getRadius() * 2, getPosition().y);
	vectorPies.push_back(pie);  //pour faire les collisions des pies et leurs mouvements
}

