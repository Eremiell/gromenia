#include <SFML/Graphics.hpp>
#include <string>

namespace gromenia {
	class Button {
		public:
			Button(std::string label, const sf::Texture &up, const sf::Texture &down, sf::Vector2f pos, const sf::Font &font, float button_size);
			void draw(sf::RenderWindow &window);
			void go_down();
			void go_up();
		protected:
			
		private:
			const float button_size;
			const static unsigned int font_size = 50;
			//bool is_up = true;
			const sf::Texture &up;
			const sf::Texture &down;
			sf::Vector2i pos;
			sf::Sprite sprite;
			sf::Text label;
	};
}
