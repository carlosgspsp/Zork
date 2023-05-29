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
	const list<Entity*>& GetContains();
	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);

	//Set contains
	//Add contains
	//Remove contains


	void SetType(EntityType type);
	void SetName(string name);
	void SetDescription(string description);
	



};


