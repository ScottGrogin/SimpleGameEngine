#pragma once
#include "Vector2D.h"
#include <SDL_image.h>
#include "TileTypes.h"
#include "Entity.h"

class Tile :public Entity {
private:
	TileTypes::TileType type;

	SDL_Rect srcRect, destRect;
	SDL_Texture* texture;




public:
	Vector2D globalPos, pos;
	static const int size = 16;
	static const int newSize = 64;
	bool canWalkOn;
	Tile();
	Tile(TileTypes::TileType type, Vector2D globalPos, SDL_Renderer* renderer);
	Vector2D getGlobalPos();
	void setGlobalPos(Vector2D newPos);
	Vector2D getPos();
	void update();
	void draw(SDL_Renderer* renderer);
	void destroy();

};

