// hellosfml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"

int main()
{

	enum class State{
		PAUSED,LEVEING_UP,GAME_OVER,PLAYING
	};

	State state = State::PLAYING;
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y=VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x,resolution.y),);




	return 0;
}

