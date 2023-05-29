#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "entity.h"

using namespace std;

enum Actions
{
	TAKE,
	LOOK,
	INVENTORY,
	GO,
	PUT,
	DROP,
	OPEN,
	CLOSE,
	TURN_ON,
};

class World
{
private:
	vector<Entity*> entities;
	bool finish_game;
	map<string, Actions> actions_map;
	Entity* player;
public:
	World();
	void Play();
	void ParseCommand(string command);
	bool GameFinished();
	vector<string> Tokenize(string command);
};
