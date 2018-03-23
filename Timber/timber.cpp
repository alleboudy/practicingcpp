// hellosfml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	//Create a video mode object
	VideoMode vm(1920,1080);

	//Create and open a window for the game
	RenderWindow window(vm,"Timberyastaaa:D",Style::Fullscreen);
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");

	Sprite spriteBackground ;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0,0);

	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setPosition(810,0);
	spriteTree.setTexture(textureTree);
	bool beeActive=false;
	float beeSpeed = 0.0f;

	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(700,700);
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");

	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	spriteCloud1.setPosition(0,0);
	spriteCloud2.setPosition(0,300);
	spriteCloud3.setPosition(0,450);

	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;


	Clock clock;


	while (window.isOpen())
	{

		/*
		Handle player inputs here
		*/

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();

		}


		/*
		update the scene
		*/
		Time dt =clock.restart();
		if (!beeActive)
		{
			srand((int)time(0)*10);
			beeSpeed = (rand()%200)+200;

			srand((int)time(0)*10);
			float height =(rand()%500)+500;
			spriteBee.setPosition(2000,height);
			beeActive=true;
		}else
		{
			spriteBee.setPosition(

				spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()),
				spriteBee.getPosition().y);

			if (spriteBee.getPosition().x<-100)
			{
				beeActive=false;

			}
		}

		if (!cloud1Active)
		{
			srand((int)time(0)*10);
			cloud1Speed = (rand()%200);
			srand((int)time(0)*10);
			float height = (rand()%150)-150;
			spriteCloud1.setPosition(-200,height);
			cloud1Active = true;

		}
		else
		{
			spriteCloud1.setPosition(

				spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()),
				spriteCloud1.getPosition().y);

			if (spriteCloud1.getPosition().x>1920)
			{
				cloud1Active=false;

			}
		}




		if (!cloud2Active)
		{
			srand((int)time(0)*20);
			cloud2Speed = (rand()%200);
			srand((int)time(0)*20);
			float height = (rand()%300)-150;
			spriteCloud2.setPosition(-200,height);
			cloud2Active = true;

		}
		else
		{
			spriteCloud2.setPosition(

				spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()),
				spriteCloud2.getPosition().y);

			if (spriteCloud2.getPosition().x>1920)
			{
				cloud2Active=false;

			}
		}

			if (!cloud3Active)
		{
			srand((int)time(0)*30);
			cloud3Speed = (rand()%200);
			srand((int)time(0)*30);
			float height = (rand()%450)-150;
			spriteCloud3.setPosition(-200,height);
			cloud3Active = true;

		}
		else
		{
			spriteCloud3.setPosition(

				spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()),
				spriteCloud3.getPosition().y);

			if (spriteCloud3.getPosition().x>1920)
			{
				cloud3Active=false;

			}
		}




		/*
		draw the scene
		*/
		//clear everything from the previous frame
		window.clear();
		window.draw(spriteBackground);
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		window.draw(spriteTree);
		window.draw(spriteBee);






		//draw the new scene here

		//show what has been drawn

		window.display();


	}
	return 0;
}

