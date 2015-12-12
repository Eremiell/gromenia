#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

namespace gromenia {
	class Game {
		public:
			Game();
			const sf::Texture& get_texture(std::string label);
			void load_texture(std::string label, std::string filename);
			void game_loop();
		protected:
			
		private:
			const static unsigned int window_width = 1360;
			const static unsigned int window_height = 768;
			std::unordered_map<std::string, sf::Texture> texture_atlas;
			sf::RenderWindow window;
			sf::Font font;
	};
}
