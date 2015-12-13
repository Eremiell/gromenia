#ifndef GAME_STATE_ISLAND_VIEW_HPP
#define GAME_STATE_ISLAND_VIEW_HPP

#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "button.hpp"
#include "game.hpp"

namespace gromenia {
	class Game;
	
	class GameStateIslandView : public GameState {
		public:
			virtual void draw();
			virtual void parse_events();
			virtual void update();
			GameStateIslandView(Game *game, sf::Font *font);
		protected:
			
		private:
			sf::Sprite island;
			Button back;
			Button *button_selected = nullptr;
			Area area_selected;
			sf::Sprite arrow;
			sf::Text area_name;
			void area_right();
			void area_left();
			void set_area(Area area);
			//sf::Text logo;
			bool arrow_up = false;
			unsigned int arrow_mid;
			float button_size = 2.0f;
			//Button play;
			//Button load;
			//Button save;
			//Button exit;
	};
}

#endif
