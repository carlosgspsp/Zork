#pragma once
#include "creature.h"



class Player : public Creature
{
public:
	Player(string name, string description, Room* location);
	void Update()override; 
};

