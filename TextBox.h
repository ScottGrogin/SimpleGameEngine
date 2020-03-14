#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>
#include"Vector2D.h"
#include<string>
using std::string;
class TextBox {
private:
	TTF_Font* badGuy;
	SDL_Rect srcRect, destRect, textRect;
	SDL_Texture* fontTexture;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int counter,timer;
	const int width = 112, height = 32;
public:
	TextBox();
	
	void init(SDL_Renderer* renderer);
	void displayBox( string text, Vector2D screenLocation, Vector2D widthAndHeight, int textSpeed, bool instantlyDisplayText,bool resetCounter);
};

