#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

namespace gromenia {
	class Tile {
		public:
			Tile(const sf::Texture &texture, sf::IntRect bounds);
			const sf::Sprite& get_sprite();
		protected:
			
		private:
			sf::Sprite sprite;
	};
}

#endif
