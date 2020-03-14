#include "SDL.h"
#include "Game.h"
#include <iostream>
#include "Bee.h"
using std::cout;
using std::endl;
int main(int argc, char* argv[]) {

	Game game("The 7 Masks", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	const int FPS = 120;
	const int delay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	Entity *e = &Bee(Vector2D(0,0), NULL);
	e->update();
	while (game.isRunning()) {
		frameStart = SDL_GetTicks();
		game.handleEvents();
		game.update();
		game.draw();
		frameTime = SDL_GetTicks() - frameStart;
		if (delay > frameTime) {
			SDL_Delay(delay - frameTime);
		}
	}
	
	
	return 0;
}