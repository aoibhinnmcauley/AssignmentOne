
#include "stdafx.h"
#include "Collision.h"

bool Collision::satCollision(BouncingThing& aObject, BouncingThing& bObject)
{
        sf::Vector2f axis;
        double tmp, minA, maxA, minB, maxB;
        int side;
		int aNumSides = 4;
        int bNumSides = 4;
		sf::VertexArray aPoints(sf::Points, aNumSides);// aObject.GetShape();
		aPoints[0].position = aObject.pointOne; 
		aPoints[1].position = aObject.pointTwo; 
		aPoints[2].position = aObject.pointThree; 
		aPoints[3].position = bObject.pointFour;
        sf::VertexArray bPoints(sf::Points, bNumSides); //= bObject.GetShape();
	    bPoints[0].position = bObject.pointOne; 
		bPoints[1].position = bObject.pointTwo; 
		bPoints[2].position = bObject.pointThree;
		bPoints[3].position = bObject.pointFour;
		sf::Vector2f aCenter = aObject.centre;
		sf::Vector2f bCenter = bObject.centre;
 
        /* test polygon A's sides */
        for (side = 0; side < aNumSides; side++)
        {
                /* get the axis that we will project onto */
                if (side == 0)
                {
                        axis.x = aPoints[aNumSides - 1].position.y - aPoints[0].position.y;
                        axis.y = aPoints[0].position.x - aPoints[aNumSides - 1].position.x;
                }
                else
                {
                        axis.x = aPoints[side - 1].position.y - aPoints[side].position.y;
                        axis.y = aPoints[side].position.x - aPoints[side - 1].position.x;
                }
 
                /* normalize the axis */
                tmp = sqrt(axis.x * axis.x + axis.y * axis.y);
                axis.x = axis.x / tmp;
                axis.y = axis.y / tmp;//chANGE
 
                /* project polygon A onto axis to determine the min/max */
                minA = maxA = aPoints[0].position.x * axis.x + aPoints[0].position.y * axis.y;
                for (int i = 1; i < aNumSides; i++)
                {
                        tmp = aPoints[i].position.x * axis.x + aPoints[i].position.y * axis.y;
                        if (tmp > maxA)
                                maxA = tmp;
                        else if (tmp < minA)
                                minA = tmp;
                }
                /* correct for offset */
                tmp = aCenter.x * axis.x + aCenter.y * axis.y;
 
                minA += tmp;
                maxA += tmp;
 
                /* project polygon B onto axis to determine the min/max */
                minB = maxB = bPoints[0].position.x * axis.x + bPoints[0].position.y * axis.y;
                for (int i = 1; i < bNumSides; i++)
                {
                        tmp = bPoints[i].position.x * axis.x + bPoints[i].position.y * axis.y;
                        if (tmp > maxB)
                                maxB = tmp;
                        else if (tmp < minB)
                                minB = tmp;
                }
                /* correct for offset */
                tmp = bCenter.x * axis.x + bCenter.y * axis.y;
 
                minB += tmp;
                maxB += tmp;

				 if (maxA < minB || minA > maxB)
                        return false;
 
                
        }
 
        /* test polygon B's sides */
        for (side = 0; side < bNumSides; side++)
        {
                /* get the axis that we will project onto */
                if (side == 0)
                {
                        axis.x = bPoints[bNumSides - 1].position.y - bPoints[0].position.y;
                        axis.y = bPoints[0].position.x - bPoints[bNumSides - 1].position.x;
                }
                else
                {
                        axis.x = bPoints[side - 1].position.y - bPoints[side].position.y;
                        axis.y = bPoints[side].position.x - bPoints[side - 1].position.x;
                }
 
                /* normalize the axis */
                tmp = sqrt(axis.x * axis.x + axis.y * axis.y);
 
                axis.x /= tmp;
                axis.y /= tmp;
 
                /* project polygon A onto axis to determine the min/max */
                minA = maxA = aPoints[0].position.x * axis.x + aPoints[0].position.y * axis.y;
                for (int i = 1; i < aNumSides; i++)
                {
                        tmp = aPoints[i].position.x * axis.x + aPoints[i].position.y * axis.y;
                        if (tmp > maxA)
                                maxA = tmp;
                        else if (tmp < minA)
                                minA = tmp;
                }
                /* correct for offset */
 
                tmp = aCenter.x * axis.x + aCenter.y * axis.y;
 
                minA += tmp;
                maxA += tmp;
 
                /* project polygon B onto axis to determine the min/max */
                minB = maxB = bPoints[0].position.x * axis.x + bPoints[0].position.y * axis.y;
                for (int i = 1; i < bNumSides; i++)
                {
                        tmp = bPoints[i].position.x * axis.x + bPoints[i].position.y * axis.y;
                        if (tmp > maxB)
                                maxB = tmp;
                        else if (tmp < minB)
                                minB = tmp;
                }
                /* correct for offset */
                tmp = bCenter.x * axis.x + bCenter.y * axis.y;
 
                minB += tmp;
                maxB += tmp;
 
                ///* test if lines intersect, if not, return false */
                //if (maxA < minB || minA > maxB)
                //        return true;
				/* test if lines intersect, if not, return false */
                if (maxA < minB || minA > maxB)
                        return false;
				
        }
 
        return true;
}