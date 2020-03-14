#include "Tile.h"
#include "TextureLoader.h"
#include <iostream>
using std::cout;
using std::endl;
Tile::Tile() {

}
Tile::Tile(TileTypes::TileType type, Vector2D globalPos, SDL_Renderer* renderer):type(type), globalPos(globalPos),canWalkOn(false){
	switch (type) {
	case TileTypes::Grass:
		texture = TextureLoader::LoadTexture("assets/tiles/generic-rpg-Slice.png", renderer);
		canWalkOn = true;
		break;
	case TileTypes::Water:
		texture = TextureLoader::LoadTexture("assets/tiles/generic-rpg-tile-waterfall01.png", renderer);
		canWalkOn = false;
		break;
	case TileTypes::Void:
		texture = TextureLoader::LoadTexture("assets/tiles/trans.png", renderer);
		canWalkOn = false;
		break;

	case TileTypes::House:
		texture = TextureLoader::LoadTexture("assets/tiles/generic-rpg-tile02.png", renderer);
		canWalkOn = true;
		break;
	default:
		break;
	}
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

void Tile::update() {
	destRect.x = pos.x;
	destRect.y = pos.y;
	//cout << destRect.x << endl;
	//for tile animation
}

void Tile::draw(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
}

void Tile::destroy() {
}

Vector2D Tile::getGlobalPos() {
	return globalPos;
}

void Tile::setGlobalPos(Vector2D newPos) {
	globalPos = newPos;
}

Vector2D Tile::getPos() {
	return pos;
}

