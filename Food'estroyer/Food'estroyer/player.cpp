#include "game.h"
#include "player.h"


Player::Player() {
	this->setRadius(50);
	this->setFillColor(sf::Color::Green);
}

Bonus::Bonus(float PosX, float PosY, std::string setId) : posX(PosX), posY(PosY), id(setId){
	this->setPosition(posX, posY);
	this->setFillColor(sf::Color::Red);
	//potentiellement changer la moveSpeed/size par rapport à l'id
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

void Bonus::behavior(float timeElapsed, sf::RenderWindow &window, std::vector<Bonus*> vectorBonus) {
	move(0, moveSpeed * timeElapsed);
	if (getPosition().y > window.getSize().y + getSize().y || !state) {
		auto it = std::find(vectorBonus.begin(), vectorBonus.end(), this);
		delete this;
		vectorBonus.erase(it);
	}
}

