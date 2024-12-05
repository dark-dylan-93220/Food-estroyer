#include "julien.game.h" //changer en j.game.h après commit

//in j.ennemi.h
class Ennemy : public sf::CircleShape {
protected:
	bool alive = true;
	float posX, posY;
	float size;
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

Ennemy::Ennemy(float x, float y, float s) : posX(x), posY(y), size(s) :

Shooters::Shooters(float x, float y, float s) : Ennemy(x,y,s) {
	this->setRadius(size);
}

Shooters::shoot() {
	sf::RectangleShape projectile(sf::Vector2f(5, 1));
	projectile.setPosition(posX - size/2, posY);
	projectile.setFillColor(sf::Color::Red);


}

Normals::Normals(float x, float y, float size) : Ennemy(x, y, s) {
	this->setRadius(size);
}

