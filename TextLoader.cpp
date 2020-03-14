#include "TextLoader.h"


 SDL_Texture* TextLoader::LoadText(TTF_Font* font,const char* text,SDL_Color color ,SDL_Renderer* renderer) {
	SDL_Surface* temp = TTF_RenderText_Solid(font,text,color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
	return texture;
}
