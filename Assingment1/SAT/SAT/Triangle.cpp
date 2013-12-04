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
#include "Triangle.h" 

Triangle::Triangle(sf::Vector2f centre, sf::Vector2f vel,float angle):BouncingThing(centre, vel, angle)
{
	pointOne = sf::Vector2f(-20,-20);
	pointTwo = sf::Vector2f(20,20);
	pointThree = sf::Vector2f(-20,20);
	velocity = vel;
	
}
	
	void Triangle::Draw(){
	glBegin(GL_TRIANGLES);//draw a Triangle
    glColor3d(255,100,0);
	glVertex2d(centre.x + pointOne.x,centre.y + pointOne.y);
	 glColor3d(0,200,250);
    glVertex2d(centre.x + pointTwo.x,centre.y + pointTwo.y);
	 glColor3d(150,40,255);
    glVertex2d(centre.x + pointThree.x,centre.y + pointThree.y);
 
        glEnd(); 
	}

	