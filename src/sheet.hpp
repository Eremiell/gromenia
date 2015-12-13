#ifndef SHEET_HPP
#define SHEET_HPP

#include <SFML/Graphics.hpp>

namespace gromenia {
	enum class Collidable {COLLIDABLE, NONCOLLIDABLE};
	
	class Sheet {
		public:
			Sheet(const sf::Texture &sheet, Collidable collidable, unsigned int tile_width, unsigned int tile_height, unsigned int spacing, unsigned int margin);
			const sf::Texture& get_sheet();
			Collidable get_collidable();
			sf::IntRect get_bounds(unsigned int tile_num);
		protected:
			
		private:
			const sf::Texture &sheet;
			Collidable collidable;
			unsigned int tile_width;
			unsigned int tile_height;
			unsigned int spacing;
			unsigned int margin;
	};
}

#endif
