#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game_state_main_menu.hpp"
#include "game_state.hpp"
#include "dawnbringer32.hpp"
#include "button.hpp"
#include "game.hpp"

namespace gromenia {
	void GameStateMainMenu::draw() {
		this->game->window.clear(DawnBringer32::Viking);
		this->game->window.draw(logo);
		play.draw(this->game->window);
		load.draw(this->game->window);
		save.draw(this->game->window);
		exit.draw(this->game->window);
		this->game->window.display();
		return;
	}
	
	void GameStateMainMenu::parse_events() {
		sf::Event event;
		while (this->game->window.pollEvent(event)) {
			switch (event.type) {
				case (sf::Event::Closed):
					this->game->window.close();
					break;
			}
		}
		if (this->logo_up) {
			if (logo.getPosition().y < 120) {
				logo.move(0, 2);
			}
			else {
				this->logo_up = false;
			}
		}
		else {
			if (logo.getPosition().y > 80) {
				logo.move(0, -2);
			}
			else {
				this->logo_up = true;
			}
		}
		return;
	}
	
	void GameStateMainMenu::update() {
		return;
	}
	
	GameStateMainMenu::GameStateMainMenu(Game *game, sf::Font *font) : GameState(game, font), logo("The Legend of Gromenia", *this->font, 75) {
		logo.setPosition(130, 100);
		logo.setColor(DawnBringer32::White);
		unsigned int button_left_indent_center = (this->game->window_width - this->button_size * this->game->get_texture("button_brown_up").getSize().x) / 2;
		unsigned int button_top_indent = 300;
		play.load("Play", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_center, button_top_indent), *this->font);
		button_top_indent += 20 + this->button_size * this->game->get_texture("button_brown_up").getSize().y;
		unsigned int button_left_indent_left = (this->game->window_width - 2 * this->button_size * this->game->get_texture("button_brown_up").getSize().x - 50) / 2;
		unsigned int button_left_indent_right = button_left_indent_left + this->button_size * this->game->get_texture("button_brown_up").getSize().x + 50;
		load.load("Load", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_left, button_top_indent), *this->font);
		save.load("Save", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_right, button_top_indent), *this->font);
		button_top_indent += 20 + this->button_size * this->game->get_texture("button_brown_up").getSize().y;
		exit.load("Exit", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_center, button_top_indent), *this->font);
	}
}
