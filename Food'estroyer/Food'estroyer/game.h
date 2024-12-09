#ifndef GAME_H
#define GAME_H

// --- STL --- //
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
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
	// Window
	sf::WindowBase windowBase;
	sf::RenderWindow window;
	// Views
	bool startUpScreenOn = true;
	bool settingsScreenOn = false;
	bool playScreenOn = false;
	// Time gestion
	sf::Clock Clock;
	int currentFramerateLimit = 60;
	float f_ElapsedTime;
	std::chrono::steady_clock::time_point startingTimePoint, currentTimePoint;
	// Language
	std::string language = "EN";
	// Testing
	bool levelOneOn = false;
	bool backgroundActive = true;

private:
	void setupGraphicalElements();
	void setShooterPositions();
	void setEnemySpawn();
	void playerInput();
	void pollEvents();
	void update();
	void render();

};

#endif // !GAME_H