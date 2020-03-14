#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char* fileName, SDL_Renderer* renderer) {
	SDL_Surface* temp = IMG_Load(fileName);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
	return texture;
}
