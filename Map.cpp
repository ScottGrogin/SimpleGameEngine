#include "Map.h"
#include <iostream>
#include "Bee.h"

using std::cout;
using std::endl;

void Map::destroy() {
	for (Entity* e : mgNonPlayerEntities) {
		delete e;
	}

}



	void Map::loadMapBg(MapTypes::MapType type, SDL_Renderer* renderer) {
	int i = 0;
	switch (type) {
	case MapTypes::Test:
		//Backgroung
		SDL_Surface* surface = IMG_Load("assets/maps/testMap/testMapBg.png");
		width = surface->w * Tile::newSize;
		height = surface->h * Tile::newSize;
		
		
		for (int y = 0; y < surface->h ; y++) {
			for (int x = 0; x <surface->w; x++) {		
		
				Uint32 color = getpixel(surface, x, y);	
				
				if (color == 65280) {
					
					tiles.emplace_back(Tile(TileTypes::Grass,Vector2D(x*Tile::newSize,y*Tile::newSize),renderer));
				}
				if (color == 16711680) {
					tiles.emplace_back(Tile(TileTypes::Water, Vector2D(x * Tile::newSize, y * Tile::newSize), renderer));
				}
				if (color == 0) {
					tiles.emplace_back(Tile(TileTypes::Void, Vector2D(x * Tile::newSize, y * Tile::newSize), renderer));
				}
			
	
			}
		}
		
		//Foreground
	  surface = IMG_Load("assets/maps/testMap/testMapFg.png");

		for (int y = 0; y < surface->h; y++) {
			for (int x = 0; x < surface->w; x++) {

				Uint32 color = getpixel(surface, x, y);
				//cout << color << endl;
				if (color == 4278255615) {

					fgTiles.emplace_back(Tile(TileTypes::House, Vector2D(x * Tile::newSize, y * Tile::newSize), renderer));
				}

			}
		}
	
		
		surface = IMG_Load("assets/maps/testMap/testMapMg.png");

		for (int y = 0; y < surface->h; y++) {
			for (int x = 0; x < surface->w; x++) {

				Uint32 color = getpixel(surface, x, y);
				//cout << color << endl;
				if (color == 4278190335) {
				
					mgNonPlayerEntities.emplace_back(new Bee(Vector2D(x * Tile::newSize, y * Tile::newSize), renderer));
				}

			}
		}
		SDL_FreeSurface(surface);
		break;
	}
	
	//cout<< ": " << tiles.size() << endl;

}
void Map::update() {
	for (Entity* e : mgNonPlayerEntities) {
		e->update();
	}

	for (Tile& t : fgTiles) {
		t.update();
	}
	for (Tile &t : tiles) {
		t.update();
	}
	
}
void Map::draw(SDL_Renderer* renderer) {
	for (Tile &t : tiles) {
		t.draw(renderer);
	}
}

void Map::mgDraw(SDL_Renderer* renderer) {
	for (Entity* e : mgNonPlayerEntities) {
		e->draw(renderer);
	}
}

void Map::fgDraw(SDL_Renderer* renderer) {
	for (Tile& t : fgTiles) {
		t.draw(renderer);
	}
}
Uint32 Map::getpixel(SDL_Surface* surface, int x, int y) {
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp) {
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16*)p;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32*)p;
		break;

	default:
		return 0;       /* shouldn't happen, but avoids warnings */
	}
}
Map::Map() {
}
