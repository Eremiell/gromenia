#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include "button.hpp"
#include "dawnbringer32.hpp"

namespace gromenia {
	Button::Button(float button_size) : button_size(button_size) {
		this->label = new sf::Text();
	}
	
	Button::Button(std::string label, sf::Texture &up, sf::Texture &down, sf::Vector2f pos, const sf::Font &font, float button_size) : button_size(button_size), up(&up), down(&down), pos(pos) {
		this->sprite.setTexture(*this->up);
		this->sprite.setScale(this->button_size, this->button_size);
		this->sprite.setPosition(this->pos);
		this->label = new sf::Text(label, font, this->font_size);
		this->label->setPosition(this->pos.x + 115, this->pos.y + 20);
		this->label->setColor(DawnBringer32::White);
	}
	
	Button::~Button() {
		if (this->label != nullptr) {
			delete this->label;
		}
	}
	
	void Button::draw(sf::RenderWindow &window) {
		window.draw(this->sprite);
		window.draw(*this->label);
		return;
	}
	
	void Button::go_down() {
		this->sprite.setTexture(*this->down);
		this->label->setColor(DawnBringer32::GoldenFizz);
		return;
	}
	
	void Button::go_up() {
		this->sprite.setTexture(*this->up);
		this->label->setColor(DawnBringer32::White);
		return;
	}
	
	void Button::load(std::string label, sf::Texture &up, sf::Texture &down, sf::Vector2f pos, const sf::Font &font) {
		this->up = &up;
		this->down = &down;
		this->pos = pos;
		if (this->label != nullptr) {
			delete this->label;
		}
		this->label = new sf::Text(label, font, this->font_size);
		this->sprite.setTexture(*this->up);
		this->sprite.setScale(this->button_size, this->button_size);
		this->sprite.setPosition(this->pos);
		this->label->setPosition(this->pos.x + 115, this->pos.y + 20);
		this->label->setColor(DawnBringer32::White);
	}
}

