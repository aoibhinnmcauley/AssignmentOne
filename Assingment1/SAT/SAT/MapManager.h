#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "DemoConstants.h"
#include "Square.h"
#include <map>
#include <list>
#include <algorithm> // for STL find()

using std::list;
using std::map;

// See MapManager.cpp for instructions on each member function below.

class MapManager {
public:

	MapManager();

	void clearBucketLists();

	void registerSprite( Square * sprite );


	list<Square *> getNearbySprites( Square & sprite );

	

private:

	map< int, list< Square *> > m_buckets;

	list<int> getBucketId( Square const & sprite );	

	void addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn );

};

#endif