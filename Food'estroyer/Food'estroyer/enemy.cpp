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

void Normal::behavior(float timeElapsed) {
	move(-500 * timeElapsed, 0);
}

void Shooter::behavior(float timeElapsed, std::vector<Shooter>& vectorShooter, std::vector<sf::Vector2f>& shooterPositions, std::vector<sf::RectangleShape>& projectiles, std::vector<bool>& positionsOccupied){
	int counter(0);
	possiblePositions = shooterPositions;
	while (!positionFound || waitingForPosition) {
		// Dylan : J'ai refait cette boucle, les ennemis apparaissaient des fois sur la même case, j'ai réglé ce problème.
		for (int i = 0; i < 15; ++i) {
			if (positionsOccupied[i] == true) {
				counter++;
			}
		}
		if (counter == 15) {
			// Some function to make the appearing entity dissapear if every slot is occupied
			// TEMPORARY
			positionChoice = { -500.f,-500.f };
			positionFound = true;
			waitingForPosition = false;
			std::cout << "ALL OCCUPIED" << std::endl;
			counter = 0;
		}
		randomPositionChoice = rand() % shooterPositions.size(); // Between 0 and 14
		if (positionsOccupied[randomPositionChoice] == false) {
			positionFound = true;
			waitingForPosition = false;
			positionsOccupied[randomPositionChoice] = true;
			positionChoice = possiblePositions[randomPositionChoice];
		}
		std::cout << "Current state of spaces : " << positionsOccupied[0] << " " << positionsOccupied[1] << " " << positionsOccupied[2] << " " << positionsOccupied[3] << " " << positionsOccupied[4] << " " << positionsOccupied[5] << " " << positionsOccupied[6] << " " << positionsOccupied[7] << " " << positionsOccupied[8] << " " << positionsOccupied[9] << " " << positionsOccupied[10] << " " << positionsOccupied[11] << " " << positionsOccupied[12] << " " << positionsOccupied[13] << " " << positionsOccupied[14] << std::endl;
	}
	// REDUCE SPEED IF SHOOTER IS APPROACHING POSITION
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
		if ((positionChoice.x - getPosition().x < 1.f) || (getPosition().x - positionChoice.x < 1.f)) setPosition(positionChoice.x, getPosition().y);
		if (positionChoice.y < getPosition().y) moveDirY = -moveDirY;
		if (positionChoice.y > getPosition().y) moveDirY = moveDirY;
		if ((positionChoice.y - getPosition().y < 1.f) || (getPosition().y - positionChoice.y < 1.f)) setPosition(getPosition().x, positionChoice.y);

		if (getPosition() != positionChoice) move((moveDirX * 100) * timeElapsed, (moveDirY * 100) * timeElapsed);
		else 
		{
			// Shoots here
			if (shootCooldown >= 100) { // ici : varier le nombre de boucle pour que les ennemis shoot +ou- vite - A remplacer par une durée de temps variable
				sf::RectangleShape *projectile = new sf::RectangleShape(sf::Vector2f(20, 10));
				projectile->setPosition(getPosition().x - getRadius(), getPosition().y + getRadius() - projectile->getSize().y / 2);
				projectile->setFillColor(sf::Color::Yellow);
				projectiles.push_back(projectile);
				shootCooldown = 0;
			}
			else { shootCooldown += timeElapsed; }
		}
	}
}

void Elite::behavior(float timeElapsed, sf::CircleShape player, std::vector<sf::RectangleShape> &projectiles, sf::RenderWindow &window){ //pour tracker le personnage après un délai

	//GAUCHE DROITE
	move(moveDirX * timeElapsed, 0);
	if (getPosition().x <= window.getSize().x && getPosition().x >= 0) {
		if (getPosition().x <= window.getSize().x / 2 + getRadius() * 2)
			moveDirX = -moveDirX;
		if (getPosition().x >= window.getSize().x - getRadius() * 2)
			moveDirX = -moveDirX;
	}
	
	//SUIVRE LE JOUEUR SUR L'AXE Y
	if (getPosition().y > player.getPosition().y || getPosition().y < player.getPosition().y) {
		trackCooldown += timeElapsed; //set un chrono
	}
	if (trackCooldown > 0.02f) { //à varier selon l'agressivité voulue
		if (getPosition().y > player.getPosition().y) 
			move(0, -300 * timeElapsed);
		else if (getPosition().y < player.getPosition().y)
			move(0, 300 * timeElapsed);
		else { trackCooldown = 0; }
	}
	//TIRER
	if (shootCooldown >= 0.4f) {
		sf::RectangleShape projectile(sf::Vector2f(30, 15));
		projectile.setPosition(getPosition().x - getRadius(), getPosition().y + getRadius() - projectile.getSize().y/2);
		projectile.setFillColor(sf::Color::Red);
	if (shootCooldown == 50) {
		sf::RectangleShape *projectile = new sf::RectangleShape(sf::Vector2f(30, 15));
		projectile->setPosition(getPosition().x - getRadius(), getPosition().y + getRadius() - projectile->getSize().y/2);
		projectile->setFillColor(sf::Color::Red);
		projectiles.push_back(projectile);
		shootCooldown = 0;
	}
	else { shootCooldown += timeElapsed; }
}