#include "game.h"
#include "enemy.h"
#include "player.h"

namespace {
	// DATA STL (STandard Library)
	int mouseLastDownX, mouseLastDownY;
	float scoreCounter;
	bool isMouseDragging;
	bool isFullscreen = true;
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes(); // Gets the native resolutions of the machine this program is running on
	float clownWalkAnimationTime = 0.f;
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
	sf::Text gameplayPauseFullscreenText;
	// MUSICS
	sf::Music bgStartUpScreenMusic;
	sf::Music bgStartUpScreenMusic2;
	sf::Music bgShopMusic;
	sf::Music bgShopMusic2;
	sf::Music bgLvl1Music;
	sf::Music bgLvl2Music;
	sf::Music bgLvl3Music;
	// SOUNDS
	sf::SoundBuffer sugarCrunchBuffer;
	sf::Sound sugarCrunch;
	// IMAGES
	sf::Image pieCursorImg;
	// TEXTURES
		// BACKGROUNDS & ICONS
	sf::Texture settingsIcon;
	sf::Texture bgStartUpScreen;
	sf::Texture levelOneParralax01;
	sf::Texture levelOneParralax02;
	sf::Texture levelOneParralax03;
	sf::Texture levelOneParralax04;
	sf::Texture levelOneParralax05;
	sf::Texture levelOneParralax06;
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
		// ENEMMIES
	sf::Texture deathTexture1;
	sf::Texture deathTexture2;
	sf::Texture sugarTexture;
	sf::Texture shooterProjectile;
	sf::Texture eliteProjectile;
	sf::Texture painBizarre;
	sf::Texture tomato;
	sf::Texture banana;
	sf::Texture apple;
	sf::Texture burger;
	sf::Texture carrot;
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
	sf::Texture gameplayUIPauseSoundPlus;
	sf::Texture gameplayUIPauseSoundMinus;
	sf::Texture gameplayPauseCheckboxTexture;
	sf::Texture nothing;
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
	sf::RectangleShape gameplayPauseFullscreenCheckbox;
	// SPRITES
	sf::Sprite bgStartUpScreenSprite;
	sf::Sprite settingsIconSprite;
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
	sf::Sprite playerCurrentSprite;
	sf::Sprite gameplayUILifeBarCurrentSprite;
	// VECTORS
	std::vector<sf::Vector2f> shooterPositions; ////////////////////////////////
	std::vector<Projectile*> projectiles;
	std::vector<Sugar*> vectorSugar;
	std::vector<Pie*> vectorPies;
	std::vector<Normal> vectorNormal;
	std::vector<Shooter> vectorShooter;
	std::vector<Elite> vectorElite;
	// PLAYER 
	Player player;
	// DESSINER POINTEURS
	Projectile projectileDraw;
	Sugar sugarDraw;
	Sugar sugarIcone;
	Pie pieDraw;
}

Game::Game() :
	windowBase(sf::VideoMode(modes[0].width, modes[0].height), "Base"),     // To get relative positions to the native resolution if needed
	window    (sf::VideoMode(modes[0].width, modes[0].height), "Food'estroyer", sf::Style::Fullscreen)
{
	// Time gestion
	f_ElapsedTime = 0.f;
	m_isRunning = true;
	windowBase.setVisible(false);
	window.setFramerateLimit(60);
	startingTimePoint = std::chrono::high_resolution_clock::now();
	currentTimePoint = startingTimePoint;
	// Ennemies
	for (int i = 0; i < 15; ++i) positionsOccupied.push_back(false);
}

void Game::setupGraphicalElements() {
	// COLORS
	DARK_THEME   = sf::Color(30, 30, 30);
	LIGHT_GRAY   = sf::Color(175, 175, 175);
	LIGHT_RED    = sf::Color(230, 30, 30);
	LIGHT_GREEN  = sf::Color(30, 230, 20);
	LIGHT_YELLOW = sf::Color(238, 255, 0);
	// FONTS
	FPSFont.loadFromFile          ("Assets/Fonts/FPS.TTF");
	puppy.loadFromFile            ("Assets/Fonts/FriskyPuppy.ttf");
	alien.loadFromFile            ("Assets/Fonts/alienAlphabet.ttf");
	graffitiBorders.loadFromFile  ("Assets/Fonts/graffitiBorders.otf");
	graffitiNoBorders.loadFromFile("Assets/Fonts/graffitiNoBorders.ttf");
	score.loadFromFile            ("Assets/Fonts/score.TTF");
	scoreBold.loadFromFile        ("Assets/Fonts/scoreBold.TTF");
	// MUSICS
	bgStartUpScreenMusic.openFromFile ("Assets/Songs/Music/startMenuLoop.mp3");
	bgStartUpScreenMusic2.openFromFile("Assets/Songs/Music/startMenuLoop2.mp3");
	bgShopMusic.openFromFile          ("Assets/Songs/Music/shopLoop.mp3");
	bgShopMusic2.openFromFile         ("Assets/Songs/Music/shopLoop2.mp3");
	bgLvl1Music.openFromFile          ("Assets/Songs/Music/bgMusicLevel1.mp3");
	bgLvl2Music.openFromFile          ("Assets/Songs/Music/bgMusicLevel2.mp3");
	bgLvl3Music.openFromFile          ("Assets/Songs/Music/bgMusicLevel3.mp3");
	bgStartUpScreenMusic.setVolume(50);
	bgStartUpScreenMusic2.setVolume(50);
	bgShopMusic.setVolume(50);
	bgShopMusic2.setVolume(50);
	bgLvl1Music.setVolume(50);
	bgLvl2Music.setVolume(50);
	bgLvl3Music.setVolume(50);
	bgStartUpScreenMusic2.setLoop(true);
	bgStartUpScreenMusic2.play();
	// SOUNDS
	sugarCrunchBuffer.loadFromFile("Assets/Sound Effects/sugar crunch.wav");
	sugarCrunch.setBuffer(sugarCrunchBuffer);
	// IMAGES
	pieCursorImg.loadFromFile("Assets/Images/pieCursor.png");
	window.setIcon(pieCursorImg.getSize().x, pieCursorImg.getSize().y, pieCursorImg.getPixelsPtr());
	// TEXTURES
	bgStartUpScreen.loadFromFile            ("Assets/Images/bgStartUpScreen.jpg");
	settingsIcon.loadFromFile               ("Assets/Images/settingsIcon.png");
	levelOneParralax01.loadFromFile         ("Assets/Images/Level1/level1Background01.png");
	levelOneParralax02.loadFromFile         ("Assets/Images/Level1/level1Background02.png");
	levelOneParralax03.loadFromFile         ("Assets/Images/Level1/level1Background03.png");
	levelOneParralax04.loadFromFile         ("Assets/Images/Level1/level1Background04.png");
	levelOneParralax05.loadFromFile         ("Assets/Images/Level1/level1Background05.png");
	levelOneParralax06.loadFromFile         ("Assets/Images/Level1/level1Background06.png");
	playerMove1.loadFromFile                ("Assets/Images/Clown/Walk/frame_0_walk_clown.png");
	playerMove2.loadFromFile                ("Assets/Images/Clown/Walk/frame_1_walk_clown.png");
	playerAttack1.loadFromFile              ("Assets/Images/Clown/Attack/frame_0_attack_clown.png");
	playerAttack2.loadFromFile              ("Assets/Images/Clown/Attack/frame_1_attack_clown.png");
	playerDeath1.loadFromFile               ("Assets/Images/Clown/Death/frame_0_death_clown.png");
	playerDeath2.loadFromFile               ("Assets/Images/Clown/Death/frame_1_death_clown.png");
	playerDeath3.loadFromFile               ("Assets/Images/Clown/Death/frame_2_death_clown.png");
	playerDeath4.loadFromFile               ("Assets/Images/Clown/Death/frame_3_death_clown.png");
	playerDeath5.loadFromFile               ("Assets/Images/Clown/Death/frame_4_death_clown.png");
	playerDeath6.loadFromFile               ("Assets/Images/Clown/Death/frame_5_death_clown.png");
	pieTexture.loadFromFile                 ("Assets/Images/Clown/Pies/butterscotchPie.png");
	deathTexture1.loadFromFile                ("Assets/Images/Enemy/Death/death1.png");
	deathTexture2.loadFromFile                ("Assets/Images/Enemy/Death/death2.png");
	painBizarre.loadFromFile                ("Assets/Images/Enemy/Shooter/m.png");
	tomato.loadFromFile                     ("Assets/Images/Enemy/Shooter/tomato.png");
	banana.loadFromFile                     ("Assets/Images/Enemy/Shooter/banana.png");
	apple.loadFromFile                      ("Assets/Images/Enemy/Shooter/apple.png");
	burger.loadFromFile                     ("Assets/Images/Enemy/Shooter/burger.png");
	carrot.loadFromFile                     ("Assets/Images/Enemy/Shooter/carrot.png");
	sugarTexture.loadFromFile               ("Assets/Images/Enemy/sugarSquare.png");
	shooterProjectile.loadFromFile          ("Assets/Images/Enemy/Projectiles/shooterProjectile.png");
	eliteProjectile.loadFromFile            ("Assets/Images/Enemy/Projectiles/eliteProjectile.png");
	gameplayUILifeBar01Active.loadFromFile  ("Assets/Images/GameplayUI/01-active.png");
	gameplayUILifeBar02Active.loadFromFile  ("Assets/Images/GameplayUI/02-active.png");
	gameplayUILifeBar03Active.loadFromFile  ("Assets/Images/GameplayUI/03-active.png");
	gameplayUILifeBar04Active.loadFromFile  ("Assets/Images/GameplayUI/04-active.png");
	gameplayUILifeBar05Active.loadFromFile  ("Assets/Images/GameplayUI/05-active.png");
	gameplayUILifeBar06Active.loadFromFile  ("Assets/Images/GameplayUI/06-active.png");
	gameplayUILifeBar07Active.loadFromFile  ("Assets/Images/GameplayUI/07-active.png");
	gameplayUILifeBar08Active.loadFromFile  ("Assets/Images/GameplayUI/08-active.png");
	gameplayUILifeBar09Active.loadFromFile  ("Assets/Images/GameplayUI/09-active.png");
	gameplayUILifeBar10Active.loadFromFile  ("Assets/Images/GameplayUI/10-active.png");
	gameplayUILifeBar11Active.loadFromFile  ("Assets/Images/GameplayUI/11-active.png");
	gameplayUILifeBar12Active.loadFromFile  ("Assets/Images/GameplayUI/12-active.png");
	gameplayUILifeBar13Active.loadFromFile  ("Assets/Images/GameplayUI/13-active.png");
	gameplayUILifeBar14Active.loadFromFile  ("Assets/Images/GameplayUI/14-active.png");
	gameplayUILifeBar15Active.loadFromFile  ("Assets/Images/GameplayUI/15-active.png");
	gameplayUILifeBar16Active.loadFromFile  ("Assets/Images/GameplayUI/16-active.png");
	gameplayUILifeBar17Active.loadFromFile  ("Assets/Images/GameplayUI/17-active.png");
	gameplayUILifeBar18Active.loadFromFile  ("Assets/Images/GameplayUI/18-active.png");
	gameplayUILifeBar19Active.loadFromFile  ("Assets/Images/GameplayUI/19-active.png");
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
	gameplayPauseCheckboxTexture.loadFromFile("Assets/Images/GameplayUI/PauseMenu/checkbox-ok.png");
	nothing.loadFromFile("Assets/images/GameplayUI/PauseMenu/checkbox-no.png");
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
	gameplayPauseContent.setSize(sf::Vector2f((window.getSize().x * 0.66f), (window.getSize().y * 0.65f)));
	gameplayPauseContent.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseContent.getLocalBounds().width / 2, window.getSize().y / 2 - gameplayPauseContent.getLocalBounds().height / 2));
	gameplayPauseContent.setFillColor(sf::Color(200, 200, 200, 200));
	gameplayPauseContent.setOutlineThickness(2.f);
	gameplayPauseContent.setOutlineColor(sf::Color::Black);
	gameplayPauseGoBackBtn.setSize(sf::Vector2f(gameplayPauseContent.getSize().x / 5, window.getSize().y / 16.f));
	gameplayPauseExitBtn.setSize(gameplayPauseGoBackBtn.getSize());
	gameplayPauseGoBackBtn.setPosition(sf::Vector2f(gameplayPauseContent.getPosition().x + window.getSize().x * 0.01f, gameplayPauseContent.getPosition().y + gameplayPauseContent.getLocalBounds().height - gameplayPauseGoBackBtn.getLocalBounds().height - window.getSize().x * 0.01f));
	gameplayPauseExitBtn.setPosition(sf::Vector2f(gameplayPauseContent.getPosition().x + gameplayPauseContent.getLocalBounds().width  - gameplayPauseExitBtn.getLocalBounds().width - window.getSize().x * 0.01f, gameplayPauseContent.getPosition().y + gameplayPauseContent.getLocalBounds().height - gameplayPauseExitBtn.getLocalBounds().height - window.getSize().x * 0.01f));
	gameplayPauseGoBackBtn.setFillColor(sf::Color(200,200,200,200));
	gameplayPauseExitBtn.setFillColor(sf::Color(200,200,200,200));
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
	gameplayPauseFullscreenCheckbox.setSize(sf::Vector2f(gameplayPauseGoBackBtn.getSize().y, gameplayPauseGoBackBtn.getSize().y));
	gameplayPauseFullscreenCheckbox.setOutlineThickness(1.f);
	gameplayPauseFullscreenCheckbox.setOutlineColor(sf::Color::Black);
	gameplayPauseFullscreenCheckbox.setPosition(sf::Vector2f(window.getSize().x / 2 + window.getSize().x * 0.02f, gameplayPauseGoBackBtn.getPosition().y));
	if (window.getSize() == sf::Vector2u(modes[0].width, modes[0].height))
		gameplayPauseFullscreenCheckbox.setTexture(&gameplayPauseCheckboxTexture);
	else
		gameplayPauseFullscreenCheckbox.setTexture(&nothing);
	// SPRITES
	bgStartUpScreenSprite.setTexture(bgStartUpScreen);
	bgStartUpScreenSprite.setScale(sf::Vector2f((window.getSize().x / bgStartUpScreenSprite.getLocalBounds().width), (window.getSize().y / bgStartUpScreenSprite.getLocalBounds().height)));
	bgStartUpScreenSprite.setPosition(sf::Vector2f(0,0));
	settingsIconSprite.setTexture(settingsIcon);
	settingsIconSprite.setPosition(sf::Vector2f(20.f, 20.f));
	levelOneParralax01Sprite.setTexture(levelOneParralax01);
	levelOneParralax02Sprite.setTexture(levelOneParralax02);
	levelOneParralax03Sprite.setTexture(levelOneParralax03);
	levelOneParralax04Sprite.setTexture(levelOneParralax04);
	levelOneParralax05Sprite.setTexture(levelOneParralax05);
	levelOneParralax06Sprite.setTexture(levelOneParralax06);
	levelOneParralax01SpriteCopy.setTexture(levelOneParralax01);
	levelOneParralax02SpriteCopy.setTexture(levelOneParralax02);
	levelOneParralax03SpriteCopy.setTexture(levelOneParralax03);
	levelOneParralax04SpriteCopy.setTexture(levelOneParralax04);
	levelOneParralax05SpriteCopy.setTexture(levelOneParralax05);
	levelOneParralax06SpriteCopy.setTexture(levelOneParralax06);
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
	levelOneParralax01Sprite.setPosition(sf::Vector2f(0,0));
	levelOneParralax02Sprite.setPosition(sf::Vector2f(0,0));
	levelOneParralax03Sprite.setPosition(sf::Vector2f(0,0));
	levelOneParralax04Sprite.setPosition(sf::Vector2f(0,0));
	levelOneParralax05Sprite.setPosition(sf::Vector2f(0,0));
	levelOneParralax06Sprite.setPosition(sf::Vector2f(0,0));
	levelOneParralax01SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x,0));
	levelOneParralax02SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x,0));
	levelOneParralax03SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x,0));
	levelOneParralax04SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x,0));
	levelOneParralax05SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x,0));
	levelOneParralax06SpriteCopy.setPosition(sf::Vector2f(0 + (float)window.getSize().x,0));
	playerCurrentSprite.setTexture(playerMove1);
	playerCurrentSprite.setScale(sf::Vector2f((window.getSize().x * 0.05f) / (playerCurrentSprite.getLocalBounds().width), (window.getSize().y * 0.10f) / (playerCurrentSprite.getLocalBounds().height)));
	playerCurrentSprite.setPosition(sf::Vector2f(window.getSize().x * 0.07f, (window.getSize().y / 2) - (playerCurrentSprite.getGlobalBounds().height / 2)));
	player.setPosition(playerCurrentSprite.getPosition());
	gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Active);
	gameplayUILifeBarCurrentSprite.setScale(sf::Vector2f((window.getSize().x * 0.20f) / (gameplayUILifeBarCurrentSprite.getLocalBounds().width), (window.getSize().x * 0.04356f) / (gameplayUILifeBarCurrentSprite.getLocalBounds().height)));
	gameplayUILifeBarCurrentSprite.setPosition(sf::Vector2f(0, 0));
	// TEXTS
	// Fps
	FPSText.setFont(FPSFont);
	FPSText.setCharacterSize(12);
	FPSText.setFillColor(sf::Color::Black);
	FPSText.setString("FPS : 60.00");
	// Main menu
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
	shopText.setPosition(sf::Vector2f(((float)(window.getSize().x / 2.f) - (float)(shopText.getLocalBounds().width / 2.f)), (float)(window.getSize().y / 2.f)));
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
	// Gameplay pause menu
	gameplayPauseTitleText.setFont(puppy);
	gameplayPauseTitleText.setCharacterSize(60);
	gameplayPauseTitleText.setFillColor(sf::Color::White);
	gameplayPauseTitleText.setOutlineThickness(1.f);
	gameplayPauseTitleText.setOutlineColor(sf::Color::Black);
	gameplayPauseTitleText.setString("Pause");
	gameplayPauseTitleText.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseTitleText.getLocalBounds().width / 2, gameplayPauseContent.getPosition().y + window.getSize().x * 0.01f));
	gameplayPauseGoBackText.setFont(puppy);
	gameplayPauseGoBackText.setCharacterSize(35);
	gameplayPauseGoBackText.setFillColor(sf::Color::White);
	gameplayPauseGoBackText.setOutlineThickness(1.f);
	gameplayPauseGoBackText.setOutlineColor(sf::Color::Black);
	if (language == "EN")
		gameplayPauseGoBackText.setString("Go back");
	else if (language == "FR")
		gameplayPauseGoBackText.setString("Reprendre");
	gameplayPauseGoBackText.setPosition(sf::Vector2f(gameplayPauseGoBackBtn.getPosition().x + gameplayPauseGoBackBtn.getLocalBounds().width / 2 - gameplayPauseGoBackText.getLocalBounds().width / 2, gameplayPauseGoBackBtn.getPosition().y + gameplayPauseGoBackBtn.getSize().y / 6));
	gameplayPauseExitText.setFont(puppy);
	gameplayPauseExitText.setCharacterSize(35);
	gameplayPauseExitText.setFillColor(sf::Color::White);
	gameplayPauseExitText.setOutlineThickness(1.f);
	gameplayPauseExitText.setOutlineColor(sf::Color::Black);
	if (language == "EN")
		gameplayPauseExitText.setString("Exit");
	else if (language == "FR")
		gameplayPauseExitText.setString("Quitter");
	gameplayPauseExitText.setPosition(sf::Vector2f(gameplayPauseExitBtn.getPosition().x + gameplayPauseExitBtn.getLocalBounds().width / 2 - gameplayPauseExitText.getLocalBounds().width / 2, gameplayPauseExitBtn.getPosition().y + gameplayPauseExitBtn.getSize().y / 6));
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
	if (language == "EN")
		gameplayPauseMusicText.setString("Music");
	else if (language == "FR")
		gameplayPauseMusicText.setString("Musique");
	gameplayPauseMusicText.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseMusicText.getLocalBounds().width / 2, window.getSize().y / 2 - gameplayPauseMusicText.getLocalBounds().height / 2 - 2 * gameplayPauseMusicControlZone.getGlobalBounds().height));
	gameplayPauseSFXText.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseSFXText.getLocalBounds().width / 2, window.getSize().y / 2 - gameplayPauseSFXText.getLocalBounds().height / 2));
	gameplayPausePlusSoundTextSFX.setFont(puppy);
	gameplayPausePlusSoundTextSFX.setCharacterSize(35);
	gameplayPausePlusSoundTextSFX.setString("+");
	gameplayPausePlusSoundTextSFX.setFillColor(sf::Color(DARK_THEME));
	gameplayPausePlusSoundTextSFX.setOutlineThickness(1.f);
	gameplayPausePlusSoundTextSFX.setOutlineColor(sf::Color::Black);
	gameplayPausePlusSoundTextSFX.setPosition(sf::Vector2f(gameplayPauseSFXText.getPosition().x + gameplayPauseSFXText.getGlobalBounds().width + gameplayPausePlusSoundTextSFX.getLocalBounds().width, gameplayPauseSFXText.getPosition().y));
	gameplayPausePlusSoundTextMusic = gameplayPausePlusSoundTextSFX;
	gameplayPausePlusSoundTextMusic.setPosition(sf::Vector2f(gameplayPauseMusicText.getPosition().x + gameplayPauseMusicText.getGlobalBounds().width + gameplayPausePlusSoundTextMusic.getLocalBounds().width, gameplayPauseMusicText.getPosition().y));
	gameplayPauseMinusSoundTextSFX.setFont(puppy);
	gameplayPauseMinusSoundTextSFX.setCharacterSize(35);
	gameplayPauseMinusSoundTextSFX.setString("-");
	gameplayPauseMinusSoundTextSFX.setFillColor(sf::Color(DARK_THEME));
	gameplayPauseMinusSoundTextSFX.setOutlineThickness(1.f);
	gameplayPauseMinusSoundTextSFX.setOutlineColor(sf::Color::Black);
	gameplayPauseMinusSoundTextSFX.setPosition(sf::Vector2f(gameplayPauseSFXText.getPosition().x - gameplayPauseSFXText.getGlobalBounds().width / 1.4f, gameplayPauseSFXText.getPosition().y));
	gameplayPauseMinusSoundTextMusic = gameplayPauseMinusSoundTextSFX;
	gameplayPauseMinusSoundTextMusic.setPosition(sf::Vector2f(gameplayPauseMusicText.getPosition().x - gameplayPauseMusicText.getGlobalBounds().width / 1.8f, gameplayPauseMusicText.getPosition().y));
	gameplayPauseFullscreenText.setFont(puppy);
	gameplayPauseFullscreenText.setCharacterSize(35);
	gameplayPauseFullscreenText.setFillColor(sf::Color::White);
	gameplayPauseFullscreenText.setOutlineThickness(1.f);
	gameplayPauseFullscreenText.setOutlineColor(sf::Color(DARK_THEME));
	if (language == "EN")
		gameplayPauseFullscreenText.setString("Fullscreen");
	else if (language == "FR")
		gameplayPauseFullscreenText.setString("Plein écran");
	gameplayPauseFullscreenText.setPosition(sf::Vector2f(window.getSize().x / 2 - gameplayPauseFullscreenText.getGlobalBounds().width / 2 - gameplayPauseFullscreenCheckbox.getSize().x, gameplayPauseGoBackText.getPosition().y));
	// Gameplay UI
	gameplayUIScoreText.setFont(score);
	gameplayUIScoreText.setCharacterSize(50);
	gameplayUIScoreText.setLetterSpacing(1.1f);
	gameplayUIScoreText.setString("Score : 000000");
	gameplayUIScoreText.setFillColor(sf::Color::Black);
	gameplayUIScoreText.setPosition(sf::Vector2f(window.getSize().x - gameplayUIScoreText.getGlobalBounds().width - window.getSize().x * 0.01f, 0));
	sugarIcone.setScale(0.05f, 0.05f);
	sugarIcone.setTexture(sugarTexture);
	sugarIcone.setPosition(window.getSize().x /** 0.99*/ - (sugarIcone.getLocalBounds().width * sugarIcone.getScale().x) * 1.8f, window.getSize().y /** 0.97*/ - (sugarIcone.getLocalBounds().height * sugarIcone.getScale().y) * 1.8f);
	gameplayUISugarText.setFont(score);
	gameplayUISugarText.setCharacterSize((unsigned int)((float)sugarIcone.getLocalBounds().height * (float)sugarIcone.getScale().y));
	gameplayUISugarText.setLetterSpacing(1.1f); 
	gameplayUISugarText.setFillColor(sf::Color::White);
	gameplayUISugarText.setString("00000000");
	gameplayUISugarText.setPosition(sugarIcone.getPosition().x - gameplayUISugarText.getGlobalBounds().width - window.getSize().x * 0.005f, sugarIcone.getPosition().y - gameplayUISugarText.getGlobalBounds().height * 0.2f);
	// CURSORS
	pie.loadFromPixels(pieCursorImg.getPixelsPtr(), pieCursorImg.getSize(), {1, 32});
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

void Game::setEnemySpawn() {
	// Test pour randomiser la génération des ennemis au départ d'un niveau
	// Il marche mais les textures sont toutes blanches
	/*int randomYPosition, randomSize, randomClass, randomSkins;
	float xSpawnPosition = window.getSize().x + 100.f;
	const int randomHeights[10]           = { 0, 100, 200, 300, 400, 500, 600, 700, 800, 900 };
	const char randomSizes[3]             = { 's', 'm', 'l' };
	sf::Texture randomEnemySkins[6] = { apple, burger, banana, painBizarre, carrot, tomato };

	for (int i = 0; i < numberOfStartingEnnemies; ++i) {
		randomClass = rand() % 3 + 1;
		randomSize = rand() % 3;
		randomYPosition = rand() % 10;
		randomSkins = rand() % 6;

		Normal normal(xSpawnPosition, randomHeights[randomYPosition], randomSizes[randomSize], window);
		normal.setTexture(randomEnemySkins[randomSkins]);

		Shooter shooter(xSpawnPosition, randomHeights[randomYPosition], randomSizes[randomSize], window);
		shooter.setTexture(randomEnemySkins[randomSkins]);

		Elite elite(xSpawnPosition, randomHeights[randomYPosition], randomSizes[randomSize], window);
		elite.setTexture(randomEnemySkins[randomSkins]);

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

	}*/
	Shooter shooter1(window.getSize().x + 100.f, 800, 'm', window);
	shooter1.setTexture(apple);
	vectorShooter.push_back(shooter1);
	Shooter shooter2(window.getSize().x + 100.f, 900, 'm', window);
	shooter2.setTexture(burger);
	vectorShooter.push_back(shooter2);
	Shooter shooter3(window.getSize().x + 100.f, 1000, 'm', window);
	shooter3.setTexture(burger);
	vectorShooter.push_back(shooter3);
	Shooter shooter4(window.getSize().x + 100.f, 100, 'm', window);
	shooter4.setTexture(banana);
	vectorShooter.push_back(shooter4);
	Shooter shooter5(window.getSize().x + 100.f, 200, 'm', window);
	shooter5.setTexture(apple);
	vectorShooter.push_back(shooter5);
	Shooter shooter6(window.getSize().x + 100.f, 300, 'm', window);
	shooter6.setTexture(banana);
	vectorShooter.push_back(shooter6);
	Shooter shooter7(window.getSize().x + 100.f, 400, 'm', window);
	shooter7.setTexture(painBizarre);
	vectorShooter.push_back(shooter7);
	Shooter shooter8(window.getSize().x + 100.f, 500, 'm', window);
	shooter8.setTexture(banana);
	vectorShooter.push_back(shooter8);
	Shooter shooter9(window.getSize().x + 100.f, 600, 'm', window);
	shooter9.setTexture(carrot);
	vectorShooter.push_back(shooter9);
	Shooter shooter10(window.getSize().x + 100.f, 700, 'm', window);
	shooter10.setTexture(banana);
	vectorShooter.push_back(shooter10);
	Shooter shooter11(window.getSize().x + 100.f, 900, 'm', window);
	shooter11.setTexture(painBizarre);
	vectorShooter.push_back(shooter11);
	Shooter shooter12(window.getSize().x + 100.f, 900, 'm', window);
	shooter12.setTexture(burger);
	vectorShooter.push_back(shooter12);
	Shooter shooter13(window.getSize().x + 100.f, 900, 'm', window);
	shooter13.setTexture(burger);
	vectorShooter.push_back(shooter13);
	Shooter shooter14(window.getSize().x + 100.f, 900, 'm', window);
	shooter14.setTexture(painBizarre);
	vectorShooter.push_back(shooter14);
	Shooter shooter15(window.getSize().x + 100.f, 200, 'm', window);
	shooter15.setTexture(apple);
	vectorShooter.push_back(shooter15);
	Shooter shooter16(window.getSize().x + 100.f, 300, 'm', window);
	shooter16.setTexture(painBizarre);
	vectorShooter.push_back(shooter16);
	Normal normal1(1900, 500, 's', window);
	normal1.setTexture(painBizarre);
	vectorNormal.push_back(normal1);
	Elite elite1(1200, 800, 's', window);
	elite1.setTexture(carrot);
	vectorElite.push_back(elite1);
	Elite elite2(1500, 700, 'm', window);
	elite2.setTexture(tomato);
	vectorElite.push_back(elite2);
	Elite elite3(1300, 400, 'l', window);
	elite3.setTexture(carrot);
	vectorElite.push_back(elite3);
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
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = true;
				}
				if (pauseResolutionMode1Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[1].width, modes[1].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode2Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[2].width, modes[2].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode3Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[3].width, modes[3].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode4Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[4].width, modes[4].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play(); 
					isFullscreen = false;
				}
				if (pauseResolutionMode5Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[5].width, modes[5].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode6Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[6].width, modes[6].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode7Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[7].width, modes[7].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode8Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[8].width, modes[8].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode9Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[9].width, modes[9].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
					isFullscreen = false;
				}
				if (pauseResolutionMode10Text.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					window.create(sf::VideoMode(modes[10].width, modes[10].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
					window.setFramerateLimit(currentFramerateLimit);
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
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
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
				}
				if (pauseLanguageFRText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y) && language != "FR") {
					language = "FR";
					setupGraphicalElements();
					bgStartUpScreenMusic2.stop();
					bgShopMusic.play();
				}
			}
			if (startUpScreenOn) {
				// Options
				if (settingsIconSprite.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					settingsScreenOn = true;
					startUpScreenOn = false;
					bgStartUpScreenMusic2.pause();
				}
				// Jouer
				if (playText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					playScreenOn = true;
					startUpScreenOn = false;
					levelOneOn = true;
					backgroundActive = true;
					bgStartUpScreenMusic2.stop();
					bgLvl1Music.setLoop(false);
					bgLvl1Music.play();
				}
				// Quitter
				if (quitText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					m_isRunning = false;
				}
			}
			if (playScreenOn) {
				// To be defined
				if (showPauseMenu) {
					if (gameplayPauseExitBtn.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						levelOneOn = false;
						backgroundActive = false;
						showPauseMenu = false;
						startUpScreenOn = true;
						bgStartUpScreenMusic2.play();
					}
					if (gameplayPauseGoBackBtn.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
						backgroundActive = true;
						showPauseMenu = false;
						bgLvl1Music.play();
					}
					if (gameplayPausePlusSoundTextSFX.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						if(gameplayPauseSFXControlInnerZone.getScale().x < 1.f)
							gameplayPauseSFXControlInnerZone.setScale(sf::Vector2f(gameplayPauseSFXControlInnerZone.getScale().x + 0.05f, 1.f));
					}
					if (gameplayPauseMinusSoundTextSFX.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						if (gameplayPauseSFXControlInnerZone.getScale().x > 0.f)
							gameplayPauseSFXControlInnerZone.setScale(sf::Vector2f(gameplayPauseSFXControlInnerZone.getScale().x - 0.05f, 1.f));
					}
					if (gameplayPausePlusSoundTextMusic.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						if (gameplayPauseMusicControlInnerZone.getScale().x < 1.f) {
							gameplayPauseMusicControlInnerZone.setScale(sf::Vector2f(gameplayPauseMusicControlInnerZone.getScale().x + 0.05f, 1.f));
							if (levelOneOn) {
								bgLvl1Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
							}
						}
					}
					if (gameplayPauseMinusSoundTextMusic.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						if (gameplayPauseMusicControlInnerZone.getScale().x < 1.f) {
							gameplayPauseMusicControlInnerZone.setScale(sf::Vector2f(gameplayPauseMusicControlInnerZone.getScale().x - 0.05f, 1.f));
							if (levelOneOn) {
								bgLvl1Music.setVolume(100 * gameplayPauseMusicControlInnerZone.getScale().x);
							}
						}
					}
					if (gameplayPauseFullscreenCheckbox.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) 
					{
						if (isFullscreen) {
							window.create(sf::VideoMode(modes[3].width, modes[3].height), "Food'estroyer", sf::Style::Titlebar | sf::Style::Close);
							window.setFramerateLimit(currentFramerateLimit);
							setupGraphicalElements();
							bgStartUpScreenMusic2.stop();
							isFullscreen = false;
						}
						else {
							window.create(sf::VideoMode(modes[0].width, modes[0].height), "Food'estroyer", sf::Style::Fullscreen);
							window.setFramerateLimit(currentFramerateLimit);
							setupGraphicalElements();
							bgStartUpScreenMusic2.stop();
						}
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
				bgShopMusic.stop();
				bgStartUpScreenMusic2.play();
			}
			else if(startUpScreenOn) {
				m_isRunning = false;
			}
		}
	default:
		break;
	}
}

void Game::clownWalkAnimation() {
	if (clownWalkAnimationTime >= 0.1f) playerCurrentSprite.setTexture(playerMove2);
	if (clownWalkAnimationTime >= 0.2f) {
		playerCurrentSprite.setTexture(playerMove1);

		clownWalkAnimationTime = 0.f;
	}
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

void Game::scoreCalculation() {
	scoreCounter += (100.f * f_ElapsedTime);
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

void Game::playerInput() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		player.move(0, -800 * f_ElapsedTime);
		if (player.getPosition().y <= 0)
			player.setPosition(player.getPosition().x, 0);
		playerCurrentSprite.setPosition(player.getPosition());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player.move(0, 800 * f_ElapsedTime);
		if (player.getPosition().y + player.getRadius() * 2 >= window.getSize().y)
			player.setPosition(player.getPosition().x, window.getSize().y - player.getRadius() *  2);
		playerCurrentSprite.setPosition(player.getPosition());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.move(800 * f_ElapsedTime, 0);
		if (player.getPosition().x >= window.getSize().x - player.getRadius() * 2)
			player.setPosition(window.getSize().x - player.getRadius() * 2, player.getPosition().y);
		playerCurrentSprite.setPosition(player.getPosition());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		player.move(-800 * f_ElapsedTime, 0);
		if (player.getPosition().x <= 0)
			player.setPosition(0, player.getPosition().y);
		playerCurrentSprite.setPosition(player.getPosition());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		if (levelOneOn && backgroundActive) {
			backgroundActive = false;
			showPauseMenu = true;
			bgLvl1Music.pause();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (levelOneOn && backgroundActive) {
			// Ici y'aura le shoot
			if (player.getShootCooldown() >= 0.2f) {
				player.throwPie(vectorPies, window);
				player.setShootCooldown(0);
			}
			playerCurrentSprite.setTexture(playerAttack1);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		if (levelOneOn && backgroundActive) {
			// SPECIAL ATTACK
			if (player.getSpecialCooldown() >= 5.f) {
				player.specialAtk(vectorPies, window);
				player.setSpecialCooldown(0);
			}
			playerCurrentSprite.setTexture(playerAttack1);
		}
	}
}

void Game::playerCollisions() {

	for (int i = 0; i < projectiles.size(); i++) {
		if (player.getGlobalBounds().contains(projectiles[i]->getPosition())) {     ///// hurt box plus petite (cercle) pour les projectiles
			player.damagePlayer(projectiles[i]->getAtkPower());
			projectiles[i]->setState(false);
		}
	}
	for (int i = 0; i < vectorSugar.size(); i++) {
		if (playerCurrentSprite.getGlobalBounds().contains(vectorSugar[i]->getPosition())) {  ////hurt box = sprite du clown pour ramasser les sucres plus facilement
			player.setSugarCount(vectorSugar[i]->getValue());
			sugarCrunch.play();                                                ///////////////////////couper le début du son
			vectorSugar[i]->setState(false);
		}
	}
}

void Game::playerHPSetter() {
	if (player.getPlayerHP() <= 100.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Active);
		else{ gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Inactive); }
	}
	if (player.getPlayerHP() <= 95.f && player.getPlayerHP() > 90.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar02Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar02Inactive); }
	}
	if (player.getPlayerHP() <= 90.f && player.getPlayerHP() > 85.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar03Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar03Inactive); }
	}
	if (player.getPlayerHP() <= 85.f && player.getPlayerHP() > 80.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar04Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar04Inactive); }
	}
	if (player.getPlayerHP() <= 80.f && player.getPlayerHP() > 75.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar05Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar05Inactive); }
	}
	if (player.getPlayerHP() <= 75.f && player.getPlayerHP() > 70.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar06Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar06Inactive); }
	}
	if (player.getPlayerHP() <= 70.f && player.getPlayerHP() > 65.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar07Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar07Inactive); }
	}
	if (player.getPlayerHP() <= 65.f && player.getPlayerHP() > 60.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar08Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar08Inactive); }
	}
	if (player.getPlayerHP() <= 60.f && player.getPlayerHP() > 55.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar01Inactive); }
	}
	if (player.getPlayerHP() <= 55.f && player.getPlayerHP() > 50.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar09Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar09Inactive); }
	}
	if (player.getPlayerHP() <= 50.f && player.getPlayerHP() > 45.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar10Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar10Inactive); }
	}
	if (player.getPlayerHP() <= 45.f && player.getPlayerHP() > 40.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar11Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar11Inactive); }
	}
	if (player.getPlayerHP() <= 40.f && player.getPlayerHP() > 35.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar12Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar12Inactive); }
	}
	if (player.getPlayerHP() <= 35.f && player.getPlayerHP() > 30.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar13Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar13Inactive); }
	}
	if (player.getPlayerHP() <= 30.f && player.getPlayerHP() > 25.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar14Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar14Inactive); }
	}
	if (player.getPlayerHP() <= 25.f && player.getPlayerHP() > 20.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar15Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar15Inactive); }
	}
	if (player.getPlayerHP() <= 20.f && player.getPlayerHP() > 15.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar16Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar16Inactive); }
	}
	if (player.getPlayerHP() <= 15.f && player.getPlayerHP() > 10.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar17Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar17Inactive); }
	}
	if (player.getPlayerHP() <= 10.f && player.getPlayerHP() > 0.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar18Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar18Inactive); }
	}
	if (player.getPlayerHP() <= 0.f && player.getPlayerHP() > 90.f) {
		if (player.getSpecialCooldown() >= 5.f)
			gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar19Active);
		else { gameplayUILifeBarCurrentSprite.setTexture(gameplayUILifeBar19Inactive); }
	}
}

void Game::nonPlayerBehavior() {
	for (int i = 0; i < vectorPies.size(); i++) {
		vectorPies[i]->move(vectorPies[i]->getSpeed() * f_ElapsedTime, 0);
		if (vectorPies[i]->getPosition().x > window.getSize().x + vectorPies[i]->getRadius() * 2
			|| vectorPies[i]->getState() == false) {
			delete vectorPies[i];
			vectorPies.erase(vectorPies.begin() + i);
		}
	}
	for (int i = 0; i < vectorSugar.size(); i++) {
		vectorSugar[i]->move(-300 * f_ElapsedTime, 0);
		if (vectorSugar[i]->getPosition().x < 0 - /*(vectorSugar[i]->getLocalBounds().width * vectorSugar[i]->getScale().x)*/ 100.f
			|| vectorSugar[i]->getState() == false) {
			delete vectorSugar[i];
			vectorSugar.erase(vectorSugar.begin() + i);
		}
	}
	for (int i = 0; i < projectiles.size(); i++) {
		projectiles[i]->move(-600 * f_ElapsedTime, 0);
		if (projectiles[i]->getPosition().x < 0 - /*(projectiles[i]->getLocalBounds().width * projectiles[i]->getScale().x)*/ 100.f
			|| projectiles[i]->getState() == false) {
			delete projectiles[i];
			projectiles.erase(projectiles.begin() + i);
		}
	}
	for (int i = 0; i < vectorNormal.size(); i++) {
		if (vectorNormal[i].getAlive()) {
			vectorNormal[i].behavior(f_ElapsedTime);
			vectorNormal[i].dropSugar(vectorSugar, vectorNormal[i]);
			for (Pie*& pie : vectorPies) {
				if (vectorNormal[i].getGlobalBounds().intersects(pie->getGlobalBounds())) {
					vectorNormal[i].setHp(-pie->getAtkPower()); 
					if (pie->specialType == 'b') {
						pie->hitCounter++;
						if (pie->hitCounter >= 3)//HIT DETECTION INCONSISTENT : specialAtk ne touche que 2 shooter (dans une meme ligne) alors  qu'il les one shot
							pie->setState(false);
					}
					else { pie->setState(false); }
					
				}
			}
		}
		else {
			vectorNormal[i].deathAnimationTimer += f_ElapsedTime;
			vectorNormal[i].setTexture(deathTexture1);
			if (vectorNormal[i].deathAnimationTimer >= 0.3f) { vectorNormal[i].setTexture(deathTexture2); }
			if (vectorNormal[i].deathAnimationTimer >= 0.5f) { vectorNormal.erase(vectorNormal.begin() + i); }
		}
	}
	for (int i = 0; i < vectorShooter.size(); i++) {
		if (vectorShooter[i].getAlive()) {
			vectorShooter[i].behavior(f_ElapsedTime, vectorShooter, shooterPositions, projectiles, positionsOccupied);
			vectorShooter[i].dropSugar(vectorSugar, vectorShooter[i]);
			for (Pie*& pie : vectorPies) {
				if (vectorShooter[i].getGlobalBounds().intersects(pie->getGlobalBounds())) {
					vectorShooter[i].setHp(-pie->getAtkPower());
					if (pie->specialType == 'b') {
						pie->hitCounter++;
						if (pie->hitCounter >= 3)
							pie->setState(false);
					}
					else { pie->setState(false); }
				}
			}
		}
		else {
			vectorShooter[i].deathAnimationTimer += f_ElapsedTime;
			vectorShooter[i].setTexture(deathTexture1);
			if (vectorShooter[i].deathAnimationTimer >= 0.3f) { vectorShooter[i].setTexture(deathTexture2); }
			if (vectorShooter[i].deathAnimationTimer >= 0.5f) { vectorShooter.erase(vectorShooter.begin() + i); }
		}
	}
	for (int i = 0; i < vectorElite.size(); i++) {
		if (vectorElite[i].getAlive()) {
			vectorElite[i].behavior(f_ElapsedTime, player, projectiles, window);
			vectorElite[i].dropSugar(vectorSugar, vectorElite[i]);
			for (Pie*& pie : vectorPies) {
				if (vectorElite[i].getGlobalBounds().intersects(pie->getGlobalBounds())) {
					vectorElite[i].setHp(-pie->getAtkPower());
					if (pie->specialType == 'b') {
						pie->hitCounter++;
						if (pie->hitCounter >= 3)
							pie->setState(false);
					}
					else { pie->setState(false); }
				}
			}
		}
		else {
			vectorElite[i].deathAnimationTimer += f_ElapsedTime;
			vectorElite[i].setTexture(deathTexture1);
			if (vectorElite[i].deathAnimationTimer >= 0.3f) { vectorElite[i].setTexture(deathTexture2); }
			if (vectorElite[i].deathAnimationTimer >= 0.5f) { vectorElite.erase(vectorElite.begin() + i); }
		}
	}
}

void Game::nonPlayerDraw() {
	for (Pie*& pie : vectorPies) {
		pieDraw.setRadius(pie->getRadius());
		pieDraw.setTexture(&pieTexture);
		pieDraw.setPosition(pie->getPosition());
		window.draw(pieDraw);
	}
	for (Projectile*& projectile : projectiles) {
		projectileDraw.setScale(projectile->getScale());
		if (projectile->getId() == "shooter")
			projectileDraw.setTexture(shooterProjectile);
		if (projectile->getId() == "elite")
			projectileDraw.setTexture(eliteProjectile);
		projectileDraw.setPosition(projectile->getPosition());
		window.draw(projectileDraw);
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
}

void Game::run() {

	setupGraphicalElements();
	setShooterPositions();
	setEnemySpawn();                                          //////////////////////

	while (m_isRunning) {
		// Funtctions loop
		FPSCalculation();
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
	//UPDATE SHOOTER PLACEMENTS IF RESOLUTION IS CHANGED
	if (settingsScreenOn) { 
		shooterPositions[0]  = { (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.1) };
		shooterPositions[1]  = { (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.3) };
		shooterPositions[2]  = { (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.5) };
		shooterPositions[3]  = { (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.7) };
		shooterPositions[4]  = { (float)(window.getSize().x * 0.9), (float)(window.getSize().y * 0.9) };
		shooterPositions[5]  = { (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.1) };
		shooterPositions[6]  = { (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.3) };
		shooterPositions[7]  = { (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.5) };
		shooterPositions[8]  = { (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.7) };
		shooterPositions[9]  = { (float)(window.getSize().x * 0.8), (float)(window.getSize().y * 0.9) };
		shooterPositions[10] = { (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.1) };
		shooterPositions[11] = { (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.3) };
		shooterPositions[12] = { (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.5) };
		shooterPositions[13] = { (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.7) };
		shooterPositions[14] = { (float)(window.getSize().x * 0.7), (float)(window.getSize().y * 0.9) };
	}

	if (levelOneOn) {
		if (backgroundActive) {
			clownWalkAnimationTime += f_ElapsedTime;
			
			scoreCalculation();
			sugarCalculation();
			playerHPSetter();
			player.setShootCooldown(f_ElapsedTime);
			player.setSpecialCooldown(f_ElapsedTime);
			playerInput();
			playerCollisions();
			nonPlayerBehavior();
			clownWalkAnimation();

			backgroundMovementLevel1();
		}
	}
}

void Game::render() {
	window.clear(sf::Color::Black);

	if (settingsScreenOn) {
		window.draw(bgStartUpScreenSprite);
		window.draw(screenShadowWhenBlured);
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
			window.draw(gameplayUILifeBarCurrentSprite);
			window.draw(gameplayUIScoreText);
			window.draw(sugarIcone);
			window.draw(gameplayUISugarText);
		}
		if (showPauseMenu) {
			window.draw(screenShadowWhenBlured);
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
			window.draw(gameplayPauseFullscreenCheckbox);
			window.draw(gameplayPauseFullscreenText);
		}
	}

	window.draw(FPSText);
	window.setMouseCursor(pie);
	window.display();
}