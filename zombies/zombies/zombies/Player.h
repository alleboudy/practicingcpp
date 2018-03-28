#include "stdafx.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class Player{

private:
	static const int START_SPEED = 200;
	static const int START_HEALTH = 100;

	//location of the player
	Vector2f m_position;

	Sprite m_sprite;

	Texture m_texture;

	Vector2f m_resolution;

	//size of the arena

	IntRect m_arena;

	//size of each tile of the arena
	int m_tileSize;

	//which direction is the player moving?
	bool m_upPressed;
	bool m_downPressed;
	bool m_rightPressed;
	bool m_leftPressed;

	//how much health left
	int m_health;

	//max health the player can have
	int m_maxHealth;

	//when the player was last hit
	Time m_lastHit;

	//speed in pixels per second
	float m_speed;



public:
	Player();

	void spawn(IntRect arena, Vector2f resolution, int tileSize);
	void resetPlayerStats();
	//hadle the player getting hit by a zombie
	bool hit(Time timeHit);

	//when was the player last hit?

	Time getLastHitTime();

	FloatRect getPosition();

	//get the center of the player
	Vector2f getCenter();

	//which angle is the player facing
	float getRotation();

	Sprite getSprite();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//stop the player movement in a specific direction

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();


	//shall be called each frame
	void update(float elapsedTime, Vector2i mousePosition);

	//upgrade player speed
	void upgradeSpeed();

	void upgradeHealth();

	void increaseHealthLevel(int amount);

	int getHealth();





};