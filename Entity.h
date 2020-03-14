#pragma once
#include "Vector2D.h"
#include "SDL_image.h"
#include<iostream>

using std::cout;
using std::endl;
class Entity {
public:
	
	static const int newSize=64;
	virtual void update() {/*cout<<"entity"<<endl;*/}
	virtual void draw(SDL_Renderer* renderer) {}
	virtual Vector2D getGlobalPos() {return Vector2D();}
	virtual void setGlobalPos(Vector2D newPos) {}
	virtual void setPos(Vector2D newPos) {}
	virtual Vector2D getPos() { return Vector2D(); }
	virtual void dialouge(bool reset) {}

};