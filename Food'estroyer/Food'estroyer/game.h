#ifndef GAME_H
#define GAME_H

// --- Standard library --- //
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
	sf::RenderWindow window;
	// Views
	bool startUpScreenOn = true;
	bool settingsScreenOn = false;
	bool playScreenOn = false;
	// Time gestion
	int currentFramerateLimit = 60;
	sf::Clock Clock;
	float f_ElapsedTime;
	std::chrono::steady_clock::time_point startingTimePoint, currentTimePoint;
	float spriteUpdateTimer = 0;
	// Language
	std::string language = "EN";
	// Layers
	bool levelOneOn = false;
	bool levelTwoOn = false;
	bool levelThreeOn = false;
	bool backgroundActive = true;
	bool showPauseMenu = false;
	// Ennemies
	std::vector<bool> positionsOccupied;
	int numberOfStartingEnnemies = 5;
	// Testing
	int deathCounter = 0;

private:
	// Loading elements
	void splashScreen();
	void changeLanguages() const;
	void loadStartUpScreen();
	void loadSettings();
	void loadLevelAssets();    // Called once BEFORE laodGameplayAssets()
	void loadGameplayAssets(); // Called multiple times
	void loadTextPositions();
	void loadLevel1();
	void loadLevel2();
	void loadLevel3();
	// Set the game up
	void setShooterPositions();
	void setEnemySpawn();
	// In game collisions & controls
	void playerInput();
	void playerCollisions();
	void playerHPSetter();
	void playerBonusSetter();
	void playerDeath();
	void updateStatsSpritesCooldown();
	void nonPlayerBehavior();
	void nonPlayerDraw();
	void clownWalkAnimation();
	// Parralax backgrounds gestion
	void backgroundMovementLevel1();
	void backgroundMovementLevel2();
	void backgroundMovementLevel3();
	// Calculations
	void scoreCalculation();
	void sugarCalculation();
	void FPSCalculation();
	// Main loop
	void pollEvents();
	void update();
	void render();

};

#endif // !GAME_H