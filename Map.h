#pragma once
#include "Tile.h"
#include<vector>
#include "MapTypes.h"
using std::vector;
class Map {
private:

public:
	int width, height;
	vector<Tile> tiles;
	vector<Tile> fgTiles;
	vector<Entity*> mgNonPlayerEntities;
	void destroy();
	void loadMapBg(MapTypes::MapType type,SDL_Renderer* renderer);
	void update();
	void draw(SDL_Renderer* renderer);
	void mgDraw(SDL_Renderer* renderer);
	void fgDraw(SDL_Renderer* renderer);
	Uint32 getpixel(SDL_Surface* surface, int x, int y);
	Map();
};

