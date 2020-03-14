#include "Camera.h"
#include <iostream>
#include "Entity.h"

using std::cout;
using std::endl;
Camera::Camera() {
}
void Camera::track(Player& player, Map& map) {
	for (Tile& t : map.tiles) {
		t.pos.x = t.globalPos.x + player.pos.x- player.globalPos.x;
		t.pos.y = t.globalPos.y + player.pos.y  - player.globalPos.y;
	}
	for (Tile& t : map.fgTiles) {
		t.pos.x = t.globalPos.x + player.pos.x - player.globalPos.x;
		t.pos.y = t.globalPos.y + player.pos.y - player.globalPos.y;
	}

	for (Entity* e : map.mgNonPlayerEntities) {
		e->setPos( Vector2D(e->getGlobalPos().x + player.pos.x - player.globalPos.x,e->getGlobalPos().y + player.pos.y - player.globalPos.y));
	}

}
