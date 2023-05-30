#pragma once
#include "entity.h"
#include "room.h"
#include "item.h"


using namespace std;

enum ExitDirections
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	UP,
	DOWN
};

class Exit : public Entity
{
private:
	ExitDirections direction;
	Room* source;
	Room* destination;
	Item* key;
	bool locked;
	bool closeable;
	bool open;
public:
	Exit(string name, string description, ExitDirections direction, Room* source, Room* destination); //Exit constructor
	Exit(string name, string description, ExitDirections direction, Room* source, Room* destination, bool locked, Item* key);
	void Update()override;
	Room* GetSource();
	Room* GetDestination();
	ExitDirections GetDirection();
	bool isLocked();
	void setLocked(bool locked);
	Item* getKey();

};

