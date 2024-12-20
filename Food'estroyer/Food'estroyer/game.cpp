#include "game.h"
#include "enemy.h"
#include "player.h"

namespace {
	// DATA STL (STandard Library)
	int mouseLastDownX = 0;
	int mouseLastDownY = 0;
	float scoreCounter = 0.f;
	float bonusDropTimer = 0.f;
	float factorSugarScaling = 0.f;
	bool isMouseDragging = false;
	bool isFullscreen = true;
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes(); // Gets the native resolutions of the machine this program is running on
	float clownWalkAnimationTime = 0.f;
	float bossAnimationTime = 0.f;
	float bossEyeAnimationTime = 0.f;
	float gameOverAnimation = 0;
	float ennemiesSpawnCooldown = 1.2f;
	float ennemiesSpawnCooldownDuration = 0.f;
	bool levelOneCompleted = false;
	bool levelTwoCompleted = false;
	bool levelThreeCompleted = false;
	bool bossFightStarted = false;
	bool bossFightCompleted = false;
	int deadEnnemies = 0;
	int damageTakenPlayer = 0;
	bool showNoHitBonus = false;
	bool showNoMissBonus = false;
	int howToPlayActiveIndex = 0;
	bool spawnCooldownPhaseOne = false;
	bool spawnCooldownPhaseTwo = false;
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
	sf::Text howToPlayText;
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
	sf::Text gameplayPauseGoBackText;
	sf::Text gameplayPauseExitText;
	sf::Text gameplayPauseTitleText;
	sf::Text gameplayPauseSFXText;
	sf::Text gameplayPauseMusicText;
	sf::Text gameplayPausePlusSoundTextSFX;
	sf::Text gameplayPauseMinusSoundTextSFX;
	sf::Text gameplayPausePlusSoundTextMusic;
	sf::Text gameplayPauseMinusSoundTextMusic;
	sf::Text gameplayUIScoreText;
	sf::Text gameplayUIPlayerLife;
	sf::Text gameplayUIPlayerCombo;
	sf::Text gameplayUISugarForUpgrades;
	sf::Text gameplayUIBossLife;
	sf::Text gameplayUISugarText;
	sf::Text gameplayUIStatAtkText;
	sf::Text gameplayUIStatMaxHpText;
	sf::Text gameplayUIStatSpeedText;
	sf::Text gameplayUISetSpecialBase;
	sf::Text gameplayUISetSpecialTriple;
	sf::Text gameplayUISetSpecialRain;
	sf::Text gameplayUINoHitBonus;
	sf::Text gameplayUINoMissBonus;
	sf::Text levelEndScreenTotalScore;
	sf::Text levelEndScreenTotalEnnemiesKilled;
	sf::Text levelEndScreenTotalDamageTaken;
	sf::Text levelEndScreenTitle;
	sf::Text levelEndScreenNextButton;
	sf::Text levelEndScreenQuitButton;
	sf::Text gameOverText;
	sf::Text retryText;
	sf::Text giveUpText;
	sf::Text levelSelectionScreenOne;
	sf::Text levelSelectionScreenTwo;
	sf::Text levelSelectionScreenThree;
	sf::Text levelSelectionScreenTitle;
	// MUSICS
	sf::Music bgStartUpScreenMusic;
	sf::Music bgLvl1Music;
	sf::Music bgLvl2Music;
	sf::Music bgLvl3Music;
	sf::Music bgBossfightMusic;
	// SOUNDS
	sf::SoundBuffer sugarCrunchBuffer;
	sf::Sound sugarCrunchSound;
	sf::SoundBuffer oofBuffer;
	sf::Sound oofSound;
	sf::SoundBuffer playerDeathBuffer;
	sf::Sound playerDeathSound;
	sf::SoundBuffer vineBoomBuffer;
	sf::Sound vineBoomSound;
	// IMAGES
	sf::Image pieCursorImg;
	// TEXTURES
		// BACKGROUNDS & ICONS
	sf::Texture settingsIcon;
	sf::Texture bgStartUpScreen;
	sf::Texture bgStartUpScreenEnd;
	sf::Texture levelOneParralax01;
	sf::Texture levelOneParralax02;
	sf::Texture levelOneParralax03;
	sf::Texture levelOneParralax04;
	sf::Texture levelOneParralax05;
	sf::Texture levelOneParralax06;
	sf::Texture levelTwoParralax01;
	sf::Texture levelTwoParralax02;
	sf::Texture levelTwoParralax03;
	sf::Texture levelTwoParralax04;
	sf::Texture levelTwoParralax05;
	sf::Texture levelTwoParralax06;
	sf::Texture levelTwoParralax07;
	sf::Texture levelTwoParralax08;
	sf::Texture levelTwoParralaxBG;
	sf::Texture levelThreeParralax01;
	sf::Texture levelThreeParralax02;
	sf::Texture levelThreeParralax03;
	sf::Texture levelThreeParralax04;
	sf::Texture levelThreeParralax05;
	sf::Texture levelThreeParralax06;
	sf::Texture levelThreeParralax07;
	sf::Texture levelThreeParralax08;
	// PLAYER
	sf::Texture playerMove1;
	sf::Texture playerMove2;
	sf::Texture playerAttack1;
	sf::Texture playerAttack2;
	sf::Texture playerDeath1;
	sf::Texture playerDeath2;
	sf::Texture playerDeath3;
	sf::Texture playerDeath4;
	sf::Texture playerDeath5;
	sf::Texture playerDeath6;
	sf::Texture pieTexture;
	sf::Texture shieldTexture;
	sf::Texture shieldIconeTexture;
	sf::Texture x2IconeTexture;
	sf::Texture oneUpIconeTexture;
	sf::Sprite bonusIconeTemplate; //POUR LA BOUCLE DE COLLISIONS DES POINTEURS DE BONUS
	// ENEMIES
	sf::Texture deathTexture1;
	sf::Texture deathTexture2;
	sf::Texture sugarTexture;
	sf::Texture shooterProjectile;
	sf::Texture eliteProjectile;
	sf::Texture bossProjectile;
	sf::Texture bossSecondProjectile;
	sf::Texture bossSpecialProjectile;
	sf::Texture painBizarre;
	sf::Texture tomato;
	sf::Texture banana;
	sf::Texture apple;
	sf::Texture burger;
	sf::Texture carrot;
	sf::Texture avocado;
	sf::Texture fries;
	sf::Texture salad;
	sf::Texture pepper;
	sf::Texture candy;
	// BOSS 
	sf::Texture bossTexture1;
	sf::Texture bossTexture2;
	sf::Texture bossTexture3;
	sf::Texture bossEyeTexture1;
	sf::Texture bossEyeTexture2;
	sf::Texture bossEyeTexture3;
	// UI
	sf::Texture gameplayUILifeBar01Active;
	sf::Texture gameplayUILifeBar02Active;
	sf::Texture gameplayUILifeBar03Active;
	sf::Texture gameplayUILifeBar04Active;
	sf::Texture gameplayUILifeBar05Active;
	sf::Texture gameplayUILifeBar06Active;
	sf::Texture gameplayUILifeBar07Active;
	sf::Texture gameplayUILifeBar08Active;
	sf::Texture gameplayUILifeBar09Active;
	sf::Texture gameplayUILifeBar10Active;
	sf::Texture gameplayUILifeBar11Active;
	sf::Texture gameplayUILifeBar12Active;
	sf::Texture gameplayUILifeBar13Active;
	sf::Texture gameplayUILifeBar14Active;
	sf::Texture gameplayUILifeBar15Active;
	sf::Texture gameplayUILifeBar16Active;
	sf::Texture gameplayUILifeBar17Active;
	sf::Texture gameplayUILifeBar18Active;
	sf::Texture gameplayUILifeBar19Active;
	sf::Texture gameplayUILifeBar20Active;
	sf::Texture gameplayUILifeBar21Active;
	sf::Texture gameplayUILifeBar01Inactive;
	sf::Texture gameplayUILifeBar02Inactive;
	sf::Texture gameplayUILifeBar03Inactive;
	sf::Texture gameplayUILifeBar04Inactive;
	sf::Texture gameplayUILifeBar05Inactive;
	sf::Texture gameplayUILifeBar06Inactive;
	sf::Texture gameplayUILifeBar07Inactive;
	sf::Texture gameplayUILifeBar08Inactive;
	sf::Texture gameplayUILifeBar09Inactive;
	sf::Texture gameplayUILifeBar10Inactive;
	sf::Texture gameplayUILifeBar11Inactive;
	sf::Texture gameplayUILifeBar12Inactive;
	sf::Texture gameplayUILifeBar13Inactive;
	sf::Texture gameplayUILifeBar14Inactive;
	sf::Texture gameplayUILifeBar15Inactive;
	sf::Texture gameplayUILifeBar16Inactive;
	sf::Texture gameplayUILifeBar17Inactive;
	sf::Texture gameplayUILifeBar18Inactive;
	sf::Texture gameplayUILifeBar19Inactive;
	sf::Texture gameplayUILifeBar20Inactive;
	sf::Texture gameplayUILifeBar21Inactive;
	sf::Texture gameplayUIPauseSoundPlus;
	sf::Texture gameplayUIPauseSoundMinus;
	// HOW TO PLAY
	sf::Texture howToPlayFR1;
	sf::Texture howToPlayFR2;
	sf::Texture howToPlayFR3;
	sf::Texture howToPlayFR4;
	sf::Texture howToPlayEN1;
	sf::Texture howToPlayEN2;
	sf::Texture howToPlayEN3;
	sf::Texture howToPlayEN4;
	sf::Texture howToPlayNext;
	sf::Texture howToPlayPrevious;
	// SHAPES
	sf::RectangleShape darkerLayer;
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
	sf::RectangleShape gameplayPauseContent;
	sf::RectangleShape gameplayPauseGoBackBtn;
	sf::RectangleShape gameplayPauseExitBtn;
	sf::RectangleShape gameplayPauseMusicControlZone;
	sf::RectangleShape gameplayPauseMusicControlZoneBG;
	sf::RectangleShape gameplayPauseSFXControlZone;
	sf::RectangleShape gameplayPauseSFXControlZoneBG;
	sf::RectangleShape gameplayPauseMusicControlInnerZone;
	sf::RectangleShape gameplayPauseSFXControlInnerZone;
	sf::RectangleShape gameplayPauseMusicControlPlusBtn;
	sf::RectangleShape gameplayPauseMusicControlMinusBtn;
	sf::RectangleShape gameplayPauseSFXControlPlusBtn;
	sf::RectangleShape gameplayPauseSFXControlMinusBtn;
	sf::RectangleShape gameplayPauseSettingsMenuBtn;
	sf::RectangleShape levelProgressionBarBG;
	sf::RectangleShape levelProgressionBarFG;
	// SPRITES
	sf::Sprite bgStartUpScreenSprite;
	sf::Sprite bgStartUpScreenEndSprite;
	sf::Sprite settingsIconSprite;
	// How to play
	sf::Sprite howToPlayFrench1;
	sf::Sprite howToPlayFrench2;
	sf::Sprite howToPlayFrench3;
	sf::Sprite howToPlayFrench4;
	sf::Sprite howToPlayEnglish1;
	sf::Sprite howToPlayEnglish2;
	sf::Sprite howToPlayEnglish3;
	sf::Sprite howToPlayEnglish4;
	sf::Sprite howToPlayNextSlide;
	sf::Sprite howToPlayPreviousSlide;
	sf::Sprite howToPlayFrench[4];
	sf::Sprite howToPlayEnglish[4];
	// Level 1
	sf::Sprite levelOneBackgroundStartSprite;
	sf::Sprite levelOneParralax01Sprite;
	sf::Sprite levelOneParralax02Sprite;
	sf::Sprite levelOneParralax03Sprite;
	sf::Sprite levelOneParralax04Sprite;
	sf::Sprite levelOneParralax05Sprite;
	sf::Sprite levelOneParralax06Sprite;
	sf::Sprite levelOneParralax01SpriteCopy;
	sf::Sprite levelOneParralax02SpriteCopy;
	sf::Sprite levelOneParralax03SpriteCopy;
	sf::Sprite levelOneParralax04SpriteCopy;
	sf::Sprite levelOneParralax05SpriteCopy;
	sf::Sprite levelOneParralax06SpriteCopy;
	// Level 2
	sf::Sprite levelTwoParralax01Sprite;
	sf::Sprite levelTwoParralax02Sprite;
	sf::Sprite levelTwoParralax03Sprite;
	sf::Sprite levelTwoParralax04Sprite;
	sf::Sprite levelTwoParralax05Sprite;
	sf::Sprite levelTwoParralax06Sprite;
	sf::Sprite levelTwoParralax07Sprite;
	sf::Sprite levelTwoParralax08Sprite;
	sf::Sprite levelTwoParralaxBGSprite;
	sf::Sprite levelTwoParralax01SpriteCopy;
	sf::Sprite levelTwoParralax02SpriteCopy;
	sf::Sprite levelTwoParralax03SpriteCopy;
	sf::Sprite levelTwoParralax04SpriteCopy;
	sf::Sprite levelTwoParralax05SpriteCopy;
	sf::Sprite levelTwoParralax06SpriteCopy;
	sf::Sprite levelTwoParralax07SpriteCopy;
	sf::Sprite levelTwoParralax08SpriteCopy;
	sf::Sprite levelTwoParralaxBGSpriteCopy;
	// Level 3
	sf::Sprite levelThreeParralax01Sprite;
	sf::Sprite levelThreeParralax02Sprite;
	sf::Sprite levelThreeParralax03Sprite;
	sf::Sprite levelThreeParralax04Sprite;
	sf::Sprite levelThreeParralax05Sprite;
	sf::Sprite levelThreeParralax06Sprite;
	sf::Sprite levelThreeParralax07Sprite;
	sf::Sprite levelThreeParralaxBGSprite;
	sf::Sprite levelThreeParralax01SpriteCopy;
	sf::Sprite levelThreeParralax02SpriteCopy;
	sf::Sprite levelThreeParralax03SpriteCopy;
	sf::Sprite levelThreeParralax04SpriteCopy;
	sf::Sprite levelThreeParralax05SpriteCopy;
	sf::Sprite levelThreeParralax06SpriteCopy;
	sf::Sprite levelThreeParralax07SpriteCopy;
	sf::Sprite levelThreeParralaxBGSpriteCopy;
	// Others
	sf::Sprite playerCurrentSprite;
	sf::Sprite gameplayUILifeBarCurrentSprite;
	sf::Sprite shieldSprite;
	// VECTORS
	std::vector<sf::Vector2f> shooterPositions; ////////////////////////////////
	std::vector<Projectile*> vectorProjectile;
	std::vector<Sugar*> vectorSugar;
	std::vector<Pie*> vectorPie;
	std::vector<Normal> vectorNormal;
	std::vector<Shooter> vectorShooter;
	std::vector<Elite> vectorElite;
	std::vector<Bonus*> vectorBonus;
	// PLAYER 
	Player player;
	//BOSS
	Boss boss;
	sf::Sprite bossEye;
	sf::Sprite bossEye2;
	// DESSINER POINTEURS
	Projectile projectileDraw;
	Projectile projectileDrawRound;
	Sugar sugarDraw;
	Pie pieDraw;
	Bonus bonusDraw(1.f, 1.f, "shield", player);
	//ICONES UI
	Sugar sugarIcone;
	sf::RectangleShape shieldDraw;
	sf::RectangleShape x2Draw;
	sf::RectangleShape oneUpDraw;
	//STRING DECLARATION
	std::string atkLvlString;
	std::string maxHpLvlString;
	std::string speedLvlString;
	std::string baseSpecialString;
	std::string tripleSpecialString;
	std::string rainSpecialString;
}

Game::Game() :
	window(sf::VideoMode(modes[0].width, modes[0].height), "Food'estroyer", sf::Style::Fullscreen)
{
	// Time gestion
	f_ElapsedTime = 0.f;
	m_isRunning = true;
	window.setVerticalSyncEnabled(true);
	// Ennemies
	for (int i = 0; i < 15; ++i) positionsOccupied.push_back(false);
	splashScreen();
}

void Game::splashScreen() {
	sf::Texture splashScreenTexture;
	sf::Sprite splashScreenBackground;
	splashScreenTexture.loadFromFile("Assets/Images/splashScreenBacgkround.jpg");
	splashScreenBackground.setTexture(splashScreenTexture);
	splashScreenBackground.setScale(sf::Vector2f(window.getSize().x / splashScreenBackground.getLocalBounds().width, window.getSize().y / splashScreenBackground.getLocalBounds().height));
	splashScreenBackground.setPosition(0, 0);
	window.draw(splashScreenBackground);
	window.display();
}

void Game::loadStartUpScreen() {
	// COLORS
	DARK_THEME = sf::Color(30, 30, 30);
	LIGHT_GRAY = sf::Color(175, 175, 175);
	LIGHT_RED = sf::Color(230, 30, 30);
	LIGHT_GREEN = sf::Color(30, 230, 20);
	LIGHT_YELLOW = sf::Color(238, 255, 0);
	// FONTS
	FPSFont.loadFromFile("Assets/Fonts/FPS.TTF");
	puppy.loadFromFile("Assets/Fonts/FriskyPuppy.ttf");
	// MUSICS
	bgStartUpScreenMusic.openFromFile("Assets/Songs/Music/startMenuLoop.mp3");
	bgStartUpScreenMusic.setLoop(true);
	// IMAGES
	pieCursorImg.loadFromFile("Assets/Images/pieCursor.png");
	// TEXTURES
	bgStartUpScreen.loadFromFile("Assets/Images/bgStartUpScreen.jpg");
	bgStartUpScreenEnd.loadFromFile("Assets/Images/bgStartUpScreen.png");
	settingsIcon.loadFromFile("Assets/Images/settingsIcon.png");
	// SPRITES
	bgStartUpScreenSprite.setTexture(bgStartUpScreen);
	bgStartUpScreenSprite.setScale(sf::Vector2f((window.getSize().x / bgStartUpScreenSprite.getLocalBounds().width), (window.getSize().y / bgStartUpScreenSprite.getLocalBounds().height)));
	bgStartUpScreenSprite.setPosition(sf::Vector2f(0, 0));
	bgStartUpScreenEndSprite.setTexture(bgStartUpScreenEnd);
	bgStartUpScreenEndSprite.setScale(sf::Vector2f((window.getSize().x / bgStartUpScreenEndSprite.getLocalBounds().width), (window.getSize().y / bgStartUpScreenEndSprite.getLocalBounds().height)));
	bgStartUpScreenEndSprite.setPosition(sf::Vector2f(0, 0));
	settingsIconSprite.setTexture(settingsIcon);
	settingsIconSprite.setPosition(sf::Vector2f(20.f, 20.f));
	// TEXTS
	// Main menu
	FPSText.setFont(FPSFont);
	FPSText.setCharacterSize(12);
	FPSText.setFillColor(sf::Color::Black);
	FPSText.setString("FPS : 60.00");
	playText.setFont(puppy);
	playText.setCharacterSize(40);
	playText.setFillColor(sf::Color::White);
	playText.setOutlineThickness(1);
	playText.setOutlineColor(sf::Color(DARK_THEME));
	howToPlayText.setFont(puppy);
	howToPlayText.setCharacterSize(40);
	howToPlayText.setFillColor(sf::Color::White);
	howToPlayText.setOutlineThickness(1);
	howToPlayText.setOutlineColor(sf::Color(DARK_THEME));
	quitText.setFont(puppy);
	quitText.setCharacterSize(40);
	quitText.setFillColor(sf::Color::White);
	quitText.setOutlineThickness(1);
	quitText.setOutlineColor(sf::Color(DARK_THEME));
	copyright.setFont(puppy);
	copyright.setCharacterSize(23);
	copyright.setString("Dylan Hollemaert & Julien Rodrigues | 2024");
	copyright.setFillColor(sf::Color::White);
	copyright.setOutlineThickness(1);
	copyright.setOutlineColor(sf::Color(DARK_THEME));
	// CURSORS
	pie.loadFromPixels(pieCursorImg.getPixelsPtr(), pieCursorImg.getSize(), { 1, 1 });
}

void Game::changeLanguages() const {
	if (language == "EN") {
		playText.setString("Play");
		howToPlayText.setString("How to play");
		quitText.setString("Quit");
		pauseTopBarResolutionText.setString("Resolution");
		pauseTopBarColorThemeText.setString("Theme");
		pauseTopBarLanguageText.setString("Language");
		pauseFPSMaxText.setString("Limitless");
		gameplayPauseGoBackText.setString("Go back");
		gameplayPauseExitText.setString("Exit");
		gameplayPauseMusicText.setString("Music");
	}
	else if (language == "FR") {
		playText.setString("Jouer");
		howToPlayText.setString("Tutos");
		quitText.setString("Quitter");
		pauseTopBarResolutionText.setString("Résolution");
		pauseTopBarColorThemeText.setString("Thème");
		pauseTopBarLanguageText.setString("Langue");
		pauseFPSMaxText.setString("Pas de limite");
		gameplayPauseGoBackText.setString("Reprendre");
		gameplayPauseExitText.setString("Quitter");
		gameplayPauseMusicText.setString("Musique");
	}
}

void Game::loadTextPositions() {
	FPSText.setPosition(sf::Vector2f((window.getSize().x / 2) - (FPSText.getLocalBounds().width / 2), FPSText.getLocalBounds().height));
	playText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (playText.getLocalBounds().width / 2)), (window.getSize().y / 2) - 70.f));
	howToPlayText.setPosition(sf::Vector2f(((float)(window.getSize().x / 2.f) - (float)(howToPlayText.getLocalBounds().width / 2.f)), (float)(window.getSize().y / 2.f)));
	quitText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (quitText.getLocalBounds().width / 2)), (window.getSize().y / 2) + 70.f));
	copyright.setPosition(sf::Vector2f(((window.getSize().x / 2) - (copyright.getLocalBounds().width / 2)), window.getSize().y - 45.f));
	gameplayPauseTitleText.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseTitleText.getLocalBounds().width / 2, gameplayPauseContent.getPosition().y + window.getSize().x * 0.01f));
	gameplayPauseGoBackText.setPosition(sf::Vector2f(gameplayPauseGoBackBtn.getPosition().x + gameplayPauseGoBackBtn.getLocalBounds().width / 2 - gameplayPauseGoBackText.getLocalBounds().width / 2, gameplayPauseGoBackBtn.getPosition().y + gameplayPauseGoBackBtn.getSize().y / 6));
	gameplayPauseExitText.setPosition(sf::Vector2f(gameplayPauseExitBtn.getPosition().x + gameplayPauseExitBtn.getLocalBounds().width / 2 - gameplayPauseExitText.getLocalBounds().width / 2, gameplayPauseExitBtn.getPosition().y + gameplayPauseExitBtn.getSize().y / 6));
	gameplayPauseMusicText.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseMusicText.getLocalBounds().width / 2, window.getSize().y / 2 - gameplayPauseMusicText.getLocalBounds().height / 2 - 2 * gameplayPauseMusicControlZone.getGlobalBounds().height));
	gameplayPauseSFXText.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseSFXText.getLocalBounds().width / 2, window.getSize().y / 2 - gameplayPauseSFXText.getLocalBounds().height / 2));
	gameplayPausePlusSoundTextSFX.setPosition(sf::Vector2f(gameplayPauseSFXText.getPosition().x + gameplayPauseSFXText.getGlobalBounds().width + gameplayPausePlusSoundTextSFX.getLocalBounds().width, gameplayPauseSFXText.getPosition().y));
	gameplayPausePlusSoundTextMusic.setPosition(sf::Vector2f(gameplayPauseMusicText.getPosition().x + gameplayPauseMusicText.getGlobalBounds().width + gameplayPausePlusSoundTextMusic.getLocalBounds().width, gameplayPauseMusicText.getPosition().y));
	gameplayPauseMinusSoundTextSFX.setPosition(sf::Vector2f(gameplayPauseSFXText.getPosition().x - gameplayPauseSFXText.getGlobalBounds().width / 1.4f, gameplayPauseSFXText.getPosition().y));
	gameplayPauseMinusSoundTextMusic.setPosition(sf::Vector2f(gameplayPauseMusicText.getPosition().x - gameplayPauseMusicText.getGlobalBounds().width / 1.8f, gameplayPauseMusicText.getPosition().y));
	pauseTopBarResolutionText.setPosition(sf::Vector2f(menuPauseTopBarResolution.getPosition().x + (menuPauseTopBarResolution.getLocalBounds().width * 0.5f) - (pauseTopBarResolutionText.getLocalBounds().width * 0.5f) - 8.f, menuPauseTopBarResolution.getPosition().y + (menuPauseTopBarResolution.getLocalBounds().height * 0.5f) - (pauseTopBarResolutionText.getLocalBounds().height * 0.5f) - 8.f));
	pauseTopBarFPSText.setPosition(sf::Vector2f(menuPauseTopBarFPS.getPosition().x + (menuPauseTopBarFPS.getLocalBounds().width * 0.5f) - (pauseTopBarFPSText.getLocalBounds().width * 0.5f) - 8.f, pauseTopBarResolutionText.getPosition().y));
	pauseTopBarColorThemeText.setPosition(sf::Vector2f(menuPauseTopBarColorTheme.getPosition().x + (menuPauseTopBarColorTheme.getLocalBounds().width * 0.5f) - (pauseTopBarColorThemeText.getLocalBounds().width * 0.5f) - 8.f, pauseTopBarResolutionText.getPosition().y));
	pauseTopBarLanguageText.setPosition(sf::Vector2f(menuPauseTopBarLanguage.getPosition().x + (menuPauseTopBarLanguage.getLocalBounds().width * 0.5f) - (pauseTopBarLanguageText.getLocalBounds().width * 0.5f) - 8.f, pauseTopBarResolutionText.getPosition().y));
	pauseResolutionMode0Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.02f)));
	pauseResolutionMode1Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.05f)));
	pauseResolutionMode2Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.08f)));
	pauseResolutionMode3Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.11f)));
	pauseResolutionMode4Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.14f)));
	pauseResolutionMode5Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.17f)));
	pauseResolutionMode6Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.20f)));
	pauseResolutionMode7Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.23f)));
	pauseResolutionMode8Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.26f)));
	pauseResolutionMode9Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.29f)));
	pauseResolutionMode10Text.setPosition(sf::Vector2f(pauseTopBarResolutionText.getPosition().x, menuPauseContent.getPosition().y + (window.getSize().x * 0.32f)));
	pauseFPS60Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode0Text.getPosition().y));
	pauseFPS120Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode2Text.getPosition().y));
	pauseFPS240Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode4Text.getPosition().y));
	pauseFPS360Text.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode6Text.getPosition().y));
	pauseFPSVsyncText.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode8Text.getPosition().y));
	pauseFPSMaxText.setPosition(sf::Vector2f(pauseTopBarFPSText.getPosition().x - (window.getSize().x * 0.02f), pauseResolutionMode10Text.getPosition().y));
	pauseLanguageENText.setPosition(sf::Vector2f(pauseTopBarLanguageText.getPosition().x, pauseResolutionMode0Text.getPosition().y));
	pauseLanguageFRText.setPosition(sf::Vector2f(pauseTopBarLanguageText.getPosition().x, pauseResolutionMode2Text.getPosition().y));
	window.setIcon(pieCursorImg.getSize().x, pieCursorImg.getSize().y, pieCursorImg.getPixelsPtr());
}

void Game::loadSettings() {
	// SHAPES
	bgStartUpScreenSprite.setScale(sf::Vector2f((window.getSize().x / bgStartUpScreenSprite.getLocalBounds().width), (window.getSize().y / bgStartUpScreenSprite.getLocalBounds().height)));
	darkerLayer.setSize(sf::Vector2f(window.getSize()));
	darkerLayer.setPosition(0.f, 0.f);
	darkerLayer.setFillColor(sf::Color(64, 64, 64, 125));
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
	menuPauseContent.setFillColor(sf::Color(200, 200, 200, 200));
	menuPauseContent.setOutlineThickness(2.f);
	menuPauseContent.setOutlineColor(sf::Color::Black);
	// TEXTS
	// Settings menu
	pauseTopBarResolutionText.setFont(puppy);
	pauseTopBarResolutionText.setCharacterSize(40);
	pauseTopBarResolutionText.setFillColor(sf::Color::White);
	pauseTopBarResolutionText.setOutlineThickness(1);
	pauseTopBarResolutionText.setOutlineColor(sf::Color(DARK_THEME));
	pauseTopBarFPSText.setFont(puppy);
	pauseTopBarFPSText.setCharacterSize(40);
	pauseTopBarFPSText.setString("FPS");
	pauseTopBarFPSText.setFillColor(sf::Color::White);
	pauseTopBarFPSText.setOutlineThickness(1);
	pauseTopBarFPSText.setOutlineColor(sf::Color(DARK_THEME));
	pauseTopBarColorThemeText.setFont(puppy);
	pauseTopBarColorThemeText.setCharacterSize(40);
	pauseTopBarColorThemeText.setFillColor(sf::Color::White);
	pauseTopBarColorThemeText.setOutlineThickness(1);
	pauseTopBarColorThemeText.setOutlineColor(sf::Color(DARK_THEME));
	pauseTopBarLanguageText.setFont(puppy);
	pauseTopBarLanguageText.setCharacterSize(40);
	pauseTopBarLanguageText.setFillColor(sf::Color::White);
	pauseTopBarLanguageText.setOutlineThickness(1);
	pauseTopBarLanguageText.setOutlineColor(sf::Color(DARK_THEME));
	// Content
	pauseResolutionMode0Text.setFont(puppy);
	pauseResolutionMode1Text.setFont(puppy);
	pauseResolutionMode2Text.setFont(puppy);
	pauseResolutionMode3Text.setFont(puppy);
	pauseResolutionMode4Text.setFont(puppy);
	pauseResolutionMode5Text.setFont(puppy);
	pauseResolutionMode6Text.setFont(puppy);
	pauseResolutionMode7Text.setFont(puppy);
	pauseResolutionMode8Text.setFont(puppy);
	pauseResolutionMode9Text.setFont(puppy);
	pauseResolutionMode10Text.setFont(puppy);
	pauseResolutionMode0Text.setString(std::to_string(modes[0].width) + "x" + std::to_string(modes[0].height));
	pauseResolutionMode1Text.setString(std::to_string(modes[1].width) + "x" + std::to_string(modes[1].height));
	pauseResolutionMode2Text.setString(std::to_string(modes[2].width) + "x" + std::to_string(modes[2].height));
	pauseResolutionMode3Text.setString(std::to_string(modes[3].width) + "x" + std::to_string(modes[3].height));
	pauseResolutionMode4Text.setString(std::to_string(modes[4].width) + "x" + std::to_string(modes[4].height));
	pauseResolutionMode5Text.setString(std::to_string(modes[5].width) + "x" + std::to_string(modes[5].height));
	pauseResolutionMode6Text.setString(std::to_string(modes[6].width) + "x" + std::to_string(modes[6].height));
	pauseResolutionMode7Text.setString(std::to_string(modes[7].width) + "x" + std::to_string(modes[7].height));
	pauseResolutionMode8Text.setString(std::to_string(modes[8].width) + "x" + std::to_string(modes[8].height));
	pauseResolutionMode9Text.setString(std::to_string(modes[9].width) + "x" + std::to_string(modes[9].height));
	pauseResolutionMode10Text.setString(std::to_string(modes[10].width) + "x" + std::to_string(modes[10].height));
	pauseResolutionMode0Text.setCharacterSize(40);
	pauseResolutionMode1Text.setCharacterSize(40);
	pauseResolutionMode2Text.setCharacterSize(40);
	pauseResolutionMode3Text.setCharacterSize(40);
	pauseResolutionMode4Text.setCharacterSize(40);
	pauseResolutionMode5Text.setCharacterSize(40);
	pauseResolutionMode6Text.setCharacterSize(40);
	pauseResolutionMode7Text.setCharacterSize(40);
	pauseResolutionMode8Text.setCharacterSize(40);
	pauseResolutionMode9Text.setCharacterSize(40);
	pauseResolutionMode10Text.setCharacterSize(40);
	pauseResolutionMode0Text.setFillColor(sf::Color::White);
	pauseResolutionMode1Text.setFillColor(sf::Color::White);
	pauseResolutionMode2Text.setFillColor(sf::Color::White);
	pauseResolutionMode3Text.setFillColor(sf::Color::White);
	pauseResolutionMode4Text.setFillColor(sf::Color::White);
	pauseResolutionMode5Text.setFillColor(sf::Color::White);
	pauseResolutionMode6Text.setFillColor(sf::Color::White);
	pauseResolutionMode7Text.setFillColor(sf::Color::White);
	pauseResolutionMode8Text.setFillColor(sf::Color::White);
	pauseResolutionMode9Text.setFillColor(sf::Color::White);
	pauseResolutionMode10Text.setFillColor(sf::Color::White);
	pauseResolutionMode0Text.setOutlineThickness(1.f);
	pauseResolutionMode1Text.setOutlineThickness(1.f);
	pauseResolutionMode2Text.setOutlineThickness(1.f);
	pauseResolutionMode3Text.setOutlineThickness(1.f);
	pauseResolutionMode4Text.setOutlineThickness(1.f);
	pauseResolutionMode5Text.setOutlineThickness(1.f);
	pauseResolutionMode6Text.setOutlineThickness(1.f);
	pauseResolutionMode7Text.setOutlineThickness(1.f);
	pauseResolutionMode8Text.setOutlineThickness(1.f);
	pauseResolutionMode9Text.setOutlineThickness(1.f);
	pauseResolutionMode10Text.setOutlineThickness(1.f);
	pauseResolutionMode0Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode1Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode2Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode3Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode4Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode5Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode6Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode7Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode8Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode9Text.setOutlineColor(sf::Color(DARK_THEME));
	pauseResolutionMode10Text.setOutlineColor(sf::Color(DARK_THEME));
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
	pauseLanguageENText.setFont(puppy);
	pauseLanguageENText.setCharacterSize(40);
	pauseLanguageENText.setString("English");
	pauseLanguageENText.setFillColor(sf::Color::White);
	pauseLanguageENText.setOutlineThickness(1);
	pauseLanguageENText.setOutlineColor(DARK_THEME);
	pauseLanguageFRText.setFont(puppy);
	pauseLanguageFRText.setCharacterSize(40);
	pauseLanguageFRText.setString("Français");
	pauseLanguageFRText.setFillColor(sf::Color::White);
	pauseLanguageFRText.setOutlineThickness(1);
	pauseLanguageFRText.setOutlineColor(DARK_THEME);
}

// Only loaded once
void Game::loadLevelAssets() { // Only loaded once
	// FONTS
	score.loadFromFile("Assets/Fonts/score.TTF");
	scoreBold.loadFromFile("Assets/Fonts/scoreBold.TTF");
	// MUSICS
	bgBossfightMusic.openFromFile("Assets/Songs/Music/bossFightMusic.mp3");
	bgBossfightMusic.setLoop(true);
	bgLvl1Music.openFromFile("Assets/Songs/Music/bgMusicLevel1.mp3");
	bgLvl2Music.openFromFile("Assets/Songs/Music/bgMusicLevel2.mp3");
	bgLvl3Music.openFromFile("Assets/Songs/Music/bgMusicLevel3.mp3");
	bgStartUpScreenMusic.setVolume(50);
	bgBossfightMusic.setVolume(50);
	bgLvl1Music.setVolume(50);
	bgLvl2Music.setVolume(50);
	bgLvl3Music.setVolume(50);
	// SOUNDS
	sugarCrunchBuffer.loadFromFile("Assets/Sound Effects/sugar crunch.wav");
	sugarCrunchSound.setBuffer(sugarCrunchBuffer);
	oofBuffer.loadFromFile("Assets/Sound Effects/oof.wav");
	oofSound.setBuffer(oofBuffer);
	playerDeathBuffer.loadFromFile("Assets/Sound Effects/death.wav");
	playerDeathSound.setBuffer(playerDeathBuffer);
	vineBoomBuffer.loadFromFile("Assets/Sound Effects/vine boom.mp3");
	vineBoomSound.setBuffer(vineBoomBuffer);
	oofSound.setVolume(50);
	playerDeathSound.setVolume(50);
	sugarCrunchSound.setVolume(50);
	vineBoomSound.setVolume(50);
	// TEXTURES
	levelOneParralax01.loadFromFile("Assets/Images/Level1/level1Background01.png");
	levelOneParralax02.loadFromFile("Assets/Images/Level1/level1Background02.png");
	levelOneParralax03.loadFromFile("Assets/Images/Level1/level1Background03.png");
	levelOneParralax04.loadFromFile("Assets/Images/Level1/level1Background04.png");
	levelOneParralax05.loadFromFile("Assets/Images/Level1/level1Background05.png");
	levelOneParralax06.loadFromFile("Assets/Images/Level1/level1Background06.png");
	levelTwoParralax01.loadFromFile("Assets/Images/Level2/1.PNG");
	levelTwoParralax02.loadFromFile("Assets/Images/Level2/2.PNG");
	levelTwoParralax03.loadFromFile("Assets/Images/Level2/3.PNG");
	levelTwoParralax04.loadFromFile("Assets/Images/Level2/4.PNG");
	levelTwoParralax05.loadFromFile("Assets/Images/Level2/5.PNG");
	levelTwoParralax06.loadFromFile("Assets/Images/Level2/6.PNG");
	levelTwoParralax07.loadFromFile("Assets/Images/Level2/7.PNG");
	levelTwoParralax08.loadFromFile("Assets/Images/Level2/8.PNG");
	levelTwoParralaxBG.loadFromFile("Assets/Images/Level2/BG.PNG");
	levelThreeParralax01.loadFromFile("Assets/Images/Level3/1.png");
	levelThreeParralax02.loadFromFile("Assets/Images/Level3/2.png");
	levelThreeParralax03.loadFromFile("Assets/Images/Level3/3.png");
	levelThreeParralax04.loadFromFile("Assets/Images/Level3/4.png");
	levelThreeParralax05.loadFromFile("Assets/Images/Level3/5.png");
	levelThreeParralax06.loadFromFile("Assets/Images/Level3/6.png");
	levelThreeParralax07.loadFromFile("Assets/Images/Level3/7.png");
	levelThreeParralax08.loadFromFile("Assets/Images/Level3/BG.png");
	// PLAYER
	playerMove1.loadFromFile("Assets/Images/Clown/Walk/frame_0_walk_clown.png");
	playerMove2.loadFromFile("Assets/Images/Clown/Walk/frame_1_walk_clown.png");
	playerAttack1.loadFromFile("Assets/Images/Clown/Attack/frame_0_attack_clown.png");
	playerAttack2.loadFromFile("Assets/Images/Clown/Attack/frame_1_attack_clown.png");
	playerDeath1.loadFromFile("Assets/Images/Clown/Death/frame_0_death_clown.png");
	playerDeath2.loadFromFile("Assets/Images/Clown/Death/frame_1_death_clown.png");
	playerDeath3.loadFromFile("Assets/Images/Clown/Death/frame_2_death_clown.png");
	playerDeath4.loadFromFile("Assets/Images/Clown/Death/frame_3_death_clown.png");
	playerDeath5.loadFromFile("Assets/Images/Clown/Death/frame_4_death_clown.png");
	playerDeath6.loadFromFile("Assets/Images/Clown/Death/frame_5_death_clown.png");
	pieTexture.loadFromFile("Assets/Images/Clown/Pies/butterscotchPie.png");
	shieldTexture.loadFromFile("Assets/Images/Clown/shield.png");
	shieldIconeTexture.loadFromFile("Assets/Images/Clown/shieldIcone.png");
	x2IconeTexture.loadFromFile("Assets/Images/Clown/x2Icone.png");
	oneUpIconeTexture.loadFromFile("Assets/Images/Clown/oneUpIcone.png");
	deathTexture1.loadFromFile("Assets/Images/Enemy/Death/death1.png");
	deathTexture2.loadFromFile("Assets/Images/Enemy/Death/death2.png");
	// ENEMIES
	painBizarre.loadFromFile("Assets/Images/Enemy/Modele/pixelatedBread.png");
	tomato.loadFromFile("Assets/Images/Enemy/Modele/tomato.png");
	banana.loadFromFile("Assets/Images/Enemy/Modele/banana.png");
	apple.loadFromFile("Assets/Images/Enemy/Modele/apple.png");
	burger.loadFromFile("Assets/Images/Enemy/Modele/burger.png");
	carrot.loadFromFile("Assets/Images/Enemy/Modele/carrot.png");
	avocado.loadFromFile("Assets/Images/Enemy/Modele/avocado.png");
	fries.loadFromFile("Assets/Images/Enemy/Modele/fries.png");
	salad.loadFromFile("Assets/Images/Enemy/Modele/salad.png");
	pepper.loadFromFile("Assets/Images/Enemy/Modele/pepper.png");
	candy.loadFromFile("Assets/Images/Enemy/Modele/candy.png");
	// BOSS
	bossTexture1.loadFromFile("Assets/Images/Enemy/Boss/spaghettiBoss1.png");
	bossTexture2.loadFromFile("Assets/Images/Enemy/Boss/spaghettiBoss2.png");
	bossTexture3.loadFromFile("Assets/Images/Enemy/Boss/spaghettiBoss3.png");
	bossEyeTexture1.loadFromFile("Assets/Images/Enemy/Boss/bossEye1.png");
	bossEyeTexture2.loadFromFile("Assets/Images/Enemy/Boss/bossEye2.png");
	bossEyeTexture3.loadFromFile("Assets/Images/Enemy/Boss/bossEye3.png");
	// ENEMY CREATIONS
	sugarTexture.loadFromFile("Assets/Images/Enemy/sugarSquare.png");
	shooterProjectile.loadFromFile("Assets/Images/Enemy/Projectiles/shooterProjectile.png");
	eliteProjectile.loadFromFile("Assets/Images/Enemy/Projectiles/eliteProjectile.png");
	bossProjectile.loadFromFile("Assets/Images/Enemy/Projectiles/bossProjectile.png");
	bossSecondProjectile.loadFromFile("Assets/Images/Enemy/Projectiles/meatBall.png");
	bossSpecialProjectile.loadFromFile("Assets/Images/Enemy/Projectiles/bossSpecialProjectile.png");
	// GAMEPLAY UI
	gameplayUILifeBar01Active.loadFromFile("Assets/Images/GameplayUI/01-active.png");
	gameplayUILifeBar02Active.loadFromFile("Assets/Images/GameplayUI/02-active.png");
	gameplayUILifeBar03Active.loadFromFile("Assets/Images/GameplayUI/03-active.png");
	gameplayUILifeBar04Active.loadFromFile("Assets/Images/GameplayUI/04-active.png");
	gameplayUILifeBar05Active.loadFromFile("Assets/Images/GameplayUI/05-active.png");
	gameplayUILifeBar06Active.loadFromFile("Assets/Images/GameplayUI/06-active.png");
	gameplayUILifeBar07Active.loadFromFile("Assets/Images/GameplayUI/07-active.png");
	gameplayUILifeBar08Active.loadFromFile("Assets/Images/GameplayUI/08-active.png");
	gameplayUILifeBar09Active.loadFromFile("Assets/Images/GameplayUI/09-active.png");
	gameplayUILifeBar10Active.loadFromFile("Assets/Images/GameplayUI/10-active.png");
	gameplayUILifeBar11Active.loadFromFile("Assets/Images/GameplayUI/11-active.png");
	gameplayUILifeBar12Active.loadFromFile("Assets/Images/GameplayUI/12-active.png");
	gameplayUILifeBar13Active.loadFromFile("Assets/Images/GameplayUI/13-active.png");
	gameplayUILifeBar14Active.loadFromFile("Assets/Images/GameplayUI/14-active.png");
	gameplayUILifeBar15Active.loadFromFile("Assets/Images/GameplayUI/15-active.png");
	gameplayUILifeBar16Active.loadFromFile("Assets/Images/GameplayUI/16-active.png");
	gameplayUILifeBar17Active.loadFromFile("Assets/Images/GameplayUI/17-active.png");
	gameplayUILifeBar18Active.loadFromFile("Assets/Images/GameplayUI/18-active.png");
	gameplayUILifeBar19Active.loadFromFile("Assets/Images/GameplayUI/19-active.png");
	gameplayUILifeBar20Active.loadFromFile("Assets/Images/GameplayUI/20-active.png");
	gameplayUILifeBar21Active.loadFromFile("Assets/Images/GameplayUI/21-active.png");
	gameplayUILifeBar01Inactive.loadFromFile("Assets/Images/GameplayUI/01-inactive.png");
	gameplayUILifeBar02Inactive.loadFromFile("Assets/Images/GameplayUI/02-inactive.png");
	gameplayUILifeBar03Inactive.loadFromFile("Assets/Images/GameplayUI/03-inactive.png");
	gameplayUILifeBar04Inactive.loadFromFile("Assets/Images/GameplayUI/04-inactive.png");
	gameplayUILifeBar05Inactive.loadFromFile("Assets/Images/GameplayUI/05-inactive.png");
	gameplayUILifeBar06Inactive.loadFromFile("Assets/Images/GameplayUI/06-inactive.png");
	gameplayUILifeBar07Inactive.loadFromFile("Assets/Images/GameplayUI/07-inactive.png");
	gameplayUILifeBar08Inactive.loadFromFile("Assets/Images/GameplayUI/08-inactive.png");
	gameplayUILifeBar09Inactive.loadFromFile("Assets/Images/GameplayUI/09-inactive.png");
	gameplayUILifeBar10Inactive.loadFromFile("Assets/Images/GameplayUI/10-inactive.png");
	gameplayUILifeBar11Inactive.loadFromFile("Assets/Images/GameplayUI/11-inactive.png");
	gameplayUILifeBar12Inactive.loadFromFile("Assets/Images/GameplayUI/12-inactive.png");
	gameplayUILifeBar13Inactive.loadFromFile("Assets/Images/GameplayUI/13-inactive.png");
	gameplayUILifeBar14Inactive.loadFromFile("Assets/Images/GameplayUI/14-inactive.png");
	gameplayUILifeBar15Inactive.loadFromFile("Assets/Images/GameplayUI/15-inactive.png");
	gameplayUILifeBar16Inactive.loadFromFile("Assets/Images/GameplayUI/16-inactive.png");
	gameplayUILifeBar17Inactive.loadFromFile("Assets/Images/GameplayUI/17-inactive.png");
	gameplayUILifeBar18Inactive.loadFromFile("Assets/Images/GameplayUI/18-inactive.png");
	gameplayUILifeBar19Inactive.loadFromFile("Assets/Images/GameplayUI/19-inactive.png");
	gameplayUILifeBar20Inactive.loadFromFile("Assets/Images/GameplayUI/20-inactive.png");
	gameplayUILifeBar21Inactive.loadFromFile("Assets/Images/GameplayUI/21-inactive.png");
	// HOW TO PLAY TEXUTRES
	howToPlayEN1.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/EN/1.png");
	howToPlayEN2.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/EN/2.png");
	howToPlayEN3.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/EN/3.png");
	howToPlayEN4.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/EN/4.png");
	howToPlayFR1.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/FR/1.png");
	howToPlayFR2.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/FR/2.png");
	howToPlayFR3.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/FR/3.png");
	howToPlayFR4.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/FR/4.png");
	howToPlayNext.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/RightTriangle.png");
	howToPlayPrevious.loadFromFile("Assets/Images/GameplayUI/HowToPlayMenu/LeftTriangle.png");
	// SPRITES
	howToPlayEnglish1.setTexture(howToPlayEN1);
	howToPlayEnglish2.setTexture(howToPlayEN2);
	howToPlayEnglish3.setTexture(howToPlayEN3);
	howToPlayEnglish4.setTexture(howToPlayEN4);
	howToPlayFrench1.setTexture(howToPlayFR1);
	howToPlayFrench2.setTexture(howToPlayFR2);
	howToPlayFrench3.setTexture(howToPlayFR3);
	howToPlayFrench4.setTexture(howToPlayFR4);
	howToPlayNextSlide.setTexture(howToPlayNext);
	howToPlayPreviousSlide.setTexture(howToPlayPrevious);
	levelOneParralax01Sprite.setTexture(levelOneParralax01);
	levelOneParralax02Sprite.setTexture(levelOneParralax02);
	levelOneParralax03Sprite.setTexture(levelOneParralax03);
	levelOneParralax04Sprite.setTexture(levelOneParralax04);
	levelOneParralax05Sprite.setTexture(levelOneParralax05);
	levelOneParralax06Sprite.setTexture(levelOneParralax06);
	levelTwoParralax01Sprite.setTexture(levelTwoParralax01);
	levelTwoParralax02Sprite.setTexture(levelTwoParralax02);
	levelTwoParralax03Sprite.setTexture(levelTwoParralax03);
	levelTwoParralax04Sprite.setTexture(levelTwoParralax04);
	levelTwoParralax05Sprite.setTexture(levelTwoParralax05);
	levelTwoParralax06Sprite.setTexture(levelTwoParralax06);
	levelTwoParralax07Sprite.setTexture(levelTwoParralax07);
	levelTwoParralax08Sprite.setTexture(levelTwoParralax08);
	levelTwoParralaxBGSprite.setTexture(levelTwoParralaxBG);
	levelThreeParralax01Sprite.setTexture(levelThreeParralax01);
	levelThreeParralax02Sprite.setTexture(levelThreeParralax02);
	levelThreeParralax03Sprite.setTexture(levelThreeParralax03);
	levelThreeParralax04Sprite.setTexture(levelThreeParralax04);
	levelThreeParralax05Sprite.setTexture(levelThreeParralax05);
	levelThreeParralax06Sprite.setTexture(levelThreeParralax06);
	levelThreeParralax07Sprite.setTexture(levelThreeParralax07);
	levelThreeParralaxBGSprite.setTexture(levelThreeParralax08);
	levelOneParralax01SpriteCopy.setTexture(levelOneParralax01);
	levelOneParralax02SpriteCopy.setTexture(levelOneParralax02);
	levelOneParralax03SpriteCopy.setTexture(levelOneParralax03);
	levelOneParralax04SpriteCopy.setTexture(levelOneParralax04);
	levelOneParralax05SpriteCopy.setTexture(levelOneParralax05);
	levelOneParralax06SpriteCopy.setTexture(levelOneParralax06);
	levelTwoParralax01SpriteCopy.setTexture(levelTwoParralax01);
	levelTwoParralax02SpriteCopy.setTexture(levelTwoParralax02);
	levelTwoParralax03SpriteCopy.setTexture(levelTwoParralax03);
	levelTwoParralax04SpriteCopy.setTexture(levelTwoParralax04);
	levelTwoParralax05SpriteCopy.setTexture(levelTwoParralax05);
	levelTwoParralax06SpriteCopy.setTexture(levelTwoParralax06);
	levelTwoParralax07SpriteCopy.setTexture(levelTwoParralax07);
	levelTwoParralax08SpriteCopy.setTexture(levelTwoParralax08);
	levelTwoParralaxBGSpriteCopy.setTexture(levelTwoParralaxBG);
	levelThreeParralax01SpriteCopy.setTexture(levelThreeParralax01);
	levelThreeParralax02SpriteCopy.setTexture(levelThreeParralax02);
	levelThreeParralax03SpriteCopy.setTexture(levelThreeParralax03);
	levelThreeParralax04SpriteCopy.setTexture(levelThreeParralax04);
	levelThreeParralax05SpriteCopy.setTexture(levelThreeParralax05);
	levelThreeParralax06SpriteCopy.setTexture(levelThreeParralax06);
	levelThreeParralax07SpriteCopy.setTexture(levelThreeParralax07);
	levelThreeParralaxBGSpriteCopy.setTexture(levelThreeParralax08);
	playerCurrentSprite.setTexture(playerMove1);
	shieldSprite.setTexture(shieldTexture);
	gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Active);
	// TEXTS
	// Gameplay pause menu
	gameplayPauseTitleText.setFont(puppy);
	gameplayPauseTitleText.setCharacterSize(60);
	gameplayPauseTitleText.setFillColor(sf::Color::White);
	gameplayPauseTitleText.setOutlineThickness(1.f);
	gameplayPauseTitleText.setOutlineColor(sf::Color::Black);
	gameplayPauseTitleText.setString("Pause");
	gameplayPauseGoBackText.setFont(puppy);
	gameplayPauseGoBackText.setCharacterSize(35);
	gameplayPauseGoBackText.setFillColor(sf::Color::White);
	gameplayPauseGoBackText.setOutlineThickness(1.f);
	gameplayPauseGoBackText.setOutlineColor(sf::Color::Black);
	gameplayPauseExitText.setFont(puppy);
	gameplayPauseExitText.setCharacterSize(35);
	gameplayPauseExitText.setFillColor(sf::Color::White);
	gameplayPauseExitText.setOutlineThickness(1.f);
	gameplayPauseExitText.setOutlineColor(sf::Color::Black);
	gameplayPauseSFXText.setFont(puppy);
	gameplayPauseSFXText.setCharacterSize(30);
	gameplayPauseSFXText.setString("SFX");
	gameplayPauseSFXText.setLetterSpacing(2.f);
	gameplayPauseMusicText.setLetterSpacing(2.f);
	gameplayPauseMusicText.setFont(puppy);
	gameplayPauseMusicText.setCharacterSize(30);
	gameplayPauseMusicText.setFillColor(sf::Color::White);
	gameplayPauseMusicText.setOutlineThickness(1.f);
	gameplayPauseMusicText.setOutlineColor(sf::Color(DARK_THEME));
	gameplayPauseSFXText.setFillColor(sf::Color::White);
	gameplayPauseSFXText.setOutlineThickness(1.f);
	gameplayPauseSFXText.setOutlineColor(sf::Color(DARK_THEME));
	gameplayPausePlusSoundTextSFX.setFont(puppy);
	gameplayPausePlusSoundTextSFX.setCharacterSize(35);
	gameplayPausePlusSoundTextSFX.setString("+");
	gameplayPausePlusSoundTextSFX.setFillColor(sf::Color(DARK_THEME));
	gameplayPausePlusSoundTextSFX.setOutlineThickness(1.f);
	gameplayPausePlusSoundTextSFX.setOutlineColor(sf::Color::Black);
	gameplayPausePlusSoundTextMusic = gameplayPausePlusSoundTextSFX;
	gameplayPauseMinusSoundTextSFX.setFont(puppy);
	gameplayPauseMinusSoundTextSFX.setCharacterSize(35);
	gameplayPauseMinusSoundTextSFX.setString("-");
	gameplayPauseMinusSoundTextSFX.setFillColor(sf::Color(DARK_THEME));
	gameplayPauseMinusSoundTextSFX.setOutlineThickness(1.f);
	gameplayPauseMinusSoundTextSFX.setOutlineColor(sf::Color::Black);
	gameplayPauseMinusSoundTextMusic = gameplayPauseMinusSoundTextSFX;
	// Gameplay UI
	gameplayUIScoreText.setFont(score);
	gameplayUIScoreText.setCharacterSize(50);
	gameplayUIScoreText.setLetterSpacing(1.1f);
	gameplayUIScoreText.setString("Score : 000000");
	gameplayUIScoreText.setFillColor(sf::Color::Black);
	sugarIcone.setScale(0.05f, 0.05f);
	sugarIcone.setTexture(sugarTexture);
	bonusIconeTemplate.setTexture(shieldIconeTexture); /////////////
	gameplayUISugarText.setFont(score);
	gameplayUISugarText.setCharacterSize((unsigned int)((float)sugarIcone.getLocalBounds().height * (float)sugarIcone.getScale().y));
	gameplayUISugarText.setLetterSpacing(1.1f);
	gameplayUISugarText.setFillColor(sf::Color::White);
	gameplayUISugarText.setString("00000000");
	gameplayUIStatAtkText.setFont(score);
	gameplayUIStatAtkText.setCharacterSize(30);
	gameplayUIStatAtkText.setLetterSpacing(1.1f);
	gameplayUIStatAtkText.setFillColor(sf::Color::White);
	gameplayUIStatAtkText.setString("not initialised");
	gameplayUIStatMaxHpText.setFont(score);
	gameplayUIStatMaxHpText.setCharacterSize(30);
	gameplayUIStatMaxHpText.setLetterSpacing(1.1f);
	gameplayUIStatMaxHpText.setFillColor(sf::Color::White);
	gameplayUIStatMaxHpText.setString("not initialised");
	gameplayUIStatSpeedText.setFont(score);
	gameplayUIStatSpeedText.setCharacterSize(30);
	gameplayUIStatSpeedText.setLetterSpacing(1.1f);
	gameplayUIStatSpeedText.setFillColor(sf::Color::White);
	gameplayUIStatSpeedText.setString("not initialised");
	gameplayUISetSpecialBase.setFont(score);
	gameplayUISetSpecialBase.setCharacterSize(30);
	gameplayUISetSpecialBase.setLetterSpacing(1.1f);
	gameplayUISetSpecialBase.setFillColor(sf::Color::Red); //BASE EST TJ EQUIPED PAR DEFAUT DONC RED
	gameplayUISetSpecialBase.setString("not initialised");
	gameplayUISetSpecialTriple.setFont(score);
	gameplayUISetSpecialTriple.setCharacterSize(30);
	gameplayUISetSpecialTriple.setLetterSpacing(1.1f);
	gameplayUISetSpecialTriple.setFillColor(sf::Color::White);
	gameplayUISetSpecialTriple.setString("not initialised");
	gameplayUISetSpecialRain.setFont(score);
	gameplayUISetSpecialRain.setCharacterSize(30);
	gameplayUISetSpecialRain.setLetterSpacing(1.1f);
	gameplayUISetSpecialRain.setFillColor(sf::Color::White);
	gameplayUISetSpecialRain.setString("not initialised");
	gameplayUINoHitBonus.setFont(score);
	gameplayUINoHitBonus.setCharacterSize(30);
	gameplayUINoHitBonus.setLetterSpacing(1.1f);
	gameplayUINoHitBonus.setFillColor(sf::Color::Black);
	gameplayUINoHitBonus.setString("NO HIT : +50%");
	gameplayUINoMissBonus.setFont(score);
	gameplayUINoMissBonus.setCharacterSize(30);
	gameplayUINoMissBonus.setLetterSpacing(1.1f);
	gameplayUINoMissBonus.setFillColor(sf::Color::Black);
	gameplayUINoMissBonus.setString("NO MISS : +50%");
}// Called once

// Loaded multiple times
void Game::loadGameplayAssets() {
	// SHAPES
	levelProgressionBarBG.setSize(sf::Vector2f(window.getSize().x * 0.20f, window.getSize().y * 0.03f));
	levelProgressionBarBG.setPosition(window.getSize().x - levelProgressionBarBG.getLocalBounds().width - window.getSize().x * 0.01f, window.getSize().y - levelProgressionBarBG.getLocalBounds().height - window.getSize().x * 0.01f);
	levelProgressionBarBG.setFillColor(sf::Color::Transparent);
	levelProgressionBarBG.setOutlineThickness(2);
	levelProgressionBarBG.setOutlineColor(sf::Color::Black);
	levelProgressionBarFG = levelProgressionBarBG;
	levelProgressionBarFG.setOutlineThickness(0);
	levelProgressionBarFG.setFillColor(sf::Color::Green);
	levelProgressionBarFG.scale(sf::Vector2f(0, 1)); // On initialise la barre de progression à 0%, en gros vide
	gameplayPauseContent.setSize(sf::Vector2f((window.getSize().x * 0.66f), (window.getSize().y * 0.65f)));
	gameplayPauseContent.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseContent.getLocalBounds().width / 2, window.getSize().y / 2 - gameplayPauseContent.getLocalBounds().height / 2));
	gameplayPauseContent.setFillColor(sf::Color(200, 200, 200, 200));
	gameplayPauseContent.setOutlineThickness(2.f);
	gameplayPauseContent.setOutlineColor(sf::Color::Black);
	gameplayPauseGoBackBtn.setSize(sf::Vector2f(gameplayPauseContent.getSize().x / 5, window.getSize().y / 16.f));
	gameplayPauseExitBtn.setSize(gameplayPauseGoBackBtn.getSize());
	gameplayPauseGoBackBtn.setPosition(sf::Vector2f(gameplayPauseContent.getPosition().x + window.getSize().x * 0.01f, gameplayPauseContent.getPosition().y + gameplayPauseContent.getLocalBounds().height - gameplayPauseGoBackBtn.getLocalBounds().height - window.getSize().x * 0.01f));
	gameplayPauseExitBtn.setPosition(sf::Vector2f(gameplayPauseContent.getPosition().x + gameplayPauseContent.getLocalBounds().width - gameplayPauseExitBtn.getLocalBounds().width - window.getSize().x * 0.01f, gameplayPauseContent.getPosition().y + gameplayPauseContent.getLocalBounds().height - gameplayPauseExitBtn.getLocalBounds().height - window.getSize().x * 0.01f));
	gameplayPauseGoBackBtn.setFillColor(sf::Color(200, 200, 200, 200));
	gameplayPauseExitBtn.setFillColor(sf::Color(200, 200, 200, 200));
	gameplayPauseGoBackBtn.setOutlineThickness(1.f);
	gameplayPauseExitBtn.setOutlineThickness(1.f);
	gameplayPauseGoBackBtn.setOutlineColor(sf::Color::Black);
	gameplayPauseExitBtn.setOutlineColor(sf::Color::Black);
	gameplayPauseMusicControlZone.setSize(sf::Vector2f(gameplayPauseContent.getGlobalBounds().width - window.getSize().x * 0.30f, gameplayPauseContent.getGlobalBounds().height * 0.09f));
	gameplayPauseMusicControlZone.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseMusicControlZone.getSize().x / 2, window.getSize().y / 2 - gameplayPauseMusicControlZone.getSize().y / 2 - gameplayPauseMusicControlZone.getSize().y));
	gameplayPauseMusicControlZone.setFillColor(sf::Color::Transparent);
	gameplayPauseMusicControlZone.setOutlineThickness(1.f);
	gameplayPauseMusicControlZone.setOutlineColor(sf::Color::Black);
	gameplayPauseSFXControlZone.setSize(sf::Vector2f(gameplayPauseContent.getGlobalBounds().width - window.getSize().x * 0.30f, gameplayPauseContent.getGlobalBounds().height * 0.09f));
	gameplayPauseSFXControlZone.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseSFXControlZone.getSize().x / 2, window.getSize().y / 2 - gameplayPauseSFXControlZone.getSize().y / 2 + gameplayPauseSFXControlZone.getSize().y));
	gameplayPauseSFXControlZone.setFillColor(sf::Color::Transparent);
	gameplayPauseSFXControlZone.setOutlineThickness(1.f);
	gameplayPauseSFXControlZone.setOutlineColor(sf::Color::Black);
	gameplayPauseMusicControlInnerZone = gameplayPauseMusicControlZone;
	gameplayPauseMusicControlInnerZone.setOutlineThickness(0);
	gameplayPauseMusicControlInnerZone.setFillColor(sf::Color::White);
	gameplayPauseMusicControlInnerZone.setScale(0.5f, 1.f);
	gameplayPauseSFXControlInnerZone = gameplayPauseSFXControlZone;
	gameplayPauseSFXControlInnerZone.setOutlineThickness(0);
	gameplayPauseSFXControlInnerZone.setFillColor(sf::Color::White);
	gameplayPauseSFXControlInnerZone.scale(0.5f, 1.f);
	gameplayPauseMusicControlZoneBG = gameplayPauseMusicControlZone;
	gameplayPauseMusicControlZoneBG.setOutlineThickness(0);
	gameplayPauseMusicControlZoneBG.setFillColor(sf::Color(30, 30, 30, 100));
	gameplayPauseSFXControlZoneBG = gameplayPauseSFXControlZone;
	gameplayPauseSFXControlZoneBG.setOutlineThickness(0);
	gameplayPauseSFXControlZoneBG.setFillColor(sf::Color(30, 30, 30, 100));
	playerCurrentSprite.setScale(sf::Vector2f((window.getSize().x * 0.05f) / (playerCurrentSprite.getLocalBounds().width), (window.getSize().y * 0.10f) / (playerCurrentSprite.getLocalBounds().height)));
	playerCurrentSprite.setPosition(sf::Vector2f(window.getSize().x * 0.07f, (window.getSize().y / 2) - (playerCurrentSprite.getGlobalBounds().height / 2)));
	player.setPosition(playerCurrentSprite.getPosition());
	shieldSprite.setScale(playerCurrentSprite.getScale().x, playerCurrentSprite.getScale().y);
	shieldSprite.setPosition(playerCurrentSprite.getPosition());
	gameplayUILifeBarCurrentSprite.setScale(sf::Vector2f((window.getSize().x * 0.20f) / (gameplayUILifeBarCurrentSprite.getLocalBounds().width), (window.getSize().x * 0.04356f) / (gameplayUILifeBarCurrentSprite.getLocalBounds().height)));
	gameplayUILifeBarCurrentSprite.setPosition(sf::Vector2f(0, 0));
	gameplayUIScoreText.setPosition(sf::Vector2f(window.getSize().x - gameplayUIScoreText.getGlobalBounds().width - window.getSize().x * 0.01f, 0));
	gameplayUINoHitBonus.setPosition(gameplayUIScoreText.getPosition().x + gameplayUIScoreText.getGlobalBounds().width - gameplayUINoHitBonus.getGlobalBounds().width, gameplayUIScoreText.getPosition().y + gameplayUIScoreText.getCharacterSize());
	gameplayUINoMissBonus.setPosition(gameplayUIScoreText.getPosition().x + gameplayUIScoreText.getGlobalBounds().width - gameplayUINoMissBonus.getGlobalBounds().width, gameplayUINoHitBonus.getPosition().y + gameplayUINoHitBonus.getCharacterSize());
	sugarIcone.setPosition(window.getSize().x / 2 - sugarIcone.getGlobalBounds().width / 2 + gameplayUISugarText.getLocalBounds().width / 2, window.getSize().y - (sugarIcone.getLocalBounds().height * sugarIcone.getScale().y) * 1.8f);
	boss.setTexture(bossTexture1);
	boss.setPosition(window.getSize().x * 1.1, 0/*window.getSize().y / 2 - (boss.getLocalBounds().height * boss.getScale().y) / 2*/); //taille boss texture : 640x1080 donc le calcul égale à 0 en ajustant le scaling
	boss.setScale(window.getSize().x / 3 / boss.getLocalBounds().width, window.getSize().y / boss.getLocalBounds().height);
	bossEye.setTexture(bossEyeTexture1);
	bossEye.setScale(window.getSize().x * 0.05 / bossEye.getLocalBounds().width, window.getSize().y * 0.09 / bossEye.getLocalBounds().height);
	bossEye2.setTexture(bossEyeTexture1);
	bossEye2.setScale(window.getSize().x * 0.05 / bossEye2.getLocalBounds().width, window.getSize().y * 0.09 / bossEye2.getLocalBounds().height);
	// HOW TO PLAY SECTION
	howToPlayEnglish1.setScale((window.getSize().y * 0.40f) / howToPlayEnglish1.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayEnglish1.getLocalBounds().width));
	howToPlayEnglish2.setScale((window.getSize().y * 0.40f) / howToPlayEnglish2.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayEnglish2.getLocalBounds().width));
	howToPlayEnglish3.setScale((window.getSize().y * 0.40f) / howToPlayEnglish3.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayEnglish3.getLocalBounds().width));
	howToPlayEnglish4.setScale((window.getSize().y * 0.40f) / howToPlayEnglish4.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayEnglish4.getLocalBounds().width));
	howToPlayFrench1.setScale((window.getSize().y * 0.40f) / howToPlayFrench1.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayFrench1.getLocalBounds().width));
	howToPlayFrench2.setScale((window.getSize().y * 0.40f) / howToPlayFrench2.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayFrench2.getLocalBounds().width));
	howToPlayFrench3.setScale((window.getSize().y * 0.40f) / howToPlayFrench3.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayFrench3.getLocalBounds().width));
	howToPlayFrench4.setScale((window.getSize().y * 0.40f) / howToPlayFrench4.getLocalBounds().width, ((window.getSize().y * 0.40f) / howToPlayFrench4.getLocalBounds().width));
	howToPlayPreviousSlide.setScale(sf::Vector2f((window.getSize().x * 0.05f) / howToPlayPreviousSlide.getLocalBounds().width, (window.getSize().x * 0.05f) / howToPlayPreviousSlide.getLocalBounds().width));
	howToPlayNextSlide.setScale(sf::Vector2f((window.getSize().x * 0.05f) / howToPlayNextSlide.getLocalBounds().width, (window.getSize().x * 0.05f) / howToPlayNextSlide.getLocalBounds().width));
	howToPlayPreviousSlide.setPosition(sf::Vector2f(window.getSize().x / 2 - howToPlayPreviousSlide.getGlobalBounds().width / 2 - window.getSize().y * 0.30f, window.getSize().y / 2 - howToPlayPreviousSlide.getGlobalBounds().height / 2));
	howToPlayNextSlide.setPosition(sf::Vector2f(window.getSize().x / 2 - howToPlayNextSlide.getGlobalBounds().width / 2 + window.getSize().y * 0.30f, window.getSize().y / 2 - howToPlayNextSlide.getGlobalBounds().height / 2));
	howToPlayEnglish1.setPosition(sf::Vector2f(window.getSize().x / 2 - howToPlayEnglish1.getGlobalBounds().width / 2, window.getSize().y / 2 - howToPlayEnglish1.getGlobalBounds().height / 2));
	howToPlayEnglish2.setPosition(howToPlayEnglish1.getPosition());
	howToPlayEnglish3.setPosition(howToPlayEnglish1.getPosition());
	howToPlayEnglish4.setPosition(howToPlayEnglish1.getPosition());
	howToPlayFrench1.setPosition(howToPlayEnglish1.getPosition());
	howToPlayFrench2.setPosition(howToPlayEnglish1.getPosition());
	howToPlayFrench3.setPosition(howToPlayEnglish1.getPosition());
	howToPlayFrench4.setPosition(howToPlayEnglish1.getPosition());
	howToPlayFrench[0] = howToPlayFrench1;
	howToPlayFrench[1] = howToPlayFrench2;
	howToPlayFrench[2] = howToPlayFrench3;
	howToPlayFrench[3] = howToPlayFrench4;
	howToPlayEnglish[0] = howToPlayEnglish1;
	howToPlayEnglish[1] = howToPlayEnglish2;
	howToPlayEnglish[2] = howToPlayEnglish3;
	howToPlayEnglish[3] = howToPlayEnglish4;
	// TEXTS
	gameplayUISugarText.setPosition(sugarIcone.getPosition().x - gameplayUISugarText.getGlobalBounds().width - window.getSize().x * 0.005f, sugarIcone.getPosition().y - gameplayUISugarText.getGlobalBounds().height * 0.2f);
	// Should be loading the ennemies here, each time we launch a level.
	setEnemySpawn(numberOfStartingEnnemies, true);
	setShooterPositions();
}

void Game::setupLevelSelectionScreen() {
	shooterPositions.clear(); // Pour éviter les bugs au cas où (avant l'appel de loadGameplayAssets())
	loadGameplayAssets();     // Bien vérifier que le truc n'est executé qu'une seule fois
	loadSettings();           // Pour avoir accès à une shape sans tout bouger
	levelSelectionScreenTitle = gameplayPauseTitleText;
	if (language == "EN")
		levelSelectionScreenTitle.setString("Level selection");
	else if (language == "FR")
		levelSelectionScreenTitle.setString("Selection du niveau");
	levelSelectionScreenTitle.setPosition(sf::Vector2f(window.getSize().x / 2 - levelSelectionScreenTitle.getLocalBounds().width / 2, gameplayPauseContent.getPosition().y + window.getSize().x * 0.01f));
	levelSelectionScreenOne   = gameplayPauseExitText;
	levelSelectionScreenTwo   = gameplayPauseExitText;
	levelSelectionScreenThree = gameplayPauseExitText;
	levelSelectionScreenOne.setCharacterSize(35);
	levelSelectionScreenTwo.setCharacterSize(35);
	levelSelectionScreenThree.setCharacterSize(35);
	if (language == "FR") {
		levelSelectionScreenOne.setString("Niveau 1");
		levelSelectionScreenTwo.setString("Niveau 2");
		levelSelectionScreenThree.setString("Niveau 3");
	}
	else if (language == "EN") {
		levelSelectionScreenOne.setString("Level 1");
		levelSelectionScreenTwo.setString("Level 2");
		levelSelectionScreenThree.setString("Level 3");
	}
	levelSelectionScreenOne.setPosition(sf::Vector2f(window.getSize().x / 2 - levelSelectionScreenOne.getLocalBounds().width / 2, gameplayPauseContent.getPosition().y + (float)gameplayPauseContent.getGlobalBounds().height / 3.25f));
	levelSelectionScreenTwo.setPosition(sf::Vector2f(window.getSize().x / 2 - levelSelectionScreenTwo.getLocalBounds().width / 2, gameplayPauseContent.getPosition().y + (float)gameplayPauseContent.getGlobalBounds().height / 1.75f));
	levelSelectionScreenThree.setPosition(sf::Vector2f(window.getSize().x / 2 - levelSelectionScreenThree.getLocalBounds().width / 2, gameplayPauseContent.getPosition().y + gameplayPauseContent.getGlobalBounds().height - window.getSize().x * 0.05f));
	if (levelTwoUnlocked)
		levelSelectionScreenTwo.setFillColor(sf::Color::White);
	else
		levelSelectionScreenTwo.setFillColor(LIGHT_GRAY);
	if (levelThreeUnlocked)
		levelSelectionScreenThree.setFillColor(sf::Color::White);
	else
		levelSelectionScreenThree.setFillColor(LIGHT_GRAY);
}

void Game::loadLevel1() {
	// SPRITES
	levelOneParralax01Sprite.setScale(sf::Vector2f((window.getSize().x / levelOneParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelOneParralax01Sprite.getLocalBounds().height)));
	levelOneParralax02Sprite.setScale(sf::Vector2f((window.getSize().x / levelOneParralax02Sprite.getLocalBounds().width), (window.getSize().y / levelOneParralax02Sprite.getLocalBounds().height)));
	levelOneParralax03Sprite.setScale(sf::Vector2f((window.getSize().x / levelOneParralax03Sprite.getLocalBounds().width), (window.getSize().y / levelOneParralax03Sprite.getLocalBounds().height)));
	levelOneParralax04Sprite.setScale(sf::Vector2f((window.getSize().x / levelOneParralax04Sprite.getLocalBounds().width), (window.getSize().y / levelOneParralax04Sprite.getLocalBounds().height)));
	levelOneParralax05Sprite.setScale(sf::Vector2f((window.getSize().x / levelOneParralax05Sprite.getLocalBounds().width), (window.getSize().y / levelOneParralax05Sprite.getLocalBounds().height)));
	levelOneParralax06Sprite.setScale(sf::Vector2f((window.getSize().x / levelOneParralax06Sprite.getLocalBounds().width), (window.getSize().y / levelOneParralax06Sprite.getLocalBounds().height)));
	levelOneParralax01SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelOneParralax01SpriteCopy.getLocalBounds().width), (window.getSize().y / levelOneParralax01SpriteCopy.getLocalBounds().height)));
	levelOneParralax02SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelOneParralax02SpriteCopy.getLocalBounds().width), (window.getSize().y / levelOneParralax02SpriteCopy.getLocalBounds().height)));
	levelOneParralax03SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelOneParralax03SpriteCopy.getLocalBounds().width), (window.getSize().y / levelOneParralax03SpriteCopy.getLocalBounds().height)));
	levelOneParralax04SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelOneParralax04SpriteCopy.getLocalBounds().width), (window.getSize().y / levelOneParralax04SpriteCopy.getLocalBounds().height)));
	levelOneParralax05SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelOneParralax05SpriteCopy.getLocalBounds().width), (window.getSize().y / levelOneParralax05SpriteCopy.getLocalBounds().height)));
	levelOneParralax06SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelOneParralax06SpriteCopy.getLocalBounds().width), (window.getSize().y / levelOneParralax06SpriteCopy.getLocalBounds().height)));
	levelOneParralax01Sprite.setPosition(sf::Vector2f(0, 0));
	levelOneParralax02Sprite.setPosition(sf::Vector2f(0, 0));
	levelOneParralax03Sprite.setPosition(sf::Vector2f(0, 0));
	levelOneParralax04Sprite.setPosition(sf::Vector2f(0, 0));
	levelOneParralax05Sprite.setPosition(sf::Vector2f(0, 0));
	levelOneParralax06Sprite.setPosition(sf::Vector2f(0, 0));
	levelOneParralax01SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelOneParralax02SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelOneParralax03SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelOneParralax04SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelOneParralax05SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelOneParralax06SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
}

void Game::loadLevel2() {
	levelTwoParralax01Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax02Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax03Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax04Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax05Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax06Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax07Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax08Sprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralaxBGSprite.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax01SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax02SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax03SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax04SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax05SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax06SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax07SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax08SpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralaxBGSpriteCopy.setScale(levelOneParralax01Sprite.getScale());
	levelTwoParralax01Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax02Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax03Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax04Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax05Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax06Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax07Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax08Sprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralaxBGSprite.setPosition(sf::Vector2f(0, 0));
	levelTwoParralax01SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralax02SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralax03SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralax04SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralax05SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralax06SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralax07SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralax08SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
	levelTwoParralaxBGSpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x, 0));
}

void Game::loadLevel3() {
	levelThreeParralax01Sprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax02Sprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax03Sprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax04Sprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax05Sprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax06Sprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax07Sprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralaxBGSprite.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax01SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax02SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax03SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax04SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax05SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax06SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax07SpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralaxBGSpriteCopy.setScale(sf::Vector2f((window.getSize().x / levelThreeParralax01Sprite.getLocalBounds().width), (window.getSize().y / levelThreeParralax01Sprite.getLocalBounds().height)));
	levelThreeParralax01Sprite.setPosition(sf::Vector2f(0, 0));
	levelThreeParralax02Sprite.setPosition(sf::Vector2f(0, 0));
}

void Game::backgroundMovementLevel1() {
	levelOneParralax01Sprite.move(sf::Vector2f(-100 * f_ElapsedTime, 0));
	levelOneParralax02Sprite.move(sf::Vector2f(-200 * f_ElapsedTime, 0));
	levelOneParralax03Sprite.move(sf::Vector2f(-300 * f_ElapsedTime, 0));
	levelOneParralax04Sprite.move(sf::Vector2f(-400 * f_ElapsedTime, 0));
	levelOneParralax05Sprite.move(sf::Vector2f(-500 * f_ElapsedTime, 0));
	levelOneParralax06Sprite.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	levelOneParralax01SpriteCopy.move(sf::Vector2f(-100 * f_ElapsedTime, 0));
	levelOneParralax02SpriteCopy.move(sf::Vector2f(-200 * f_ElapsedTime, 0));
	levelOneParralax03SpriteCopy.move(sf::Vector2f(-300 * f_ElapsedTime, 0));
	levelOneParralax04SpriteCopy.move(sf::Vector2f(-400 * f_ElapsedTime, 0));
	levelOneParralax05SpriteCopy.move(sf::Vector2f(-500 * f_ElapsedTime, 0));
	levelOneParralax06SpriteCopy.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	// 1 Original
	if (levelOneParralax01Sprite.getPosition().x <= 0) {
		levelOneParralax01SpriteCopy.setPosition(sf::Vector2f(levelOneParralax01Sprite.getPosition().x + (levelOneParralax01Sprite.getLocalBounds().width * levelOneParralax01Sprite.getScale().x), 0));
	}
	if (levelOneParralax01Sprite.getPosition().x <= (-1 * (levelOneParralax01Sprite.getLocalBounds().width * levelOneParralax01Sprite.getScale().x))) {
		levelOneParralax01Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 1 copy
	if (levelOneParralax01SpriteCopy.getPosition().x <= 0) {
		levelOneParralax01Sprite.setPosition(sf::Vector2f(levelOneParralax01SpriteCopy.getPosition().x + (levelOneParralax01SpriteCopy.getLocalBounds().width * levelOneParralax01SpriteCopy.getScale().x), 0));
	}
	if (levelOneParralax01SpriteCopy.getPosition().x <= (-1 * (levelOneParralax01SpriteCopy.getLocalBounds().width * levelOneParralax01SpriteCopy.getScale().x))) {
		levelOneParralax01SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 2 Original
	if (levelOneParralax02Sprite.getPosition().x <= 0) {
		levelOneParralax02SpriteCopy.setPosition(sf::Vector2f(levelOneParralax02Sprite.getPosition().x + (levelOneParralax02Sprite.getLocalBounds().width * levelOneParralax02Sprite.getScale().x), 0));
	}
	if (levelOneParralax02Sprite.getPosition().x <= (-1 * (levelOneParralax02Sprite.getLocalBounds().width * levelOneParralax02Sprite.getScale().x))) {
		levelOneParralax02Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 2 copy
	if (levelOneParralax02SpriteCopy.getPosition().x <= 0) {
		levelOneParralax02Sprite.setPosition(sf::Vector2f(levelOneParralax02SpriteCopy.getPosition().x + (levelOneParralax02SpriteCopy.getLocalBounds().width * levelOneParralax02SpriteCopy.getScale().x), 0));
	}
	if (levelOneParralax02SpriteCopy.getPosition().x <= (-1 * (levelOneParralax02SpriteCopy.getLocalBounds().width * levelOneParralax02SpriteCopy.getScale().x))) {
		levelOneParralax02SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 3 Original
	if (levelOneParralax03Sprite.getPosition().x <= 0) {
		levelOneParralax03SpriteCopy.setPosition(sf::Vector2f(levelOneParralax03Sprite.getPosition().x + (levelOneParralax03Sprite.getLocalBounds().width * levelOneParralax03Sprite.getScale().x), 0));
	}
	if (levelOneParralax03Sprite.getPosition().x <= (-1 * (levelOneParralax03Sprite.getLocalBounds().width * levelOneParralax03Sprite.getScale().x))) {
		levelOneParralax03Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 3 copy
	if (levelOneParralax03SpriteCopy.getPosition().x <= 0) {
		levelOneParralax03Sprite.setPosition(sf::Vector2f(levelOneParralax03SpriteCopy.getPosition().x + (levelOneParralax03SpriteCopy.getLocalBounds().width * levelOneParralax03SpriteCopy.getScale().x), 0));
	}
	if (levelOneParralax03SpriteCopy.getPosition().x <= (-1 * (levelOneParralax03SpriteCopy.getLocalBounds().width * levelOneParralax03SpriteCopy.getScale().x))) {
		levelOneParralax03SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 4 Original
	if (levelOneParralax04Sprite.getPosition().x <= 0) {
		levelOneParralax04SpriteCopy.setPosition(sf::Vector2f(levelOneParralax04Sprite.getPosition().x + (levelOneParralax04Sprite.getLocalBounds().width * levelOneParralax04Sprite.getScale().x), 0));
	}
	if (levelOneParralax04Sprite.getPosition().x <= (-1 * (levelOneParralax04Sprite.getLocalBounds().width * levelOneParralax04Sprite.getScale().x))) {
		levelOneParralax04Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 4 copy
	if (levelOneParralax04SpriteCopy.getPosition().x <= 0) {
		levelOneParralax04Sprite.setPosition(sf::Vector2f(levelOneParralax04SpriteCopy.getPosition().x + (levelOneParralax04SpriteCopy.getLocalBounds().width * levelOneParralax04SpriteCopy.getScale().x), 0));
	}
	if (levelOneParralax04SpriteCopy.getPosition().x <= (-1 * (levelOneParralax04SpriteCopy.getLocalBounds().width * levelOneParralax04SpriteCopy.getScale().x))) {
		levelOneParralax04SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 5 Original
	if (levelOneParralax05Sprite.getPosition().x <= 0) {
		levelOneParralax05SpriteCopy.setPosition(sf::Vector2f(levelOneParralax05Sprite.getPosition().x + (levelOneParralax05Sprite.getLocalBounds().width * levelOneParralax05Sprite.getScale().x), 0));
	}
	if (levelOneParralax05Sprite.getPosition().x <= (-1 * (levelOneParralax05Sprite.getLocalBounds().width * levelOneParralax05Sprite.getScale().x))) {
		levelOneParralax05Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 5 copy
	if (levelOneParralax05SpriteCopy.getPosition().x <= 0) {
		levelOneParralax05Sprite.setPosition(sf::Vector2f(levelOneParralax05SpriteCopy.getPosition().x + (levelOneParralax05SpriteCopy.getLocalBounds().width * levelOneParralax05SpriteCopy.getScale().x), 0));
	}
	if (levelOneParralax05SpriteCopy.getPosition().x <= (-1 * (levelOneParralax05SpriteCopy.getLocalBounds().width * levelOneParralax05SpriteCopy.getScale().x))) {
		levelOneParralax05SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 6 Original
	if (levelOneParralax06Sprite.getPosition().x <= 0) {
		levelOneParralax06SpriteCopy.setPosition(sf::Vector2f(levelOneParralax06Sprite.getPosition().x + (levelOneParralax06Sprite.getLocalBounds().width * levelOneParralax06Sprite.getScale().x), 0));
	}
	if (levelOneParralax06Sprite.getPosition().x <= (-1 * (levelOneParralax06Sprite.getLocalBounds().width * levelOneParralax06Sprite.getScale().x))) {
		levelOneParralax06Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 6 copy
	if (levelOneParralax06SpriteCopy.getPosition().x <= 0) {
		levelOneParralax06Sprite.setPosition(sf::Vector2f(levelOneParralax06SpriteCopy.getPosition().x + (levelOneParralax06SpriteCopy.getLocalBounds().width * levelOneParralax06SpriteCopy.getScale().x), 0));
	}
	if (levelOneParralax06SpriteCopy.getPosition().x <= (-1 * (levelOneParralax06SpriteCopy.getLocalBounds().width * levelOneParralax06SpriteCopy.getScale().x))) {
		levelOneParralax06SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
}

void Game::backgroundMovementLevel2() {
	levelTwoParralaxBGSprite.move(sf::Vector2f(-100 * f_ElapsedTime, 0));
	levelTwoParralax01Sprite.move(sf::Vector2f(-800 * f_ElapsedTime, 0));
	levelTwoParralax02Sprite.move(sf::Vector2f(-700 * f_ElapsedTime, 0));
	levelTwoParralax03Sprite.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	levelTwoParralax04Sprite.move(sf::Vector2f(-500 * f_ElapsedTime, 0));
	levelTwoParralax05Sprite.move(sf::Vector2f(-400 * f_ElapsedTime, 0));
	levelTwoParralax06Sprite.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	levelTwoParralax07Sprite.move(sf::Vector2f(-300 * f_ElapsedTime, 0));
	levelTwoParralax08Sprite.move(sf::Vector2f(-200 * f_ElapsedTime, 0));
	levelTwoParralaxBGSpriteCopy.move(sf::Vector2f(-100 * f_ElapsedTime, 0));
	levelTwoParralax01SpriteCopy.move(sf::Vector2f(-800 * f_ElapsedTime, 0));
	levelTwoParralax02SpriteCopy.move(sf::Vector2f(-700 * f_ElapsedTime, 0));
	levelTwoParralax03SpriteCopy.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	levelTwoParralax04SpriteCopy.move(sf::Vector2f(-500 * f_ElapsedTime, 0));
	levelTwoParralax05SpriteCopy.move(sf::Vector2f(-400 * f_ElapsedTime, 0));
	levelTwoParralax06SpriteCopy.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	levelTwoParralax07SpriteCopy.move(sf::Vector2f(-300 * f_ElapsedTime, 0));
	levelTwoParralax08SpriteCopy.move(sf::Vector2f(-200 * f_ElapsedTime, 0));

	// 1 Original
	if (levelTwoParralax01Sprite.getPosition().x <= 0) {
		levelTwoParralax01SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax01Sprite.getPosition().x + (levelTwoParralax01Sprite.getLocalBounds().width * levelTwoParralax01Sprite.getScale().x), 0));
	}
	if (levelTwoParralax01Sprite.getPosition().x <= (-1 * (levelTwoParralax01Sprite.getLocalBounds().width * levelTwoParralax01Sprite.getScale().x))) {
		levelTwoParralax01Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 1 copy
	if (levelTwoParralax01SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax01Sprite.setPosition(sf::Vector2f(levelTwoParralax01SpriteCopy.getPosition().x + (levelTwoParralax01SpriteCopy.getLocalBounds().width * levelTwoParralax01SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax01SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax01SpriteCopy.getLocalBounds().width * levelTwoParralax01SpriteCopy.getScale().x))) {
		levelTwoParralax01SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 2 Original
	if (levelTwoParralax02Sprite.getPosition().x <= 0) {
		levelTwoParralax02SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax02Sprite.getPosition().x + (levelTwoParralax02Sprite.getLocalBounds().width * levelTwoParralax02Sprite.getScale().x), 0));
	}
	if (levelTwoParralax02Sprite.getPosition().x <= (-1 * (levelTwoParralax02Sprite.getLocalBounds().width * levelTwoParralax02Sprite.getScale().x))) {
		levelTwoParralax02Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 2 copy
	if (levelTwoParralax02SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax02Sprite.setPosition(sf::Vector2f(levelTwoParralax02SpriteCopy.getPosition().x + (levelTwoParralax02SpriteCopy.getLocalBounds().width * levelTwoParralax02SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax02SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax02SpriteCopy.getLocalBounds().width * levelTwoParralax02SpriteCopy.getScale().x))) {
		levelTwoParralax02SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 3 Original
	if (levelTwoParralax03Sprite.getPosition().x <= 0) {
		levelTwoParralax03SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax03Sprite.getPosition().x + (levelTwoParralax03Sprite.getLocalBounds().width * levelTwoParralax03Sprite.getScale().x), 0));
	}
	if (levelTwoParralax03Sprite.getPosition().x <= (-1 * (levelTwoParralax03Sprite.getLocalBounds().width * levelTwoParralax03Sprite.getScale().x))) {
		levelTwoParralax03Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 3 copy
	if (levelTwoParralax03SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax03Sprite.setPosition(sf::Vector2f(levelTwoParralax03SpriteCopy.getPosition().x + (levelTwoParralax03SpriteCopy.getLocalBounds().width * levelTwoParralax03SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax03SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax03SpriteCopy.getLocalBounds().width * levelTwoParralax03SpriteCopy.getScale().x))) {
		levelTwoParralax03SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 4 Original
	if (levelTwoParralax04Sprite.getPosition().x <= 0) {
		levelTwoParralax04SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax04Sprite.getPosition().x + (levelTwoParralax04Sprite.getLocalBounds().width * levelTwoParralax04Sprite.getScale().x), 0));
	}
	if (levelTwoParralax04Sprite.getPosition().x <= (-1 * (levelTwoParralax04Sprite.getLocalBounds().width * levelTwoParralax04Sprite.getScale().x))) {
		levelTwoParralax04Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 4 copy
	if (levelTwoParralax04SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax04Sprite.setPosition(sf::Vector2f(levelTwoParralax04SpriteCopy.getPosition().x + (levelTwoParralax04SpriteCopy.getLocalBounds().width * levelTwoParralax04SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax04SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax04SpriteCopy.getLocalBounds().width * levelTwoParralax04SpriteCopy.getScale().x))) {
		levelTwoParralax04SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 5 Original
	if (levelTwoParralax05Sprite.getPosition().x <= 0) {
		levelTwoParralax05SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax05Sprite.getPosition().x + (levelTwoParralax05Sprite.getLocalBounds().width * levelTwoParralax05Sprite.getScale().x), 0));
	}
	if (levelTwoParralax05Sprite.getPosition().x <= (-1 * (levelTwoParralax05Sprite.getLocalBounds().width * levelTwoParralax05Sprite.getScale().x))) {
		levelTwoParralax05Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 5 copy
	if (levelTwoParralax05SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax05Sprite.setPosition(sf::Vector2f(levelTwoParralax05SpriteCopy.getPosition().x + (levelTwoParralax05SpriteCopy.getLocalBounds().width * levelTwoParralax05SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax05SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax05SpriteCopy.getLocalBounds().width * levelOneParralax05SpriteCopy.getScale().x))) {
		levelTwoParralax05SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 6 Original
	if (levelTwoParralax06Sprite.getPosition().x <= 0) {
		levelTwoParralax06SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax06Sprite.getPosition().x + (levelTwoParralax06Sprite.getLocalBounds().width * levelTwoParralax06Sprite.getScale().x), 0));
	}
	if (levelTwoParralax06Sprite.getPosition().x <= (-1 * (levelTwoParralax06Sprite.getLocalBounds().width * levelTwoParralax06Sprite.getScale().x))) {
		levelTwoParralax06Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 6 copy
	if (levelTwoParralax06SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax06Sprite.setPosition(sf::Vector2f(levelTwoParralax06SpriteCopy.getPosition().x + (levelTwoParralax06SpriteCopy.getLocalBounds().width * levelTwoParralax06SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax06SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax06SpriteCopy.getLocalBounds().width * levelTwoParralax06SpriteCopy.getScale().x))) {
		levelTwoParralax06SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 7 Original
	if (levelTwoParralax07Sprite.getPosition().x <= 0) {
		levelTwoParralax07SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax07Sprite.getPosition().x + (levelTwoParralax07Sprite.getLocalBounds().width * levelTwoParralax07Sprite.getScale().x), 0));
	}
	if (levelTwoParralax07Sprite.getPosition().x <= (-1 * (levelTwoParralax07Sprite.getLocalBounds().width * levelTwoParralax07Sprite.getScale().x))) {
		levelTwoParralax07Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 7 copy
	if (levelTwoParralax07SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax07Sprite.setPosition(sf::Vector2f(levelTwoParralax07SpriteCopy.getPosition().x + (levelTwoParralax07SpriteCopy.getLocalBounds().width * levelTwoParralax07SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax07SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax07SpriteCopy.getLocalBounds().width * levelTwoParralax07SpriteCopy.getScale().x))) {
		levelTwoParralax07SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 8 Original
	if (levelTwoParralax08Sprite.getPosition().x <= 0) {
		levelTwoParralax08SpriteCopy.setPosition(sf::Vector2f(levelTwoParralax08Sprite.getPosition().x + (levelTwoParralax08Sprite.getLocalBounds().width * levelTwoParralax08Sprite.getScale().x), 0));
	}
	if (levelTwoParralax08Sprite.getPosition().x <= (-1 * (levelTwoParralax08Sprite.getLocalBounds().width * levelTwoParralax08Sprite.getScale().x))) {
		levelTwoParralax08Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 8 copy
	if (levelTwoParralax08SpriteCopy.getPosition().x <= 0) {
		levelTwoParralax08Sprite.setPosition(sf::Vector2f(levelTwoParralax08SpriteCopy.getPosition().x + (levelTwoParralax08SpriteCopy.getLocalBounds().width * levelTwoParralax08SpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralax08SpriteCopy.getPosition().x <= (-1 * (levelTwoParralax08SpriteCopy.getLocalBounds().width * levelTwoParralax08SpriteCopy.getScale().x))) {
		levelTwoParralax08SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// BG Original
	if (levelTwoParralaxBGSprite.getPosition().x <= 0) {
		levelTwoParralaxBGSpriteCopy.setPosition(sf::Vector2f(levelTwoParralaxBGSprite.getPosition().x + (levelTwoParralaxBGSprite.getLocalBounds().width * levelTwoParralaxBGSprite.getScale().x), 0));
	}
	if (levelTwoParralaxBGSprite.getPosition().x <= (-1 * (levelTwoParralaxBGSprite.getLocalBounds().width * levelTwoParralaxBGSprite.getScale().x))) {
		levelTwoParralaxBGSprite.setPosition(sf::Vector2f(0, 0));
	}
	// BG copy
	if (levelTwoParralaxBGSpriteCopy.getPosition().x <= 0) {
		levelTwoParralaxBGSprite.setPosition(sf::Vector2f(levelTwoParralaxBGSpriteCopy.getPosition().x + (levelTwoParralaxBGSpriteCopy.getLocalBounds().width * levelTwoParralaxBGSpriteCopy.getScale().x), 0));
	}
	if (levelTwoParralaxBGSpriteCopy.getPosition().x <= (-1 * (levelTwoParralaxBGSpriteCopy.getLocalBounds().width * levelTwoParralaxBGSpriteCopy.getScale().x))) {
		levelTwoParralaxBGSpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
}

void Game::backgroundMovementLevel3() {
	levelThreeParralaxBGSprite.move(sf::Vector2f(-100 * f_ElapsedTime, 0));
	levelThreeParralax01Sprite.move(sf::Vector2f(-200 * f_ElapsedTime, 0));
	levelThreeParralax02Sprite.move(sf::Vector2f(-300 * f_ElapsedTime, 0));
	levelThreeParralax03Sprite.move(sf::Vector2f(-400 * f_ElapsedTime, 0));
	levelThreeParralax04Sprite.move(sf::Vector2f(-500 * f_ElapsedTime, 0));
	levelThreeParralax05Sprite.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	levelThreeParralax06Sprite.move(sf::Vector2f(-800 * f_ElapsedTime, 0));
	levelThreeParralax07Sprite.move(sf::Vector2f(-800 * f_ElapsedTime, 0));
	levelThreeParralaxBGSpriteCopy.move(sf::Vector2f(-100 * f_ElapsedTime, 0));
	levelThreeParralax01SpriteCopy.move(sf::Vector2f(-200 * f_ElapsedTime, 0));
	levelThreeParralax02SpriteCopy.move(sf::Vector2f(-300 * f_ElapsedTime, 0));
	levelThreeParralax03SpriteCopy.move(sf::Vector2f(-400 * f_ElapsedTime, 0));
	levelThreeParralax04SpriteCopy.move(sf::Vector2f(-500 * f_ElapsedTime, 0));
	levelThreeParralax05SpriteCopy.move(sf::Vector2f(-600 * f_ElapsedTime, 0));
	levelThreeParralax06SpriteCopy.move(sf::Vector2f(-800 * f_ElapsedTime, 0));
	levelThreeParralax07SpriteCopy.move(sf::Vector2f(-800 * f_ElapsedTime, 0));
	// 1 Original
	if (levelThreeParralax01Sprite.getPosition().x <= 0) {
		levelThreeParralax01SpriteCopy.setPosition(sf::Vector2f(levelThreeParralax01Sprite.getPosition().x + (levelThreeParralax01Sprite.getLocalBounds().width * levelThreeParralax01Sprite.getScale().x), 0));
	}
	if (levelThreeParralax01Sprite.getPosition().x <= (-1 * (levelThreeParralax01Sprite.getLocalBounds().width * levelThreeParralax01Sprite.getScale().x))) {
		levelThreeParralax01Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 1 copy
	if (levelThreeParralax01SpriteCopy.getPosition().x <= 0) {
		levelThreeParralax01Sprite.setPosition(sf::Vector2f(levelThreeParralax01SpriteCopy.getPosition().x + (levelThreeParralax01SpriteCopy.getLocalBounds().width * levelThreeParralax01SpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralax01SpriteCopy.getPosition().x <= (-1 * (levelThreeParralax01SpriteCopy.getLocalBounds().width * levelThreeParralax01SpriteCopy.getScale().x))) {
		levelThreeParralax01SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 2 Original
	if (levelThreeParralax02Sprite.getPosition().x <= 0) {
		levelThreeParralax02SpriteCopy.setPosition(sf::Vector2f(levelThreeParralax02Sprite.getPosition().x + (levelThreeParralax02Sprite.getLocalBounds().width * levelThreeParralax02Sprite.getScale().x), 0));
	}
	if (levelThreeParralax02Sprite.getPosition().x <= (-1 * (levelThreeParralax02Sprite.getLocalBounds().width * levelThreeParralax02Sprite.getScale().x))) {
		levelThreeParralax02Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 2 copy
	if (levelThreeParralax02SpriteCopy.getPosition().x <= 0) {
		levelThreeParralax02Sprite.setPosition(sf::Vector2f(levelThreeParralax02SpriteCopy.getPosition().x + (levelThreeParralax02SpriteCopy.getLocalBounds().width * levelThreeParralax02SpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralax02SpriteCopy.getPosition().x <= (-1 * (levelThreeParralax02SpriteCopy.getLocalBounds().width * levelThreeParralax02SpriteCopy.getScale().x))) {
		levelThreeParralax02SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 3 Original
	if (levelThreeParralax03Sprite.getPosition().x <= 0) {
		levelThreeParralax03SpriteCopy.setPosition(sf::Vector2f(levelThreeParralax03Sprite.getPosition().x + (levelThreeParralax03Sprite.getLocalBounds().width * levelThreeParralax03Sprite.getScale().x), 0));
	}
	if (levelThreeParralax03Sprite.getPosition().x <= (-1 * (levelThreeParralax03Sprite.getLocalBounds().width * levelThreeParralax03Sprite.getScale().x))) {
		levelThreeParralax03Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 3 copy
	if (levelThreeParralax03SpriteCopy.getPosition().x <= 0) {
		levelThreeParralax03Sprite.setPosition(sf::Vector2f(levelThreeParralax03SpriteCopy.getPosition().x + (levelThreeParralax03SpriteCopy.getLocalBounds().width * levelThreeParralax03SpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralax03SpriteCopy.getPosition().x <= (-1 * (levelThreeParralax03SpriteCopy.getLocalBounds().width * levelThreeParralax03SpriteCopy.getScale().x))) {
		levelThreeParralax03SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 4 Original
	if (levelThreeParralax04Sprite.getPosition().x <= 0) {
		levelThreeParralax04SpriteCopy.setPosition(sf::Vector2f(levelThreeParralax04Sprite.getPosition().x + (levelThreeParralax04Sprite.getLocalBounds().width * levelThreeParralax04Sprite.getScale().x), 0));
	}
	if (levelThreeParralax04Sprite.getPosition().x <= (-1 * (levelThreeParralax04Sprite.getLocalBounds().width * levelThreeParralax04Sprite.getScale().x))) {
		levelThreeParralax04Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 4 copy
	if (levelThreeParralax04SpriteCopy.getPosition().x <= 0) {
		levelThreeParralax04Sprite.setPosition(sf::Vector2f(levelThreeParralax04SpriteCopy.getPosition().x + (levelThreeParralax04SpriteCopy.getLocalBounds().width * levelThreeParralax04SpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralax04SpriteCopy.getPosition().x <= (-1 * (levelThreeParralax04SpriteCopy.getLocalBounds().width * levelThreeParralax04SpriteCopy.getScale().x))) {
		levelThreeParralax04SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 5 Original
	if (levelThreeParralax05Sprite.getPosition().x <= 0) {
		levelThreeParralax05SpriteCopy.setPosition(sf::Vector2f(levelThreeParralax05Sprite.getPosition().x + (levelThreeParralax05Sprite.getLocalBounds().width * levelThreeParralax05Sprite.getScale().x), 0));
	}
	if (levelThreeParralax05Sprite.getPosition().x <= (-1 * (levelThreeParralax05Sprite.getLocalBounds().width * levelThreeParralax05Sprite.getScale().x))) {
		levelThreeParralax05Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 5 copy
	if (levelThreeParralax05SpriteCopy.getPosition().x <= 0) {
		levelThreeParralax05Sprite.setPosition(sf::Vector2f(levelThreeParralax05SpriteCopy.getPosition().x + (levelThreeParralax05SpriteCopy.getLocalBounds().width * levelThreeParralax05SpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralax05SpriteCopy.getPosition().x <= (-1 * (levelThreeParralax05SpriteCopy.getLocalBounds().width * levelThreeParralax05SpriteCopy.getScale().x))) {
		levelThreeParralax05SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 6 Original
	if (levelThreeParralax06Sprite.getPosition().x <= 0) {
		levelThreeParralax06SpriteCopy.setPosition(sf::Vector2f(levelThreeParralax06Sprite.getPosition().x + (levelThreeParralax06Sprite.getLocalBounds().width * levelThreeParralax06Sprite.getScale().x), 0));
	}
	if (levelThreeParralax06Sprite.getPosition().x <= (-1 * (levelThreeParralax06Sprite.getLocalBounds().width * levelThreeParralax06Sprite.getScale().x))) {
		levelThreeParralax06Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 6 copy
	if (levelThreeParralax06SpriteCopy.getPosition().x <= 0) {
		levelThreeParralax06Sprite.setPosition(sf::Vector2f(levelThreeParralax06SpriteCopy.getPosition().x + (levelThreeParralax06SpriteCopy.getLocalBounds().width * levelThreeParralax06SpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralax06SpriteCopy.getPosition().x <= (-1 * (levelThreeParralax06SpriteCopy.getLocalBounds().width * levelThreeParralax06SpriteCopy.getScale().x))) {
		levelThreeParralax06SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// 7 Original
	if (levelThreeParralax07Sprite.getPosition().x <= 0) {
		levelThreeParralax07SpriteCopy.setPosition(sf::Vector2f(levelThreeParralax07Sprite.getPosition().x + (levelThreeParralax07Sprite.getLocalBounds().width * levelThreeParralax07Sprite.getScale().x), 0));
	}
	if (levelThreeParralax07Sprite.getPosition().x <= (-1 * (levelThreeParralax07Sprite.getLocalBounds().width * levelThreeParralax07Sprite.getScale().x))) {
		levelThreeParralax07Sprite.setPosition(sf::Vector2f(0, 0));
	}
	// 7 copy
	if (levelThreeParralax07SpriteCopy.getPosition().x <= 0) {
		levelThreeParralax07Sprite.setPosition(sf::Vector2f(levelThreeParralax07SpriteCopy.getPosition().x + (levelThreeParralax07SpriteCopy.getLocalBounds().width * levelThreeParralax07SpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralax07SpriteCopy.getPosition().x <= (-1 * (levelThreeParralax07SpriteCopy.getLocalBounds().width * levelThreeParralax07SpriteCopy.getScale().x))) {
		levelThreeParralax07SpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
	// BG Original
	if (levelThreeParralaxBGSprite.getPosition().x <= 0) {
		levelThreeParralaxBGSpriteCopy.setPosition(sf::Vector2f(levelThreeParralaxBGSprite.getPosition().x + (levelThreeParralaxBGSprite.getLocalBounds().width * levelThreeParralaxBGSprite.getScale().x), 0));
	}
	if (levelThreeParralaxBGSprite.getPosition().x <= (-1 * (levelThreeParralaxBGSprite.getLocalBounds().width * levelThreeParralaxBGSprite.getScale().x))) {
		levelThreeParralaxBGSprite.setPosition(sf::Vector2f(0, 0));
	}
	// BG copy
	if (levelThreeParralaxBGSpriteCopy.getPosition().x <= 0) {
		levelThreeParralaxBGSprite.setPosition(sf::Vector2f(levelThreeParralaxBGSpriteCopy.getPosition().x + (levelThreeParralaxBGSpriteCopy.getLocalBounds().width * levelThreeParralaxBGSpriteCopy.getScale().x), 0));
	}
	if (levelThreeParralaxBGSpriteCopy.getPosition().x <= (-1 * (levelThreeParralaxBGSpriteCopy.getLocalBounds().width * levelThreeParralaxBGSpriteCopy.getScale().x))) {
		levelThreeParralaxBGSpriteCopy.setPosition(sf::Vector2f(0, 0));
	}
}

void Game::setShooterPositions() {
	shooterPositions.push_back({ (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.1) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.3) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.5) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.7) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.9) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.1) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.3) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.5) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.7) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.9) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.1) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.3) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.5) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.7) });
	shooterPositions.push_back({ (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.9) });
}

void Game::setEnemySpawn(int numberOfEnnemies, bool isBonusSpawning) {
	int randomYPosition(0), randomSize(0), randomClass(0), randomBonusName(0), randomBonusXPos(0);
	const float xSpawnPosition = window.getSize().x + 100.f;
	const float randomHeights[9] = {
		window.getSize().y * 0.10f, window.getSize().y * 0.20f, window.getSize().y * 0.30f, 
		window.getSize().y * 0.40f, window.getSize().y * 0.50f, window.getSize().y * 0.60f,
		window.getSize().y * 0.70f, window.getSize().y * 0.80f, window.getSize().y * 0.90f
	};
	const char randomSizes[3] = { 's', 'm', 'l' };
	const char* bonusNames[3] = { "shield", "x2", "oneUp" };
	const float bonusXSpawn[2] = { (float)window.getSize().x * 0.1f, (float)window.getSize().x * 0.2f };
	std::vector<sf::Texture*> randomEnemySkins = { &apple, &burger, &banana, &painBizarre, &carrot, &tomato, &fries, &salad, &avocado, &pepper };
	for (int i = 0; i < numberOfEnnemies; ++i) {
		randomClass = rand() % 3 + 1;
		randomSize = rand() % 3;
		randomYPosition = rand() % 9;

		Normal normal  (xSpawnPosition, randomHeights[randomYPosition], randomSizes[randomSize], window, candy/**randomEnemySkins[rand() % 10]*/);
		//COMPORTEMENT DE BASE
		//Shooter shooter(xSpawnPosition, randomHeights[randomYPosition], randomSizes[randomSize], window, *randomEnemySkins[rand() % 10]);
		//NOUVEAU COMPORTEMENT
		Shooter shooter(xSpawnPosition, randomHeights[randomYPosition], randomSizes[randomSize], window, *randomEnemySkins[rand() % 10], player);
		Elite elite    (xSpawnPosition, randomHeights[randomYPosition], randomSizes[randomSize], window, *randomEnemySkins[rand() % 10]);

		switch (randomClass) {
		case 1:
			vectorNormal.push_back(normal);
			break;
		case 2:
			vectorShooter.push_back(shooter);
			break;
		case 3:
			vectorElite.push_back(elite);
			break;
		default:
			break;
		}
	}
	if (isBonusSpawning) { // Paramètre optionnel, valeur par défaut set à false.
		randomBonusName = rand() % 3;
		randomBonusXPos = rand() % 2;
		Bonus* bonus = new Bonus(bonusXSpawn[randomBonusXPos], -50.f, bonusNames[randomBonusName], player);
		vectorBonus.push_back(bonus);
	}
}

void Game::endScreenInit() {
	std::string totalScore = "";
	if (language == "FR")
		totalScore = "Score final : " + std::to_string((int)scoreCounter);
	else if (language == "EN")
		totalScore = "Final score : " + std::to_string((int)scoreCounter);
	std::string totalKills = std::to_string(deadEnnemies);
	std::string damageTaken = std::to_string(damageTakenPlayer);
	levelEndScreenTitle = gameplayPauseTitleText;
	if (language == "EN")
		levelEndScreenTitle.setString("Level completed");
	else if (language == "FR")
		levelEndScreenTitle.setString("Niveau terminé");
	levelEndScreenTitle.setPosition(sf::Vector2f(window.getSize().x / 2 - levelEndScreenTitle.getLocalBounds().width / 2, levelEndScreenTitle.getPosition().y));
	levelEndScreenNextButton = gameplayPauseGoBackText;
	if (language == "EN")
		levelEndScreenNextButton.setString("Next");
	else if (language == "FR")
		levelEndScreenNextButton.setString("Suivant");
	levelEndScreenNextButton.setPosition(sf::Vector2f(gameplayPauseContent.getPosition().x + gameplayPauseContent.getLocalBounds().width - levelEndScreenNextButton.getLocalBounds().width - window.getSize().x * 0.03f, levelEndScreenNextButton.getPosition().y));
	levelEndScreenQuitButton = gameplayPauseExitText;
	if (language == "EN")
		levelEndScreenQuitButton.setString("Quit");
	else if (language == "FR")
		levelEndScreenQuitButton.setString("Quitter");
	levelEndScreenQuitButton.setPosition(sf::Vector2f(gameplayPauseContent.getPosition().x + window.getSize().x * 0.03f, levelEndScreenQuitButton.getPosition().y));
	levelEndScreenTotalScore = levelEndScreenQuitButton;
	levelEndScreenTotalScore.setString(totalScore);
	levelEndScreenTotalScore.setPosition(sf::Vector2f(window.getSize().x / 2 - levelEndScreenTotalScore.getLocalBounds().width / 2, levelEndScreenQuitButton.getPosition().y - 70.f));
	levelEndScreenTotalEnnemiesKilled = levelEndScreenTotalScore;
	if (language == "EN")
		levelEndScreenTotalEnnemiesKilled.setString("Enemies killed : " + totalKills);
	else if (language == "FR")
		levelEndScreenTotalEnnemiesKilled.setString("Ennemis tués : " + totalKills);
	levelEndScreenTotalEnnemiesKilled.setPosition(sf::Vector2f(window.getSize().x / 2 - levelEndScreenTotalEnnemiesKilled.getLocalBounds().width / 2, levelEndScreenTotalScore.getPosition().y - 70.f));
	levelEndScreenTotalDamageTaken = levelEndScreenTotalEnnemiesKilled;
	if (language == "EN")
		levelEndScreenTotalDamageTaken.setString("Damage taken : " + damageTaken);
	else if (language == "FR")
		levelEndScreenTotalDamageTaken.setString("Dégats pris : " + damageTaken);
	levelEndScreenTotalDamageTaken.setPosition(sf::Vector2f(window.getSize().x / 2 - levelEndScreenTotalDamageTaken.getLocalBounds().width / 2, levelEndScreenTotalEnnemiesKilled.getPosition().y - 70.f));
}

void Game::clearAllVectors() {
	for (auto bonus : vectorBonus) {
		delete bonus;
	}
	vectorBonus.clear();
	for (auto pie : vectorPie) {
		delete pie;
	}
	vectorPie.clear();
	for (auto sugar : vectorSugar) {
		delete sugar;
	}
	vectorSugar.clear();
	for (auto projectile : vectorProjectile) {
		delete projectile;
	}
	vectorProjectile.clear();
	vectorNormal.clear();
	vectorShooter.clear();
	vectorElite.clear();
	shooterPositions.clear();
	for (int i = 0; i < 15; ++i) {
		positionsOccupied[i] = false;
	}
	damageTakenPlayer = 0;
	deadEnnemies = 0;
	scoreCounter = 0;
}

void Game::FPSCalculation() {
	// FPS calculation
	f_ElapsedTime = Clock.restart().asSeconds();
	float f_FPS = (1.f / f_ElapsedTime);
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << f_FPS;
	std::string FPSValue = oss.str();
	FPSText.setString("FPS : " + FPSValue);
}

void Game::clownWalkAnimation() {
	if (player.getPlayerLife()) {
		if (clownWalkAnimationTime >= 0.1f) playerCurrentSprite.setTexture(playerMove2);
		if (clownWalkAnimationTime >= 0.2f) {
			playerCurrentSprite.setTexture(playerMove1);

			clownWalkAnimationTime = 0.f;
		}
	}
}

void Game::bossAnimation() {
	if (bossAnimationTime >= 0.1f)
		boss.setTexture(bossTexture1);
	if (bossAnimationTime >= 0.2f)
		boss.setTexture(bossTexture2);
	if (bossAnimationTime >= 0.3f) {
		boss.setTexture(bossTexture3);
		bossAnimationTime = 0;
	}
	if (bossEyeAnimationTime <= 3.f) {
		bossEye.setTexture(bossEyeTexture1);
		bossEye2.setTexture(bossEyeTexture1);
	}
	if (bossEyeAnimationTime >= 3.1f) {
		bossEye.setTexture(bossEyeTexture2);
		bossEye2.setTexture(bossEyeTexture2);
	}
	if (bossEyeAnimationTime >= 3.2f) {
		bossEye.setTexture(bossEyeTexture3);
		bossEye2.setTexture(bossEyeTexture3);
	}
	if (bossEyeAnimationTime >= 3.3f) {
		bossEye.setTexture(bossEyeTexture2);
		bossEye2.setTexture(bossEyeTexture2);
	}
	if (bossEyeAnimationTime >= 3.4f)
		bossEyeAnimationTime = 0.f;
}

void Game::scoreCalculation() {
	if (scoreCounter < 10)
		gameplayUIScoreText.setString("Score : 00000" + std::to_string((int)scoreCounter));
	else if (scoreCounter < 100)
		gameplayUIScoreText.setString("Score : 0000" + std::to_string((int)scoreCounter));
	else if (scoreCounter < 1000)
		gameplayUIScoreText.setString("Score : 000" + std::to_string((int)scoreCounter));
	else if (scoreCounter < 10000)
		gameplayUIScoreText.setString("Score : 00" + std::to_string((int)scoreCounter));
	else if (scoreCounter < 100000)
		gameplayUIScoreText.setString("Score : 0" + std::to_string((int)scoreCounter));
	else
		gameplayUIScoreText.setString("Score : " + std::to_string((int)scoreCounter));
}

void Game::sugarCalculation() {
	if (player.getSugarCount() < 10)
		gameplayUISugarText.setString("0000000" + std::to_string((int)player.getSugarCount()));
	else if (player.getSugarCount() < 100)
		gameplayUISugarText.setString("000000" + std::to_string((int)player.getSugarCount()));
	else if (player.getSugarCount() < 1000)
		gameplayUISugarText.setString("00000" + std::to_string((int)player.getSugarCount()));
	else if (player.getSugarCount() < 10000)
		gameplayUISugarText.setString("0000" + std::to_string((int)player.getSugarCount()));
	else if (player.getSugarCount() < 100000)
		gameplayUISugarText.setString("000" + std::to_string((int)player.getSugarCount()));
	else if (player.getSugarCount() < 1000000)
		gameplayUISugarText.setString("00" + std::to_string((int)player.getSugarCount()));
	else if (player.getSugarCount() < 10000000)
		gameplayUISugarText.setString("0" + std::to_string((int)player.getSugarCount()));
	else
		gameplayUISugarText.setString("Score : " + std::to_string((int)player.getSugarCount()));
}

void Game::statCalculation() {
	// UPDATE STRING
	if (language == "EN") {
		atkLvlString = "ATK (" + std::to_string(player.atkLvl) + ")      UP : " + std::to_string(player.atkLvlUpCost);
		maxHpLvlString = "HP (" + std::to_string(player.maxHpLvl) + ")        UP : " + std::to_string(player.maxHpLvlUpCost);
		speedLvlString = "SPEED (" + std::to_string(player.speedLvl) + ")  UP : " + std::to_string(player.speedLvlUpCost);
		baseSpecialString = "BASE";
		if (player.tripleBought) tripleSpecialString = "TRIPLE";
		else { tripleSpecialString = "TRIPLE COST : " + std::to_string(player.tripleCost); }
		if (player.rainBought) rainSpecialString = "RAIN";
		else { rainSpecialString = "RAIN COST : " + std::to_string(player.rainCost); }
	}
	else if (language == "FR") {
		atkLvlString = "ATQ (" + std::to_string(player.atkLvl) + ")      SUP : " + std::to_string(player.atkLvlUpCost);
		maxHpLvlString = "PV (" + std::to_string(player.maxHpLvl) + ")        SUP : " + std::to_string(player.maxHpLvlUpCost);
		speedLvlString = "VIT (" + std::to_string(player.speedLvl) + ")  SUP : " + std::to_string(player.speedLvlUpCost);
		baseSpecialString = "BASE";
		if (player.tripleBought) tripleSpecialString = "TRIPLE";
		else { tripleSpecialString = "PRIX TRIPLE : " + std::to_string(player.tripleCost); }
		if (player.rainBought) rainSpecialString = "PLUIE";
		else { rainSpecialString = "PRIX PLUIE : " + std::to_string(player.rainCost); }
	}
	// SET STRING
	gameplayUIStatAtkText.setString(atkLvlString);
	gameplayUIStatMaxHpText.setString(maxHpLvlString);
	gameplayUIStatSpeedText.setString(speedLvlString);
	gameplayUISetSpecialBase.setString(baseSpecialString);
	gameplayUISetSpecialTriple.setString(tripleSpecialString);
	gameplayUISetSpecialRain.setString(rainSpecialString);
	// SET POSITION
	gameplayUISetSpecialBase.setPosition(window.getSize().x * 0.01f, window.getSize().y - gameplayUISetSpecialBase.getCharacterSize() * 1.5f);
	gameplayUISetSpecialTriple.setPosition(gameplayUISetSpecialBase.getPosition().x + gameplayUISetSpecialBase.getLocalBounds().width + window.getSize().x * 0.05f, gameplayUISetSpecialBase.getPosition().y);
	gameplayUISetSpecialRain.setPosition(gameplayUISetSpecialTriple.getPosition().x + gameplayUISetSpecialTriple.getLocalBounds().width + window.getSize().x * 0.05f, gameplayUISetSpecialBase.getPosition().y);
	gameplayUIStatAtkText.setPosition(gameplayUISetSpecialBase.getPosition().x, gameplayUIStatMaxHpText.getPosition().y - gameplayUIStatMaxHpText.getCharacterSize());
	sugarIcone.setPosition(gameplayUIStatAtkText.getPosition().x + gameplayUISugarText.getLocalBounds().width + window.getSize().x * 0.005f, gameplayUIStatAtkText.getPosition().y - gameplayUIStatAtkText.getLocalBounds().height);
	gameplayUISugarText.setPosition(sugarIcone.getPosition().x - gameplayUISugarText.getGlobalBounds().width - window.getSize().x * 0.005f, sugarIcone.getPosition().y - gameplayUISugarText.getGlobalBounds().height * 0.2f);
	gameplayUIStatMaxHpText.setPosition(gameplayUISetSpecialBase.getPosition().x, gameplayUIStatSpeedText.getPosition().y - gameplayUIStatSpeedText.getCharacterSize());
	gameplayUIStatSpeedText.setPosition(gameplayUISetSpecialBase.getPosition().x, gameplayUISetSpecialBase.getPosition().y - gameplayUIStatSpeedText.getCharacterSize() * 1.1f);
}

void Game::playerInput() {
	if (player.getPlayerLife()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			player.move(0, -player.getSpeed() * f_ElapsedTime);
			if (player.getPosition().y <= 0)
				player.setPosition(player.getPosition().x, 0);
			playerCurrentSprite.setPosition(player.getPosition());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.move(0, player.getSpeed() * f_ElapsedTime);
			if (player.getPosition().y + player.getRadius() * 2 >= window.getSize().y)
				player.setPosition(player.getPosition().x, window.getSize().y - player.getRadius() * 2);
			playerCurrentSprite.setPosition(player.getPosition());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.move(player.getSpeed() * f_ElapsedTime, 0);
			if (player.getPosition().x >= window.getSize().x - player.getRadius() * 2)
				player.setPosition(window.getSize().x - player.getRadius() * 2, player.getPosition().y);
			playerCurrentSprite.setPosition(player.getPosition());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			player.move(-player.getSpeed() * f_ElapsedTime, 0);
			if (player.getPosition().x <= 0)
				player.setPosition(0, player.getPosition().y);
			playerCurrentSprite.setPosition(player.getPosition());
		}                                           // EFFET DE CINEMATIQUE
		if (!boss.spawning) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (backgroundActive) {
					// Ici y'aura le shoot
					if (player.getShootTimer() >= player.getShootCooldown()) {
						player.throwPie(vectorPie, window);
						player.resetShootTimer(0);
					}
					playerCurrentSprite.setTexture(playerAttack1);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
				if (backgroundActive) {
					// SPECIAL ATTACK
					if (player.getSpecialTimer() >= player.getSpecialCooldown()) {
						player.specialAtk(vectorPie, window);
						player.resetSpecialTimer(0);
						if (player.getSpectialAtkType() == "rain") {
							player.raining = true;
							player.rainCount++;
						}
					}
					playerCurrentSprite.setTexture(playerAttack1);
				}
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		if (backgroundActive) {
			backgroundActive = false;
			showPauseMenu = true;
			if (levelOneOn)
				bgLvl1Music.pause();
			else if (levelTwoOn)
				bgLvl2Music.pause();
			else if (levelThreeOn)
				bgLvl3Music.pause();
		}
	}
	shieldSprite.setPosition(playerCurrentSprite.getPosition());

	if (player.raining) {
		if (player.getSpecialTimer() >= 0.3 && player.rainCount == 1) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 0.6 && player.rainCount == 2) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 0.9 && player.rainCount == 3) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 1.2 && player.rainCount == 4) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 1.5 && player.rainCount == 5) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 1.8 && player.rainCount == 6) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 2.1 && player.rainCount == 7) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 2.4 && player.rainCount == 8) { player.specialAtk(vectorPie, window); player.rainCount++; }
		if (player.getSpecialTimer() >= 2.7) { player.specialAtk(vectorPie, window); player.raining = false; player.rainCount = 0; }
	}
}

void Game::playerCollisions() {
	if (player.getPlayerLife()) {
		if (player.hurtTimer >= 0.5) {   // COOLDOWN D'INVINCIBILITE APRES DEGATS RECUS
			player.hurtTimer = 0;
			player.hurtCount = 0;
		}
		if (player.hurtCount == 0) {        //INVINCIBLE PENDANT UNE COURTE DUREE APRES AVOIR PRIT DES DEGATS
			for (Projectile*& projectile : vectorProjectile) {
				if (player.getGlobalBounds().contains(projectile->getPosition())) {     ///// hurt box plus petite (cercle) pour les projectiles
					if (player.getShield()) {
						player.setShield(false);
						player.hurtCount++;
					}
					else {
						player.damagePlayer(projectile->getAtkPower());
						oofSound.play();
						player.hurtCount++;
						playerCurrentSprite.setColor(LIGHT_RED);
						player.noHitTimer = 0;
						damageTakenPlayer += (int)projectile->getAtkPower();
					}
					projectile->setState(false);
				}
			}
			for (Normal& normal : vectorNormal) {
				if (player.getGlobalBounds().intersects(normal.getGlobalBounds())) {
					if (player.getShield()) {
						player.setShield(false);
					}
					else {
						player.damagePlayer(normal.getAtkPower()); player.hurtCount++; playerCurrentSprite.setColor(LIGHT_RED);
						oofSound.play();
						player.noHitTimer = 0;
						damageTakenPlayer += (int)normal.getAtkPower();
					}
				}
			}
			for (Shooter& shooter : vectorShooter) {
				if (player.getGlobalBounds().intersects(shooter.getGlobalBounds())) {
					if (player.getShield()) {
						player.setShield(false);
					}
					else {
						player.damagePlayer(shooter.getAtkPower()); player.hurtCount++; playerCurrentSprite.setColor(LIGHT_RED);
						oofSound.play();
						player.noHitTimer = 0;
						damageTakenPlayer += (int)shooter.getAtkPower();
					}
				}
			}
			for (Elite& elite : vectorElite) {
				if (player.getGlobalBounds().intersects(elite.getGlobalBounds())) {
					if (player.getShield()) {
						player.setShield(false);
					}
					else {
						player.damagePlayer(elite.getAtkPower()); player.hurtCount++; playerCurrentSprite.setColor(LIGHT_RED);
						oofSound.play();
						player.noHitTimer = 0;
						damageTakenPlayer += (int)elite.getAtkPower();
					}
				}
			}
			if (player.getGlobalBounds().intersects(boss.getGlobalBounds())) {
				if (player.getShield()) {
					player.setShield(false);
				}
				else {
					player.damagePlayer(boss.getAtkPower()); player.hurtCount++; playerCurrentSprite.setColor(LIGHT_RED);
					oofSound.play();
					player.noHitTimer = 0;
					damageTakenPlayer += (int)boss.getAtkPower();
				}
			}
		}
		for (Sugar*& sugar : vectorSugar) {
			//PROBLEME DE TAILLE DE POINTEUR, ON FAIT DONC PAR RAPPORT A LA TEXTURE * UN SCALING FIXE. PAREIL POUR LA BOUCLE DES BONUS EN DESSOUS
			if (playerCurrentSprite.getGlobalBounds().contains(sugar->getPosition().x, sugar->getPosition().y) ||
				playerCurrentSprite.getGlobalBounds().contains(sugar->getPosition().x, sugar->getPosition().y + sugarIcone.getLocalBounds().height * 0.08f) ||
				playerCurrentSprite.getGlobalBounds().contains(sugar->getPosition().x + sugarIcone.getLocalBounds().width * 0.08f, sugar->getPosition().y + sugarIcone.getLocalBounds().height * 0.08f) ||
				playerCurrentSprite.getGlobalBounds().contains(sugar->getPosition().x + sugarIcone.getLocalBounds().width * 0.08f, sugar->getPosition().y))
			{
				player.setSugarCount(sugar->getValue());
				player.healPlayer(player.getPlayerMaxHP() * sugar->healValue);
				if (player.getPlayerHP() > player.getPlayerMaxHP()) player.setPlayerHP(player.getPlayerMaxHP());
				sugarCrunchSound.play();
				sugar->setState(false);
			}
		}
		for (Bonus*& bonus : vectorBonus) {
			if (playerCurrentSprite.getGlobalBounds().contains(bonus->getPosition().x, bonus->getPosition().y) ||
				playerCurrentSprite.getGlobalBounds().contains(bonus->getPosition().x, bonus->getPosition().y + bonusIconeTemplate.getLocalBounds().height * 0.05f) ||
				playerCurrentSprite.getGlobalBounds().contains(bonus->getPosition().x + bonusIconeTemplate.getLocalBounds().width * 0.05f, bonus->getPosition().y + bonusIconeTemplate.getLocalBounds().height * 0.05f) ||
				playerCurrentSprite.getGlobalBounds().contains(bonus->getPosition().x + bonusIconeTemplate.getLocalBounds().width * 0.05f, bonus->getPosition().y))
			{

				player.setBonusCooldown(bonus->getCooldown());                     //actuellement, ramasser un 2e bonus refresh le timer du 1er
				if (bonus->getId() == "shield") { player.setShield(true); }
				if (bonus->getId() == "x2") { player.setX2(true); }
				if (bonus->getId() == "oneUp") { player.setOneUp(true); }
				player.resetBonusTimer(0);
				bonus->setState(false);
			}
		}
	}
}

void Game::playerHPSetter() {
	if (player.getPlayerHP() <= player.getPlayerMaxHP()) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 19 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 18 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar02Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar02Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 18 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 17 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar03Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar03Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 17 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 16 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar04Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar04Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 16 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 15 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar05Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar05Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 15 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 14 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar06Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar06Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 14 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 13 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar07Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar07Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 13 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 12 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar08Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar08Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 12 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 11 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar09Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar09Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 11 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 10 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar10Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar10Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 10 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 9 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar11Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar11Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 9 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 8 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar12Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar12Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 8 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 7 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar13Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar13Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 7 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 6 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar14Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar14Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 6 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 5 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar15Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar15Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 5 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 4 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar16Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar16Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 4 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 3 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar17Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar17Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 3 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 2 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar18Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar18Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 2 / 20 && player.getPlayerHP() > player.getPlayerMaxHP() * 1 / 20) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar19Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar19Inactive); }
	}
	if (player.getPlayerHP() <= player.getPlayerMaxHP() * 1 / 20 && player.getPlayerHP() > 0.f) {
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar20Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar20Inactive); }
	}
	if (player.getPlayerHP() <= 0.f) {
		player.setPlayerHP(0);
		if (player.getSpecialTimer() >= player.getSpecialCooldown())
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar21Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar21Inactive); }
	}
}

void Game::playerBonusSetter() {
	//SCORE MULTIPLIER
	if (player.noHitTimer > player.noHitCooldown) {
		player.noHitMultiplier = 1.5;
		showNoHitBonus = true;
	}
	else { player.noHitMultiplier = 1; showNoHitBonus = false; }

	if (player.accuracyCounter >= player.accuracyBonusSetter) {
		player.accuracyMultiplier = 1.5;
		showNoMissBonus = true;
	}
	else { player.accuracyMultiplier = 1; showNoMissBonus = false; }

	//ACTUAL BONUS
	shieldDraw.setSize(sf::Vector2f(30, 30));
	shieldDraw.setPosition(gameplayUILifeBarCurrentSprite.getPosition().x + window.getSize().y * 0.01f,
		gameplayUILifeBarCurrentSprite.getPosition().y + (gameplayUILifeBarCurrentSprite.getLocalBounds().height * gameplayUILifeBarCurrentSprite.getScale().y) + window.getSize().y * 0.01f);
	shieldDraw.setTexture(&shieldIconeTexture);

	x2Draw.setSize(sf::Vector2f(30, 30));
	x2Draw.setPosition(shieldDraw.getPosition().x + shieldDraw.getSize().x + window.getSize().y * 0.01f, shieldDraw.getPosition().y);
	x2Draw.setTexture(&x2IconeTexture);

	oneUpDraw.setSize(sf::Vector2f(30, 30));
	oneUpDraw.setPosition(x2Draw.getPosition().x + x2Draw.getSize().x + window.getSize().y * 0.01f, x2Draw.getPosition().y);
	oneUpDraw.setTexture(&oneUpIconeTexture);

	if (player.getBonusTimer() >= player.getBonusCooldown()) {
		player.setShield(false);
		player.setX2(false);
		player.setOneUp(false);
		player.resetBonusTimer(0);
	}
}

bool Game::playerDeath() {
	if (player.getPlayerHP() == 0) {
		if (player.getOneUp()) {
			player.setOneUp(false);
			player.setPlayerHP(player.getPlayerMaxHP() / 2.f);
		}
		else { player.setPlayerLife(false); }

	}
	if (!player.getPlayerLife()) {
		playerCurrentSprite.setColor(sf::Color::White);
		deathCounter++;
		if (deathCounter == 1) {
			bgLvl1Music.stop();
			bgLvl2Music.stop();
			bgLvl3Music.stop();
			playerDeathSound.play();
		}
		gameOverAnimation += f_ElapsedTime;
		

		if (gameOverAnimation > 0 && gameOverAnimation <= 0.2)
			playerCurrentSprite.setTexture(playerDeath1);
		if (gameOverAnimation > 0.2 && gameOverAnimation <= 0.4)
			playerCurrentSprite.setTexture(playerDeath2);
		if (gameOverAnimation > 0.4 && gameOverAnimation <= 0.9)
			playerCurrentSprite.setTexture(playerDeath3);
		if (gameOverAnimation > 0.9 && gameOverAnimation <= 1.2)
			playerCurrentSprite.setTexture(playerDeath4);
		if (gameOverAnimation > 1.2 && gameOverAnimation <= 1.5)
			playerCurrentSprite.setTexture(playerDeath5);
		if (gameOverAnimation > 1.5 && gameOverAnimation <= 1.8)
			playerCurrentSprite.setTexture(playerDeath6);
		if (gameOverAnimation > 1.8 && gameOverAnimation <= 2.1)
			playerCurrentSprite.setTexture(playerDeath3);
		if (gameOverAnimation > 2.1 && gameOverAnimation <= 2.3)
			playerCurrentSprite.setTexture(playerDeath4);
		if (gameOverAnimation > 2.3 && gameOverAnimation <= 2.6)
			playerCurrentSprite.setTexture(playerDeath5);
		if (gameOverAnimation > 2.6)
			playerCurrentSprite.setTexture(playerDeath6);
		if (gameOverAnimation > 3) 
			return true;
	}
	return false;
}

void Game::updateStatsSpritesCooldown() {
	// UPDATE PLAYER SPECIAL COOLDOWN
	if (player.getSpectialAtkType() == "base") { player.setSpecialCooldown(5); gameplayUISetSpecialBase.setFillColor(sf::Color::Red); }
	if (player.getSpectialAtkType() == "triple") { player.setSpecialCooldown(3); gameplayUISetSpecialTriple.setFillColor(sf::Color::Red); }
	if (player.getSpectialAtkType() == "rain") { player.setSpecialCooldown(10); gameplayUISetSpecialRain.setFillColor(sf::Color::Red); }

	// RESET SPRITE DU JOUEUR APRES UN HIT
	if (player.hurtTimer >= 0.5) {
		playerCurrentSprite.setColor(sf::Color::White);
	}
	// RESET SPRITES DES ENNEMIS APRES UN HIT
	if (spriteUpdateTimer >= 0.1) {
		for (Normal& normal : vectorNormal)
			normal.setColor(sf::Color::White);
		for (Shooter& shooter : vectorShooter)
			shooter.setColor(sf::Color::White);
		for (Elite& elite : vectorElite)
			elite.setColor(sf::Color::White);
		boss.setColor(sf::Color::White);
		bossEye.setColor(sf::Color::White);
		bossEye2.setColor(sf::Color::White);

	}
}

void Game::nonPlayerBehavior() {
	for (auto it = vectorBonus.begin(); it != vectorBonus.end(); ) {
		Bonus* bonus = *it;
		if (!bonus->behavior(f_ElapsedTime, window, vectorBonus)) {
			delete bonus;                  // Free memory
			it = vectorBonus.erase(it);    // Erase returns the next valid iterator
		}
		else {
			++it; // Move to the next element
		}
	}
	for (auto it = vectorPie.begin(); it != vectorPie.end(); ) {
		Pie* pie = *it;
		if (!pie->behavior(f_ElapsedTime, window, vectorPie)) {
			if (pie->missed) { player.accuracyCounter = 0; }                                         //RESET ACCURACY COUNTER ICI
			delete pie;                  // Free memory
			it = vectorPie.erase(it);    // Erase returns the next valid iterator
		}
		else {
			++it; // Move to the next element
		}
	}
	for (auto it = vectorSugar.begin(); it != vectorSugar.end(); ) {
		Sugar* sugar = *it;
		if (!sugar->behavior(f_ElapsedTime, window, vectorSugar)) {
			delete sugar;                  // Free memory
			it = vectorSugar.erase(it);    // Erase returns the next valid iterator
		}
		else {
			++it; // Move to the next element
		}
	}
	for (auto it = vectorProjectile.begin(); it != vectorProjectile.end(); ) {
		Projectile* projectile = *it;
		if (!projectile->behavior(f_ElapsedTime, window, vectorProjectile, player)) {
			delete projectile;                  // Free memory
			it = vectorProjectile.erase(it);    // Erase returns the next valid iterator
		}
		else {
			++it; // Move to the next element
		}
	}
	for (int i = 0; i < vectorNormal.size(); i++) {
		if (vectorNormal[i].getAlive()) {
			vectorNormal[i].behavior(f_ElapsedTime, vectorNormal, window);
			vectorNormal[i].dropSugar(vectorSugar, vectorNormal[i]);
			for (Pie*& pie : vectorPie) {
				if (vectorNormal[i].getGlobalBounds().intersects(pie->getGlobalBounds())) {
					vectorNormal[i].setHp(-pie->getAtkPower());
					if (pie->maxHitNumber == 1) player.accuracyCounter++; //POUR SET LE MULTIPLIER, IL FAUT UNIQUEMENT TOUCHER HIT AVEC UNE NORMAL ATK
					spriteUpdateTimer = 0;
					vectorNormal[i].setColor(sf::Color::Red);
					if (pie->hitCounter < pie->maxHitNumber) {
						pie->hitCounter++;
					}
					else { pie->setState(false); }
				}
			}
		}
		else {
			vectorNormal[i].deathAnimationTimer += f_ElapsedTime;
			vectorNormal[i].setTexture(deathTexture1);
			if (vectorNormal[i].deathAnimationTimer >= 0.3f) { vectorNormal[i].setTexture(deathTexture2); }
			if (vectorNormal[i].deathAnimationTimer >= 0.5f) {
				vectorNormal.erase(vectorNormal.begin() + i);
				scoreCounter += 100 * player.noHitMultiplier * player.accuracyMultiplier;
				deadEnnemies++;
			}
		}
	}
	for (int i = 0; i < vectorShooter.size(); i++) {
		if (vectorShooter[i].getAlive()) {
			//COMPORTEMENT DE BASE
			//vectorShooter[i].behavior(f_ElapsedTime, vectorShooter, shooterPositions, vectorProjectile, positionsOccupied, window);
			//NOUVEAU COMPORTEMENT
			vectorShooter[i].behavior(f_ElapsedTime, vectorShooter, vectorProjectile, window);
			vectorShooter[i].dropSugar(vectorSugar, vectorShooter[i]);
			for (Pie*& pie : vectorPie) {
				if (vectorShooter[i].getGlobalBounds().intersects(pie->getGlobalBounds())) {
					vectorShooter[i].setHp(-pie->getAtkPower());
					if (pie->maxHitNumber == 1) player.accuracyCounter++;
					spriteUpdateTimer = 0;
					vectorShooter[i].setColor(sf::Color::Red);
					if (pie->hitCounter < pie->maxHitNumber) {
						pie->hitCounter++;
					}
					else { pie->setState(false); }
				}
			}
		}
		else {
			positionsOccupied[i % 15] = false;
			vectorShooter[i].deathAnimationTimer += f_ElapsedTime;
			vectorShooter[i].setTexture(deathTexture1);
			if (vectorShooter[i].deathAnimationTimer >= 0.3f) { vectorShooter[i].setTexture(deathTexture2); }
			if (vectorShooter[i].deathAnimationTimer >= 0.5f) {
				vectorShooter.erase(vectorShooter.begin() + i);
				scoreCounter += 100 * player.noHitMultiplier * player.accuracyMultiplier;
				deadEnnemies++;
			}
		}
	}
	for (int i = 0; i < vectorElite.size(); i++) {
		if (vectorElite[i].getAlive()) {
			vectorElite[i].behavior(f_ElapsedTime, player, vectorProjectile, window);
			vectorElite[i].dropSugar(vectorSugar, vectorElite[i]);
			for (Pie*& pie : vectorPie) {
				if (vectorElite[i].getGlobalBounds().intersects(pie->getGlobalBounds())) {
					vectorElite[i].setHp(-pie->getAtkPower());
					if (pie->maxHitNumber == 1) player.accuracyCounter++;
					spriteUpdateTimer = 0;
					vectorElite[i].setColor(sf::Color::Red);
					if (pie->hitCounter < pie->maxHitNumber) {
						pie->hitCounter++;
					}
					else { pie->setState(false); }
				}
			}
		}
		else {
			vectorElite[i].deathAnimationTimer += f_ElapsedTime;
			vectorElite[i].setTexture(deathTexture1);
			if (vectorElite[i].deathAnimationTimer >= 0.3f) { vectorElite[i].setTexture(deathTexture2); }
			if (vectorElite[i].deathAnimationTimer >= 0.5f) {
				vectorElite.erase(vectorElite.begin() + i);
				scoreCounter += 100 * player.noHitMultiplier * player.accuracyMultiplier;
				deadEnnemies++;
			}
		}
	}
	// BOSS
	if (boss.spawned && boss.getAlive()) {
		bossEye.setPosition(boss.getPosition().x,
			window.getSize().y / 3 - (bossEye.getLocalBounds().height * bossEye.getScale().y) / 2);

		bossEye2.setPosition(boss.getPosition().x,
			window.getSize().y / 1.5 - (bossEye2.getLocalBounds().height * bossEye2.getScale().y) / 2);

		for (Pie*& pie : vectorPie) {
			if (boss.getGlobalBounds().intersects(pie->getGlobalBounds())) {
				boss.setHp(-pie->getAtkPower());
				spriteUpdateTimer = 0;
				boss.setColor(LIGHT_YELLOW);
				if (pie->hitCounter < pie->maxHitNumber) {
					pie->hitCounter++;
				}
				else { pie->setState(false); }
			}
			if (bossEye.getGlobalBounds().intersects(pie->getGlobalBounds())) {
				boss.setHp(-pie->getAtkPower() * 2);  //CRIT DAMAGE SUR L'OEIL
				spriteUpdateTimer = 0;
				bossEye.setColor(LIGHT_RED);
				if (pie->hitCounter < pie->maxHitNumber) {
					pie->hitCounter++;
				}
				else { 
					pie->setState(false);
					scoreCounter += 100 * player.noHitMultiplier * player.accuracyMultiplier;
				}
			}
			if (bossEye2.getGlobalBounds().intersects(pie->getGlobalBounds())) {
				boss.setHp(-pie->getAtkPower() * 2);  //CRIT DAMAGE SUR L'OEIL
				spriteUpdateTimer = 0;
				bossEye2.setColor(LIGHT_RED);
				if (pie->hitCounter < pie->maxHitNumber) {
					pie->hitCounter++;
				}
				else { 
					pie->setState(false);
					scoreCounter += 100 * player.noHitMultiplier * player.accuracyMultiplier;
				}
			}
		}

		if (!boss.behavior(f_ElapsedTime, player, vectorProjectile, window)) {
			boss.setPosition(window.getSize().x * 1.1, boss.getPosition().y);
			player.resetVariables();
			levelThreeCompleted = true;
			loadTextPositions();
			backgroundActive = false;
			bossFightStarted = false;
			bossFightCompleted = true;
			levelProgression = levelThreeDuration + 1;
			endScreenInit();
		}
	}
}

void Game::nonPlayerDraw() {
	for (Bonus*& bonus : vectorBonus) {
		bonusDraw.setSize(sf::Vector2f(30.f, 30.f));

		if (bonus->getId() == "shield") bonusDraw.setTexture(&shieldIconeTexture);
		if (bonus->getId() == "x2") bonusDraw.setTexture(&x2IconeTexture);
		if (bonus->getId() == "oneUp") bonusDraw.setTexture(&oneUpIconeTexture);
		bonusDraw.setPosition(bonus->getPosition());
		window.draw(bonusDraw);
	}
	for (Pie*& pie : vectorPie) {
		pieDraw.setRadius(pie->getRadius());
		pieDraw.setTexture(&pieTexture);
		pieDraw.setPosition(pie->getPosition());
		window.draw(pieDraw);
	}
	for (Projectile*& projectile : vectorProjectile) {
		projectileDraw.setScale(projectile->getScale());
		projectileDrawRound.setScale(projectile->getScale());

		if (projectile->getId() == "bossLeft" || projectile->getId() == "bossRight" || projectile->getId() == "bossUp" || projectile->getId() == "bossDown") {
			projectileDrawRound.setTexture(bossSecondProjectile);
			projectileDrawRound.setPosition(projectile->getPosition());
			window.draw(projectileDrawRound);
		}
		else {
			if (projectile->getId() == "shooter")
				projectileDraw.setTexture(shooterProjectile);
			if (projectile->getId() == "elite")
				projectileDraw.setTexture(eliteProjectile);
			if (projectile->getId() == "boss")
				projectileDraw.setTexture(bossProjectile);
			if (projectile->getId() == "bossSpecial")
				projectileDraw.setTexture(bossSpecialProjectile);
			projectileDraw.setPosition(projectile->getPosition());
			window.draw(projectileDraw);
		}
	}
	for (Sugar*& sugar : vectorSugar) {
		sugarDraw.setScale(sugar->getScale());
		sugarDraw.setTexture(sugarTexture);
		sugarDraw.setPosition(sugar->getPosition());
		window.draw(sugarDraw);
	}
	for (Normal& normal : vectorNormal) {
		window.draw(normal);
	}
	for (Shooter& shooter : vectorShooter) {
		window.draw(shooter);
	}
	for (Elite& elite : vectorElite) {
		window.draw(elite);
	}
	if (player.getShield()) { window.draw(shieldDraw); }
	if (player.getX2()) { window.draw(x2Draw); }
	if (player.getOneUp()) { window.draw(oneUpDraw); }

	if (boss.getAlive() && boss.spawned && levelThreeOn) {
		window.draw(boss);
		window.draw(bossEye);
		window.draw(bossEye2);
	}
}

void Game::run() {

	loadStartUpScreen();
	changeLanguages();
	loadLevelAssets();
	loadTextPositions();
	//setShooterPosition();
	bgStartUpScreenMusic.play();

	while (m_isRunning) {
		// Funtctions loop
		FPSCalculation();
		pollEvents();
		update();
		render();
	}

	std::cout << "Closed" << std::endl;
	window.close();

}

void Game::pollEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
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
				if (howToPlayText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					howToPlayText.setFillColor(LIGHT_YELLOW);
				else
					howToPlayText.setFillColor(sf::Color::White);
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
			if (howToPlayScreenOn) {
				if (howToPlayPreviousSlide.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					howToPlayPreviousSlide.setColor(LIGHT_GRAY);
				else
					howToPlayPreviousSlide.setColor(sf::Color::White);
				if (howToPlayNextSlide.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					howToPlayNextSlide.setColor(LIGHT_GRAY);
				else
					howToPlayNextSlide.setColor(sf::Color::White);
			}
			if (levelSelectionScreenOn) {
				if (levelSelectionScreenOne.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					levelSelectionScreenOne.setFillColor(sf::Color::Green);
				else
					levelSelectionScreenOne.setFillColor(sf::Color::White);
				if (levelTwoUnlocked) {
					if (levelSelectionScreenTwo.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						levelSelectionScreenTwo.setFillColor(sf::Color::Green);
					else
						levelSelectionScreenTwo.setFillColor(sf::Color::White);
				}
				else {
					if (levelSelectionScreenTwo.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						levelSelectionScreenTwo.setFillColor(sf::Color::Red);
					else
						levelSelectionScreenTwo.setFillColor(LIGHT_GRAY);
				}
				if (levelThreeUnlocked) {
					if (levelSelectionScreenThree.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						levelSelectionScreenThree.setFillColor(sf::Color::Green);
					else
						levelSelectionScreenThree.setFillColor(sf::Color::White);
				}
				else {
					if (levelSelectionScreenThree.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						levelSelectionScreenThree.setFillColor(sf::Color::Red);
					else
						levelSelectionScreenThree.setFillColor(LIGHT_GRAY);
				}
			}
			if (playScreenOn && !levelSelectionScreenOn) {
				if (gameOverScreenOn) {
					if (retryText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						retryText.setFillColor(LIGHT_YELLOW);
					else
						retryText.setFillColor(sf::Color::White);
					if (giveUpText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						giveUpText.setFillColor(LIGHT_YELLOW);
					else
						giveUpText.setFillColor(sf::Color::White);
				}
				if (showPauseMenu) {
					if (gameplayPauseExitBtn.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						gameplayPauseExitText.setFillColor(LIGHT_RED);
					else
						gameplayPauseExitText.setFillColor(sf::Color::White);
					if (gameplayPauseGoBackBtn.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						gameplayPauseGoBackText.setFillColor(LIGHT_GREEN);
					else
						gameplayPauseGoBackText.setFillColor(sf::Color::White);
					if (gameplayPausePlusSoundTextSFX.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						gameplayPausePlusSoundTextSFX.setFillColor(sf::Color::White);
					else
						gameplayPausePlusSoundTextSFX.setFillColor(sf::Color(DARK_THEME));
					if (gameplayPauseMinusSoundTextSFX.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						gameplayPauseMinusSoundTextSFX.setFillColor(sf::Color::White);
					else
						gameplayPauseMinusSoundTextSFX.setFillColor(sf::Color(DARK_THEME));
					if (gameplayPausePlusSoundTextMusic.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						gameplayPausePlusSoundTextMusic.setFillColor(sf::Color::White);
					else
						gameplayPausePlusSoundTextMusic.setFillColor(sf::Color(DARK_THEME));
					if (gameplayPauseMinusSoundTextMusic.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						gameplayPauseMinusSoundTextMusic.setFillColor(sf::Color::White);
					else
						gameplayPauseMinusSoundTextMusic.setFillColor(sf::Color(DARK_THEME));
				}
				if (levelOneCompleted || levelTwoCompleted || levelThreeCompleted) {
					if (levelEndScreenNextButton.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						levelEndScreenNextButton.setFillColor(sf::Color::Green);
					else
						levelEndScreenNextButton.setFillColor(sf::Color::White);
					if (levelEndScreenQuitButton.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
						levelEndScreenQuitButton.setFillColor(LIGHT_RED);
					else
						levelEndScreenQuitButton.setFillColor(sf::Color::White);
				}
				if (gameplayUIStatAtkText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					gameplayUIStatAtkText.setFillColor(LIGHT_YELLOW);
				else
					gameplayUIStatAtkText.setFillColor(sf::Color::White);
				if (gameplayUIStatMaxHpText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					gameplayUIStatMaxHpText.setFillColor(LIGHT_YELLOW);
				else
					gameplayUIStatMaxHpText.setFillColor(sf::Color::White);
				if (gameplayUIStatSpeedText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					gameplayUIStatSpeedText.setFillColor(LIGHT_YELLOW);
				else
					gameplayUIStatSpeedText.setFillColor(sf::Color::White);
				if (gameplayUISetSpecialBase.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					gameplayUISetSpecialBase.setFillColor(LIGHT_YELLOW);
				else
					gameplayUISetSpecialBase.setFillColor(sf::Color::White);
				if (gameplayUISetSpecialTriple.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					gameplayUISetSpecialTriple.setFillColor(LIGHT_YELLOW);
				else
					gameplayUISetSpecialTriple.setFillColor(sf::Color::White);
				if (gameplayUISetSpecialRain.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
					gameplayUISetSpecialRain.setFillColor(LIGHT_YELLOW);
				else
					gameplayUISetSpecialRain.setFillColor(sf::Color::White);
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (settingsScreenOn) {
					if (!menuPauseContent.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y) && !menuPauseTopBar.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						settingsScreenOn = false;
						startUpScreenOn = true;
						settingsIconSprite.setColor(sf::Color::White);
						bgStartUpScreenMusic.play();
					}
					if (pauseResolutionMode0Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[0].width, modes[0].height), "Food'estroyer", sf::Style::Fullscreen);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = true;
					}
					if (pauseResolutionMode1Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[1].width, modes[1].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode2Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[2].width, modes[2].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode3Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[3].width, modes[3].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode4Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[4].width, modes[4].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode5Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[5].width, modes[5].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode6Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[6].width, modes[6].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode7Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[7].width, modes[7].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode8Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[8].width, modes[8].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode9Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[9].width, modes[9].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
					}
					if (pauseResolutionMode10Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						window.create(sf::VideoMode(modes[10].width, modes[10].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
						window.setFramerateLimit(currentFramerateLimit);
						loadSettings();
						loadTextPositions();
						isFullscreen = false;
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
						changeLanguages();
						loadTextPositions();
					}
					if (pauseLanguageFRText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y) && language != "FR") {
						language = "FR";
						changeLanguages();
						loadTextPositions();
					}
				}
				if (startUpScreenOn) {
					// Options
					if (settingsIconSprite.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						settingsScreenOn = true;
						startUpScreenOn = false;
						loadSettings();
						loadTextPositions();
						bgStartUpScreenMusic.pause();
					}
					// Jouer
					if (playText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						levelProgression = 0;
						playScreenOn = true;
						startUpScreenOn = false;
						bgLvl1Music.setLoop(false);
						bgLvl2Music.setLoop(false);
						bgLvl3Music.setLoop(false);
						levelSelectionScreenOn = true;
						setupLevelSelectionScreen();
					}
					if (howToPlayText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						howToPlayScreenOn = true;
						startUpScreenOn = false;
						loadGameplayAssets();
					}
					// Quitter
					if (quitText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						m_isRunning = false;
					}
				}
				if (howToPlayScreenOn) {
					if (howToPlayPreviousSlide.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (howToPlayActiveIndex == 0) howToPlayActiveIndex = 3;
						else howToPlayActiveIndex--;
					}
					if (howToPlayNextSlide.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (howToPlayActiveIndex == 3) howToPlayActiveIndex = 0;
						else howToPlayActiveIndex++;
					}
				}
				if (playScreenOn && !levelSelectionScreenOn) {
					if (showPauseMenu) {
						if (gameplayPauseExitBtn.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
							gameOverAnimation = 0;
							deathCounter = 0;
							player.resetVariables();
							bgLvl1Music.stop();
							bgLvl2Music.stop();
							bgLvl3Music.stop();
							levelOneOn = false;
							levelTwoOn = false;
							levelThreeOn = false;
							backgroundActive = false;
							showPauseMenu = false;
							clearAllVectors();
							for (int i = 0; i < 15; ++i)
								positionsOccupied[i] = false;
							startUpScreenOn = true;
							bgBossfightMusic.stop();
							bgStartUpScreenMusic.play();
						}
						if (gameplayPauseGoBackBtn.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
							backgroundActive = true;
							showPauseMenu = false;
							if (levelOneOn)
								bgLvl1Music.play();
							if (levelTwoOn)
								bgLvl2Music.play();
							if (levelThreeOn) {
								if (!bossFightStarted)
									bgLvl3Music.play();
								else
									bgBossfightMusic.play();
							}
						}
						if (gameplayPausePlusSoundTextSFX.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
						{
							if (gameplayPauseSFXControlInnerZone.getScale().x < 1.f) {
								gameplayPauseSFXControlInnerZone.setScale(sf::Vector2f(gameplayPauseSFXControlInnerZone.getScale().x + 0.05f, 1.f));
								oofSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
								playerDeathSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
								sugarCrunchSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
								vineBoomSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
							}
						}
						if (gameplayPauseMinusSoundTextSFX.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
						{
							if (gameplayPauseSFXControlInnerZone.getScale().x > 0.f) {
								gameplayPauseSFXControlInnerZone.setScale(sf::Vector2f(gameplayPauseSFXControlInnerZone.getScale().x - 0.05f, 1.f));
								oofSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
								playerDeathSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
								sugarCrunchSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
								vineBoomSound.setVolume(100 * gameplayPauseSFXControlInnerZone.getScale().x);
							}
						}
						if (gameplayPausePlusSoundTextMusic.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
						{
							if (gameplayPauseMusicControlInnerZone.getScale().x < 1.f && gameplayPauseMusicControlInnerZone.getScale().x >= 0.f) {
								gameplayPauseMusicControlInnerZone.setScale(sf::Vector2f(gameplayPauseMusicControlInnerZone.getScale().x + 0.05f, 1.f));
								bgStartUpScreenMusic.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								if (levelOneOn) {
									bgLvl1Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								}
								if (levelTwoOn) {
									bgLvl2Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								}
								if (levelThreeOn) {
									bgLvl3Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
									bgBossfightMusic.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								}
							}
						}
						if (gameplayPauseMinusSoundTextMusic.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
						{
							if (gameplayPauseMusicControlInnerZone.getScale().x <= 1.f && gameplayPauseMusicControlInnerZone.getScale().x > 0.f) {
								gameplayPauseMusicControlInnerZone.setScale(sf::Vector2f(gameplayPauseMusicControlInnerZone.getScale().x - 0.05f, 1.f));
								bgStartUpScreenMusic.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								if (levelOneOn) {
									bgLvl1Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								}
								if (levelTwoOn) {
									bgLvl2Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								}
								if (levelThreeOn) {
									bgLvl3Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
									bgBossfightMusic.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
								}
							}
						}
					}
					if (levelOneCompleted || levelTwoCompleted || levelThreeCompleted) {
						if (levelEndScreenNextButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
							clearAllVectors();
							player.resetVariables();
							backgroundActive = true;
							levelProgression = 0.f;
							scoreCounter = 0;
							if (levelOneOn) {
								loadGameplayAssets();
								loadLevel2();
								bgLvl1Music.stop();
								bgLvl2Music.play();
								levelOneOn = false;
								levelTwoOn = true;
								loadTextPositions();
								return;
							}
							else if (levelTwoOn) {
								loadGameplayAssets();
								loadLevel3();
								bgLvl2Music.stop();
								bgLvl3Music.play();
								levelThreeOn = true;
								levelTwoOn = false;
								return;
							}
							else if (levelThreeOn) {
								bgLvl3Music.stop();
								bgBossfightMusic.stop();
								bossFightStarted = false;
								bgStartUpScreenMusic.play();
								startUpScreenOn = true;
								levelThreeOn = false;
								boss.spawned = false;
								boss.spawning = false;
								return;
							}
						}
						if (levelEndScreenQuitButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
							levelOneOn = false; levelTwoOn = false; levelThreeOn = false; bossFightStarted = false;
							bgLvl1Music.stop(); bgLvl2Music.stop(); bgLvl3Music.stop(); bgBossfightMusic.stop();
							boss.spawned = false;
							boss.spawning = false;
							startUpScreenOn = true;
							bgStartUpScreenMusic.play();
						}
					}
					if (gameplayUIStatAtkText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (player.getSugarCount() >= player.atkLvlUpCost) {
							player.setSugarCount(-player.atkLvlUpCost);
							player.setAtkPower(1.25f); // *= 1.25
							player.atkLvl++;
							player.atkLvlUpCost *= 1.25f;
						}
					}
					if (gameplayUIStatMaxHpText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (player.getSugarCount() >= player.maxHpLvlUpCost) {
							player.setSugarCount(-player.maxHpLvlUpCost);
							player.setPlayerMaxHP(10.f); // += 10
							player.maxHpLvl++;
							player.maxHpLvlUpCost *= 1.25f;
						}
					}
					if (gameplayUIStatSpeedText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (player.getSugarCount() >= player.speedLvlUpCost) {
							player.setSugarCount(-player.speedLvlUpCost);
							player.setPlayerSpeed(100.f); // += 100
							player.speedLvl++;
							player.speedLvlUpCost *= 1.25f;
						}
					}
					if (gameplayUISetSpecialBase.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						player.setSpecialAtkType("base"); player.resetSpecialTimer(0);
						gameplayUISetSpecialTriple.setFillColor(sf::Color::White);
						gameplayUISetSpecialRain.setFillColor(sf::Color::White);
					}
					if (gameplayUISetSpecialTriple.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (!player.tripleBought && player.getSugarCount() >= player.tripleCost) {
							player.tripleBought = true;
							player.setSugarCount(-player.tripleCost);
							player.setSpecialAtkType("triple");
							player.resetSpecialTimer(0);
						}
						else if (player.tripleBought) {
							player.setSpecialAtkType("triple"); player.resetSpecialTimer(0);
							gameplayUISetSpecialBase.setFillColor(sf::Color::White);
							gameplayUISetSpecialRain.setFillColor(sf::Color::White);
						}
					}
					if (gameplayUISetSpecialRain.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (!player.rainBought && player.getSugarCount() >= player.rainCost) {
							player.rainBought = true;
							player.setSugarCount(-player.rainCost);
							player.setSpecialAtkType("rain");
							player.resetSpecialTimer(0);
						}
						else if (player.rainBought) {
							player.setSpecialAtkType("rain"); player.resetSpecialTimer(0);
							gameplayUISetSpecialBase.setFillColor(sf::Color::White);
							gameplayUISetSpecialTriple.setFillColor(sf::Color::White);
						}
					}
				}
				if (gameOverScreenOn) {
					bgStartUpScreenMusic.stop();
					bgBossfightMusic.stop();
					bgLvl1Music.stop();
					bgLvl2Music.stop();
					bgLvl3Music.stop();
					if (retryText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						gameOverAnimation = 0;
						deathCounter = 0;
						backgroundActive = true;
						gameOverScreenOn = false;
						player.resetVariables();
						clearAllVectors();
						loadGameplayAssets();
						setEnemySpawn(numberOfStartingEnnemies, false);
						levelProgression = 0;
						if (levelOneOn) {
							bgLvl1Music.stop();
							loadLevel1();
							bgLvl1Music.play();
						}
						else if (levelTwoOn) {
							bgLvl2Music.stop();
							loadLevel2();
							bgLvl2Music.play();
						}
						else if (levelThreeOn) {
							boss.setupBoss();
							boss.spawned = false;
							boss.spawning = false;
							bgBossfightMusic.stop();
							bgLvl3Music.stop();
							loadLevel3();
							bgLvl3Music.play();
						}
					}
					if (giveUpText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						gameOverAnimation = 0;
						deathCounter = 0;
						levelOneOn = false;
						levelTwoOn = false;
						levelThreeOn = false;
						showPauseMenu = false;
						backgroundActive = false;
						gameOverScreenOn = false;
						startUpScreenOn = true;
						boss.setupBoss();
						boss.spawned = false;
						boss.spawning = false;
						clearAllVectors();
						player.resetVariables();
						setShooterPositions();
						bgStartUpScreenMusic.play();
					}
				}
				if (levelSelectionScreenOn) {
					playerCurrentSprite.setColor(sf::Color::White);
					if (levelSelectionScreenOne.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						clearAllVectors();
						loadGameplayAssets();
						loadLevel1();
						levelOneOn = true;
						backgroundActive = true;
						levelSelectionScreenOn = false;
						bgStartUpScreenMusic.pause();
						bgLvl1Music.play();
					}
					if (levelSelectionScreenTwo.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (levelTwoUnlocked) {
							clearAllVectors();
							loadGameplayAssets();
							loadLevel2();
							levelTwoOn = true;
							backgroundActive = true;
							levelSelectionScreenOn = false;
							bgStartUpScreenMusic.pause();
							bgLvl2Music.play();
						}
					}
					if (levelSelectionScreenThree.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						if (levelThreeUnlocked) {
							clearAllVectors();
							loadGameplayAssets();
							loadLevel3();
							boss.setupBoss();
							bossFightCompleted = false;
							bossFightStarted = false;
							bgBossfightMusic.stop();
							levelThreeOn = true;
							backgroundActive = true;
							levelSelectionScreenOn = false;
							bgStartUpScreenMusic.pause();
							bgLvl3Music.play();
						}
					}
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
					bgStartUpScreenMusic.play();
				}
				else if (startUpScreenOn) {
					m_isRunning = false;
				}
				else if (howToPlayScreenOn) {
					howToPlayScreenOn = false;
					startUpScreenOn = true;
					howToPlayText.setFillColor(sf::Color::White);
				}
				else if (playScreenOn && !levelSelectionScreenOn) {
					loadTextPositions();
					if (bossFightStarted) {
						bgBossfightMusic.pause();
					}
				}
				else if (levelSelectionScreenOn) {
					levelSelectionScreenOn = false;
					startUpScreenOn = true;
				}
			}
			break;
		default:
			break;
		}
	}
}

void Game::update() {
	// MECHANICS
	if (levelOneOn) {
		if (backgroundActive) {
			if (levelProgression < levelOneDuration) {
				levelProgression += f_ElapsedTime;
				levelProgressionBarFG.setScale(sf::Vector2f((levelProgression / levelOneDuration), 1.f));
				clownWalkAnimationTime += f_ElapsedTime;
				bossAnimationTime += f_ElapsedTime;
				bossEyeAnimationTime += f_ElapsedTime;
				bonusDropTimer += f_ElapsedTime;

				scoreCalculation();
				sugarCalculation();
				statCalculation();
				playerHPSetter();
				playerBonusSetter();
				player.setShootTimer(f_ElapsedTime);
				player.setSpecialTimer(f_ElapsedTime);
				player.setBonusTimer(f_ElapsedTime); // (il est reset quand le joueur touche un bonus donc pas besoin de condition)
				if (player.hurtCount > 0) {
					player.hurtTimer += f_ElapsedTime;
				}

				if (levelProgression / levelOneDuration > 0.33f && !spawnCooldownPhaseOne) {
					spawnCooldownPhaseOne = true;
					ennemiesSpawnCooldown -= 0.1f;
				}
				if (levelProgression / levelOneDuration > 0.66f && !spawnCooldownPhaseTwo) {
					spawnCooldownPhaseTwo = true;
					ennemiesSpawnCooldown -= 0.1f;
				}

				spriteUpdateTimer += f_ElapsedTime;
				player.noHitTimer += f_ElapsedTime;
				ennemiesSpawnCooldownDuration += f_ElapsedTime;
				if (ennemiesSpawnCooldownDuration > ennemiesSpawnCooldown) {
					ennemiesSpawnCooldownDuration = 0.f;
					if (bonusDropTimer > 20.f) {
						setEnemySpawn(1, true);
						bonusDropTimer = 0.f;
					}
					else {
						setEnemySpawn(1);
					}
				}
				playerInput();
				updateStatsSpritesCooldown();
				playerCollisions();
				nonPlayerBehavior();
				clownWalkAnimation();
				bossAnimation();

				backgroundMovementLevel1();
			}
			else {
				spawnCooldownPhaseOne = false;
				spawnCooldownPhaseTwo = false;
				levelTwoUnlocked = true;
				levelOneCompleted = true;
				loadTextPositions();
				backgroundActive = false;
				endScreenInit();
			}
		}
	}
	if (levelTwoOn) {
		ennemiesSpawnCooldown = 1.f;
		if (backgroundActive) {
			if (levelProgression < levelTwoDuration) {
				levelProgression += f_ElapsedTime;
				levelProgressionBarFG.setScale(sf::Vector2f((levelProgression / levelTwoDuration), 1.f));
				clownWalkAnimationTime += f_ElapsedTime;
				bossAnimationTime += f_ElapsedTime;
				bossEyeAnimationTime += f_ElapsedTime;
				bonusDropTimer += f_ElapsedTime;

				scoreCalculation();
				sugarCalculation();
				statCalculation();
				playerHPSetter();
				playerBonusSetter();
				player.setShootTimer(f_ElapsedTime);
				player.setSpecialTimer(f_ElapsedTime);
				player.setBonusTimer(f_ElapsedTime); // (il est reset quand le joueur touche un bonus donc pas besoin de condition)
				if (player.hurtCount > 0) {
					player.hurtTimer += f_ElapsedTime;
				}

				if (levelProgression / levelTwoDuration > 0.33f && !spawnCooldownPhaseOne) {
					spawnCooldownPhaseOne = true;
					ennemiesSpawnCooldown -= 0.1f;
				}
				if (levelProgression / levelTwoDuration > 0.66f && !spawnCooldownPhaseTwo) {
					spawnCooldownPhaseTwo = true;
					ennemiesSpawnCooldown -= 0.1f;
				}

				spriteUpdateTimer += f_ElapsedTime;
				player.noHitTimer += f_ElapsedTime;
				ennemiesSpawnCooldownDuration += f_ElapsedTime;
				if (ennemiesSpawnCooldownDuration > ennemiesSpawnCooldown) {
					ennemiesSpawnCooldownDuration = 0.f;
					if (bonusDropTimer > 20.f) {
						setEnemySpawn(1, true);
						bonusDropTimer = 0.f;
					}
					else {
						setEnemySpawn(1);
					}
				}
				playerInput();
				updateStatsSpritesCooldown();
				playerCollisions();
				nonPlayerBehavior();
				clownWalkAnimation();
				bossAnimation();

				backgroundMovementLevel2();
			}
			else {
				spawnCooldownPhaseOne = false;
				spawnCooldownPhaseTwo = false;
				levelThreeUnlocked = true;
				levelTwoCompleted = true;
				loadTextPositions();
				backgroundActive = false;
				endScreenInit();
			}
		}
	}
	if (levelThreeOn) {
		ennemiesSpawnCooldown = 0.8f;
		if (backgroundActive) {
			// Phase normale du niveau 3 (avec le timer)
			if (levelProgression < levelThreeDuration) {
				bossFightStarted = false;
				levelProgression += f_ElapsedTime;
				levelProgressionBarFG.setScale(sf::Vector2f((levelProgression / levelThreeDuration), 1.f));
				clownWalkAnimationTime += f_ElapsedTime;
				bossAnimationTime += f_ElapsedTime;
				bossEyeAnimationTime += f_ElapsedTime;
				bonusDropTimer += f_ElapsedTime;

				scoreCalculation();
				sugarCalculation();
				statCalculation();
				playerHPSetter();
				playerBonusSetter();
				player.setShootTimer(f_ElapsedTime);
				player.setSpecialTimer(f_ElapsedTime);
				player.setBonusTimer(f_ElapsedTime); // (il est reset quand le joueur touche un bonus donc pas besoin de condition)
				if (player.hurtCount > 0) {
					player.hurtTimer += f_ElapsedTime;
				}

				if (levelProgression / levelThreeDuration > 0.33f && !spawnCooldownPhaseOne) {
					spawnCooldownPhaseOne = true;
					ennemiesSpawnCooldown -= 0.1f;
				}
				if (levelProgression / levelThreeDuration > 0.66f && !spawnCooldownPhaseTwo) {
					spawnCooldownPhaseTwo = true;
					ennemiesSpawnCooldown -= 0.1f;
				}

				spriteUpdateTimer += f_ElapsedTime;
				player.noHitTimer += f_ElapsedTime;
				ennemiesSpawnCooldownDuration += f_ElapsedTime;
				if (ennemiesSpawnCooldownDuration > ennemiesSpawnCooldown) {
					ennemiesSpawnCooldownDuration = 0.f;
					if (bonusDropTimer > 20.f) {
						setEnemySpawn(1, true);
						bonusDropTimer = 0.f;
					}
					else {
						setEnemySpawn(1);
					}
				}
				playerInput();
				updateStatsSpritesCooldown();
				playerCollisions();
				nonPlayerBehavior();
				clownWalkAnimation();
				bossAnimation();

				backgroundMovementLevel3();
			}
			// Préparation du bossfight
			else if(!bossFightStarted) {
				spawnCooldownPhaseOne = false;
				spawnCooldownPhaseTwo = false;
				bgLvl3Music.stop();
				clearAllVectors();
				setShooterPositions(); // Pour éviter les bugs dans les appels de fonctions dans nonPlayerBehavior(), même s'il n y aura pas de shooters
				levelProgressionBarFG.setFillColor(sf::Color::Transparent);
				levelProgressionBarBG.setOutlineThickness(0);
				boss.setupBoss();
				boss.setTexture(bossTexture1);
				boss.spawning = true;
				boss.spawned = true;
				bossFightStarted = true;
				bgBossfightMusic.play();
			}
			// Bossfight!
			else if (bossFightStarted) {
				if (!boss.getAlive())
					bossFightStarted = false;
				clownWalkAnimationTime += f_ElapsedTime;
				bossAnimationTime += f_ElapsedTime;
				bossEyeAnimationTime += f_ElapsedTime;
				scoreCalculation();
				sugarCalculation();
				statCalculation();
				playerHPSetter();
				playerBonusSetter();
				player.setShootTimer(f_ElapsedTime);
				player.setSpecialTimer(f_ElapsedTime);
				player.setBonusTimer(f_ElapsedTime); // (il est reset quand le joueur touche un bonus donc pas besoin de condition)
				if (player.hurtCount > 0) {
					player.hurtTimer += f_ElapsedTime;
				}
				spriteUpdateTimer += f_ElapsedTime;
				player.noHitTimer += f_ElapsedTime;
				playerInput();
				updateStatsSpritesCooldown();
				playerCollisions();
				playerDeath();
				nonPlayerBehavior();
				clownWalkAnimation();
				bossAnimation();

				backgroundMovementLevel3();
			}
			else {
				bossFightCompleted = true;
				bossFightStarted = false;
				levelProgression = 0;
				levelThreeOn = false;
			}
		}
	}
	if (playerDeath() && backgroundActive) { gameOverScreenOn = true; vineBoomSound.play(); bgBossfightMusic.stop(); bgLvl1Music.stop(); bgLvl2Music.stop(); bgLvl3Music.stop(); }

	if (gameOverScreenOn) {
		gameOverText.setFont(puppy);
		gameOverText.setCharacterSize(100);
		gameOverText.setLetterSpacing(1.1f);
		gameOverText.setFillColor(sf::Color::Red);
		gameOverText.setOutlineColor(sf::Color::Black);
		gameOverText.setOutlineThickness(1.f);
		gameOverText.setPosition((window.getSize().x - gameOverText.getLocalBounds().width) / 2,
			gameplayPauseContent.getPosition().y + gameplayPauseContent.getSize().y / 3 - gameOverText.getCharacterSize() / 2);
		retryText.setFont(puppy);
		retryText.setCharacterSize(50);
		retryText.setLetterSpacing(1.1f);
		retryText.setOutlineColor(sf::Color::Black);
		retryText.setOutlineThickness(1.f);
		retryText.setPosition((window.getSize().x - retryText.getLocalBounds().width) / 2,
			gameOverText.getPosition().y + gameOverText.getCharacterSize() + window.getSize().y * 0.1);
		giveUpText.setFont(puppy);
		giveUpText.setCharacterSize(50);
		giveUpText.setLetterSpacing(1.1f);
		giveUpText.setOutlineColor(sf::Color::Black);
		giveUpText.setOutlineThickness(1.f);
		giveUpText.setPosition((window.getSize().x - giveUpText.getLocalBounds().width) / 2, retryText.getPosition().y + retryText.getCharacterSize() * 2);

		if (language == "EN") {
			gameOverText.setString("GAME OVER");
			retryText.setString("TRY AGAIN");
			giveUpText.setString("GIVE UP");
		}
		else if (language == "FR") {
			gameOverText.setString("FIN DE PARTIE");
			retryText.setString("RECOMMENCER");
			giveUpText.setString("ABANDONNER");
		}
		backgroundActive = false;
	}
}

void Game::render() {
	window.clear(sf::Color::Black);

	if (settingsScreenOn) {
		if (!bossFightCompleted)
			window.draw(bgStartUpScreenSprite);
		else
			window.draw(bgStartUpScreenEndSprite);
		window.draw(darkerLayer);
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
		if (!bossFightCompleted)
			window.draw(bgStartUpScreenSprite);
		else
			window.draw(bgStartUpScreenEndSprite);
		window.draw(playText);
		window.draw(howToPlayText);
		window.draw(quitText);
		window.draw(copyright);
		window.draw(settingsIconSprite);
	}

	if (levelSelectionScreenOn) {
		if (!bossFightCompleted)
			window.draw(bgStartUpScreenSprite);
		else
			window.draw(bgStartUpScreenEndSprite);
		window.draw(darkerLayer);
		window.draw(gameplayPauseContent);
		window.draw(levelSelectionScreenTitle);
		window.draw(levelSelectionScreenOne);
		window.draw(levelSelectionScreenTwo);
		window.draw(levelSelectionScreenThree);
	}

	if (howToPlayScreenOn) {
		if (!bossFightCompleted)
			window.draw(bgStartUpScreenSprite);
		else
			window.draw(bgStartUpScreenEndSprite);
		window.draw(darkerLayer);
		window.draw(gameplayPauseContent);
		if (language == "EN")
			window.draw(howToPlayEnglish[howToPlayActiveIndex]);
		else if (language == "FR")
			window.draw(howToPlayFrench[howToPlayActiveIndex]);
		window.draw(howToPlayPreviousSlide);
		window.draw(howToPlayNextSlide);
	}

	if (playScreenOn) {
		if (levelOneOn) {
			// --- FOND PARRALAXE --- //
			window.draw(levelOneParralax01Sprite);
			window.draw(levelOneParralax01SpriteCopy);
			window.draw(levelOneParralax02Sprite);
			window.draw(levelOneParralax02SpriteCopy);
			window.draw(levelOneParralax03Sprite);
			window.draw(levelOneParralax03SpriteCopy);
			window.draw(levelOneParralax04Sprite);
			window.draw(levelOneParralax04SpriteCopy);
			window.draw(levelOneParralax05Sprite);
			window.draw(levelOneParralax05SpriteCopy);
			window.draw(levelOneParralax06Sprite);
			window.draw(levelOneParralax06SpriteCopy);
			// --- ENNEMIS & JOUEUR --- //
			nonPlayerDraw();
			window.draw(playerCurrentSprite);
			if (player.getShield())
				window.draw(shieldSprite);
			window.draw(gameplayUILifeBarCurrentSprite);
			window.draw(gameplayUIScoreText);
			if (showNoHitBonus) window.draw(gameplayUINoHitBonus);
			if (showNoMissBonus) window.draw(gameplayUINoMissBonus);
			window.draw(sugarIcone);
			window.draw(gameplayUISugarText);
			window.draw(gameplayUIStatAtkText);
			window.draw(gameplayUIStatMaxHpText);
			window.draw(gameplayUIStatSpeedText);
			window.draw(gameplayUISetSpecialBase);
			window.draw(gameplayUISetSpecialTriple);
			window.draw(gameplayUISetSpecialRain);
			window.draw(levelProgressionBarBG);
			window.draw(levelProgressionBarFG);
			if (levelOneCompleted && levelProgression > levelOneDuration) {
				window.draw(gameplayPauseContent);
				window.draw(levelEndScreenTitle);
				window.draw(levelEndScreenTotalScore);
				window.draw(levelEndScreenTotalDamageTaken);
				window.draw(levelEndScreenTotalEnnemiesKilled);
				window.draw(levelEndScreenNextButton);
				window.draw(levelEndScreenQuitButton);
			}
		}
		if (levelTwoOn) {
			// --- FOND PARRALAXE --- //
			window.draw(levelTwoParralaxBGSprite);
			window.draw(levelTwoParralaxBGSpriteCopy);
			window.draw(levelTwoParralax08Sprite);
			window.draw(levelTwoParralax08SpriteCopy);
			window.draw(levelTwoParralax07Sprite);
			window.draw(levelTwoParralax07SpriteCopy);
			window.draw(levelTwoParralax06Sprite);
			window.draw(levelTwoParralax06SpriteCopy);
			window.draw(levelTwoParralax05Sprite);
			window.draw(levelTwoParralax05SpriteCopy);
			window.draw(levelTwoParralax04Sprite);
			window.draw(levelTwoParralax04SpriteCopy);
			window.draw(levelTwoParralax03Sprite);
			window.draw(levelTwoParralax03SpriteCopy);
			window.draw(levelTwoParralax02Sprite);
			window.draw(levelTwoParralax02SpriteCopy);
			window.draw(levelTwoParralax01Sprite);
			window.draw(levelTwoParralax01SpriteCopy);
			// --- ENNEMIS & JOUEUR --- //
			nonPlayerDraw();
			window.draw(playerCurrentSprite);
			if (player.getShield())
				window.draw(shieldSprite);
			window.draw(gameplayUILifeBarCurrentSprite);
			window.draw(gameplayUIScoreText);
			if (showNoHitBonus) window.draw(gameplayUINoHitBonus);
			if (showNoMissBonus) window.draw(gameplayUINoMissBonus);
			window.draw(sugarIcone);
			window.draw(gameplayUISugarText);
			window.draw(gameplayUIStatAtkText);
			window.draw(gameplayUIStatMaxHpText);
			window.draw(gameplayUIStatSpeedText);
			window.draw(gameplayUISetSpecialBase);
			window.draw(gameplayUISetSpecialTriple);
			window.draw(gameplayUISetSpecialRain);
			window.draw(levelProgressionBarBG);
			window.draw(levelProgressionBarFG);
			if (levelTwoCompleted && levelProgression > levelTwoDuration) {
				window.draw(gameplayPauseContent);
				window.draw(levelEndScreenTitle);
				window.draw(levelEndScreenTotalScore);
				window.draw(levelEndScreenTotalDamageTaken);
				window.draw(levelEndScreenTotalEnnemiesKilled);
				window.draw(levelEndScreenNextButton);
				window.draw(levelEndScreenQuitButton);
			}
		}
		if (levelThreeOn) {
			// --- FOND PARRALAXE --- //
			window.draw(levelThreeParralaxBGSprite);
			window.draw(levelThreeParralaxBGSpriteCopy);
			window.draw(levelThreeParralax01Sprite);
			window.draw(levelThreeParralax01SpriteCopy);
			window.draw(levelThreeParralax02Sprite);
			window.draw(levelThreeParralax02SpriteCopy);
			window.draw(levelThreeParralax03Sprite);
			window.draw(levelThreeParralax03SpriteCopy);
			window.draw(levelThreeParralax04Sprite);
			window.draw(levelThreeParralax04SpriteCopy);
			window.draw(levelThreeParralax05Sprite);
			window.draw(levelThreeParralax05SpriteCopy);
			window.draw(levelThreeParralax06Sprite);
			window.draw(levelThreeParralax06SpriteCopy);
			window.draw(levelThreeParralax07Sprite);
			window.draw(levelThreeParralax07SpriteCopy);
			// --- ENNEMIS & JOUEUR --- //
			nonPlayerDraw();
			window.draw(playerCurrentSprite);
			if (player.getShield())
				window.draw(shieldSprite);
			window.draw(gameplayUILifeBarCurrentSprite);
			window.draw(gameplayUIScoreText);
			if (showNoHitBonus) window.draw(gameplayUINoHitBonus);
			if (showNoMissBonus) window.draw(gameplayUINoMissBonus);
			window.draw(sugarIcone);
			window.draw(gameplayUISugarText);
			window.draw(gameplayUIStatAtkText);
			window.draw(gameplayUIStatMaxHpText);
			window.draw(gameplayUIStatSpeedText);
			window.draw(gameplayUISetSpecialBase);
			window.draw(gameplayUISetSpecialTriple);
			window.draw(gameplayUISetSpecialRain);
			window.draw(levelProgressionBarBG);
			window.draw(levelProgressionBarFG);
			if (levelThreeCompleted && levelProgression > levelThreeDuration && bossFightCompleted) {
				window.draw(gameplayPauseContent);
				window.draw(levelEndScreenTitle);
				window.draw(levelEndScreenTotalScore);
				window.draw(levelEndScreenTotalDamageTaken);
				window.draw(levelEndScreenTotalEnnemiesKilled);
				window.draw(levelEndScreenNextButton);
				window.draw(levelEndScreenQuitButton);
			}
		}
		if (showPauseMenu) {
			window.draw(darkerLayer);
			window.draw(gameplayPauseContent);
			window.draw(gameplayPauseGoBackBtn);
			window.draw(gameplayPauseExitBtn);
			window.draw(gameplayPauseTitleText);
			window.draw(gameplayPauseGoBackText);
			window.draw(gameplayPauseExitText);
			window.draw(gameplayPauseMusicControlZoneBG);
			window.draw(gameplayPauseMusicControlZone);
			window.draw(gameplayPauseSFXControlZoneBG);
			window.draw(gameplayPauseSFXControlZone);
			window.draw(gameplayPauseMusicControlInnerZone);
			window.draw(gameplayPauseSFXControlInnerZone);
			window.draw(gameplayPauseMusicText);
			window.draw(gameplayPauseSFXText);
			window.draw(gameplayPausePlusSoundTextSFX);
			window.draw(gameplayPauseMinusSoundTextSFX);
			window.draw(gameplayPausePlusSoundTextMusic);
			window.draw(gameplayPauseMinusSoundTextMusic);
		}
	}

	if (gameOverScreenOn) {
		window.draw(darkerLayer);
		window.draw(gameplayPauseContent);
		window.draw(gameOverText);
		window.draw(retryText);
		window.draw(giveUpText);
	}

	window.draw(FPSText);
	window.setMouseCursor(pie);
	window.display();
}