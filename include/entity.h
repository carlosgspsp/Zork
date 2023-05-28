#pragma once

#include <iostream>
#include <list>
#include <string>

using namespace std;

enum EntityType
{
	CREATURE,
	EXIT,
	ROOM,
	ITEM,
};

class Entity
{
private:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;

public:
	Entity(string name, string description, EntityType type);

	virtual void Update() = 0;

	EntityType GetType();
	string GetName();
	string GetDescription();
	list<Entity*>& GetContains();


	void SetType(EntityType type);
	void SetName(string name);
	void SetDescription(string description);
	



};


