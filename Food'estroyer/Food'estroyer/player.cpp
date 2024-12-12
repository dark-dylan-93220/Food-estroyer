#include "game.h"
#include "player.h"


Player::Player() {
	this->setRadius(50);
	this->setFillColor(sf::Color::Green);
}

void Player::throwPie(std::vector<Pie*> &vectorPies, sf::RenderWindow &window) {
	Pie* pie = new Pie;
	pie->setAtkPower(atkPower);
	pie->setRadius(getPieSize() * window.getSize().x);
	pie->setSpeed(getPieSpeed());
	pie->setPosition(getPosition().x + getRadius() + pie->getRadius(), getPosition().y + getRadius() - pie->getRadius());
	vectorPies.push_back(pie);
	shootCooldown = 0;
}

void Player::specialAtk(std::vector<Pie*> &vectorPies, sf::RenderWindow &window) {
	switch (specialAtkType) {
	case 'b':
		Pie* specialPie = new Pie;
		specialPie->specialType = specialAtkType;
		specialPie->setAtkPower(atkPower * 3);
		specialPie->setRadius(getPieSize() * 5 * window.getSize().x);
		specialPie->setSpeed(getPieSpeed());
		specialPie->setPosition(getPosition().x + getRadius() + specialPie->getRadius(), getPosition().y + getRadius() - specialPie->getRadius());
		vectorPies.push_back(specialPie);
		specialCooldown = 0;
		break;
	}
}

