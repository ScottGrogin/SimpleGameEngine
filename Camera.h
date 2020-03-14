#pragma once
#include "Player.h"
#include "Map.h"
class Camera {
public:
	Camera();
	void track(Player& player, Map& map);
};

