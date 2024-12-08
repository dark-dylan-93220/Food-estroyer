#include "game.h"
#include "enemy.h"

//sf::Clock Clock;
//std::chrono::steady_clock::time_point beginTime = std::chrono::high_resolution_clock::now();
//std::chrono::duration<float> timeElapsed;

Enemy::Enemy(float x, float y, char s) : size(s){
	this->setPosition(x, y);
	if (s == 's') this->setRadius(10);
	else if (s == 'm') this->setRadius(30);
	else if (s == 'l') this->setRadius(50);
}


Normal::Normal(float x, float y, char s) : Enemy(x, y, s) {}

void Normal::behavior() {
	move(-5, 0);
}


Shooter::Shooter(float x, float y, char s) : Enemy(x, y, s) {}

void Shooter::behavior(std::vector<sf::Vector2f>& shooterPositions, 
	std::vector<sf::RectangleShape>& projectiles, std::vector<Shooter>& vectorShooter){
	occupied = shooterPositions;
	while (!pFound || pWait) {
		pFound = true;
		pWait = false;
		index = rand() % occupied.size();
		pChoice = occupied[index];
		if(vectorShooter.size() > 0){
			for (sf::CircleShape& shooter : vectorShooter) {
				if (shooter.getPosition() == pChoice) {
					pFound = false;
				}
			}
		}
		occupied.erase(occupied.begin() + index);       // sortir si aucun des emplacements n'est libre
		if (occupied.size() == 0) {
			pFound = true;
			pWait = true;
		}
	}
	if (pFound == true && pWait == false) {
		//REDUCE SPEED IF SHOOTER IS APPROACHING POSITION
		if (pChoice.x > getPosition().x) {
			if (pChoice.x - getPosition().x <= 20)
				moveDirX = 1;
			else { moveDirX = 3; }
		}
		if (pChoice.x < getPosition().x) {
			if (getPosition().x - pChoice.x <= 20)
				moveDirX = 1;
			else { moveDirX = 3; }
		}
		if (pChoice.y > getPosition().y) {
			if (pChoice.y - getPosition().y <= 20)
				moveDirY = 1;
			else { moveDirY = 3; }
		}
		if (pChoice.y < getPosition().y) {
			if (getPosition().y - pChoice.y <= 20)
				moveDirY = 1;
			else { moveDirY = 3; }
		}
		

		if (pChoice.x < getPosition().x) moveDirX = -moveDirX;
		if (pChoice.x > getPosition().x) moveDirX = moveDirX;
		if (pChoice.x == getPosition().x) moveDirX = 0;
		if (pChoice.y < getPosition().y) moveDirY = -moveDirY;
		if (pChoice.y > getPosition().y) moveDirY = moveDirY;
		if (pChoice.y == getPosition().y) moveDirY = 0.;

		if (getPosition() != pChoice) move(moveDirX, moveDirY);
		else {
			if (shootCD == 100) {                                        //ici : varier le nombre de boucle pour que les ennemis shoot +ou- vite
				sf::RectangleShape projectile(sf::Vector2f(20, 10));
				projectile.setPosition(getPosition().x - getRadius(), getPosition().y + getRadius() - projectile.getSize().y / 2);
				projectile.setFillColor(sf::Color::Yellow);
				projectiles.push_back(projectile);
				shootCD = 0;
			}
			else { shootCD++; }
		}
	}

	
}


Elite::Elite(float x, float y, char s) : Enemy(x, y, s) {}

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
	if (shootCD == 50) {
		sf::RectangleShape projectile(sf::Vector2f(30, 15));
		projectile.setPosition(getPosition().x - getRadius(), getPosition().y + getRadius() - projectile.getSize().y/2);
		projectile.setFillColor(sf::Color::Red);
		projectiles.push_back(projectile);
		shootCD = 0;
	}
	else { shootCD++; }
}







