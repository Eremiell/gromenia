#include <SFML/Graphics.hpp>
#include "sheet.hpp"

namespace gromenia {
	Sheet::Sheet(const sf::Texture &sheet, Collidable collidable, unsigned int tile_width, unsigned int tile_height, unsigned int spacing, unsigned int margin) : sheet(sheet), collidable(collidable), tile_width(tile_width), tile_height(tile_height), spacing(spacing), margin(margin) {
		
	}
	
	const sf::Texture& Sheet::get_sheet() {
		return this->sheet;
	}
	
	Collidable Sheet::get_collidable() {
		return this->collidable;
	}
	
	sf::IntRect Sheet::get_bounds(unsigned int tile_num) {
		unsigned int row_size = (this->sheet.getSize().x - 2 * this->margin + this->spacing) / (this->tile_width + this->spacing);
		unsigned int row = tile_num / row_size;
		unsigned int column = tile_num % row_size - 1;
		return sf::IntRect(this->margin + column * (this->tile_width + this->spacing), this->margin + row * (this->tile_height + this->spacing), this->tile_width, this->tile_height);
	}
}

