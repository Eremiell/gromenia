#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <stack>
#include "game_state.hpp"

namespace gromenia {
	class GameState;
	
	class Game {
		public:
			const static unsigned int window_width = 1360;
			const static unsigned int window_height = 768;
			Game();
			~Game();
			sf::Texture& get_texture(std::string label);
			void load_texture(std::string label, std::string filename);
			void game_loop();
			GameState* get_state();
			void set_state(GameState *state);
			void pop_state();
			sf::RenderWindow window;
			//void switch_state(GameState *state);
		protected:
			
		private:
			std::unordered_map<std::string, sf::Texture> texture_atlas;
			sf::Font font;
			std::stack<GameState*> state_stack;
	};
}

#endif
