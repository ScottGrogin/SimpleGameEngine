#pragma once
#include "SDL_image.h"
#include <SDL_ttf.h>
class TextLoader {
public:
	static SDL_Texture* LoadText(TTF_Font* font, const char* text, SDL_Color color, SDL_Renderer* renderer);
};

