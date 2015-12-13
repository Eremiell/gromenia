#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"

namespace gromenia {
	class Game;
	
	class GameState {
		public:
			virtual void draw() = 0;
			virtual void parse_events() = 0;
			virtual void update() = 0;
			GameState(Game *game, sf::Font *font);
			Game *game;
			sf::Font *font;
		protected:
			//sf::RenderWindow *window;
		private:
			
	};
}

#endif
