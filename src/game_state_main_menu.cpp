#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game_state_main_menu.hpp"
#include "game_state_island_view.hpp"
#include "game_state.hpp"
#include "dawnbringer32.hpp"
#include "button.hpp"
#include "game.hpp"

namespace gromenia {
	void GameStateMainMenu::draw() {
		this->game->window.clear(DawnBringer32::Viking);
		this->game->window.draw(logo);
		this->play.draw(this->game->window);
		this->load.draw(this->game->window);
		this->save.draw(this->game->window);
		this->exit.draw(this->game->window);
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
				case sf::Event::KeyPressed:
					switch (event.key.code) {
						case sf::Keyboard::Left:
						case sf::Keyboard::A:
							if (this->button_selected != nullptr) {
								this->button_selected->go_up();
							}
							this->load.go_down();
							this->button_selected = &this->load;
							break;
						case sf::Keyboard::Right:
						case sf::Keyboard::D:
							if (this->button_selected != nullptr) {
								this->button_selected->go_up();
							}
							this->save.go_down();
							this->button_selected = &this->save;
							break;
						case sf::Keyboard::Up:
						case sf::Keyboard::W:
							if (this->button_selected != nullptr) {
								this->button_selected->go_up();
							}
							this->play.go_down();
							this->button_selected = &this->play;
							break;
						case sf::Keyboard::Down:
						case sf::Keyboard::S:
							if (this->button_selected != nullptr) {
								this->button_selected->go_up();
							}
							this->exit.go_down();
							this->button_selected = &this->exit;
							break;
						case sf::Keyboard::Space:
						case sf::Keyboard::Return:
							if (this->button_selected == &this->exit) {
								this->game->window.close();
							}
							else if (this->button_selected == &this->play) {
								this->game->set_state(new GameStateIslandView(this->game, this->font));
							}
							break;
					}
					break;
			}
		}
		if (this->logo_up) {
			if (this->logo.getPosition().y < 120) {
				this->logo.move(0, 2);
			}
			else {
				this->logo_up = false;
			}
		}
		else {
			if (this->logo.getPosition().y > 80) {
				this->logo.move(0, -2);
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
		this->logo.setPosition(130, 100);
		this->logo.setColor(DawnBringer32::White);
		unsigned int button_left_indent_center = (this->game->window_width - this->button_size * this->game->get_texture("button_brown_up").getSize().x) / 2;
		unsigned int button_top_indent = 300;
		this->play.load("Play", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_center, button_top_indent), *this->font);
		button_top_indent += 20 + this->button_size * this->game->get_texture("button_brown_up").getSize().y;
		unsigned int button_left_indent_left = (this->game->window_width - 2 * this->button_size * this->game->get_texture("button_brown_up").getSize().x - 50) / 2;
		unsigned int button_left_indent_right = button_left_indent_left + this->button_size * this->game->get_texture("button_brown_up").getSize().x + 50;
		this->load.load("Load", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_left, button_top_indent), *this->font);
		this->save.load("Save", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_right, button_top_indent), *this->font);
		button_top_indent += 20 + this->button_size * this->game->get_texture("button_brown_up").getSize().y;
		this->exit.load("Exit", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_center, button_top_indent), *this->font);
	}
}
