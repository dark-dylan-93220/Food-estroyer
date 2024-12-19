#include "game.h"
#include "enemy.h"
#include "player.h"

Enemy::Enemy(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture) : size(s) {
	this->setPosition(x, y);
	this->setTexture(texture);
	// Valeurs à changer en pourcentage de taille de la fenêtre.
	switch (s) {
	case ('s'):
		this->setScale(0.09f, 0.09f);
		this->hpPerSize = 0.5f;
		this->atkPowerPerSize = 0.5f;
		this->sugarValuePerSize = 0.5f;
		moveSpeedX = -400; moveSpeedY = -400;
		break;
	case('m'):
		this->setScale(0.13f, 0.13f);
		this->hpPerSize = 1.f;
		this->atkPowerPerSize = 1.f;
		this->sugarValuePerSize = 1.f;
		moveSpeedX = -300; moveSpeedY = -300;
		break;
	case('l'):
		this->setScale(0.19f, 0.19f);
		this->hpPerSize = 1.5f;
		this->atkPowerPerSize = 1.5f;
		this->sugarValuePerSize = 1.5f;
		moveSpeedX = -200; moveSpeedY = -200;
		break;
	default: std::cout << "taille d'un ennemi mal initialisée (choisir 's', 'm' ou 'l')" << std::endl; break;
	}
}
Enemy::Enemy() {}

Normal::Normal(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture) : Enemy(x, y, s, window, texture) {
	hp = 100 * hpPerSize;
	sugarValue = int(/*50*/200 * sugarValuePerSize);                                                        //ICI : VALEUR EN SUCRES DES MONSTRES
	atkPower = 30 * atkPowerPerSize; 
	this->setTexture(texture);
}
//COMPORTEMENT DE BASE
//Shooter::Shooter(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture) : Enemy(x, y, s, window, texture) {
//	this->setPosition(sf::Vector2f(window.getSize().x + 100.f, -100.f));
//	hp = 150 * hpPerSize;
//	sugarValue = int(100 * sugarValuePerSize);
//	atkPower = 15 * atkPowerPerSize;
//	this->setTexture(texture);
//}

//NOUVEAU COMPORTEMENT
Shooter::Shooter(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture, Player& player) : Enemy(x, y, s, window, texture) {
	//this->setPosition(sf::Vector2f(window.getSize().x + (getLocalBounds().width * getScale().x), player.getPosition().y + player.getRadius() - (getLocalBounds().height * getScale().y) / 2));
	hp = 150 * hpPerSize;
	sugarValue = int(/*100*/50 * sugarValuePerSize);
	atkPower = 15 * atkPowerPerSize;
	this->setTexture(texture);
}
Elite::Elite(float x, float y, char s, sf::RenderWindow& window, sf::Texture& texture) : Enemy(x, y, s, window, texture) {
	hp = /*200*/50 * hpPerSize;
	sugarValue = int(/*150*/100 * sugarValuePerSize);
	atkPower = 20 * atkPowerPerSize;
	this->setTexture(texture);
}
Boss::Boss() {
	hp = 10000;
	atkPower = 20;
	sugarValue = 5000;
	moveSpeedY = 0;
}
Projectile::Projectile() {
	if (id == "boss") speedY = 100.f /*/ 1080.f*/;
}

void Enemy::dropSugar(std::vector<Sugar*>& vectorSugar, Enemy& enemy) {
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

void Normal::behavior(float timeElapsed, std::vector<Normal>& vectorNormal, sf::RenderWindow &window) {
	if (hp <= 0 || getPosition().x < -(getLocalBounds().width * getScale().x)) { alive = false; }
	move(moveSpeedX * timeElapsed, 0);
}

//COMPORTEMENT DE BASE
//void Shooter::behavior(float timeElapsed,  std::vector<Shooter>& vectorShooter, std::vector<sf::Vector2f>& shooterPositions, 
//	std::vector<Projectile*>& vectorProjectile, std::vector<bool>& positionsOccupied, sf::RenderWindow& window) {
//
//	if (hp <= 0) { alive = false; }
//
//	int counter(0);
//	possiblePositions = shooterPositions;
//	while (!positionFound || waitingForPosition) {
//		for (int i = 0; i < 15; ++i) {
//			if (positionsOccupied[i] == true) {
//				counter++;
//			}
//		}
//		if (counter == 15) {
//			positionChoice = { 9999.f,9999.f };
//			positionFound = true;
//			waitingForPosition = false;
//			counter = 0;
//		}
//		randomPositionChoice = rand() % shooterPositions.size();
//		if (positionsOccupied[randomPositionChoice] == false) {
//			positionFound = true;
//			waitingForPosition = false;
//			positionsOccupied[randomPositionChoice] = true;
//			positionChoice = possiblePositions[randomPositionChoice];
//		}
//	}
//	// REDUCE SPEED IF SHOOTER IS APPROACHING POSITION
//	if (positionFound == true && waitingForPosition == false) {
//		if (positionChoice.x > getPosition().x) {
//			if (positionChoice.x - getPosition().x <= 20)
//				moveDirX = 1;
//			else { moveDirX = 3; }
//		}
//		if (positionChoice.x < getPosition().x) {
//			if (getPosition().x - positionChoice.x <= 20)
//				moveDirX = 1;
//			else { moveDirX = 3; }
//		}
//		if (positionChoice.y > getPosition().y) {
//			if (positionChoice.y - getPosition().y <= 20)
//				moveDirY = 1;
//			else { moveDirY = 3; }
//		}
//		if (positionChoice.y < getPosition().y) {
//			if (getPosition().y - positionChoice.y <= 20)
//				moveDirY = 1;
//			else { moveDirY = 3; }
//		}
//
//		if (positionChoice.x < getPosition().x) moveDirX = -moveDirX;
//		if (positionChoice.x > getPosition().x) moveDirX = moveDirX;
//		if (positionChoice.y < getPosition().y) moveDirY = -moveDirY;
//		if (positionChoice.y > getPosition().y) moveDirY = moveDirY;
//		if (getPosition().x - positionChoice.x > 3.f && !positionReached)
//			move((moveDirX * 100) * timeElapsed, 0);
//		if (positionChoice.y - getPosition().y > 3.f && !positionReached)
//			move(0, (moveDirY * 100) * timeElapsed);
//		if (!(getPosition().x - positionChoice.x > 3.f) && !(positionChoice.y - getPosition().y > 3.f))
//		{
//			//Center shooter position in relation to his size
//			positionReached = true;
//			if (positionReached) {
//				if (getPosition().x - targetPosition.x > 3.f)
//					move((moveDirX * 10) * timeElapsed, 0);
//				if (targetPosition.y - getPosition().y > 3.f)
//					move(0, (moveDirY * 10) * timeElapsed);
//			}
//			// Shoots here
//			if (shootCooldown >= 1.5f) { // ici : varier le nombre de boucle pour que les ennemis shoot +ou- vite - A remplacer par une durée de temps variable
//				Projectile* projectile = new Projectile;
//				projectile->setId(getId());
//				projectile->setAtkPower(atkPower);
//				switch (getSize()) {
//				case 's': projectile->setScale(0.05f, 0.05f); break;
//				case 'm': projectile->setScale(0.10f, 0.10f); break;
//				case 'l': projectile->setScale(0.15f, 0.15f); break;
//				}
//				projectile->setPosition(getPosition().x - (getLocalBounds().width * getScale().x) / 2,
//					getPosition().y + (getLocalBounds().height * getScale().y) / 2 - (projectile->getLocalBounds().height * projectile->getScale().y) / 2);
//				vectorProjectile.push_back(projectile);
//				shootCooldown = 0;
//			}
//			else { shootCooldown += timeElapsed; }
//		}
//	}
//}

//NOUVEAU COMPORTEMENT
void  Shooter::behavior(float timeElapsed, std::vector<Shooter>& vectorShooters, std::vector<Projectile*>& vectorProjectile, sf::RenderWindow& window) {
	if (hp <= 0 || getPosition().x < -(getLocalBounds().width * getScale().x)) { alive = false; }
	move(moveSpeedX * 0.25 * timeElapsed, 0);
	if (shootCooldown >= 3.f) {
		Projectile* projectile = new Projectile;
		projectile->setId(getId());
		projectile->setAtkPower(atkPower);
		switch (getSize()) {
		case 's': projectile->setScale(0.08f, 0.08f); break;
		case 'm': projectile->setScale(0.12f, 0.12f); break;
		case 'l': projectile->setScale(0.15f, 0.15f); break;
		}
		projectile->setPosition(getPosition().x - (getLocalBounds().width * getScale().x) / 2,
			getPosition().y + (getLocalBounds().height * getScale().y) / 2 - (projectile->getLocalBounds().height * projectile->getScale().y) / 2);
		vectorProjectile.push_back(projectile);
		shootCooldown = 0;
	}
	else { shootCooldown += timeElapsed; }
}

void Elite::behavior(float timeElapsed, Player &player, std::vector<Projectile*>& vectorProjectile, sf::RenderWindow& window)
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
	move(moveSpeedX * timeElapsed, 0);

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
	if (shootCooldown >= /*1.f*/2.f) {
		Projectile* projectile = new Projectile;
		projectile->setId(getId());
		projectile->setAtkPower(atkPower);
		switch (getSize()) {
		case 's': projectile->setScale(0.08f, 0.08f); break;
		case 'm': projectile->setScale(0.12f, 0.12f); break;
		case 'l': projectile->setScale(0.15f, 0.15f); break;
		}
		projectile->setPosition(getPosition().x - (getLocalBounds().width * getScale().x) / 2,
			getPosition().y + (getLocalBounds().height * getScale().y) / 2 - (projectile->getLocalBounds().height * projectile->getScale().y) / 2);
		vectorProjectile.push_back(projectile);
		shootCooldown = 0;
	}
	else { shootCooldown += timeElapsed; }
}

bool Sugar::behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Sugar*>& vectorSugar) {
	if (state) {
		move(-300 * timeElapsed, 0);
		if (getPosition().x < 0 - 100.f/*(vectorSugar[i]->getLocalBounds().width * vectorSugar[i]->getScale().x)*/)
			state = false;
		return true;
	}
	else { return  false; }
}

bool Projectile::behavior(float timeElapsed, sf::RenderWindow& window, std::vector<Projectile*>& vectorProjectiles, Player &player) {
	if (state) {
		if (getId() != "bossSpecial") {
			move(speedX /** window.getSize().x */ * timeElapsed, speedY /** window.getSize().y */ * timeElapsed);

			if (getId() == "bossLeft") {
				if (getPosition().x > startPosition.x + window.getSize().y / 2) {
					state = false;
				}
			}
			else if (getId() == "bossUp") {
				if (getPosition().y > startPosition.y + window.getSize().y / 2) {
					state = false;
				}
			}
			else if (getId() == "bossDown") {
				if (getPosition().y < startPosition.y - window.getSize().y / 2) {
					state = false;
				}
			}
		}
		else {
			if (getPosition().y > player.getPosition().y + player.getRadius() * 1.5f && getPosition().x + (getLocalBounds().width * getScale().x) > player.getPosition().x)
				speedY = -player.getSpeed() * 0.75f; //la tete chercheuse garde son efficacité peu importe la vitesse du joueur
			else if (getPosition().y < player.getPosition().y + player.getRadius() * 0.5f && getPosition().x + (getLocalBounds().width * getScale().x) > player.getPosition().x)
				speedY = player.getSpeed() * 0.75f;
			else { speedY = 0; }
			
			move(speedX * timeElapsed, speedY * timeElapsed);

			if (getPosition().x < -(getLocalBounds().width * getScale().x))
				state = false;
		}
		return true;
	}
	else { return false; }
}

bool Boss::behavior(float timeElapsed, Player& player, std::vector<Projectile*>& vectorProjectile, sf::RenderWindow& window) {
	if (hp <= 0) { hp = 0; alive = false; }
	if (alive) {

		if (getPosition().x - (getLocalBounds().width * getScale().x) / 2 > window.getSize().x / 1.9) {
			move(moveSpeedX * 0.24 * timeElapsed, moveSpeedY * timeElapsed);
			spawning = true;
		}
		else {
			spawning = false;
			switchCooldown += timeElapsed;
			if (switchCooldown >= 17) switchCooldown = 0; //ALTERNER ENTRE LES DEUX TYPES D'ATTAQUES
			// ATTAQUE NORMALE : EFFET ESSUIE GLACE
			if (shootCooldown >= 0.3 && switchCooldown < 10) {
				updatingSpeedY += updatingSpeedYSetter;
				if (updatingSpeedY >= 400 || updatingSpeedY <= -400) {
					updatingSpeedYSetter = -updatingSpeedYSetter;
				}

				Projectile* projectile1 = new(Projectile);
				projectile1->setId(getId());
				projectile1->setAtkPower(getAtkPower());
				projectile1->setScale(0.15f, 0.15f);
				projectile1->setPosition(getPosition().x - (projectile1->getLocalBounds().width * projectile1->getScale().x) / 2, getPosition().y + (getLocalBounds().height * getScale().y) / 3);
				projectile1->setSpeedX(projectileSpeedX);
				projectile1->setSpeedY(updatingSpeedY);
				vectorProjectile.push_back(projectile1);

				Projectile* projectile2 = new(Projectile);
				projectile2->setId(getId());
				projectile2->setAtkPower(getAtkPower());
				projectile2->setScale(0.15f, 0.15f);
				projectile2->setPosition(getPosition().x - (projectile2->getLocalBounds().width * projectile2->getScale().x) / 2, projectile1->getPosition().y + (getLocalBounds().height * getScale().y) / 3);
				projectile2->setSpeedX(projectileSpeedX);
				projectile2->setSpeedY(-updatingSpeedY);
				vectorProjectile.push_back(projectile2);

				shootCooldown = 0;
			}
			else { shootCooldown += timeElapsed; }

			if (secondCooldown > 0.5 && switchCooldown >= 11 && switchCooldown < 16) { // ATTAQUE NORMALE ALT : CROIX SUR POSITION JOUEUR
				//PROJECTILE DE GAUCHE
				Projectile* projectile1 = new(Projectile);
				projectile1->setId("bossLeft");
				projectile1->setAtkPower(getAtkPower());
				projectile1->setScale(0.15f, 0.15f);
				projectile1->setPosition(player.getPosition().x - (window.getSize().y / 2), player.getPosition().y + player.getRadius() - (projectile1->getLocalBounds().height * projectile1->getScale().y) / 2);
				projectile1->startPosition = projectile1->getPosition();
				projectile1->setSpeedX(-projectileSpeedX);
				vectorProjectile.push_back(projectile1);

				//PROJECTILE DE DROITE
				Projectile* projectile2 = new(Projectile);
				projectile2->setId("bossRight"); //utile uniquement pr le window.draw
				projectile2->setAtkPower(getAtkPower());
				projectile2->setScale(0.15f, 0.15f);
				projectile2->setPosition(player.getPosition().x + (window.getSize().y / 2), player.getPosition().y + player.getRadius() - (projectile2->getLocalBounds().height * projectile2->getScale().y) / 2);
				projectile2->startPosition = projectile2->getPosition();
				projectile2->setSpeedX(projectileSpeedX);
				vectorProjectile.push_back(projectile2);

				//PROJECTILE DU HAUT
				Projectile* projectile3 = new(Projectile);
				projectile3->setId("bossUp");
				projectile3->setAtkPower(getAtkPower());
				projectile3->setScale(0.15f, 0.15f);
				projectile3->setPosition(player.getPosition().x/* + player.getRadius() - (projectile3->getLocalBounds().width * projectile3->getScale().x) / 2*/, player.getPosition().y - (window.getSize().y / 2));
				projectile3->startPosition = projectile3->getPosition();
				projectile3->setSpeedX(0);
				projectile3->setSpeedY(-projectileSpeedX);
				vectorProjectile.push_back(projectile3);

				//PROJECTILE DU BAS
				Projectile* projectile4 = new(Projectile);
				projectile4->setId("bossDown");
				projectile4->setAtkPower(getAtkPower());
				projectile4->setScale(0.15f, 0.15f);
				projectile4->setPosition(player.getPosition().x/* + player.getRadius() - (projectile4->getLocalBounds().width * projectile4->getScale().x) / 2*/, player.getPosition().y + (window.getSize().y / 2));
				projectile4->startPosition = projectile4->getPosition();
				projectile4->setSpeedX(0);
				projectile4->setSpeedY(projectileSpeedX);
				vectorProjectile.push_back(projectile4);

				secondCooldown = 0;
			}
			else { secondCooldown += timeElapsed; }

			// ATTAQUE SPECIALE : TETE CHERCHEUSE
			if (specialCooldown >= 2.7 && switchCooldown < 10) {
				Projectile* projectile = new(Projectile);
				projectile->setId("bossSpecial");
				projectile->setAtkPower(getAtkPower() * 2);
				projectile->setScale(0.3f, 0.3f);
				projectile->setPosition(getPosition().x - (projectile->getLocalBounds().width * projectile->getScale().x) / 2, player.getPosition().y + player.getRadius());
				projectile->setSpeedX(projectileSpeedX * 0.75f);
				vectorProjectile.push_back(projectile);

				specialCooldown = 0;
			}
			else { specialCooldown += timeElapsed; }
		}
		return true;
	}
	else { return false; }
}