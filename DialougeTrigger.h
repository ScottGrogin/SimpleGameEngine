#pragma once
#include "Player.h"
#include "Entity.h"
class DialougeTrigger {
private:
	float getDistance(Player& player, Entity& entity);
public:
	bool isDialougeTriggered(Player& player, Entity& entity);
};

