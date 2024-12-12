#include "game.h"
#include "enemy.h"

Enemy::Enemy(float x, float y, char s, sf::RenderWindow &window) : size(s) {
	this->setPosition(x, y);
	// Valeurs à changer en pourcentage de taille de la fenêtre.
	switch (s) {
	case ('s') :
			this->setScale(0.09f, 0.09f);
			this->hpPerSize = 0.5;
			this->sugarValuePerSize = 0.5;
			moveSpeedX = -400; moveSpeedY = -400;
			break;
	case('m') :
			this->setScale(0.13f, 0.13f);
			this->hpPerSize = 1;
			this->sugarValuePerSize = 1;
			moveSpeedX = -300; moveSpeedY = -300;
			break;
	case('l') :
			this->setScale(0.19f, 0.19f);
			this->hpPerSize = 1.5;
			this->sugarValuePerSize = 1.5;
			moveSpeedX = -200; moveSpeedY = -200;
			break;
	default: std::cout << "taille d'un ennemi mal initialisée (choisir 's', 'm' ou 'l')" << std::endl; break;
	}
}

Normal::Normal(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {
	hp = 100 * hpPerSize;
	sugarValue = 50 * sugarValuePerSize;                                                        //ICI : VALEUR EN SUCRES DES MONSTRES
}
Shooter::Shooter(float x, float y, char s, sf::RenderWindow &window) : Enemy(x, y, s, window) {
	this->setPosition(sf::Vector2f(window.getSize().x + 100.f, -100.f));
	hp = 150 * hpPerSize;
	sugarValue = 100 * sugarValuePerSize;
	atkPower = 10;
}
Elite::Elite(float x, float y, char s, sf::RenderWindow& window) : Enemy(x, y, s, window) {
	hp = 200 * hpPerSize;
	sugarValue = 150 * sugarValuePerSize;
	atkPower = 20;
}

void Normal::behavior(float timeElapsed) {
	if (hp <= 0) { alive = false; }
	move(moveSpeedX * timeElapsed, 0);
}

void Enemy::dropSugar(std::vector<Sugar*> &vectorSugar, Enemy &enemy) {
	if (!alive && !dropedSugar) {
		dropedSugar = true;
		Sugar* sugar = new Sugar;
		sugar->setValue(sugarValue);
		sugar->setPosition(enemy.getPosition().x - (enemy.getLocalBounds().width * enemy.getScale().x) / 2,
			enemy.getPosition().y + (enemy.getLocalBounds().height * enemy.getScale().y) / 2 - (sugar->getLocalBounds().height * sugar->getScale().y) / 2);
		switch (getSize()) {
		case 's': sugar->setScale(0.05f, 0.05f); break;
		case 'm': sugar->setScale(0.08f, 0.08f); break;
		case 'l': sugar->setScale(0.11f, 0.11f); break;
		}
		vectorSugar.push_back(sugar);
	}
}

void Shooter::behavior(float timeElapsed, std::vector<Shooter>& vectorShooter, std::vector<sf::Vector2f>& shooterPositions, 
	std::vector<Projectile*>& projectiles, std::vector<bool>& positionsOccupied){

	if (hp <= 0) { alive = false; }

	int counter(0);
	possiblePositions = shooterPositions;
	while (!positionFound || waitingForPosition) {
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
		randomPositionChoice = rand() % shooterPositions.size();
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
				projectile->setAtkPower(atkPower);
				switch (getSize()) {
				case 's': projectile->setScale(0.05f, 0.05f); break;
				case 'm': projectile->setScale(0.10f, 0.10f); break;
				case 'l': projectile->setScale(0.15f, 0.15f); break;
				}
				projectile->setPosition(getPosition().x - (getLocalBounds().width * getScale().x) / 2, 
					getPosition().y + (getLocalBounds().height * getScale().y) / 2 - (projectile->getLocalBounds().height * projectile->getScale().y) / 2);
				projectiles.push_back(projectile);
				shootCooldown = 0;
			}
			else { shootCooldown += timeElapsed; }
		}
	}
}

void Elite::behavior(float timeElapsed, sf::CircleShape player, std::vector<Projectile*> &projectiles, sf::RenderWindow &window) 
{
	if (hp <= 0) { alive = false; }
	
	//pour tracker le personnage après un délai
	//GAUCHE DROITE
	playerPosition = { player.getPosition().x + (player.getLocalBounds().width * player.getScale().x) / 2 - (getLocalBounds().width * getScale().x) / 2,
		player.getPosition().y + (player.getLocalBounds().height * player.getScale().y) / 2 - (getLocalBounds().height * getScale().y) / 2 };

	if (getPosition().x <= window.getSize().x && getPosition().x >= 0) {
		if (getPosition().x < window.getSize().x / 2 + getLocalBounds().width * getScale().x) {
			if (size == 's')
				setPosition(window.getSize().x / 2 + 50.f, getPosition().y);
			if (size == 'm')
				setPosition(window.getSize().x / 2 + 65.f, getPosition().y);
			if (size == 'l')
				setPosition(window.getSize().x / 2 + 95.f, getPosition().y);

			moveSpeedX = -moveSpeedX;
		}
		else if (getPosition().x > window.getSize().x - getLocalBounds().width * getScale().x) {
			if (size == 's')
				setPosition(window.getSize().x - 50.f, getPosition().y);
			if (size == 'm') 
				setPosition(window.getSize().x - 65.f, getPosition().y);
			if (size == 'l')
				setPosition(window.getSize().x - 95.f, getPosition().y);

			moveSpeedX = -moveSpeedX;
		}
	}
	move(moveSpeedX* timeElapsed, 0);
	
	//SUIVRE LE JOUEUR SUR L'AXE Y
	if ((getPosition().y - playerPosition.y > 10.f || getPosition().y - playerPosition.y < -10.f))
		trackCooldown += timeElapsed; //set un chrono

	if (trackCooldown > 1.f) { //à varier selon l'agressivité voulue
		if ((getPosition().y - playerPosition.y <= 10.f && getPosition().y - playerPosition.y >= -10.f)) {
			trackCooldown = 0;
		}

		else if (getPosition().y > playerPosition.y) {
			if (getPosition().y - playerPosition.y > 10.f)
				move(0, moveSpeedY * timeElapsed);
			else { move(0, -1 * timeElapsed); }
		}
		else if (getPosition().y < playerPosition.y) {
			if (playerPosition.y - getPosition().y > 10.f)
				move(0, -moveSpeedY * timeElapsed);
			else { move(0, 1 * timeElapsed); }
		}
	}
	//TIRER
	if (shootCooldown >= 1.f) {
		Projectile* projectile = new Projectile;
		projectile->setId(getId());
		projectile->setAtkPower(atkPower);
		switch (getSize()) {
		case 's': projectile->setScale(0.05f, 0.05f); break;
		case 'm': projectile->setScale(0.10f, 0.10f); break;
		case 'l': projectile->setScale(0.15f, 0.15f); break;
		}
		projectile->setPosition(getPosition().x - (getLocalBounds().width * getScale().x) / 2,
			getPosition().y + (getLocalBounds().height * getScale().y) / 2 - (projectile->getLocalBounds().height * projectile->getScale().y) / 2);
		projectiles.push_back(projectile);
		shootCooldown = 0;
	}
	else { shootCooldown += timeElapsed; }
}