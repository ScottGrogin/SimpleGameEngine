#include "Player.h"
#include "TextureLoader.h"
#include <iostream>
#include "GameSize.h"

using std::cout;
using std::endl;





Player::Player() {
}





void Player::init(SDL_Renderer* renderer) {
	playerTex = TextureLoader::LoadTexture("assets/mobs/fox-run.png", renderer);
	facing = Directions::Right;
	animationFrame = 0;
	speed = 2;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = size;
	srcRect.h = size;




	pos.x = (GameSize::WIDTH - newSize) /2;
	pos.y = (GameSize::HEIGHT - newSize)/2;
	

	globalPos.x = (GameSize::WIDTH - newSize) / 2;;
	globalPos.y = (GameSize::HEIGHT - newSize) / 2;;

	destRect.x = pos.x;
	destRect.y = pos.y;
	destRect.w = newSize;
	destRect.h = newSize;

	up = false;
	down = false;
	left = false;
	right = false;
	z = false;
	lastFrameZ = z;
	flipType = SDL_FLIP_NONE;
	cout << "Created Player " << endl;
}

Vector2D Player::getGlobalPos() {
	return globalPos;
}

Vector2D Player::getPos() {
	return pos;
}

void Player::setGlobalPos(Vector2D newPos) {
	globalPos = newPos;
}



void Player::update() {

	movement();
	
	while (!inputs.empty() && !(*inputs.top())) {
		inputs.pop();
	}


}

void Player::handleEvents(SDL_Event& event) {
	lastFrameZ = z;
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT) {
			left = true;
			inputs.push(&left);

			
		}
		if (event.key.keysym.sym == SDLK_RIGHT) {
			right = true;
			inputs.push(&right);
			

		}
		if (event.key.keysym.sym == SDLK_UP) {
			up = true;
			inputs.push(&up);
		}

		if (event.key.keysym.sym == SDLK_DOWN) {
			down = true;
			inputs.push(&down);
		
		}

		if (event.key.keysym.sym == SDLK_z) {
			z = true;
		}
	}
	if (event.type == SDL_KEYUP) {
		if (event.key.keysym.sym == SDLK_RIGHT) {
			right = false;
		}
		if (event.key.keysym.sym == SDLK_LEFT) {
			left = false;
		}
		if (event.key.keysym.sym == SDLK_UP) {
			up = false;
		}
		if (event.key.keysym.sym == SDLK_DOWN) {
			down = false;
		}
		if (event.key.keysym.sym == SDLK_z) {
			z = false;
		}
	}
}


void Player::draw(SDL_Renderer* renderer) {

	SDL_RenderCopyEx(renderer, playerTex, &srcRect, &destRect, 0, NULL, flipType);

}
void Player::movement() {

	if (!inputs.empty()) {
		if (&up == inputs.top() && *inputs.top()) {
			globalPos.y -= speed;
			facing = Directions::Up;
		}
		if (&down == inputs.top() && *inputs.top()) {
			globalPos.y += speed;
			facing = Directions::Down;
		}
		if (&left == inputs.top() && *inputs.top()) {
			globalPos.x -= speed;
			facing = Directions::Left;
		}
		if (&right == inputs.top() && *inputs.top()) {
			globalPos.x += speed;
			facing = Directions::Right;
		}
	}
	if (!(up || down || left || right)) {
		if (srcRect.x != 0)animationFrame++;

	}
	if ((up || down || left || right)) {

		animationFrame++;
	}


	if (srcRect.x >= 24 * 5) {
		srcRect.x = 0;
	}
	if (animationFrame % 10 == 1) {
		srcRect.x += 24;
	}
	if (facing==Directions::Left) {
		flipType = SDL_FLIP_HORIZONTAL;
	}
	if (facing == Directions::Right) {
		flipType = SDL_FLIP_NONE;
	}
}

void Player::destroy() {
	SDL_DestroyTexture(playerTex);
	cout << "destroyed player texture" << endl;
}
