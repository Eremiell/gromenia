#include <tinyxml2.h>
#include <string>
#include <utility>
#include <unordered_map>
#include "tile_manager.hpp"
#include "game.hpp"
#include "sheet.hpp"

namespace gromenia {
	TileManager::TileManager(Game *game) : game(game) {
		this->load_sheet("tileset", "protomedia/tilesheet/tileset_forTiled.tsx", Collidable::COLLIDABLE);
	}
	
	const Sheet& TileManager::get_sheet(std::string name) {
		return this->sheet_atlas.at(name);
	}
	
	void TileManager::load_sheet(std::string name, std::string filename, Collidable collidable) {
		tinyxml2::XMLDocument sheet(true, tinyxml2::Whitespace::COLLAPSE_WHITESPACE);
		sheet.LoadFile(filename.c_str());
		tinyxml2::XMLElement *root = sheet.RootElement();
		std::string source = root->FirstChildElement("image")->Attribute("source");
		this->game->load_texture(name, filename.substr(0, filename.rfind("/") + 1) + source);
		this->sheet_atlas.insert(std::pair<std::string, Sheet>(name, Sheet(this->game->get_texture(name), collidable, std::stoul(root->Attribute("tilewidth")), std::stoul(root->Attribute("tileheight")), std::stoul(root->Attribute("spacing")), std::stoul(root->Attribute("margin")))));
		return;
	}
}
