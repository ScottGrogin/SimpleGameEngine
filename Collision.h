#pragma once
#include <SDL_rect.h>
#include "Entity.h"
class Collision {
public:
	Collision();
	bool isColiding(Entity& e1, Entity& e2);
	void resolveCollision(Entity& e1, Entity& e2);
	
};

