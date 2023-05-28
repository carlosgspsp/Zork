#pragma once
#include "entity.h"
#include "room.h"


class Item : public Entity
{
private:
	Room* location;
	bool takeable;
	bool container;


};

