#include "game.h"
#include "enemy.h"

Enemy::Enemy(float x, float y, char s, sf::RenderWindow &window) : size(s) {
	this->setPosition(x, y);
	// Valeurs à changer en pourcentage de taille de la fenêtre.
	if (s == 's') this->setRadius(10);
	else if (s == 'm') this->setRadius(30);
	else if (s == 'l') this->setRadius(50);
}

Normal::Normal(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {}
Shooter::Shooter(float x, float y, char s, sf::RenderWindow &window) : Enemy(x, y, s, window) {}
Elite::Elite(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {}

void Normal::behavior() {
	move(-5, 0);
}

void Shooter::behavior(std::vector<Shooter>& vectorShooter, std::vector<sf::Vector2f>& shooterPositions, std::vector<sf::RectangleShape>& projectiles){
	possiblePositions = shooterPositions;
	while (!positionFound || waitingForPosition) {
		positionFound = true;
		waitingForPosition = false;
		index = rand() % possiblePositions.size();
		// Vérif ici
		positionChoice = possiblePositions[index];
		if(vectorShooter.size() > 0){
			for (sf::CircleShape& shooter : vectorShooter) {
				if (shooter.getPosition() == positionChoice) {
					positionFound = false;
				}
			}
		}
		possiblePositions.erase(possiblePositions.begin() + index);
		if (possiblePositions.size() == 0) {
			positionFound = true;
			waitingForPosition = true;
		}
	}
	//REDUCE SPEED IF SHOOTER IS APPROACHING POSITION
	if (positionFound == true && waitingForPosition == false) {

		if (positionChoice.x > getPosition().x) {
			if (positionChoice.x - getPosition().x <= 20)
				moveDirX = 1;
			else { moveDirX = 3; }
		}
		if (positionChoice.x < getPosition().x) {
			if (getPosition().x - positionChoice.x <= 20)
				moveDirX = 1;
			else { moveDirX = 3; }
		}
		if (positionChoice.y > getPosition().y) {
			if (positionChoice.y - getPosition().y <= 20)
				moveDirY = 1;
			else { moveDirY = 3; }
		}
		if (positionChoice.y < getPosition().y) {
			if (getPosition().y - positionChoice.y <= 20)
				moveDirY = 1;
			else { moveDirY = 3; }
		}
		
		if (positionChoice.x < getPosition().x) moveDirX = -moveDirX;
		if (positionChoice.x > getPosition().x) moveDirX = moveDirX;
		if (positionChoice.x == getPosition().x) moveDirX = 0;
		if (positionChoice.y < getPosition().y) moveDirY = -moveDirY;
		if (positionChoice.y > getPosition().y) moveDirY = moveDirY;
		if (positionChoice.y == getPosition().y) moveDirY = 0;

		if (getPosition() != positionChoice) move(moveDirX, moveDirY);
		else {
			if (shootCooldown >= 100) { // ici : varier le nombre de boucle pour que les ennemis shoot +ou- vite - A remplacer par une durée de temps variable
				sf::RectangleShape projectile(sf::Vector2f(20, 10));
				projectile.setPosition(getPosition().x - getRadius(), getPosition().y + getRadius() - projectile.getSize().y / 2);
				projectile.setFillColor(sf::Color::Yellow);
				projectiles.push_back(projectile);
				shootCooldown = 0;
			}
			else { shootCooldown++; }
		}
	}
}

void Elite::behavior(sf::CircleShape player, std::vector<sf::RectangleShape> &projectiles, sf::RenderWindow &window){ //pour tracker le personnage après un délai

	//GAUCHE DROITE
	move(moveDirX, 0);
	if (getPosition().x <= window.getSize().x && getPosition().x >= 0) {
		if (getPosition().x <= window.getSize().x / 2 + getRadius() * 2)
			moveDirX = -moveDirX;
		if (getPosition().x >= window.getSize().x - getRadius() * 2)
			moveDirX = -moveDirX;
	}
	
	//SUIVRE LE JOUEUR SUR L'AXE Y
	if (getPosition().y > player.getPosition().y || getPosition().y < player.getPosition().y) {
		trackCooldown++;                                                                             //set un chrono
	}
	if (trackCooldown > 10) { //à varier selon l'agressivité voulue
		if (getPosition().y > player.getPosition().y) 
			move(0, -1);
		else if (getPosition().y < player.getPosition().y)
			move(0, 1);
		else { trackCooldown = 0; }
	}
	//TIRER
	if (shootCooldown == 50) {
		sf::RectangleShape projectile(sf::Vector2f(30, 15));
		projectile.setPosition(getPosition().x - getRadius(), getPosition().y + getRadius() - projectile.getSize().y/2);
		projectile.setFillColor(sf::Color::Red);
		projectiles.push_back(projectile);
		shootCooldown = 0;
	}
	else { shootCooldown++; }
}