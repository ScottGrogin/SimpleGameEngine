#include "DemoOverworldScene.h"
#include <iostream>
using std::cout;
using std::endl;
DemoOverworldScene::DemoOverworldScene() {
}

void DemoOverworldScene::init(SDL_Renderer* renderer){
	activeEntity = nullptr;
	isDialougeHappening = false;
	map.loadMapBg(MapTypes::Test, renderer);
	player.init(renderer);
}

void DemoOverworldScene::update() {
	if (!isDialougeHappening) {
		cam.track(player, map);
		map.update();
		player.update();
		playerCollisionCheck();
	}
	
	
}

void DemoOverworldScene::draw(SDL_Renderer* renderer) {
	map.draw(renderer);
	player.draw(renderer);
	map.mgDraw(renderer);
	map.fgDraw(renderer);
	dialougeCheck();
}

void DemoOverworldScene::destroy() {
	map.destroy();
}

void DemoOverworldScene::handleEvents(SDL_Event event) {
	player.handleEvents(event);
}




void DemoOverworldScene::playerCollisionCheck() {
	if (player.globalPos.x < 0) {
		player.globalPos.x = 0;
	}
	if (player.globalPos.y < 0) {
		player.globalPos.y = 0;
	}
	if (player.globalPos.x + Player::newSize > map.width) {
		player.globalPos.x = map.width - Player::newSize;
	}
	if (player.globalPos.y + Player::newSize > map.height) {
		player.globalPos.y = map.height - Player::newSize;
	}
	for (Tile& t : map.tiles) {
		if (!t.canWalkOn) {
			if (col.isColiding(player, t)) {
				col.resolveCollision(player, t);
			}
		}

	}
	for (Tile& t : map.fgTiles) {
		if (!t.canWalkOn) {
			if (col.isColiding(player, t)) {
				col.resolveCollision(player, t);
			}
		}

	}
	for (Entity* e : map.mgNonPlayerEntities) {
		if (col.isColiding(player, *e)) {
			col.resolveCollision(player, *e);
		}
	}
}

void DemoOverworldScene::dialougeCheck() {
	if (activeEntity == nullptr) {
		for (Entity* e : map.mgNonPlayerEntities) {
			if (dTrig.isDialougeTriggered(player, *e)) {
				activeEntity = e;
				isDialougeHappening = true;
				break;
			}
		}
	} else {

		activeEntity->dialouge(false);
		if (player.z && !player.lastFrameZ) {
			activeEntity->dialouge(true);
			activeEntity = nullptr;
			isDialougeHappening = false;
		}
	}

}



