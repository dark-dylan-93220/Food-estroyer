#include "j.game.h"

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
	// FONTS
	sf::Font puppy;
	sf::Font alien;
	sf::Font graffitiBorders;
	sf::Font graffitiNoBorders;
	sf::Font score;
	sf::Font scoreBold;
	// TEXTS
	sf::Text playText;
	sf::Text settingsText;
	sf::Text shopText;
	sf::Text quitText;
	sf::Text copyright;
	// MUSICS
	// SOUNDS
	// IMAGES
	sf::Image pieCursorImg;
	// TEXTURES
	sf::Texture bgStartUpScreen;
	// SHAPES
	// SPRITES
	sf::Sprite bgStartUpScreenSprite;
}

Game::Game() :
	windowBase(sf::VideoMode(modes[0].width, modes[0].height), "Base"),     // To get relative positions to the native resolution if needed
	window(sf::VideoMode(modes[0].width, modes[0].height), "Food'estroyer", sf::Style::Fullscreen)
{
	m_isRunning = true;
	windowBase.setVisible(false);
	window.setFramerateLimit(60);
}

void Game::setupGraphicalElements() {
	// COLORS
	DARK_THEME = sf::Color(30, 30, 30);
	LIGHT_GRAY = sf::Color(175, 175, 175);
	LIGHT_RED = sf::Color(230, 30, 30, 180);
	// FONTS
	puppy.loadFromFile("Dylan/Assets/Fonts/FriskyPuppy.ttf");
	alien.loadFromFile("Dylan/Assets/Fonts/alienAlphabet.ttf");
	graffitiBorders.loadFromFile("Dylan/Assets/Fonts/graffitiBorders.otf");
	graffitiNoBorders.loadFromFile("Dylan/Assets/Fonts/graffitiNoBorders.ttf");
	score.loadFromFile("Dylan/Assets/Fonts/score.TTF");
	scoreBold.loadFromFile("Dylan/Assets/Fonts/scoreBold.TTF");
	// TEXTS
	playText.setFont(puppy);
	playText.setCharacterSize(40);
	playText.setString("Play");
	playText.setFillColor(sf::Color::White);
	playText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (playText.getLocalBounds().width / 2)), (window.getSize().y / 2) - 70.f));
	playText.setOutlineThickness(1);
	playText.setOutlineColor(sf::Color(DARK_THEME));
	shopText.setFont(puppy);
	shopText.setCharacterSize(40);
	shopText.setString("Shop");
	shopText.setFillColor(sf::Color::White);
	shopText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (shopText.getLocalBounds().width / 2)), (window.getSize().y / 2)));
	shopText.setOutlineThickness(1);
	shopText.setOutlineColor(sf::Color(DARK_THEME));
	quitText.setFont(puppy);
	quitText.setCharacterSize(40);
	quitText.setString("Quit");
	quitText.setFillColor(sf::Color::White);
	quitText.setPosition(sf::Vector2f(((window.getSize().x / 2) - (quitText.getLocalBounds().width / 2)), (window.getSize().y / 2) + 70.f));
	quitText.setOutlineThickness(1);
	quitText.setOutlineColor(sf::Color(DARK_THEME));
	copyright.setFont(puppy);
	copyright.setCharacterSize(23);
	copyright.setString("Dylan Hollemaert & Julien Rodrigues | 2024");
	copyright.setFillColor(sf::Color::White);
	copyright.setPosition(sf::Vector2f(((window.getSize().x / 2) - (copyright.getLocalBounds().width / 2)), window.getSize().y - 45.f));
	// MUSICS
	// SOUNDS
	// IMAGES
	pieCursorImg.loadFromFile("Dylan/Assets/Images/pieCursor.png");
	// TEXTURES
	bgStartUpScreen.loadFromFile("Dylan/Assets/Images/bgStartUpScreen.jpg");
	// SHAPES
	// SPRITES
	bgStartUpScreenSprite.setTexture(bgStartUpScreen);
	bgStartUpScreenSprite.setScale(sf::Vector2f((window.getSize().x / bgStartUpScreenSprite.getLocalBounds().width), (window.getSize().y / bgStartUpScreenSprite.getLocalBounds().height)));
	bgStartUpScreenSprite.setPosition(sf::Vector2f(0, 0));
	// CURSORS
	pie.loadFromPixels(pieCursorImg.getPixelsPtr(), pieCursorImg.getSize(), { 18,14 });
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
				playText.setFillColor(LIGHT_GRAY);
			else
				playText.setFillColor(sf::Color::White);
			if (shopText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				shopText.setFillColor(LIGHT_GRAY);
			else
				shopText.setFillColor(sf::Color::White);
			if (quitText.getGlobalBounds().contains((float)event.mouseMove.x, (float)event.mouseMove.y))
				quitText.setFillColor(LIGHT_RED);
			else
				quitText.setFillColor(sf::Color::White);
		}
		break;
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) {
			// "Fermer"
			if (quitText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
				m_isRunning = false;
			}
		}
		mouseLastDownX = event.mouseButton.x;
		mouseLastDownY = event.mouseButton.y;
		isMouseDragging = true;
		break;
	case sf::Event::MouseButtonReleased:
		isMouseDragging = false;
		break;
	default:
		break;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && startUpScreenOn) {
		m_isRunning = false;
	}
}

void Game::run() {

	setupGraphicalElements();

	while (m_isRunning) {
		pollEvents();
		update();
		render();
	}

	window.close();
	windowBase.close();

}


void Game::update() {
	// MECHANICS
}

void Game::render() {
	window.clear(sf::Color::Black);

	// DRAWING
	if (startUpScreenOn) {
		window.draw(bgStartUpScreenSprite);
		window.draw(playText);
		window.draw(shopText);
		window.draw(quitText);
		window.draw(copyright);
		window.setMouseCursor(pie);
	}

	window.display();
}

/// NOTES

// I. Fonts
// Puppy : Must be used for information display
// Graffiti (borders / no borders) : must be used for dialogs, small talks, or visual effects
// Score (bold or not) : must only be used to display the user's score during the game and after the game has ended in the results panel
// Alien alphabet : must be used to display visual effects on the alien's side

// II. ...