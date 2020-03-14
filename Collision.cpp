#include "Collision.h"
#include <math.h>
#include <iostream>
#include <algorithm> 
#include "GameSize.h"
using std::cout;
using std::endl;
using std::max;
Collision::Collision() {
}

bool Collision::isColiding(Entity& e1, Entity& e2) {
	return max(fabs(e1.getGlobalPos().x - e2.getGlobalPos().x) , fabs(e1.getGlobalPos().y - e2.getGlobalPos().y)) < GameSize::TILE;
}

void Collision::resolveCollision(Entity& e1, Entity& e2) {
	float xDiff = (e1.getGlobalPos().x - e2.getGlobalPos().x);
	float yDiff = e1.getGlobalPos().y - e2.getGlobalPos().y;
	
	if (abs(xDiff) >= abs(yDiff)) {
		if (xDiff >= 0) {
			e1.setGlobalPos(e1.getGlobalPos() + Vector2D(GameSize::TILE - xDiff, 0));
		} else {
			e1.setGlobalPos(e1.getGlobalPos() + Vector2D(-GameSize::TILE - xDiff, 0));
		}

	} else {
		if (yDiff >= 0) {
			e1.setGlobalPos(e1.getGlobalPos() + Vector2D(0, GameSize::TILE - yDiff));
		} else {
			e1.setGlobalPos(e1.getGlobalPos() + Vector2D(0, -GameSize::TILE - yDiff));
		}
		
	}
}


