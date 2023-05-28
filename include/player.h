#pragma once
#include "creature.h"

enum PlayerActions
{
	TAKE,
	PUT,
	DROP,
	OPEN,
	CLOSE,
	TURN_ON,
};

class Player : public Creature
{
public:
	Player(string name, string description, Room* location);
	void Update()override; 
};

