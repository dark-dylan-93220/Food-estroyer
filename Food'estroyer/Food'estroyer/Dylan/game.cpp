#include "game.h"
#include "enemy.h"

/// THIS FILE CONTAINS THE GLOBAL FUNCTIONS USED EVERYWHERE IN THE GAME

namespace { // GLOBAL VARIABLES OF THIS FILE HERE
	// DATA STL (STandard Library)
	int mouseLastDownX, mouseLastDownY;
	bool isMouseDragging;
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes(); // Gets the native resolutions of the machine this program is running on
	// CURSORS
	sf::Cursor pie;
	// COLORS
	sf::Color DARK_THEME;
	sf::Color LIGHT_GRAY;
	sf::Color LIGHT_RED;
	sf::Color LIGHT_GREEN;
	sf::Color LIGHT_YELLOW;
	// FONTS
	sf::Font FPSFont;
	sf::Font puppy;
	sf::Font alien;
	sf::Font graffitiBorders;
	sf::Font graffitiNoBorders;
	sf::Font score;
	sf::Font scoreBold;
	// TEXTS
	// FPS
	sf::Text FPSText;
	// Start-up screen
	sf::Text playText;
	sf::Text shopText;
	sf::Text quitText;
	sf::Text copyright;
	// Options screen
	sf::Text pauseTopBarResolutionText;
	sf::Text pauseTopBarFPSText;
	sf::Text pauseTopBarColorThemeText;
	sf::Text pauseTopBarLanguageText;
	sf::Text pauseResolutionMode0Text;
	sf::Text pauseResolutionMode1Text;
	sf::Text pauseResolutionMode2Text;
	sf::Text pauseResolutionMode3Text;
	sf::Text pauseResolutionMode4Text;
	sf::Text pauseResolutionMode5Text;
	sf::Text pauseResolutionMode6Text;
	sf::Text pauseResolutionMode7Text;
	sf::Text pauseResolutionMode8Text;
	sf::Text pauseResolutionMode9Text;
	sf::Text pauseResolutionMode10Text;
	sf::Text pauseFPS60Text;
	sf::Text pauseFPS120Text;
	sf::Text pauseFPS240Text;
	sf::Text pauseFPS360Text;
	sf::Text pauseFPSVsyncText;
	sf::Text pauseFPSMaxText;
	sf::Text pauseLanguageFRText;
	sf::Text pauseLanguageENText;
	// MUSICS
	// SOUNDS
	// IMAGES
	sf::Image pieCursorImg;
	// TEXTURES
	sf::Texture settingsIcon;
	sf::Texture bgStartUpScreen;
	sf::Texture levelOneParralax01;
	sf::Texture levelOneParralax02;
	sf::Texture levelOneParralax03;
	sf::Texture levelOneParralax04;
	sf::Texture levelOneParralax05;
	sf::Texture levelOneParralax06;
	// SHAPES
	sf::RectangleShape screenShadowWhenBlured;
	sf::RectangleShape menuPauseTopBar; 
	sf::RectangleShape menuPauseTopBarResolution;
	sf::RectangleShape menuPauseTopBarFPS;
	sf::RectangleShape menuPauseTopBarColorTheme;
	sf::RectangleShape menuPauseTopBarLanguage;
	sf::RectangleShape menuPauseContent;
	sf::RectangleShape menuPauseResolutionPickingBox;
	sf::RectangleShape menuPauseFPSPickingBox;
	sf::RectangleShape menuPauseFPS60;
	sf::RectangleShape menuPauseFPS120;
	sf::RectangleShape menuPauseFPS240;
	sf::RectangleShape menuPauseFPS360;
	sf::RectangleShape menuPauseColorThemeSelectionBox;
	sf::RectangleShape menuPauseLanguageSelectionBox;
	sf::RectangleShape menuPauseLanguageFR;
	sf::RectangleShape menuPauseLanguageEN;
	// SPRITES
	sf::Sprite bgStartUpScreenSprite;
	sf::Sprite settingsIconSprite;
	sf::Sprite levelOneBackgroundStartSprite;
	sf::Sprite levelOneParralax01Sprite;
	sf::Sprite levelOneParralax02Sprite;
	sf::Sprite levelOneParralax03Sprite;
	sf::Sprite levelOneParralax04Sprite;
	sf::Sprite levelOneParralax05Sprite;
}

Game::Game() :
	windowBase(sf::VideoMode(modes[0].width, modes[0].height), "Base"),     // To get relative positions to the native resolution if needed
	window    (sf::VideoMode(modes[0].width, modes[0].height), "Food'estroyer", sf::Style::Fullscreen)
{
	f_ElapsedTime = 0.f;
	m_isRunning = true;
	windowBase.setVisible(false);
	window.setFramerateLimit(60);
	startingTimePoint = std::chrono::high_resolution_clock::now();
	currentTimePoint = startingTimePoint;
}

void Game::setupGraphicalElements() {
	// COLORS
	DARK_THEME = sf::Color(30, 30, 30);
	LIGHT_GRAY = sf::Color(175, 175, 175);
	LIGHT_RED = sf::Color(230, 30, 30);
	LIGHT_GREEN = sf::Color(30, 230, 20);
	LIGHT_YELLOW = sf::Color(238, 255, 0);
	// FONTS
	FPSFont.loadFromFile          ("Dylan/Assets/Fonts/FPS.TTF");
	puppy.loadFromFile            ("Dylan/Assets/Fonts/FriskyPuppy.ttf");
	alien.loadFromFile            ("Dylan/Assets/Fonts/alienAlphabet.ttf");
	graffitiBorders.loadFromFile  ("Dylan/Assets/Fonts/graffitiBorders.otf");
	graffitiNoBorders.loadFromFile("Dylan/Assets/Fonts/graffitiNoBorders.ttf");
	score.loadFromFile            ("Dylan/Assets/Fonts/score.TTF");
	scoreBold.loadFromFile        ("Dylan/Assets/Fonts/scoreBold.TTF");
	// MUSICS
	// SOUNDS
	// IMAGES
	pieCursorImg.loadFromFile("Dylan/Assets/Images/pieCursor.png");
	window.setIcon(pieCursorImg.getSize().x, pieCursorImg.getSize().y, pieCursorImg.getPixelsPtr());
	// TEXTURES
	bgStartUpScreen.loadFromFile("Dylan/Assets/Images/bgStartUpScreen.jpg");
	settingsIcon.loadFromFile("Dylan/Assets/Images/settingsIcon.png");
	levelOneParralax01.loadFromFile("Dylan/Assets/Images/Level1/level1Background01.png");
	levelOneParralax02.loadFromFile("Dylan/Assets/Images/Level1/level1Background02.png");
	levelOneParralax03.loadFromFile("Dylan/Assets/Images/Level1/level1Background03.png");
	levelOneParralax04.loadFromFile("Dylan/Assets/Images/Level1/level1Background04.png");
	levelOneParralax05.loadFromFile("Dylan/Assets/Images/Level1/level1Background05.png");
	levelOneParralax06.loadFromFile("Dylan/Assets/Images/Level1/level1Background06.png");
	// SHAPES
	screenShadowWhenBlured.setSize(sf::Vector2f(window.getSize()));
	screenShadowWhenBlured.setPosition(0.f, 0.f);
	screenShadowWhenBlured.setFillColor(sf::Color(64, 64, 64, 125));
	menuPauseTopBar.setSize(sf::Vector2f((window.getSize().x * 0.66f), (window.getSize().y * 0.1f)));
	menuPauseTopBar.setPosition(sf::Vector2f((window.getSize().x * 0.5f) - (menuPauseTopBar.getLocalBounds().width * 0.5f), (window.getSize().y * 0.1f)));
	menuPauseTopBar.setFillColor(sf::Color(200, 200, 200, 200));
	menuPauseTopBar.setOutlineThickness(2.f);
	menuPauseTopBar.setOutlineColor(sf::Color::Black);
	menuPauseTopBarResolution.setSize(sf::Vector2f(menuPauseTopBar.getSize().x / 4.f, menuPauseTopBar.getSize().y));
	menuPauseTopBarResolution.setPosition(menuPauseTopBar.getPosition());
	menuPauseTopBarResolution.setFillColor(sf::Color::Transparent);
	menuPauseTopBarFPS.setSize(menuPauseTopBarResolution.getSize());
	menuPauseTopBarFPS.setPosition(sf::Vector2f(menuPauseTopBarResolution.getPosition().x + menuPauseTopBarResolution.getLocalBounds().width, menuPauseTopBar.getPosition().y));
	menuPauseTopBarFPS.setFillColor(sf::Color::Transparent);
	menuPauseTopBarColorTheme.setSize(menuPauseTopBarResolution.getSize());
	menuPauseTopBarColorTheme.setPosition(sf::Vector2f(menuPauseTopBarFPS.getPosition().x + menuPauseTopBarFPS.getLocalBounds().width, menuPauseTopBar.getPosition().y));
	menuPauseTopBarColorTheme.setFillColor(sf::Color::Transparent);
	menuPauseTopBarLanguage.setSize(menuPauseTopBarResolution.getSize());
	menuPauseTopBarLanguage.setPosition(sf::Vector2f(menuPauseTopBarColorTheme.getPosition().x + menuPauseTopBarColorTheme.getLocalBounds().width, menuPauseTopBar.getPosition().y));
	menuPauseTopBarLanguage.setFillColor(sf::Color::Transparent);
	menuPauseContent.setSize(sf::Vector2f((window.getSize().x * 0.66f), (window.getSize().y * 0.65f)));
	menuPauseContent.setPosition(sf::Vector2f(menuPauseTopBar.getPosition().x, menuPauseTopBar.getPosition().y + menuPauseTopBar.getLocalBounds().height + (window.getSize().y * 0.05f)));
	menuPauseContent.setFillColor(sf::Color(200,200,200,200));
	menuPauseContent.setOutlineThickness(2.f);
	menuPauseContent.setOutlineColor(sf::Color::Black);
	// SPRITES
	bgStartUpScreenSprite.setTexture(bgStartUpScreen);
	bgStartUpScreenSprite.setScale(sf::Vector2f((window.getSize().x / bgStartUpScreenSprite.getLocalBounds().width), (window.getSize().y / bgStartUpScreenSprite.getLocalBounds().height)));
	bgStartUpScreenSprite.setPosition(sf::Vector2f(0,0));
	settingsIconSprite.setTexture(settingsIcon);
	settingsIconSprite.setPosition(sf::Vector2f(20.f, 20.f));
	// TEXTS
	// FPS
	FPSText.setFont(FPSFont);
	FPSText.setCharacterSize(12);
	FPSText.setFillColor(sf::Color::Black);
	FPSText.setString("FPS : 60.00");
	FPSText.setPosition(sf::Vector2f((window.getSize().x / 2) - (FPSText.getLocalBounds().width / 2), FPSText.getLocalBounds().height));
	playText.setFont(puppy);
	playText.setCharacterSize(40);
	if (language == "EN")
		playText.setString("Play");
	else if (language == "FR")
		playText.setString("Jouer");
	playText.setFillColor(sf::Color::White);
	playText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (playText.getLocalBounds().width / 2)), (window.getSize().y / 2) - 70.f));
	playText.setOutlineThickness(1);
	playText.setOutlineColor(sf::Color(DARK_THEME));
	shopText.setFont(puppy);
	shopText.setCharacterSize(40);
	if (language == "EN")
		shopText.setString("Shop");
	else if (language == "FR")
		shopText.setString("Boutique");
	shopText.setFillColor(sf::Color::White);
	shopText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (shopText.getLocalBounds().width / 2)), (window.getSize().y / 2)));
	shopText.setOutlineThickness(1);
	shopText.setOutlineColor(sf::Color(DARK_THEME));
	quitText.setFont(puppy);
	quitText.setCharacterSize(40);
	if (language == "EN")
		quitText.setString("Quit");
	else if (language == "FR")
		quitText.setString("Quitter");
	quitText.setFillColor(sf::Color::White);
	quitText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (quitText.getLocalBounds().width / 2)), (window.getSize().y / 2) + 70.f));
	quitText.setOutlineThickness(1);
	quitText.setOutlineColor(sf::Color(DARK_THEME));
	copyright.setFont(puppy);
	copyright.setCharacterSize(23);
	copyright.setString("Dylan Hollemaert & Julien Rodrigues | 2024");
	copyright.setFillColor(sf::Color::White);
	copyright.setOutlineThickness(1);
	copyright.setOutlineColor(sf::Color(DARK_THEME));
	copyright.setPosition(sf::Vector2f(((window.getSize().x / 2) - (copyright.getLocalBounds().width / 2)), window.getSize().y - 45.f));
	// Settings menu
	pauseTopBarResolutionText.setFont(puppy);
	pauseTopBarResolutionText.setCharacterSize(40);
	if (language == "EN")
		pauseTopBarResolutionText.setString("Resolution");
	else if (language == "FR")
		pauseTopBarResolutionText.setString("Résolution");
	pauseTopBarResolutionText.setFillColor(sf::Color::White);
	pauseTopBarResolutionText.setPosition(sf::Vector2f(menuPauseTopBarResolution.getPosition().x + (menuPauseTopBarResolution.getLocalBounds().width * 0.5f) - (pauseTopBarResolutionText.getLocalBounds().width * 0.5f) - 8.f, menuPauseTopBarResolution.getPosition().y + (menuPauseTopBarResolution.getLocalBounds().height * 0.5f) - (pauseTopBarResolutionText.getLocalBounds().height * 0.5f) - 8.f));
	pauseTopBarResolutionText.setOutlineThickness(1);
	pauseTopBarResolutionText.setOutlineColor(sf::Color(DARK_THEME));
	pauseTopBarFPSText.setFont(puppy);
	pauseTopBarFPSText.setCharacterSize(40);
	pauseTopBarFPSText.setString("FPS");
	pauseTopBarFPSText.setFillColor(sf::Color::White);
	pauseTopBarFPSText.setPosition(sf::Vector2f(menuPauseTopBarFPS.getPosition().x + (menuPauseTopBarFPS.getLocalBounds().width * 0.5f) - (pauseTopBarFPSText.getLocalBounds().width * 0.5f) - 8.f, pauseTopBarResolutionText.getPosition().y));
	pauseTopBarFPSText.setOutlineThickness(1);
	pauseTopBarFPSText.setOutlineColor(sf::Color(DARK_THEME));
	pauseTopBarColorThemeText.setFont(puppy);
	pauseTopBarColorThemeText.setCharacterSize(40);
	if (language == "EN")
		pauseTopBarColorThemeText.setString("Theme");
	else if (language == "FR")
		pauseTopBarColorThemeText.setString("Thème");
	pauseTopBarColorThemeText.setFillColor(sf::Color::White);
	pauseTopBarColorThemeText.setPosition(sf::Vector2f(menuPauseTopBarColorTheme.getPosition().x + (menuPauseTopBarColorTheme.getLocalBounds().width * 0.5f) - (pauseTopBarColorThemeText.getLocalBounds().width * 0.5f) - 8.f, pauseTopBarResolutionText.getPosition().y));
	pauseTopBarColorThemeText.setOutlineThickness(1);
	pauseTopBarColorThemeText.setOutlineColor(sf::Color(DARK_THEME));
	pauseTopBarLanguageText.setFont(puppy);
	pauseTopBarLanguageText.setCharacterSize(40);
	if (language == "EN")
		pauseTopBarLanguageText.setString("Language");
	else if (language == "FR")
		pauseTopBarLanguageText.setString("Langue");
	pauseTopBarLanguageText.setFillColor(sf::Color::White);
	pauseTopBarLanguageText.setPosition(sf::Vector2f(menuPauseTopBarLanguage.getPosition().x + (menuPauseTopBarLanguage.getLocalBounds().width * 0.5f) - (pauseTopBarLanguageText.getLocalBounds().width * 0.5f) - 8.f, pauseTopBarResolutionText.getPosition().y));
	pauseTopBarLanguageText.setOutlineThickness(1);
	pauseTopBarLanguageText.setOutlineColor(sf::Color(DARK_THEME));
	// Content
	pauseResolutionMode0Text.setFont (puppy);
	pauseResolutionMode1Text.setFont (puppy);
	pauseResolutionMode2Text.setFont (puppy);
	pauseResolutionMode3Text.setFont (puppy);
	pauseResolutionMode4Text.setFont (puppy);
	pauseResolutionMode5Text.setFont (puppy);
	pauseResolutionMode6Text.setFont (puppy);
	pauseResolutionMode7Text.setFont (puppy);
	pauseResolutionMode8Text.setFont (puppy);
	pauseResolutionMode9Text.setFont (puppy);
	pauseResolutionMode10Text.setFont(puppy);
	pauseResolutionMode0Text.setString (std::to_string(modes[0].width) +  "x" + std::to_string(modes[0].height));
	pauseResolutionMode1Text.setString (std::to_string(modes[1].width) +  "x" + std::to_string(modes[1].height));
	pauseResolutionMode2Text.setString (std::to_string(modes[2].width) +  "x" + std::to_string(modes[2].height));
	pauseResolutionMode3Text.setString (std::to_string(modes[3].width) +  "x" + std::to_string(modes[3].height));
	pauseResolutionMode4Text.setString (std::to_string(modes[4].width) +  "x" + std::to_string(modes[4].height));
	pauseResolutionMode5Text.setString (std::to_string(modes[5].width) +  "x" + std::to_string(modes[5].height));
	pauseResolutionMode6Text.setString (std::to_string(modes[6].width) +  "x" + std::to_string(modes[6].height));
	pauseResolutionMode7Text.setString (std::to_string(modes[7].width) +  "x" + std::to_string(modes[7].height));
	pauseResolutionMode8Text.setString (std::to_string(modes[8].width) +  "x" + std::to_string(modes[8].height));
	pauseResolutionMode9Text.setString (std::to_string(modes[9].width) +  "x" + std::to_string(modes[9].height));
	pauseResolutionMode10Text.setString(std::to_string(modes[10].width) + "x" + std::to_string(modes[10].height));
	pauseResolutionMode0Text.setCharacterSize (40);
	pauseResolutionMode1Text.setCharacterSize (40);
	pauseResolutionMode2Text.setCharacterSize (40);
	pauseResolutionMode3Text.setCharacterSize (40);
	pauseResolutionMode4Text.setCharacterSize (40);
	pauseResolutionMode5Text.setCharacterSize (40);
	pauseResolutionMode6Text.setCharacterSize (40);
	pauseResolutionMode7Text.setCharacterSize (40);
	pauseResolutionMode8Text.setCharacterSize (40);
	pauseResolutionMode9Text.setCharacterSize (40);
	pauseResolutionMode10Text.setCharacterSize(40);
	pauseResolutionMode0Text.setFillColor (sf::Color::White);
	pauseResolutionMode1Text.setFillColor (sf::Color::White);
	pauseResolutionMode2Text.setFillColor (sf::Color::White);
	pauseResolutionMode3Text.setFillColor (sf::Color::White);
	pauseResolutionMode4Text.setFillColor (sf::Color::White);
	pauseResolutionMode5Text.setFillColor (sf::Color::White);
	pauseResolutionMode6Text.setFillColor (sf::Color::White);
	pauseResolutionMode7Text.setFillColor (sf::Color::White);
	pauseResolutionMode8Text.setFillColor (sf::Color::White);
	pauseResolutionMode9Text.setFillColor (sf::Color::White);
	pauseResolutionMode10Text.setFillColor(sf::Color::White);
	pauseResolutionMode0Text.setOutlineThickness (1.f);
	pauseResolutionMode1Text.setOutlineThickness (1.f);
	pauseResolutionMode2Text.setOutlineThickness (1.f);
	pauseResolutionMode3Text.setOutlineThickness (1.f);
	pauseResolutionMode4Text.setOutlineThickness (1.f);
	pauseResolutionMode5Text.setOutlineThickness (1.f);
	pauseResolutionMode6Text.setOutlineThickness (1.f);
	pauseResolutionMode7Text.setOutlineThickness (1.f);
	pauseResolutionMode8Text.setOutlineThickness (1.f);
	pauseResolutionMode9Text.setOutlineThickness (1.f);
	pauseResolutionMode10Text.setOutlineThickness(1.f);
	pauseResolutionMode0Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode1Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode2Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode3Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode4Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode5Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode6Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode7Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode8Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode9Text.setOutlineColor (sf::Color(DARK_THEME));
	pauseResolutionMode10Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode0Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.02f)));
	pauseResolutionMode1Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.05f)));
	pauseResolutionMode2Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.08f)));
	pauseResolutionMode3Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.11f)));
	pauseResolutionMode4Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.14f)));
	pauseResolutionMode5Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.17f)));
	pauseResolutionMode6Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.20f)));
	pauseResolutionMode7Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.23f)));
	pauseResolutionMode8Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.26f)));
	pauseResolutionMode9Text.setPosition (sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.29f)));
	pauseResolutionMode10Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.32f)));
	pauseFPS60Text.setFont(puppy);
	pauseFPS120Text.setFont(puppy);
	pauseFPS240Text.setFont(puppy);
	pauseFPS360Text.setFont(puppy);
	pauseFPSVsyncText.setFont(puppy);
	pauseFPSMaxText.setFont(puppy);
	pauseFPS60Text.setCharacterSize(40);
	pauseFPS120Text.setCharacterSize(40);
	pauseFPS240Text.setCharacterSize(40);
	pauseFPS360Text.setCharacterSize(40);
	pauseFPSVsyncText.setCharacterSize(40);
	pauseFPSMaxText.setCharacterSize(40);
	pauseFPS60Text.setOutlineThickness(1);
	pauseFPS120Text.setOutlineThickness(1);
	pauseFPS240Text.setOutlineThickness(1);
	pauseFPS360Text.setOutlineThickness(1);
	pauseFPSVsyncText.setOutlineThickness(1);
	pauseFPSMaxText.setOutlineThickness(1);
	pauseFPS60Text.setOutlineColor(DARK_THEME);
	pauseFPS120Text.setOutlineColor(DARK_THEME);
	pauseFPS240Text.setOutlineColor(DARK_THEME);
	pauseFPS360Text.setOutlineColor(DARK_THEME);
	pauseFPSVsyncText.setOutlineColor(DARK_THEME);
	pauseFPSMaxText.setOutlineColor(DARK_THEME);
	pauseFPS60Text.setString("60 FPS");
	pauseFPS120Text.setString("120 FPS");
	pauseFPS240Text.setString("240 FPS");
	pauseFPS360Text.setString("360 FPS");
	pauseFPSVsyncText.setString("V-SYNC");
	if (language == "EN")
		pauseFPSMaxText.setString("Limitless");
	else if (language == "FR")
		pauseFPSMaxText.setString("Pas de limite");
	pauseFPS60Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode0Text.getPosition().y));
	pauseFPS120Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode2Text.getPosition().y));
	pauseFPS240Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode4Text.getPosition().y));
	pauseFPS360Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode6Text.getPosition().y));
	pauseFPSVsyncText.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x-(window.getSize().x * 0.02f), pauseResolutionMode8Text.getPosition().y));
	pauseFPSMaxText.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode10Text.getPosition().y));
	pauseLanguageENText.setFont(puppy);
	pauseLanguageENText.setCharacterSize(40);
	pauseLanguageENText.setString("English");
	pauseLanguageENText.setFillColor(sf::Color::White);
	pauseLanguageENText.setOutlineThickness(1);
	pauseLanguageENText.setOutlineColor(DARK_THEME);
	pauseLanguageENText.setPosition(sf::Vector2f(pauseTopBarLanguageText.getPosition().x, pauseResolutionMode0Text.getPosition().y));
	pauseLanguageFRText.setFont(puppy);
	pauseLanguageFRText.setCharacterSize(40);
	pauseLanguageFRText.setString("Français");
	pauseLanguageFRText.setFillColor(sf::Color::White);
	pauseLanguageFRText.setOutlineThickness(1);
	pauseLanguageFRText.setOutlineColor(DARK_THEME);
	pauseLanguageFRText.setPosition(sf::Vector2f(pauseTopBarLanguageText.getPosition().x, pauseResolutionMode2Text.getPosition().y));
	// CURSORS
	pie.loadFromPixels(pieCursorImg.getPixelsPtr(), pieCursorImg.getSize(), {(pieCursorImg.getSize().x / 2), (pieCursorImg.getSize().y / 2)});
}

void Game::setShooterPositions() {
	for (float i = 0; i < 3; i++) { //i et j doivent être des positions relatives à la taille de la fenetre
		for (float j = 0; j < 5; j++) {
			shooterPositions.push_back({ i, j });

		}
	}
	for (int i = 0; i < 3; i++) {
		std::cout << shooterPositions[i].x << " " << shooterPositions[i].y << std::endl;
	}
}

void Game::pollEvents() {
	sf::Event event;
	window.pollEvent(event);
	switch (event.type) {
	case sf::Event::Closed:
		m_isRunning = false;
		break;
	case sf::Event::MouseMoved:
		if (startUpScreenOn) {
			if (playText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				playText.setFillColor(LIGHT_GREEN);
			else
				playText.setFillColor(sf::Color::White);
			if (shopText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				shopText.setFillColor(LIGHT_YELLOW);
			else
				shopText.setFillColor(sf::Color::White);
			if (quitText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				quitText.setFillColor(LIGHT_RED);
			else
				quitText.setFillColor(sf::Color::White);
			if (settingsIconSprite.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				settingsIconSprite.setColor(LIGHT_GRAY);
			else
				settingsIconSprite.setColor(sf::Color::White);
		}
		if (settingsScreenOn) {
			// TOPBAR
			if (menuPauseTopBarResolution.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				menuPauseTopBarResolution.setFillColor(LIGHT_GRAY);
			else
				menuPauseTopBarResolution.setFillColor(sf::Color::Transparent);
			if (menuPauseTopBarFPS.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				menuPauseTopBarFPS.setFillColor(LIGHT_GRAY);
			else
				menuPauseTopBarFPS.setFillColor(sf::Color::Transparent);
			if (menuPauseTopBarColorTheme.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				menuPauseTopBarColorTheme.setFillColor(LIGHT_GRAY);
			else
				menuPauseTopBarColorTheme.setFillColor(sf::Color::Transparent);
			if (menuPauseTopBarLanguage.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				menuPauseTopBarLanguage.setFillColor(LIGHT_GRAY);
			else
				menuPauseTopBarLanguage.setFillColor(sf::Color::Transparent);
			// RESOLUTION SETTINGS
			if (pauseResolutionMode0Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode0Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode0Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode1Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode1Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode1Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode2Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode2Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode2Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode3Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode3Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode3Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode4Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode4Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode4Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode5Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode5Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode5Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode6Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode6Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode6Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode7Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode7Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode7Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode8Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode8Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode8Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode9Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode9Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode9Text.setFillColor(sf::Color::White);
			if (pauseResolutionMode10Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseResolutionMode10Text.setFillColor(LIGHT_GRAY);
			else
				pauseResolutionMode10Text.setFillColor(sf::Color::White);
			// FPS SETTINGS
			if (pauseFPS60Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseFPS60Text.setFillColor(LIGHT_GRAY);
			else
				pauseFPS60Text.setFillColor(sf::Color::White);
			if (pauseFPS120Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseFPS120Text.setFillColor(LIGHT_GRAY);
			else
				pauseFPS120Text.setFillColor(sf::Color::White);
			if (pauseFPS240Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseFPS240Text.setFillColor(LIGHT_GRAY);
			else
				pauseFPS240Text.setFillColor(sf::Color::White);
			if (pauseFPS360Text.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseFPS360Text.setFillColor(LIGHT_GRAY);
			else
				pauseFPS360Text.setFillColor(sf::Color::White);
			if (pauseFPSVsyncText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseFPSVsyncText.setFillColor(LIGHT_GRAY);
			else
				pauseFPSVsyncText.setFillColor(sf::Color::White);
			if (pauseFPSMaxText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseFPSMaxText.setFillColor(LIGHT_GRAY);
			else
				pauseFPSMaxText.setFillColor(sf::Color::White);
			// LANGUAGE SETTINGS
			if (pauseLanguageENText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseLanguageENText.setFillColor(LIGHT_GRAY);
			else
				pauseLanguageENText.setFillColor(sf::Color::White);
			if (pauseLanguageFRText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				pauseLanguageFRText.setFillColor(LIGHT_GRAY);
			else
				pauseLanguageFRText.setFillColor(sf::Color::White);
		}
		if (playScreenOn) {
			// To be defined
		}
		break;
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (settingsScreenOn) {
				if (!menuPauseContent.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y) && !menuPauseTopBar.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					settingsScreenOn = false;
					startUpScreenOn = true;
					settingsIconSprite.setColor(sf::Color::White);
				}
				if (pauseResolutionMode0Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[0].width, modes[0].height), "Food'estroyer", sf::Style::Fullscreen);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode1Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[1].width, modes[1].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode2Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[2].width, modes[2].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode3Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[3].width, modes[3].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode4Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[4].width, modes[4].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode5Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[5].width, modes[5].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode6Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[6].width, modes[6].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode7Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[7].width, modes[7].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode8Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[8].width, modes[8].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode9Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[9].width, modes[9].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseResolutionMode10Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[10].width, modes[10].height), "Food'estroyer", sf::Style::Default);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
				}
				if (pauseFPS60Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.setVerticalSyncEnabled(false);
					currentFramerateLimit = 60;
					window.setFramerateLimit(currentFramerateLimit);
				}
				if (pauseFPS120Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.setVerticalSyncEnabled(false);
					currentFramerateLimit = 120;
					window.setFramerateLimit(currentFramerateLimit);
				}
				if (pauseFPS240Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.setVerticalSyncEnabled(false);
					currentFramerateLimit = 240;
					window.setFramerateLimit(currentFramerateLimit);
				}
				if (pauseFPS360Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.setVerticalSyncEnabled(false);
					currentFramerateLimit = 360;
					window.setFramerateLimit(currentFramerateLimit);
				}
				if (pauseFPSVsyncText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.setVerticalSyncEnabled(true);
				}
				if (pauseFPSMaxText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.setVerticalSyncEnabled(false);
					currentFramerateLimit = 9999;
					window.setFramerateLimit(currentFramerateLimit);
				}
				if (pauseLanguageENText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y) && language != "EN") {
					language = "EN";
					setupGraphicalElements();
				}
				if (pauseLanguageFRText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y) && language != "FR") {
					language = "FR";
					setupGraphicalElements();
				}
			}
			if (startUpScreenOn) {
				// Options
				if (settingsIconSprite.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					settingsScreenOn = true;
					startUpScreenOn = false;
				}
				// Jouer
				if (playText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					playScreenOn = true;
					startUpScreenOn = false;
				}
				// Quitter
				if (quitText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					m_isRunning = false;
				}
			}
			if (playScreenOn) {
				// To be defined
			}
		}
		// For dragging
		mouseLastDownX = event.mouseButton.x;
		mouseLastDownY = event.mouseButton.y;
		isMouseDragging = true;
		break;
	case sf::Event::MouseButtonReleased:
		isMouseDragging = false;
		break;
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			if (settingsScreenOn) {
				settingsScreenOn = false;
				startUpScreenOn = true;
				settingsIconSprite.setColor(sf::Color::White);
			}
			else if(startUpScreenOn) {
				m_isRunning = false;
			}
			else if (playScreenOn) {
				// Some view to be defined for a quick pause menu.
				// Maybe a boolean
				m_isRunning = false;
			}
		}
	default:
		break;
	}
}

void Game::run() {

	setupGraphicalElements();

	setShooterPositions();

	while (m_isRunning) {
		// FPS calculation
		f_ElapsedTime = Clock.restart().asSeconds();
		float f_FPS = (1.f / f_ElapsedTime);
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(2) << f_FPS;
		std::string FPSValue = oss.str();
		FPSText.setString("FPS : " + FPSValue);

		// Funtctions loop
		pollEvents();
		update();
		render();
	}

	std::cout << "Closed" << std::endl;
	window.close();
	windowBase.close();

}


void Game::update() {
	// MECHANICS
	Shooter shooter(2000, 500,30);
	shooter.behavior(shooterPositions);
}

void Game::render() {
	window.clear(sf::Color::Black);
	if (settingsScreenOn) {
		window.draw(bgStartUpScreenSprite);
		// window.draw(screenShadowWhenBlured);
		// TopBar
		window.draw(menuPauseTopBar);
		window.draw(menuPauseTopBarResolution);
		window.draw(pauseTopBarResolutionText);
		window.draw(menuPauseTopBarFPS);
		window.draw(pauseTopBarFPSText);
		window.draw(menuPauseTopBarColorTheme);
		window.draw(pauseTopBarColorThemeText);
		window.draw(menuPauseTopBarLanguage);
		window.draw(pauseTopBarLanguageText);
		// Content
		window.draw(menuPauseContent);
		// ... Resolution
		window.draw(pauseResolutionMode0Text);
		window.draw(pauseResolutionMode1Text);
		window.draw(pauseResolutionMode2Text);
		window.draw(pauseResolutionMode3Text);
		window.draw(pauseResolutionMode4Text);
		window.draw(pauseResolutionMode5Text);
		window.draw(pauseResolutionMode6Text);
		window.draw(pauseResolutionMode7Text);
		window.draw(pauseResolutionMode8Text);
		window.draw(pauseResolutionMode9Text);
		window.draw(pauseResolutionMode10Text);
		// ... FPS
		window.draw(pauseFPS60Text);
		window.draw(pauseFPS120Text);
		window.draw(pauseFPS240Text);
		window.draw(pauseFPS360Text);
		window.draw(pauseFPSVsyncText);
		window.draw(pauseFPSMaxText);
		// ... Language
		window.draw(pauseLanguageENText);
		window.draw(pauseLanguageFRText);
	}

	if (startUpScreenOn) {
		window.draw(bgStartUpScreenSprite);
		window.draw(playText);
		window.draw(shopText);
		window.draw(quitText);
		window.draw(copyright);
		window.draw(settingsIconSprite);
	}

	if (playScreenOn) {
		if (levelOneOn) {
			// Objectif 07/12 à 08/12 : faire le parralaxe
		}
	}

	window.draw(FPSText);
	window.setMouseCursor(pie);
	window.display();
}