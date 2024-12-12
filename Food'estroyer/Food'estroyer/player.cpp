#include "game.h"
#include "player.h"


Player::Player() : hp(100), speed(20), atkPower(10) {
	this->setRadius(50);
	this->setFillColor(sf::Color::Green);
}

void Player::throwPie(std::vector<Pie*> &vectorPies, sf::RenderWindow &window, float timeElapsed) {
	Pie* pie = new Pie;
	pie->setAtkPower(atkPower);
	pie->setRadius(getPieSize() * window.getSize().x);
	pie->setSpeed(getPieSpeed());
	pie->setPosition(getPosition().x + getRadius() + pie->getRadius(), getPosition().y + getRadius() - pie->getRadius());
	vectorPies.push_back(pie);
	shootCooldown = 0;
}

// Ajouter le cooldown dans les KeyPressed ?
// Pourquoi pas, dans tout les cas il s'agira d'une durée de temps donc n'importe où ça peut contôler une durée de temps.

// Quel rayon ?
// Dylan : Pas en terme de pixels, mais plutôt en ratio de la taille de la fenêtre, je dirais 1% de la largeur de la fenêtre
// En gros, 50 tartes collées côte à côte feraient l'ensemble de la largeur de l'écran.

