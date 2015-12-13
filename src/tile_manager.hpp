#ifndef TILE_MANAGER_HPP
#define TILE_MANAGER_HPP

#include <unordered_map>
#include <string>
#include <tinyxml2.h>
#include "tile.hpp"
#include "sheet.hpp"
#include "game.hpp"

namespace gromenia {
	class Game;
	
	class TileManager {
		public:
			TileManager(Game *game);
			const Sheet& get_sheet(std::string);
			void load_sheet(std::string name, std::string filename, Collidable collidable);
		protected:
			
		private:
			std::unordered_map<std::string, Sheet> sheet_atlas;
			Game *game;
	};
}

#endif
