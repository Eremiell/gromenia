#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

namespace gromenia {
	class Button {
		public:
			Button(float button_size = 2.0f);
			Button(std::string label, sf::Texture &up, sf::Texture &down, sf::Vector2f pos, const sf::Font &font, float button_size = 2.0f);
			~Button();
			void draw(sf::RenderWindow &window);
			void go_down();
			void go_up();
			void load(std::string label, sf::Texture &up, sf::Texture &down, sf::Vector2f pos, const sf::Font &font);
		protected:
			
		private:
			const float button_size;
			unsigned int font_size = 50;
			//bool is_up = true;
			sf::Texture *up;
			sf::Texture *down;
			sf::Vector2f pos;
			sf::Sprite sprite;
			sf::Text *label;
	};
}

#endif
