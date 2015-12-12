#include <SFML/Graphics.hpp>
#include <string>
#include "button.hpp"
#include "dawnbringer32.hpp"

namespace gromenia {
	Button::Button(std::string label, const sf::Texture &up, const sf::Texture &down, sf::Vector2f pos, const sf::Font &font, float button_size = 2.0f) : button_size(button_size), up(up), down(down), pos(pos), label(label, font, this->font_size) {
		this->sprite.setTexture(this->up);
		this->sprite.setScale(this->button_size, this->button_size);
		this->sprite.setPosition(pos);
		this->label.setPosition(pos.x + 115, pos.y + 20);
		this->label.setColor(DawnBringer32::White);
	}
	
	void Button::draw(sf::RenderWindow &window) {
		window.draw(this->sprite);
		window.draw(this->label);
		return;
	}
	
	void Button::go_down() {
		this->sprite.setTexture(this->down);
		this->label.setColor(DawnBringer32::GoldenFizz);
		return;
	}
	
	void Button::go_up() {
		this->sprite.setTexture(this->up);
		this->label.setColor(DawnBringer32::White);
		return;
	}
}

