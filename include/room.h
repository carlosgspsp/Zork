#pragma once
#include "entity.h"
#include <vector>
#include <string>
class Room : public Entity
{
private:
public:
	Room(string name, string description); //Room constructor
	void Update()override;
	
};

