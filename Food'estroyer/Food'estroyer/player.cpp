#include "game.h"
#include "player.h"

std::vector<sf::CircleShape> vectorPies;

Player::Player() : hp(100), speed(20), atkPower(10) {
	this->setRadius(50);
	this->setFillColor(sf::Color::Green);
}

void Player::throwPie() { // Ajouter le cooldown dans les KeyPressed ?
						  // Pourquoi pas, dans tout les cas il s'agira d'une dur�e de temps donc n'importe o� �a peut cont�ler une dur�e de temps.
	sf::CircleShape pie(10);                                        // Quel rayon ?
																	// Dylan : Pas en terme de pixels, mais plut�t en ratio de la taille de la fen�tre, je dirais 1% de la largeur de la fen�tre
																	// En gros, 50 tartes coll�es c�te � c�te feraient l'ensemble de la largeur de l'�cran.
	//pie.setTexture();
	pie.setPosition(getPosition().x + pie.getRadius() * 2, getPosition().y);
	vectorPies.push_back(pie);  // Pour faire les collisions des pies et leurs mouvements
}