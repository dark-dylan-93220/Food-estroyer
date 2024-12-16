#include "game.h"
#include "player.h"


Player::Player() {
	this->setRadius(50);
	this->setFillColor(sf::Color::Green);
}

Bonus::Bonus(float PosX, float PosY, std::string setId, Player& player) : posX(PosX), posY(PosY), id(setId) {
	this->setPosition(posX, posY);
	//potentiellement changer la moveSpeed/size par rapport à l'id
	if (id == "shield") {
		cooldown = 10;
	}
	if (id == "x2") {
		cooldown = 5;
	}
	if (id == "oneUp") {
		cooldown = 20;    // ou alors permanent ?
	}
}

void Player::throwPie(std::vector<Pie*>& vectorPie, sf::RenderWindow& window) {
	if (x2) {
		Pie* pie = new Pie;
		pie->setAtkPower(atkPower);
		pie->setRadius(getPieSize() * window.getSize().x);
		pie->setSpeedX(getPieSpeedX());
		pie->setPosition(getPosition().x + getRadius() + pie->getRadius(), getPosition().y + pie->getRadius());
		vectorPie.push_back(pie);
		Pie* pie2 = new Pie;
		pie2->setAtkPower(atkPower);
		pie2->setRadius(getPieSize() * window.getSize().x);
		pie2->setSpeedX(getPieSpeedX());
		pie2->setPosition(getPosition().x + getRadius() + pie2->getRadius(), getPosition().y + getRadius());
		vectorPie.push_back(pie2);
	}
	else {
		Pie* pie = new Pie;
		pie->setAtkPower(atkPower);
		pie->setRadius(getPieSize() * window.getSize().x);
		pie->setSpeedX(getPieSpeedX());
		pie->setPosition(getPosition().x + getRadius() + pie->getRadius(), getPosition().y + getRadius() - pie->getRadius());
		vectorPie.push_back(pie);
	}
}

void Player::specialAtk(std::vector<Pie*>& vectorPie, sf::RenderWindow& window) {
	if (specialAtkType == "base") {
		Pie* specialPie = new Pie;
		specialPie->specialType = specialAtkType;
		specialPie->maxHitNumber = 20;
		specialPie->setAtkPower(atkPower * 1.5f);
		specialPie->setRadius(getPieSize() * 5 * window.getSize().x);
		specialPie->setSpeedX(getPieSpeedX());
		specialPie->setPosition(getPosition().x + getRadius() + specialPie->getRadius(), getPosition().y + getRadius() - specialPie->getRadius());
		vectorPie.push_back(specialPie);
	}
	else if (specialAtkType == "triple") {
		Pie* specialPie = new Pie;
		specialPie->specialType = specialAtkType;
		specialPie->setAtkPower(atkPower * 5);
		specialPie->setRadius(getPieSize() * 3 * window.getSize().x);
		specialPie->setSpeedX(getPieSpeedX());
		specialPie->setPosition(getPosition().x + getRadius() + specialPie->getRadius(), getPosition().y + getRadius() - specialPie->getRadius());
		vectorPie.push_back(specialPie);
		Pie* specialPie1 = new Pie;
		specialPie1->specialType = specialAtkType;
		specialPie1->setAtkPower(atkPower * 5);
		specialPie1->setRadius(getPieSize() * 3 * window.getSize().x);
		specialPie1->setSpeedX(getPieSpeedX());
		specialPie1->setSpeedY(getPieSpeedX() / 2);
		specialPie1->setPosition(getPosition().x + getRadius() + specialPie1->getRadius(), getPosition().y + getRadius() - specialPie1->getRadius());
		vectorPie.push_back(specialPie1);
		Pie* specialPie2 = new Pie;
		specialPie2->specialType = specialAtkType;
		specialPie2->setAtkPower(atkPower * 5);
		specialPie2->setRadius(getPieSize() * 3 * window.getSize().x);
		specialPie2->setSpeedX(getPieSpeedX());
		specialPie2->setSpeedY(-getPieSpeedX() / 2);
		specialPie2->setPosition(getPosition().x + getRadius() + specialPie2->getRadius(), getPosition().y + getRadius() - specialPie2->getRadius());
		vectorPie.push_back(specialPie2);
	}
	else if (specialAtkType == "rain") {
		Pie* pie = new Pie;
		pie->maxHitNumber = 5;
		pie->setAtkPower(atkPower);
		pie->setRadius(getPieSize() * window.getSize().x);
		pie->setSpeedX(getPieSpeedX() / 2.f);
		pie->setSpeedY((float)rainVariation[rand() % 15]);
		pie->setPosition(window.getSize().x / 3.f, -(float)window.getSize().y * 0.01f);
		vectorPie.push_back(pie);
	}
}

bool Bonus::behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Bonus*> &vectorBonus) {
	if (state) {
		move(0, moveSpeed * timeElapsed);
		if (getPosition().y > window.getSize().y + getSize().y)
			state = false;
		return true;
	}
	else { return false; }
}

bool Pie::behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Pie*>& vectorPie) {
	if (state) {
		move(speedX * timeElapsed, speedY * timeElapsed);
		if (getPosition().x > window.getSize().x + getRadius() * 2)
			state = false;
		return true;
	}
	else { return false; }
}
