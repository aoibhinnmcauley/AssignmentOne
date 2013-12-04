#include "stdafx.h" 
#include "Square.h"


Square::Square( sf::Vector2f centre, sf::Vector2f vel, float angle, sf::Vector3f Colour):BouncingThing(centre,vel,angle){
	// b t t b
pointOne = sf::Vector2f(-20,-20);
pointTwo = sf::Vector2f(-20,20);
pointThree = sf::Vector2f(20,20);
pointFour = sf::Vector2f(20,-20); 
rotation.rotate(angle);
velocity = vel;
colour = Colour; 
selected = false; 

}
	
 void Square::Draw(){

	 glBegin(GL_QUADS);
	 glColor3d(colour.x,colour.y,colour.z);
	glVertex2d(centre.x + pointOne.x,centre.y + pointOne.y);
	 glColor3d(colour.x,colour.y,colour.z);
    glVertex2d(centre.x + pointTwo.x,centre.y + pointTwo.y);
	 glColor3d(colour.x,colour.y,colour.z);
    glVertex2d(centre.x + pointThree.x,centre.y + pointThree.y);
	 glColor3d(colour.x,colour.y,colour.z);
    glVertex2d(centre.x + pointFour.x,centre.y + pointFour.y);
	 glEnd();
 }
	