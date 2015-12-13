#include <SFML/Graphics.hpp>
#include "tile.hpp"

namespace gromenia {
	Tile::Tile(const sf::Texture &texture, sf::IntRect bounds) : sprite(texture, bounds) {
		
	}
	
	const sf::Sprite& Tile::get_sprite() {
		return this->sprite;
	}
}
