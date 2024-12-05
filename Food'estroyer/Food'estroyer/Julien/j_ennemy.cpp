#include "j.game.h"
//#include <SFML/Graphics/RectangleShape.hpp>

//in j.ennemi.h
class Ennemy : public sf::CircleShape {
protected:
	bool alive = true;
	/*float posX, posY;
	float size;*/
	Ennemy();
};

class Normals : public Ennemy {
public:
	Normals();

};

std::vector<sf::RectangleShape> projectiles;

class Shooters : public Ennemy {
public:
	Shooters();
private: 
	void shoot();
};
//no more in j.ennemi.h





Ennemy::Ennemy(float x, float y, float s) : {
	this->setPosition(x, y);
	this->setRadius(s);
}

Shooters::Shooters(float x, float y, float s) : Ennemy(x, y, s) {}

Shooters::shoot() {
	sf::RectangleShape projectile(sf::Vector2f(5, 1));
	projectile.setPosition(posX - size/2, posY);
	projectile.setFillColor(sf::Color::Red);
	projectiles.push_back(projectile);


}

Normals::Normals(float x, float y, float size) : Ennemy(x, y, s) {
	this->setRadius(size);
}

