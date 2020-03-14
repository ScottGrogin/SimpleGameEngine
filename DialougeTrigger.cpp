#include "DialougeTrigger.h"
#include <algorithm>
#include "GameSize.h"
using std::max;

float DialougeTrigger::getDistance(Player& player, Entity& entity) {
	return  max(fabs(player.getGlobalPos().x - entity.getGlobalPos().x), fabs(player.getGlobalPos().y - entity.getGlobalPos().y));
}

bool DialougeTrigger::isDialougeTriggered(Player& player, Entity& entity) {
	float xDiff = (player.getGlobalPos().x - entity.getGlobalPos().x);
	float yDiff = player.getGlobalPos().y - entity.getGlobalPos().y;
	//Make sure that the player is close enough and facing the right direction
	bool facingRight = abs(xDiff)>abs(yDiff)&&(xDiff < 0 && player.facing == Directions::Right);
	bool facingLeft = abs(xDiff) > abs(yDiff) && (xDiff > 0 && player.facing == Directions::Left);
	bool facingUp = abs(yDiff) > abs(xDiff) && (yDiff > 0 && player.facing == Directions::Up);
	bool facingDown = abs(yDiff) > abs(xDiff) && (yDiff < 0 && player.facing == Directions::Down);

	
	if (getDistance(player,entity) < GameSize::TILE+1 && player.z && !player.lastFrameZ &&(facingRight ||facingLeft||facingDown||facingUp)) {
		return true;
	}
	return false;
}
