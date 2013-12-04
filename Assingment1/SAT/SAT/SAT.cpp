//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
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
#include "Square.h"
#include <list> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
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
#include "Collision.h"
#include "MapManager.h"
using namespace std;
 
////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 
int main() 
{ 
	 
    // Create the main window 
	MapManager mapM; 
	Collision collision; 
    sf::RenderWindow App(sf::VideoMode(800, 800, 32), "SFML OpenGL"); 
    // Create a clock for measuring time elapsed     
    sf::Clock Clock;  
    //prepare OpenGL surface for HSR 
    glClearDepth(1.f); 
    glClearColor(0.3f, 0.3f, 0.3f, 0.f); //background colour
    glEnable(GL_DEPTH_TEST); 
    glDepthMask(GL_TRUE); 
    //// Setup a perspective projection & Camera position 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(0,800,0,600,0,1); // use pixel coordinates
	int randomX, randomY; 
	float num = ( rand() % 10 ) / 10.0f;

    /* initialize random seed: */
    srand (time(NULL));

    /* generate number between 1 and 10: */
    randomX = rand() % 800 + 1;
    randomY = rand() % 800 + 1;

	
	//vector<Triangle*> triangles; 
	//triangles.resize(10);

 //  for(int i = 0; i< 10; i++)
	//{
	//	triangles[i] = new Triangle (sf::Vector2f(randomX ,randomY),sf::Vector2f(randomX, randomY), 1*randomX);
	//	randomX = rand() % 150 + 10; 
	//	randomY = rand() %80 + 10;
	//}

   vector<Square*> squares; 
	squares.resize(10);
	
	for(int i = 0; i< 10; i++)
	{
		squares[i] = new Square (sf::Vector2f(randomX ,randomY),sf::Vector2f(num, num), 2,sf::Vector3f(200,100,0));
		randomX = rand() % 800 + 1; 
		randomY = rand() % 800 + 1;
		num= ( rand() % 20 ) / 20.0f; 
	}

	 App.clear(sf::Color::Black);  
	sf::VertexArray lines(sf::Lines, 16); {
		lines[0].position = sf::Vector2f(0, 0);
        lines[1].position = sf::Vector2f(800, 0);
        lines[2].position = sf::Vector2f(0, 200);
        lines[3].position = sf::Vector2f(800, 200);
		lines[4].position = sf::Vector2f(0, 400);
        lines[5].position = sf::Vector2f(800, 400);
        lines[6].position = sf::Vector2f(0, 600);
        lines[7].position = sf::Vector2f(800, 600);
		lines[8].position = sf::Vector2f(0, 0);
        lines[9].position = sf::Vector2f(0, 800);
        lines[10].position = sf::Vector2f(200, 0);
        lines[11].position = sf::Vector2f(200, 800);
		lines[12].position = sf::Vector2f(400, 0);
        lines[13].position = sf::Vector2f(400, 800);
        lines[14].position = sf::Vector2f(600, 0);
        lines[15].position = sf::Vector2f(600, 800);
		
	};
	

 //   // Start game loop 
    while (App.isOpen()) 
    { 
        // Process events 
        sf::Event Event; 
        while (App.pollEvent(Event)) 
        { 
            // Close window : exit 
            if (Event.type == sf::Event::Closed) 
                App.close(); 
   
            // Escape key : exit 
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape)) 
                App.close();            
    
        } 
           
        //Prepare for drawing 
        // Clear color and depth buffer 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
       	 
		/*for(int i = 0; i< 10; i++)
	{
		triangles[i]->Draw(); 
		triangles[i]->Update();
	
		}*/

		
		App.draw(lines);
			
		for(int i = 0; i< 10; i++)
		{
			squares[i]->Draw(); 
			squares[i]->Update();
			//Register an id for each square in squares 
			mapM.registerSprite(squares[i]);
		
		
		}  

		for(int i = 1; i< 10; i++)
		{
			//set their colour to yellow
			squares[i]->colour = sf::Vector3f(225,225,0);
		}
		
		//Check all the nearby squares to sqaure[0]
		squares[0]->colour = sf::Vector3f(0,1,1);
		list<Square*> sList = mapM.getNearbySprites(*squares[0]);
		list<Square*>::iterator it = sList.begin(); 
	    list<Square*>::iterator end = sList.end();
        
		for (;it != end;it++)
	     {
				Square* square = *it;
				if(*it != squares[0])
				{
				square->colour = sf::Vector3f(225,182,193); 
				}	 
		}

		for (list<Square*>::iterator it1 = sList.begin(); it1 != sList.end();it1++)
	    {
			for (list<Square*>::iterator it2 = sList.begin(); it2 != sList.end();it2++)
			{
				Square* squareIt = *it1;
				Square* squareIt2 = *it2;

				if(it1 != it2)
				 {

				 if(collision.satCollision(*squareIt,*squareIt2))
				  {
					squareIt->velocity = sf::Vector2f(0,0);  
				  }
				 
				 }

			}
	  }
	
		mapM.clearBucketLists();

        glEnd(); 
   
        // Finally, display rendered frame on screen 
        App.display(); 
    } 
   
    return EXIT_SUCCESS; 
}
