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

	//get the resolution and create a SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y=VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x,resolution.y),"Zombie Arena",Style::Fullscreen);

	//create an SFML view for the main action
	View mainView(FloatRect(0,0,resolution.x,resolution.y));

	//a clock for timing everything
	Clock clock;
	Time gameTimeTotal;

	//where is the mouse in relation to the world coordinates
	Vector2f mouseWorldPosition;
	//where is the mouse in relation to the screen coordinates
	Vector2i mouseScreenPosition;


	Player player;

	IntRect arena;

	while (window.isOpen())
	{

		//handling the user inputs

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type==Event::KeyPressed)
			{

				if (event.key.code==Keyboard::Return)
				{
					switch (state)
					{
					case State::PAUSED://restart while paused
						state=State::PLAYING;
						clock.restart();//reset the clock so that there will be no frame jump, all the objects would have updated their locations as if the frame just took a very long time

						break;

					case State::GAME_OVER:
						state=State::LEVEING_UP;
						break;
					case State::PLAYING://pause a game while playing
						state=State::PAUSED;
						break;

					}
				}

				if (state==State::PLAYING)
				{
					if (Keyboard::isKeyPressed(Keyboard::W))
					{
						player.moveUp();

					}else
					{
						player.stopUp();
					}

					if (Keyboard::isKeyPressed(Keyboard::W))
					{
						player.moveLeft();

					}else
					{
						player.stopLeft();
					}

					if (Keyboard::isKeyPressed(Keyboard::D))
					{
						player.moveRight();

					}else
					{
						player.stopRight();
					}

					if (Keyboard::isKeyPressed(Keyboard::S))
					{
						player.moveDown();

					}else
					{
						player.stopDown();
					}

				}// end WASD controls

				if (event.key.code==Keyboard::Escape)
				{
					window.close();

				}

				if (state==State::LEVEING_UP)
				{

					if (Keyboard::isKeyPressed(Keyboard::Num1))
					{
						state=State::PLAYING;

					}

					if (Keyboard::isKeyPressed(Keyboard::Num2))
					{
						state=State::PLAYING;

					}

					if (Keyboard::isKeyPressed(Keyboard::Num3))
					{
						state=State::PLAYING;

					}
					if (Keyboard::isKeyPressed(Keyboard::Num4))
					{
						state=State::PLAYING;

					}
					if (Keyboard::isKeyPressed(Keyboard::Num5))
					{
						state=State::PLAYING;

					}if (Keyboard::isKeyPressed(Keyboard::Num6))
					{
						state=State::PLAYING;

					}


					if (state==State::PLAYING)
					{

						arena.width=500;
						arena.height=500;
						arena.left=0;
						arena.top = 0;

						int tileSize = 50;
						player.spawn(arena,resolution,tileSize);
						clock.restart();

					}


				}//end leveling up

			

				

			}//end of event polling



		}
			//updating the frame 
				if (state==State::PLAYING)
				{
					//get time delta
					Time dt = clock.restart();
					gameTimeTotal+=dt;

					float dtAsSeconds = dt.asSeconds();

					mouseScreenPosition = Mouse::getPosition();
					//mapping screen mouse position to world position
					mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(),mainView);
					//get the player's current position
					Vector2f playerPosition(player.getCenter());
					//make the view center around the player
					mainView.setCenter(playerPosition);
				}//end updating the scene

				//drawing the scene
				if (state==State::PLAYING)
				{
					window.clear();

					//se the main view to be displayed in the window 
					//draw everything  related to it
					window.setView(mainView);

					//draw the player
					window.draw(player.getSprite());

				}

				window.display();

	};

	return 0;

}

