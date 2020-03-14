#include "Game.h"
#include <iostream>
#include "TextureLoader.h"
#include <SDL_ttf.h>

using std::cout;
using std::endl;



Game::Game(const char* title, int x, int y, int width, int height, bool fullscreen) :running(true), window(nullptr), renderer(nullptr){
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SDL Initalized correctly" << endl;
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			cout << "Window Created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			cout << "Renderer Created" << endl;
		}
	} else {
		running = false;
	}
	TTF_Init();

	demoOvScn.init(renderer);
}

Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	demoOvScn.destroy();
	SDL_Quit();
	cout << "Cleaned" << endl;
}

void Game::update() {
	demoOvScn.update();

}
	

void Game::draw() {
	SDL_RenderClear(renderer);
	//Draw here
	demoOvScn.draw(renderer);
	SDL_RenderPresent(renderer);
}

bool Game::isRunning() {
	return running;
}

void Game::handleEvents() {
	SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)running = false;
	
		demoOvScn.handleEvents(event);
	
}
