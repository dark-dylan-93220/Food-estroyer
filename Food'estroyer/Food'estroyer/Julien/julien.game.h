#ifndef GAME_H
#define GAME_H

// --- STL --- //
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
// --- SFML --- //
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game {
public:

	Game();

	void run();

private:

	bool m_isRunning;
	sf::WindowBase windowBase;
	sf::RenderWindow window;
	bool startUpScreenOn = true;

private:
	void setupGraphicalElements();
	void pollEvents();
	void update();
	void render();

};

#endif // !GAME_H