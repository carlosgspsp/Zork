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
	void Go(vector<string> args, map<string, ExitDirections> &directions_map);
	void Look();
	void Inventory();
	void Take(vector<string> args);
	void Drop(vector<string> args);
	void Put(vector<string> args);
};

