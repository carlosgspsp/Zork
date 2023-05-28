#pragma once
#include "entity.h"
#include "room.h"


class Creature : public Entity
{
private:
	Room* location;

public:
	Creature(string name, string description, Room* location);
	void Update()override;
};

