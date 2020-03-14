#pragma once
#include "SDL_image.h"
class TextureLoader {
public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};

