#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "DemoOverworldScene.h"



class Game {
private:
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect srcRect, destRect;
	SDL_Event event;
	DemoOverworldScene demoOvScn;

	
	
public:
	Game(const char* title, int x, int y, int width, int height, bool fullscreen);
	~Game();
	void handleEvents();
	void update();
	void draw();
	bool isRunning();
	int fc;
};

