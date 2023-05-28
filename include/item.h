#pragma once
#include "room.h"


class Item : public Entity
{
private:
	Room* location;
	bool takeable;
	bool container;

public:
	void Update()override;
};

