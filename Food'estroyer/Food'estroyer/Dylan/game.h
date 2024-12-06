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
	sf::WindowBase windowBase;
	sf::RenderWindow window;
	bool startUpScreenOn = true;
	bool settingsScreenOn = false;
	sf::Clock Clock;
	int currentFramerateLimit = 60;
	std::string language = "EN";
	float f_ElapsedTime;
	std::chrono::steady_clock::time_point startingTimePoint, currentTimePoint;

private:
	void setupGraphicalElements();
	void pollEvents();
	void update();
	void render();

};

#endif // !GAME_H