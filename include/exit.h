#pragma once
#include "entity.h"
#include "room.h"

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
public:
	Exit(string name, string description, ExitDirections direction, Room* source, Room* destination); //Exit constructor
	void Update()override;
	Room* GetSource();
	Room* GetDestination();
	ExitDirections GetDirection();

};

