#pragma once
#include "Entity.h"
#include <SDL_image.h>
#include"Vector2D.h"
#include"TextBox.h"
class Bee: public Entity {
private:
	SDL_Rect srcRect, destRect;
	SDL_Texture* texture;	
	int animationFrame;
	TextBox textBox;

public:
	static const int size = 32;
	static const int newSize = 64;

	Bee();
	Bee(Vector2D globalPos, SDL_Renderer* renderer);

	Vector2D pos, globalPos;
	Vector2D getGlobalPos();
	Vector2D getPos();
	
	void setGlobalPos(Vector2D newPos);
	void setPos(Vector2D newPos);
	void dialouge(bool reset);
	void update() override;
	void draw(SDL_Renderer* renderer) override;
	void destroy();
	
};


