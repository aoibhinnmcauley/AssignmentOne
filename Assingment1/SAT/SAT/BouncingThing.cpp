#include "stdafx.h"
#include "BouncingThing.h"

BouncingThing::BouncingThing(sf::Vector2f theCentre, sf::Vector2f vel,float angle)
{
	centre = theCentre;
	rotation.rotate(angle);
	velocity = vel;
	direction = RightUp;
	


}