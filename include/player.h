#pragma once
#include "creature.h"
#include <map>
#include "../include/exit.h"

using namespace std;

class Player : public Creature
{
public:
	Player(string name, string description, Room* location);
	void Update()override; 
	void Go(vector<string> args, const vector<Entity*>& entities, map<string, ExitDirections> &directions_map);
	void Look();
	void Take(vector<string> args, const vector<Entity*>& entities);
};

