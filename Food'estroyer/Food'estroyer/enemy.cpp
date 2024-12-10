#include "game.h"
#include "enemy.h"

Enemy::Enemy(float x, float y, char s, sf::RenderWindow &window) : size(s) {
	this->setPosition(x, y);
	// Valeurs à changer en pourcentage de taille de la fenêtre.
	if (s == 's') { 
		this->setScale(0.09, 0.09);
		this->hpSize = 0.5;              // multiplier les hp de l'ennemi pas rapport à sa taille
	}
	else if (s == 'm') { 
		this->setScale(0.13, 0.13);
		this->hpSize = 1;
	}
	else if (s == 'l') {
		this->setScale(0.19, 0.19);
		this->hpSize = 1.5;
	}
}

Normal::Normal(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {
	if (size == 's') { moveSpeed = -700; }
	if (size == 'm') { moveSpeed = -500; }
	if (size == 'l') { moveSpeed = -300; }
	hp = 100 * hpSize;
}
Shooter::Shooter(float x, float y, char s, sf::RenderWindow &window) : Enemy(x, y, s, window) {
	this->setPosition(sf::Vector2f(window.getSize().x + 100.f, -100.f));
	hp = 150 * hpSize;
}
Elite::Elite(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {
	if (s == 's') moveSpeed = -700;
	if (s == 'm') moveSpeed = -500;
	if (s == 'l') moveSpeed = -300;
	hp = 200 * hpSize;
}

void Normal::behavior(float timeElapsed) {
	if (hp <= 0) { alive = false; }
	move(moveSpeed * timeElapsed, 0);
}

void Shooter::behavior(float timeElapsed, std::vector<Shooter>& vectorShooter, std::vector<sf::Vector2f>& shooterPositions, 
	std::vector<Projectile*>& projectiles, std::vector<bool>& positionsOccupied){

	if (hp <= 0) { alive = false; }

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
		if (positionChoice.y < getPosition().y) moveDirY = -moveDirY;
		if (positionChoice.y > getPosition().y) moveDirY = moveDirY;
		if (getPosition().x - positionChoice.x > 3.f && !positionReached)
			move((moveDirX * 100) * timeElapsed, 0);
		if (positionChoice.y - getPosition().y > 3.f && !positionReached)
			move(0, (moveDirY * 100) * timeElapsed);
		if(!(getPosition().x - positionChoice.x > 3.f) && !(positionChoice.y - getPosition().y > 3.f))
		{
			//Center shooter position in relation to his size
			positionReached = true;
			if (positionReached) {
				if (getPosition().x - targetPosition.x > 3.f)
					move((moveDirX * 10) * timeElapsed, 0);
				if (targetPosition.y - getPosition().y > 3.f)
					move(0, (moveDirY * 10) * timeElapsed);
			}
			// Shoots here
			if (shootCooldown >= 1.5f) { // ici : varier le nombre de boucle pour que les ennemis shoot +ou- vite - A remplacer par une durée de temps variable
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
	playerPosition = { player.getPosition().x + (player.getLocalBounds().width * player.getScale().x) / 2 - (getLocalBounds().width * getScale().x) / 2,
		player.getPosition().y + (player.getLocalBounds().height * player.getScale().y) / 2 - (getLocalBounds().height * getScale().y) / 2 };

	if (hp <= 0) { alive = false; }

	if (getPosition().x <= window.getSize().x && getPosition().x >= 0) {
		if (getPosition().x < window.getSize().x / 2 + getLocalBounds().width * getScale().x) {
			setPosition(window.getSize().x / 2 + 50.f, getPosition().y);
			moveSpeed = -moveSpeed;
		}
		else if (getPosition().x > window.getSize().x - getLocalBounds().width * getScale().x) {
			setPosition(window.getSize().x - 50.f, getPosition().y);
			moveSpeed = -moveSpeed;
		}
	}
	move(moveSpeed* timeElapsed, 0);
	
	//SUIVRE LE JOUEUR SUR L'AXE Y
	if ((getPosition().y - playerPosition.y > 10.f || getPosition().y - playerPosition.y < -10.f))
		trackCooldown += timeElapsed; //set un chrono

	if (trackCooldown > 1.f) { //à varier selon l'agressivité voulue
		if ((getPosition().y - playerPosition.y <= 10.f && getPosition().y - playerPosition.y >= -10.f)) {
			trackCooldown = 0;
		}

		else if (getPosition().y > playerPosition.y) {
			if (getPosition().y - playerPosition.y > 10.f)
				move(0, -300 * timeElapsed);
			else { move(0, -1 * timeElapsed); }
		}
		else if (getPosition().y < playerPosition.y) {
			if (playerPosition.y - getPosition().y > 10.f)
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