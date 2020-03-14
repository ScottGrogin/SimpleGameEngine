#include "TextBox.h"
#include "TextureLoader.h"
#include "TextLoader.h"
#include <iostream>
using std::cout;
using std::endl;
TextBox::TextBox() {
	
}



void TextBox::init(SDL_Renderer* renderer) {
	
	this->renderer = renderer;
	texture = TextureLoader::LoadTexture("assets/UI/generic-rpg-ui-text-box.png", renderer);
	badGuy = TTF_OpenFont("assets/fonts/pixelpoiiz.ttf",24);
	
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;
	counter = 0;
	timer = 0;

}
//The higher the number for textSpeed, the slower the text will go.
void TextBox::displayBox(string text, Vector2D screenLocation, Vector2D widthAndHeight, int textSpeed, bool instantlyDisplayText,bool resetCounter) {

	SDL_Color color = { 0,0,0 };
	if (instantlyDisplayText) {
		fontTexture = TextLoader::LoadText(badGuy, text.c_str(), color, renderer);
	} else {
		if (counter <= text.length()) {

			
			if (timer % textSpeed == 0) {
				counter++;
				
			}
			if (counter > text.length() + 1) {
				counter = text.length() + 1;
			}
			fontTexture = TextLoader::LoadText(badGuy, text.substr(0, counter).c_str(), color, renderer);
		}
	}
	
	destRect.x = screenLocation.x;
	destRect.y = screenLocation.y;
	destRect.w = widthAndHeight.x;
	destRect.h = widthAndHeight.y;
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
	textRect.w = texW;
	textRect.h = texH;  
	textRect.x = screenLocation.x + 20;
	textRect.y = screenLocation.y + texH;
	

	
	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopy(renderer, fontTexture, NULL, &textRect);
	
	if (resetCounter) { counter = 0; }
	timer++;
}
