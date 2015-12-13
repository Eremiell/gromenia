#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "game_state_island_view.hpp"
#include "game_state.hpp"
#include "game.hpp"
#include "dawnbringer32.hpp"
#include "button.hpp"

namespace gromenia {
	void GameStateIslandView::draw() {
		this->game->window.clear(DawnBringer32::Viking);
		this->game->window.draw(this->area_name);
		this->game->window.draw(this->island);
		this->game->window.draw(this->arrow);
		this->back.draw(this->game->window);
		this->game->window.display();
		return;
	}
	
	void GameStateIslandView::parse_events() {
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
							if (this->button_selected == nullptr) {
								this->area_left();
							}
							break;
						case sf::Keyboard::Right:
						case sf::Keyboard::D:
							if (this->button_selected == nullptr) {
								this->area_right();
							}
							break;
						case sf::Keyboard::Up:
						case sf::Keyboard::W:
							if (this->button_selected != nullptr) {
								this->button_selected->go_up();
							}
							this->button_selected = nullptr;
							break;
						case sf::Keyboard::Down:
						case sf::Keyboard::S:
							if (this->button_selected != nullptr) {
								this->button_selected->go_up();
							}
							this->back.go_down();
							this->button_selected = &this->back;
							break;
						case sf::Keyboard::Space:
						case sf::Keyboard::Return:
							if (this->button_selected == &this->back) {
								this->game->pop_state();
							}
							break;
					}
					break;
			}
		}
		if (this->arrow_up) {
			if (this->arrow.getPosition().y < this->arrow_mid + 10) {
				this->arrow.move(0, 2);
			}
			else {
				this->arrow_up = false;
			}
		}
		else {
			if (this->arrow.getPosition().y > this->arrow_mid - 10) {
				this->arrow.move(0, -2);
			}
			else {
				this->arrow_up = true;
			}
		}
		return;
	}
	
	void GameStateIslandView::update() {
		return;
	}
	
	GameStateIslandView::GameStateIslandView(Game *game, sf::Font *font) : GameState(game, font), island(this->game->get_texture("island")), area_selected(Area::FOREST), arrow(this->game->get_texture("arrow")), area_name("Forest", *this->font, 50) {
		unsigned int button_left_indent_center = (this->game->window_width - this->button_size * this->game->get_texture("button_brown_up").getSize().x) / 2;
		unsigned int button_top_indent = 600;
		this->back.load("Back", this->game->get_texture("button_brown_up"), this->game->get_texture("button_brown_down"), sf::Vector2f(button_left_indent_center, button_top_indent), *this->font);
		unsigned int island_left_indent_center = (this->game->window_width - 2.0f * this->game->get_texture("island").getSize().x) / 2;
		this->island.setScale(2.0f, 2.0f);
		this->island.setPosition(island_left_indent_center, 200);
		this->set_area(Area::FOREST);
		this->arrow.setColor(DawnBringer32::TahitiGold);
	}
	
	void GameStateIslandView::area_right() {
		switch (this->area_selected) {
			case Area::FOREST:
				this->set_area(Area::MOUNTAINS);
				break;
			case Area::MOUNTAINS:
				this->set_area(Area::RIVER);
				break;
			case Area::RIVER:
				this->set_area(Area::CITY);
				break;
			case Area::CITY:
				this->set_area(Area::FOREST);
				break;
		}
	}
	
	void GameStateIslandView::area_left() {
		switch (this->area_selected) {
			case Area::FOREST:
				this->set_area(Area::CITY);
				break;
			case Area::MOUNTAINS:
				this->set_area(Area::FOREST);
				break;
			case Area::RIVER:
				this->set_area(Area::MOUNTAINS);
				break;
			case Area::CITY:
				this->set_area(Area::RIVER);
				break;
		}
	}
	
	void GameStateIslandView::set_area(Area area) {
		this->area_selected = area;
		switch (this->area_selected) {
			case Area::FOREST:
				this->area_name.setString("Forest");
				this->area_name.setPosition(580, 100);
				this->arrow.setPosition(464, 160);
				this->arrow_mid = 160;
				break;
			case Area::MOUNTAINS:
				this->area_name.setString("Mountains");
				this->area_name.setPosition(520, 100);
				this->arrow.setPosition(600, 180);
				this->arrow_mid = 180;
				break;
			case Area::RIVER:
				this->area_name.setString("River");
				this->area_name.setPosition(600, 100);
				this->arrow.setPosition(645, 350);
				this->arrow_mid = 350;
				break;
			case Area::CITY:
				this->area_name.setString("City");
				this->area_name.setPosition(610, 100);
				this->arrow.setPosition(810, 250);
				this->arrow_mid = 250;
				break;
		}
	}
}
