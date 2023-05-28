#include "../include/room.h"


Room::Room(string name, string description) : Entity(name, description, EntityType::ROOM) { //Room constructor

	this->SetType(EntityType::ROOM);
	this->SetName(name);
	this->SetDescription(description);

}

