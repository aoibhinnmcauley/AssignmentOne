#include "stdafx.h"
#include "MapManager.h"


// Constructor method for the MapManager (see step 2 in the assignment)
MapManager::MapManager() {
	for(int i = 0; i <16; i++)
	{
		m_buckets[i] = std::list<Square *>();
	}
}

// Clear each entry in the map (step 3 in the assignment)
void MapManager::clearBucketLists() 
{	
	for(int i = 0; i <16; i++)
	{
		m_buckets[i].clear();
	}
}

// Register the given sprite in the map (step 5 in the assignment)
void MapManager::registerSprite( Square  *sprite ) {
	list<int> cellIds = getBucketId( *sprite );
	list<int>::iterator it = cellIds.begin(); 
	list<int>::iterator end = cellIds.end();

	for (;it != end;it++)
	  {
		 m_buckets[*it].push_back(sprite); 
	  } 
 

	// TODO: Implement logic here...
}
	
// For each sprite corner, call the AddSpriteToBucket member function below. 
// See step 4 in the assignment for further details.
list<int> MapManager::getBucketId(Square const & sprite) {
	// A list of bucket id's that the given sprite is in.
	list<int> bucketsSpriteIsIn;

	sf::Vector2f spriteCorner1 = sprite.centre + sprite.pointOne;
	sf::Vector2f spriteCorner2 = sprite.centre + sprite.pointTwo;
	sf::Vector2f spriteCorner3 = sprite.centre + sprite.pointThree;
	sf::Vector2f spriteCorner4 = sprite.centre + sprite.pointFour;

	//floor:Rounds x downward, returning the largest integral value that is not greater than x.
	int vec1 = floor( spriteCorner1.x / 200 ) + ( floor(spriteCorner1.y / 200 ) * 4 );
	int vec2 = floor( spriteCorner2.x  / 200 ) + ( floor(spriteCorner2.y / 200 ) * 4 );
	int vec3 = floor( spriteCorner3.x / 200 ) + ( floor(spriteCorner3.y / 200 ) * 4 );
	int vec4= floor( spriteCorner4.x / 200 ) + ( floor(spriteCorner4.y / 200 ) * 4 );

	bucketsSpriteIsIn.push_back(vec1);
	bucketsSpriteIsIn.push_back(vec2);
	bucketsSpriteIsIn.push_back(vec3);
	bucketsSpriteIsIn.push_back(vec4);

	bucketsSpriteIsIn.sort();

	//get's rid off any dupicate Id's
	bucketsSpriteIsIn.unique();

	return bucketsSpriteIsIn;
}

// For the given sprite corner, work out which bucket the sprite should be added to, then
//  add it's bucketid to the list.
void MapManager::addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn ) {
	// TODO: Implement logic here...
}

// Returns a list of nearby sprites for the given sprite (step 6 in the assignment).
list<Square *> MapManager::getNearbySprites( Square & sprite ) {
	// The list of nearby sprites to return.
	list<Square *> nearbySprites;
	//gets id for one sprite that is passed in
	list<int> iDs = getBucketId( sprite );
	list<int>::iterator it = iDs.begin(); 
	list<int>::iterator end = iDs.end();


	for (;it != end;it++)
	  {
		  nearbySprites.merge(m_buckets[*it]);

	  } 
 
	return nearbySprites;
}
