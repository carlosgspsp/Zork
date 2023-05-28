#pragma once
#include "entity.h"
#include "room.h"

using namespace std;

enum ExitDirection
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
	ExitDirection direction;
	Room* source;
	Room* destination;
public:
	Exit(string name, string description, ExitDirection direction, Room* source, Room* destination); //Exit constructor
	void Update()override;
};

