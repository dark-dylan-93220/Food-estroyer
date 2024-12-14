#include "game.h"
#include "player.h"


Player::Player() {
	this->setRadius(50);
	this->setFillColor(sf::Color::Green);
}

Bonus::Bonus(float PosX, float PosY, std::string setId, Player &player) : posX(PosX), posY(PosY), id(setId){
	this->setPosition(posX, posY);
	//potentiellement changer la moveSpeed/size par rapport à l'id
	if (id == "shield") {
		cooldown = 10;
	}
}

void Player::throwPie(std::vector<Pie*> &vectorPies, sf::RenderWindow &window) {
	Pie* pie = new Pie;
	pie->setAtkPower(atkPower);
	pie->setRadius(getPieSize() * window.getSize().x);
	pie->setSpeed(getPieSpeed());
	pie->setPosition(getPosition().x + getRadius() + pie->getRadius(), getPosition().y + getRadius() - pie->getRadius());
	vectorPies.push_back(pie);
	shootTimer = 0;
}

void Player::specialAtk(std::vector<Pie*> &vectorPie, sf::RenderWindow &window) {
	switch (specialAtkType) {
	case 'b':
		specialCooldown = 5.f;
		Pie* specialPie = new Pie;
		specialPie->specialType = specialAtkType;
		specialPie->setAtkPower(atkPower * 3);
		specialPie->setRadius(getPieSize() * 5 * window.getSize().x);
		specialPie->setSpeed(getPieSpeed());
		specialPie->setPosition(getPosition().x + getRadius() + specialPie->getRadius(), getPosition().y + getRadius() - specialPie->getRadius());
		vectorPie.push_back(specialPie);
		specialTimer = 0;
		break;
	}
}

bool Bonus::behavior(float timeElapsed, sf::RenderWindow &window, std::vector<Bonus*> vectorBonus) {
	if (state) {
		move(0, moveSpeed * timeElapsed);
		if (getPosition().y > window.getSize().y + getSize().y)
			state = false;
		return true;
	}
	else { return false; }
}

bool Pie::behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Pie*> vectorPie) {
	if (state) {
		move(speed * timeElapsed, 0);
		if (getPosition().x > window.getSize().x + getRadius() * 2)
			state = false;
		return true;
	}
	else { return false; }
}
