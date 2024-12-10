#include "game.h"
#include "enemy.h"

Enemy::Enemy(float x, float y, char s, sf::RenderWindow &window) : size(s) {
	this->setPosition(x, y);
	// Valeurs à changer en pourcentage de taille de la fenêtre.
	if (s == 's') this->setScale(0.09, 0.09);
	else if (s == 'm') this->setScale(0.13, 0.13);
	else if (s == 'l') this->setScale(0.19, 0.19);
}

Normal::Normal(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {
	if (size == 's') moveSpeed = -700;
	if (size == 'm') moveSpeed = -500;
	if (size == 'l') moveSpeed = -300;
}
Shooter::Shooter(float x, float y, char s, sf::RenderWindow &window) : Enemy(x, y, s, window) {}
Elite::Elite(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {
	if (s == 's') moveSpeed = -700;
	if (s == 'm') moveSpeed = -500;
	if (s == 'l') moveSpeed = -300;
}

void Normal::behavior(float timeElapsed) {
	move(moveSpeed * timeElapsed, 0);
}

void Shooter::behavior(float timeElapsed, std::vector<Shooter>& vectorShooter, std::vector<sf::Vector2f>& shooterPositions, std::vector<Projectile*>& projectiles, std::vector<bool>& positionsOccupied){
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
			counter = 0;
		}
		randomPositionChoice = rand() % shooterPositions.size(); // Between 0 and 14
		if (positionsOccupied[randomPositionChoice] == false) {
			positionFound = true;
			waitingForPosition = false;
			positionsOccupied[randomPositionChoice] = true;
			positionChoice = possiblePositions[randomPositionChoice];
		}
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
			if (shootCooldown >= 0.7f) { // ici : varier le nombre de boucle pour que les ennemis shoot +ou- vite - A remplacer par une durée de temps variable
				Projectile *projectile = new Projectile;
				projectile->setId(getId());
				projectile->setSize(sf::Vector2f(20, 10));
				projectile->setPosition(getPosition().x - (getLocalBounds().width * getScale().x) / 2, getPosition().y + (getLocalBounds().height * getScale().y) / 2 - projectile->getSize().y / 2);
				projectile->setFillColor(sf::Color::Yellow);
				projectiles.push_back(projectile);
				shootCooldown = 0;
			}
			else { shootCooldown += timeElapsed; }
		}
	}
}

void Elite::behavior(float timeElapsed, sf::CircleShape player, std::vector<Projectile*> &projectiles, sf::RenderWindow &window) 
{
	//pour tracker le personnage après un délai
	//GAUCHE DROITE

	if (getPosition().x <= window.getSize().x && getPosition().x >= 0) {
		if (getPosition().x < window.getSize().x / 2 + getLocalBounds().width * getScale().x) {
			moveSpeed = -moveSpeed;
		}
		else if (getPosition().x > window.getSize().x - getLocalBounds().width * getScale().x) {
			moveSpeed = -moveSpeed;
		}
	}
	move(moveSpeed* timeElapsed, 0);
	
	//SUIVRE LE JOUEUR SUR L'AXE Y
	if (getPosition().y > player.getPosition().y || getPosition().y < player.getPosition().y) {
		trackCooldown += timeElapsed; //set un chrono
	}
	if (trackCooldown > 3.f) { //à varier selon l'agressivité voulue
		if ((getPosition().y - player.getPosition().y < 0.5f && getPosition().y - player.getPosition().y > -0.5f))
			trackCooldown = 0;
		else if (getPosition().y > player.getPosition().y) {
			if (getPosition().y - player.getPosition().y > 3.f)
				move(0, -300 * timeElapsed);
			else { move(0, -1 * timeElapsed); }
		}
		else if (getPosition().y < player.getPosition().y) {
			if (player.getPosition().y - getPosition().y > 3.f)
				move(0, 300 * timeElapsed);
			else { move(0, 1 * timeElapsed); }
		}
		
	}
	//TIRER
	if (shootCooldown >= 0.3f) {
		Projectile *projectile = new Projectile;
		projectile->setId(getId());
		projectile->setSize(sf::Vector2f(30, 15));
		projectile->setPosition(getPosition().x - (getLocalBounds().width * getScale().x) / 2, getPosition().y + (getLocalBounds().height * getScale().y) / 2 - projectile->getSize().y / 2);
		projectile->setFillColor(sf::Color::Red);
		projectiles.push_back(projectile);
		shootCooldown = 0;
	}
	else { shootCooldown += timeElapsed; }
}