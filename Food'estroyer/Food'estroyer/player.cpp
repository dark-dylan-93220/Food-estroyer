#include "game.h"
#include "player.h"

std::vector<sf::CircleShape> vectorPies;

Player::Player() : hp(100), speed(20), atkPower(10) {
	this->setRadius(50);
	this->setFillColor(sf::Color::Green);
}

void Player::throwPie() { // Ajouter le cooldown dans les KeyPressed ?
						  // Pourquoi pas, dans tout les cas il s'agira d'une durée de temps donc n'importe où ça peut contôler une durée de temps.
	sf::CircleShape pie(10);                                        // Quel rayon ?
																	// Dylan : Pas en terme de pixels, mais plutôt en ratio de la taille de la fenêtre, je dirais 1% de la largeur de la fenêtre
																	// En gros, 50 tartes collées côte à côte feraient l'ensemble de la largeur de l'écran.
	//pie.setTexture();
	pie.setPosition(getPosition().x + pie.getRadius() * 2, getPosition().y);
	vectorPies.push_back(pie);  // Pour faire les collisions des pies et leurs mouvements
}