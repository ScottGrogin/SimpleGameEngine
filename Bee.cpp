#include "Bee.h"
#include "TextureLoader.h"
#include <iostream>
#include "GameSize.h"
using std::cout;
using std::endl;
Bee::Bee() {
}

Bee::Bee(Vector2D globalPos, SDL_Renderer* renderer):globalPos(globalPos) {
	texture = TextureLoader::LoadTexture("assets/mobs/boss_bee.png", renderer);
	textBox.init(renderer);
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = size;
	srcRect.h = size;


	pos.x = globalPos.x;
	pos.y = globalPos.y;
	destRect.x = pos.x;
	destRect.y = pos.y;

	destRect.w = newSize;
	destRect.h = newSize;
}



void Bee::update() {
	destRect.x = pos.x;
	destRect.y = pos.y;
}

void Bee::draw(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
}


Vector2D Bee::getGlobalPos() {
	return globalPos;
}

Vector2D Bee::getPos() {
	return pos;
}

void Bee::setGlobalPos(Vector2D newPos) {
	globalPos = newPos;
}
void Bee::setPos(Vector2D newPos) {
	pos = newPos;
}
void Bee::dialouge(bool reset) {

	textBox.displayBox("Buzz Buzz my guy", Vector2D(0, GameSize::HEIGHT -250), Vector2D(GameSize::WIDTH,250), 1, false,reset);
	
}
void Bee::destroy() {
}

