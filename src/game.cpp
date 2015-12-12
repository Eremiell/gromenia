#include <unordered_map>
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "dawnbringer32.hpp"
#include "button.hpp"

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
	}
	
	const sf::Texture& Game::get_texture(std::string label) {
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
		sf::Text logo("The Legend of Gromenia", this->font, 75);
		logo.setPosition(130, 100);
		logo.setColor(DawnBringer32::White);
		bool logo_up = false;
		float button_size = 2.0f;
		unsigned int button_left_indent_center = (this->window_width - button_size * this->get_texture("button_brown_up").getSize().x) / 2;
		unsigned int button_top_indent = 300;
		Button play("Play", this->get_texture("button_brown_up"), this->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_center, button_top_indent), this->font, button_size);
		button_top_indent += 20 + button_size * this->get_texture("button_brown_up").getSize().y;
		unsigned int button_left_indent_left = (this->window_width - 2 * button_size * this->get_texture("button_brown_up").getSize().x - 50) / 2;
		unsigned int button_left_indent_right = button_left_indent_left + button_size * this->get_texture("button_brown_up").getSize().x + 50;
		Button load("Load", this->get_texture("button_brown_up"), this->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_left, button_top_indent), this->font, button_size);
		Button save("Save", this->get_texture("button_brown_up"), this->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_right, button_top_indent), this->font, button_size);
		button_top_indent += 20 + button_size * this->get_texture("button_brown_up").getSize().y;
		Button exit("Exit", this->get_texture("button_brown_up"), this->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_center, button_top_indent), this->font, button_size);
		while (this->window.isOpen()) {
			sf::Event event;
			while (this->window.pollEvent(event)) {
				switch (event.type) {
					case (sf::Event::Closed):
						this->window.close();
						break;
				}
			}
			if (logo_up) {
				if (logo.getPosition().y < 120) {
					logo.move(0, 2);
				}
				else {
					logo_up = false;
				}
			}
			else {
				if (logo.getPosition().y > 80) {
					logo.move(0, -2);
				}
				else {
					logo_up = true;
				}
			}
			this->window.clear(DawnBringer32::Viking);
			this->window.draw(logo);
			play.draw(this->window);
			load.draw(this->window);
			save.draw(this->window);
			exit.draw(this->window);
			this->window.display();
			
		}
		return;
	}
}

