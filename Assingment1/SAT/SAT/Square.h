#ifndef __Square_h_
#define __Square_h_


#include "BouncingThing.h"
  

class Square:public BouncingThing
{
public:

	 sf::Vector3f colour; 
	 bool selected; 
	// b t t b
	Square::Square( sf::Vector2f centre, sf::Vector2f vel, float angle, sf::Vector3f col);
	void Draw();

};


#endif 
