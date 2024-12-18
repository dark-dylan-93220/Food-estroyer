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
	const float levelOneDuration = 20.f; // 2:00
	const float levelTwoDuration = 124.f; // 2:04
	const float levelThreeDuration = 122.f; // 2:02
	float levelProgression = 0.f;   // augmente au fur et à mesure de l'avancement dans le niveau
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
	int numberOfStartingEnnemies = 7;
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
	void setEnemySpawn(int numberOfEnnemies, bool bonus = false);
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
	void statCalculation();
	// Main loop
	void pollEvents();
	void update();
	void render();

};

#endif // !GAME_H