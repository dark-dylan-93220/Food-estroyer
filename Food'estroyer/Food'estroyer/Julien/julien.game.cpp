#include "game.h"

namespace {
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes(); // Gets the native resolutions of the machine this program is running on
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
	// SIZES, POISITONS, COLORS.
	// SPRITES, TEXTURES, IMAGES
	// FONTS, MUSICS, SOUNDS
}

void Game::pollEvents() {
	sf::Event event;
	window.pollEvent(event);
	switch (event.type) {
	case sf::Event::Closed:
		std::cout << "Fermeture du programme" << std::endl;
		m_isRunning = false;
		window.close();
		windowBase.close();
		break;
	default:
		break;
	}
}

void Game::run() {

	setupGraphicalElements();

	while (window.isOpen()) {
		pollEvents();
		update();
		render();
	}

}


void Game::update() {
	// MECHANICS
}

void Game::render() {
	window.clear();
	// DRAWING
	window.display();
}