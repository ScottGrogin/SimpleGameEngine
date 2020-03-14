#pragma once
#include "Vector2D.h"
#include <SDL_image.h>
#include"Entity.h"
#include<stack>
#include "Directions.h"

using std::stack;
class Player: public Entity {

private:
	SDL_Rect srcRect, destRect;
	SDL_Texture* playerTex;
	SDL_RendererFlip flipType;
	int animationFrame;
	int speed;
	bool up, down, left, right;
	stack<bool*> inputs;
	
	void movement();
	
public:
	bool z;
	bool lastFrameZ;
	Directions::Direction facing;
	static const int size = 24;
	static const int newSize = 64;
	Player();
	void handleEvents(SDL_Event& event);
	
	Vector2D pos,globalPos;
	void init(SDL_Renderer* renderer);
	Vector2D getGlobalPos();
	Vector2D getPos();
	void setGlobalPos(Vector2D newPos);

	void update();
	void draw(SDL_Renderer* renderer);
	void destroy();
};

