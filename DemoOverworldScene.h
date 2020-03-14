#pragma once
#include "Map.h"
#include "Player.h"
#include "Camera.h"
#include "Collision.h"
#include "DialougeTrigger.h"
class DemoOverworldScene {
private:
	Player player;
	Map map;
	Camera cam;
	Collision col;
	DialougeTrigger dTrig;
	Entity* activeEntity;
	bool isDialougeHappening;
public:
	DemoOverworldScene();
	void init(SDL_Renderer* renderer);
	void update();
	void playerCollisionCheck();
	void dialougeCheck();
	void draw(SDL_Renderer* renderer);
	void destroy();
	void handleEvents(SDL_Event event);
};

