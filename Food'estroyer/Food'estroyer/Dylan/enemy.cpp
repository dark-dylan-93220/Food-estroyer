#include "game.h"
#include "enemy.h"

//sf::Clock Clock;
std::vector<sf::RectangleShape> projectiles;
std::vector<sf::CircleShape> vectorShooters;
//std::chrono::steady_clock::time_point beginTime = std::chrono::high_resolution_clock::now();
//std::chrono::duration<float> timeElapsed;

Enemy::Enemy(float x, float y, char s) : size(s){
	this->setPosition(x, y);
	if (s == 's') this->setRadius(10);
	else if (s == 'm') this->setRadius(30);
	else if (s == 'l') this->setRadius(50);
}


Normals::Normals(float x, float y, float s) : Enemy(x, y, s) {}

void Normals::behavior() {
	move(-1, 0);
}


Shooter::Shooter(float x, float y, float s) : Enemy(x, y, s) {}

void Shooter::behavior(std::vector<sf::Vector2f> shooterPositions) { //inverser direction si on touche un bord
	int index;
	occupied = shooterPositions;
	while (!pFound) {
		index = rand() % occupied.size();
		pChoice = occupied[index];
		for (sf::CircleShape &shooter : vectorShooters) {
			if (shooter.getPosition() != pChoice) {
				if (pChoice.x < getPosition().x) moveDirX = -1;
				if (pChoice.x > getPosition().x) moveDirX = 1;
				if (pChoice.y < getPosition().y) moveDirY = -1;
				if (pChoice.y > getPosition().y) moveDirY = 1;
				pFound = true;
			}
		}
		occupied.erase(occupied.begin() + index);
		if (occupied.size() == 0) pFound = true;         // sortir si aucun des emplacements n'est libre
	}

	if(getPosition() != pChoice) move(moveDirX, moveDirY);
	else {
		if (shootCD == 20) {                                                 //ici : varier le nombre de boucle pour que les ennemis shoot +ou- vite
			sf::RectangleShape projectile(sf::Vector2f(5, 1));
			projectile.setPosition(getPosition().x - getRadius(), getPosition().y);
			projectile.setFillColor(sf::Color::Yellow);
			projectiles.push_back(projectile);
			shootCD = 0;
		}
		else { shootCD++; }
	}
}


Elite::Elite(float x, float y, float s) : Enemy(x, y, s) {}

void Elite::behavior(sf::CircleShape player){ //pour tracker le personnage après un délai
	if (getPosition().y > player.getPosition().y || getPosition().y < player.getPosition().y) {
		trackCooldown++;
	}
	if (trackCooldown > 10) { //à varier selon l'agressivité voulue
		if (getPosition().y > player.getPosition().y) move(-1, 0);
		else if (getPosition().y < player.getPosition().y) move(1, 0);
		else { trackCooldown = 0; }
	} 
	sf::RectangleShape projectile(sf::Vector2f(5, 1));
	projectile.setPosition(getPosition().x - getRadius(), getPosition().y);
	projectile.setFillColor(sf::Color::Red);
	projectiles.push_back(projectile);
}







