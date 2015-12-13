#include <unordered_map>
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game.hpp"
#include "dawnbringer32.hpp"
#include "button.hpp"
#include "game_state_main_menu.hpp"

namespace gromenia {
	Game::Game() : window(sf::VideoMode(this->window_width, this->window_height), "The Legend of Gromenia", sf::Style::Titlebar | sf::Style::Close) {
		window.setFramerateLimit(60);
		this->load_texture("button_brown_up", "protomedia/sprites/buttonLong_brown.png");
		this->load_texture("button_brown_down", "protomedia/sprites/buttonLong_brown_pressed.png");
		this->load_texture("button_beige_up", "protomedia/sprites/buttonLong_beige.png");
		this->load_texture("button_beige_down", "protomedia/sprites/buttonLong_beige_pressed.png");
		this->load_texture("button_blue_up", "protomedia/sprites/buttonLong_blue.png");
		this->load_texture("button_blue_down", "protomedia/sprites/buttonLong_blue_pressed.png");
		this->load_texture("button_gray_up", "protomedia/sprites/buttonLong_grey.png");
		this->load_texture("button_gray_down", "protomedia/sprites/buttonLong_grey_pressed.png");
		this->font.loadFromFile("protomedia/fonts/kenpixel.ttf");
		this->set_state(new GameStateMainMenu(this, &this->font));
	}
	
	Game::~Game() {
		while (!this->state_stack.empty()) {
			this->pop_state();
		}
	}
	
	sf::Texture& Game::get_texture(std::string label) {
		return this->texture_atlas.at(label);
	}
	
	void Game::load_texture(std::string label, std::string filename) {
		sf::Texture texture;
		if (!texture.loadFromFile(filename)) {
			return;
		}
		this->texture_atlas.insert(std::pair<std::string, sf::Texture>(label, texture));
		return;
	}
	
	void Game::game_loop() {
		while (this->window.isOpen() && !this->state_stack.empty()) {
			this->get_state()->parse_events();
			this->get_state()->draw();
		}
		if (this->window.isOpen() && this->state_stack.empty()) {
			this->window.close();
		}
		return;
	}
	
	GameState* Game::get_state() {
		if (!this->state_stack.empty()) {
			return this->state_stack.top();
		}
		return nullptr;
	}
	
	void Game::set_state(GameState *state) {
		this->state_stack.push(state);
		return;
	}
	
	void Game::pop_state() {
		if (!this->state_stack.empty()) {
			delete this->state_stack.top();
			this->state_stack.pop();
		}
		return;
	}
}

