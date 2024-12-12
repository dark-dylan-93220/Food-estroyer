#include "game.h"
#include "player.h"


Player::Player() : hp(100), speed(20), atkPower(10) {
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
		specialPie->setAtkPower(atkPower * 1.5);
		specialPie->setRadius(getPieSize() * 5 * window.getSize().x);
		specialPie->setSpeed(getPieSpeed());
		specialPie->setPosition(getPosition().x + getRadius() + specialPie->getRadius(), getPosition().y + getRadius() - specialPie->getRadius());
		vectorPies.push_back(specialPie);
		specialCooldown = 0;
		break;
	}
}
// Ajouter le cooldown dans les KeyPressed ?
// Pourquoi pas, dans tout les cas il s'agira d'une dur�e de temps donc n'importe o� �a peut cont�ler une dur�e de temps.

// Quel rayon ?
// Dylan : Pas en terme de pixels, mais plut�t en ratio de la taille de la fen�tre, je dirais 1% de la largeur de la fen�tre
// En gros, 50 tartes coll�es c�te � c�te feraient l'ensemble de la largeur de l'�cran.

