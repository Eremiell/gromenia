#ifndef GAME_STATE_MAIN_MENU_HPP
#define GAME_STATE_MAIN_MENU_HPP

#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "button.hpp"
#include "game.hpp"

namespace gromenia {
	class Game;
	
	class GameStateMainMenu : public GameState {
		public:
			virtual void draw();
			virtual void parse_events();
			virtual void update();
			GameStateMainMenu(Game *game, sf::Font *font);
		protected:
			
		private:
			sf::Text logo;
			bool logo_up = false;
			float button_size = 2.0f;
			Button play;
			Button load;
			Button save;
			Button exit;
			Button *button_selected = nullptr;
	};
}

#endif
