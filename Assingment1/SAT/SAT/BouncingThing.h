#ifndef __BouncingThing_h_
#define __BouncingThing_h_

#include "stdafx.h"
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
 
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>

class BouncingThing
{
	public:

	sf::Vector2f centre;
	sf::Vector2f pointOne;
	sf::Vector2f pointTwo;
	sf::Vector2f pointThree;
	sf::Vector2f pointFour;
	sf::Vector2f point;
	sf::Transform rotation;
	sf::Vector2f velocity;
	sf::Vector3f colour;

	BouncingThing::BouncingThing(sf::Vector2f centre, sf::Vector2f vel, float angle);

	void Draw();

	enum Direction {RightUp, RightDown, LeftUp, LeftDown} direction;
	void BouncingThing::Update()
	{

	if(centre.y + pointOne.y >= 795 || centre.y + pointTwo.y >= 795 ||centre.y + pointThree.y >= 795||centre.y + pointFour.y >= 795)
	{
		if(direction == RightUp)
		{
			velocity.x  = 0.5; 
			velocity.y = -0.5;
			direction = RightDown;
		}
		else if(direction == LeftUp)
		{
			
			velocity.x  = -0.5; 
			velocity.y = -0.5;
			direction = LeftDown;
		}
	}
	if(centre.x + pointOne.x >= 795 || centre.x + pointTwo.x >= 795 ||centre.x + pointThree.x >= 795||centre.y + pointFour.x >= 795)
	{
		
		if(direction == RightUp)
		{
			velocity.x  = -0.5; 
			velocity.y =  0.5;
			direction = LeftUp;
		}
		else if(direction == RightDown)
		{
			velocity.x  = -0.5; 
			velocity.y = -0.5;
			direction = LeftDown;
		}


	}
	if(centre.y +pointOne.y <= 5 ||centre.y + pointTwo.y <= 5 ||centre.y + pointThree.y <= 5||centre.y + pointFour.y <= 5)
	{
		if(direction == RightDown)
		{
			velocity.x  = 0.5; 
			velocity.y = 0.5;
			direction = RightUp;
		}
		else if(direction == LeftDown)
		{
			velocity.x  = -0.5; 
			velocity.y = 0.5;
			direction = LeftUp;
		}

		

	}
	if(centre.x +pointOne.x <= 5 ||centre.x + pointTwo.x <= 5 || centre.x +pointThree.x <= 5||centre.y + pointFour.x <= 5)
	{
		if(direction == LeftDown)
		{
			velocity.x  = 0.5; 
			velocity.y = -0.5;
			direction = RightDown;
		}
		else if(direction == LeftUp)
		{
			velocity.x  = 0.5; 
			velocity.y = 0.5;
			direction = RightUp;
		}
	}



	    pointOne = rotation.transformPoint(pointOne);
		pointTwo = rotation.transformPoint(pointTwo);
		pointThree = rotation.transformPoint(pointThree);
		pointFour = rotation.transformPoint(pointFour);
		
		centre += velocity;
}

};
#endif